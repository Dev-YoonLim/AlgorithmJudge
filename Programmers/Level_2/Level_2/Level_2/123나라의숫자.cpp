#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<int> NumberArray;
//124는 3진법 개념와 같음

string NumberChange(int n) {
    string ReturnValue = "";
    int InputNumber = n;
    int InputNumberOrigin = n;
    while (InputNumber > 3) {
        if (InputNumber % 3 == 0) {
            NumberArray.push_back(4);
            InputNumber = (InputNumber /= 3) - 1;
        }
        else {
            NumberArray.push_back(InputNumber % 3);
            InputNumber /= 3;
        }
    }
    if (InputNumber % 3 == 0)
        NumberArray.push_back(4);
    else
        NumberArray.push_back(InputNumber);

    while (NumberArray.size() > 0) {
        int values = NumberArray.back();
        NumberArray.pop_back();
        ReturnValue += to_string(values);
    }

    return ReturnValue;
}

string solution(int n) {
    string answer = "";
    answer = NumberChange(n);
    return answer;
}