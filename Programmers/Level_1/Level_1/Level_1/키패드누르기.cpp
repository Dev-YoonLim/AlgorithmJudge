#include <string>
#include <map>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;

map<int, pair<int, int>> Keypad;
pair<int, int> LKeypadindex;
pair<int, int> RKeypadindex;

void init() {
    
    Keypad[0] = pair<int, int>{ 2, 4 };
    Keypad[1] = pair<int, int>{ 1, 1 };
    Keypad[2] = pair<int, int>{ 2, 1 };
    Keypad[3] = pair<int, int>{ 3, 1 };
    Keypad[4] = pair<int, int>{ 1, 2 };
    Keypad[5] = pair<int, int>{ 2, 2 };
    Keypad[6] = pair<int, int>{ 3, 2 };
    Keypad[7] = pair<int, int>{ 1, 3 };
    Keypad[8] = pair<int, int>{ 2, 3 };
    Keypad[9] = pair<int, int>{ 3, 3 };
    Keypad[10] = pair<int, int>{ 1, 4 };
    Keypad[11] = pair<int, int>{ 3, 4 };
    LKeypadindex = Keypad[10];
    RKeypadindex = Keypad[11];
}

string TouchKeypad(vector<int> numbers, string hand) {
    string KeypadStack = "";

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            KeypadStack += 'L';
            LKeypadindex = Keypad[numbers[i]];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            KeypadStack += 'R';
            RKeypadindex = Keypad[numbers[i]];
        }
        else {
            int Right = abs(Keypad[numbers[i]].first - RKeypadindex.first) + abs(Keypad[numbers[i]].second - RKeypadindex.second);
            int left = abs(Keypad[numbers[i]].first - LKeypadindex.first) + abs(Keypad[numbers[i]].second - LKeypadindex.second);
            if (hand == "left") {
                if (Right < left) {
                    KeypadStack += 'R';
                    RKeypadindex = Keypad[numbers[i]];
                }
                else {
                    KeypadStack += 'L';
                    LKeypadindex = Keypad[numbers[i]];
                }
            }
            else {
                if (Right > left) {
                    KeypadStack += 'L';
                    LKeypadindex = Keypad[numbers[i]];
                }
                else {
                    KeypadStack += 'R';
                    RKeypadindex = Keypad[numbers[i]];
                }
            }
        }
    }
    return KeypadStack;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    init();
    answer = TouchKeypad(numbers, hand);
    return answer;
}