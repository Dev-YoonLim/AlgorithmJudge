#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0;
    string SetString;
    SetString.push_back(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (SetString.back() == s[i]) {
            SetString.pop_back();
        }
        else
            SetString.push_back(s[i]);
    }
    if (SetString.empty() == true)
        answer = 1;
    else
        answer = 0;

    return answer;
}