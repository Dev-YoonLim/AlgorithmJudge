#include <string>
#include <vector>

using namespace std;  // 나중에 다시 도전.

string ChangeString(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 97 && s[i] <= 122)
            s[i] -= 32;
    }
    return s;
}

int Cluster(string s1, string s2) {
    vector<string> s1vector;
    vector<string> s2vector;
    string s1value = "";
    string s2value = "";
    s1value = ChangeString(s1);
    s2value = ChangeString(s2);
    int Comp = 0;
    int CompCount = 0;
    float Result = 0;
    for (int i = 0; i + 1 < s1value.size(); i++) {
        string tmp = "";
        if (s1value[i] >= 65 && s1value[i] <= 90
            && s1value[i + 1] >= 65 && s1value[i + 1] <= 90) {
            tmp = s1value[i] + s1value[i + 1];
            s1vector.push_back(tmp);
        }
    }
    for (int i = 0; i + 1 < s2value.size(); i++) {
        string tmp = "";
        if (s2value[i] >= 65 && s2value[i] <= 90
            && s2value[i + 1] >= 65 && s2value[i + 1] <= 90) {
            tmp = s2value[i] + s2value[i + 1];
            s2vector.push_back(tmp);
        }
    }
    for (int i = 0; i < s1vector.size(); i++) {
        for (int j = 0; j < s2vector.size(); j++) {
            if (s1vector[i] == s2vector[j])
                CompCount++;
        }
    }
    Comp = s1vector.size() + s2vector.size() - CompCount;
    Result = (CompCount / Comp) * 65536;
    return CompCount;
}

int solution(string str1, string str2) {
    int answer = 0;
    answer = Cluster(str1, str2);
    return answer;
}