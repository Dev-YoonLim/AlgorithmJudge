#include <string>
#include <vector>

using namespace std;
//vector<string>Checkset;
int CheckString(string s) {
    string checks = "";
    string stringtmp = "";
    int count = 1;
    int result = s.size();
    for (int i = 1; i <= s.size()/2; i++) {
        count = 1;
        checks = "";
        stringtmp = "";
        checks = s.substr(0, i);
        for (int j = i; j < s.size(); j+=i) {
            if (checks == s.substr(j, i))
                count++;
            else {
                if (count > 1) {
                    stringtmp += to_string(count);
                }
                stringtmp += checks;
                checks = s.substr(j, i);
                count = 1;
            }
        }
        if (count > 1)
            stringtmp += to_string(count);
        stringtmp += checks;
        if (result > stringtmp.size())
            result = stringtmp.size();
    }
    return result;
}
int solution(string s) {
    int answer = CheckString(s);
    return answer;
}