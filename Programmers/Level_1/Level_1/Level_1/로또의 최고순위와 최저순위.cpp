#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int Hitcount = 0;
    int failcount = 0;
    int maxrate = 0;
    int minrate = 0;
    for (int i = 0; i < 6; i++) {
        if (lottos[i] != 0) {
            auto findnumber = find(win_nums.begin(), win_nums.end(), lottos[i]);
            if (findnumber == win_nums.end()) 
                failcount++;
            else 
                Hitcount++;
        }
    }
    maxrate = 1 + failcount; // 力老 肋凳
    minrate = 7 - Hitcount; // 力老 噶窃
    if (failcount == 6)
        maxrate = 6;
    answer.push_back(maxrate);
    if(Hitcount < 2)
        answer.push_back(6);
    else
        answer.push_back(minrate);
    return answer;
}