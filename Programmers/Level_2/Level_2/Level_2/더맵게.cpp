#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//힙을 쓸줄 아느냐~
//힙은 기본은 내림차순이니라
//바꾸려면 greater<자료형>()을 넣거라~

int solution(vector<int> scoville, int K) {
    vector<int> Setscoville = scoville;
    int answer = 0;
    int LowestScoville = 0;
    int Count = 0;
    make_heap(Setscoville.begin(), Setscoville.end(), greater<int>());
    LowestScoville = Setscoville.front();
    while (LowestScoville < K && Setscoville.size() != 1) {
        int First, Second, New;
        Count++;
        
        First = Setscoville.front();
        pop_heap(Setscoville.begin(), Setscoville.end(), greater<int>());
        Setscoville.pop_back();
        
        Second = Setscoville.front();
        pop_heap(Setscoville.begin(), Setscoville.end(), greater<int>());
        Setscoville.pop_back();

        New = First + 2 * Second;
        Setscoville.push_back(New);
        push_heap(Setscoville.begin(), Setscoville.end(), greater<int>());
        
        LowestScoville = Setscoville.front();
    }
    if (Setscoville.size() == 1 && Setscoville.back() < K)
        return -1;
    else
        return Count;
}

/*
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int needHot;
    priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());

    while(pq.top()<K) {
        if(pq.size()==1) return answer = -1;
        needHot=pq.top(); pq.pop();
        pq.push(needHot+pq.top()*2);
        pq.pop(); answer++;
    }

    return answer;
}
*/