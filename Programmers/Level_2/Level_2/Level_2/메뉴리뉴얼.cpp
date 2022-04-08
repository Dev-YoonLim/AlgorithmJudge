#include <string>
#include <vector>
#include <map>
//¾ÈÇ¬´Ù ½Ã¹Ù
using namespace std;
map<char, int> OrderVector;
vector<string> solution(vector<string> orders, vector<int> course) {
    string temp = "";
    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].size(); j++) {
            OrderVector[orders[i][j]] += 1;
            if (OrderVector[orders[i][j]] < 3 && OrderVector[orders[i][j]] > 1)
                temp += orders[i][j];
        }
    }
   

    vector<string> answer;
    return answer;
}