#include <string>
#include <vector>
#include <deque>

using namespace std;

deque<int>DayArray;

void CompleteWork(vector<int> Work, vector<int> Speeds) {
    int num = 0;
    for (int i = 0; i < Work.size(); i++) {
        num = (100 - Work.at(i)) / Speeds.at(i);
        if ((100 - Work.at(i)) % Speeds.at(i) == 0) {
            DayArray.push_back(num);
        }
        else {
            DayArray.push_back(num + 1);
        }
    }
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int Index = 0, Count = 0, WorkValue = 0;
    CompleteWork(progresses, speeds);
    while (DayArray.empty() == false) {
        WorkValue = DayArray[0];
        for (int i = 0; i < DayArray.size(); i++) {
            DayArray[i] -= WorkValue;
        }
        while (DayArray[0] <= 0 && DayArray.empty() == false) {
            DayArray.pop_front();
            Count++;
        }
        answer.push_back(Count);
        Count = 0;
    }
    return answer;
}

/*
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
}
*/
