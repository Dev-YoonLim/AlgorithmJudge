#include <string>
#include <vector>

using namespace std;
int answer = 0;

void DFS(vector<int> numbers, int target, int count, int sum) {
    if (count == numbers.size()) {
        if (sum == target) {
            answer++;
        }
        return;
    }
    DFS(numbers, target, count + 1, sum + numbers[count]);
    DFS(numbers, target, count + 1, sum - numbers[count]);
}

int solution(vector<int> numbers, int target) {
    int Count = 0;
    int Sum = 0;
    DFS(numbers, target, Count, Sum);
    return answer;
}