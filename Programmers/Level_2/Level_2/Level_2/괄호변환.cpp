#include <string>
#include <vector>

using namespace std;


string Devide(string p) {
    vector<char> StringStack1;
    string u = "", v = "", tmp = "";

    if (p == "")
        return "";

    for (int i = 0; i < p.size(); i++) {
        if (p[0] == '(') {
            if (p[i] == '(')
                StringStack1.push_back(p[i]);
            else if (p[i] == ')')
                StringStack1.pop_back();
        }
        else {
            if (p[i] == ')')
                StringStack1.push_back(p[i]);
            else if (p[i] == '(')
                StringStack1.pop_back();
        }

        if (StringStack1.empty() == true) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (u[0] == '(')
        return u + Devide(v);
    else {
        tmp = '(' + Devide(v) + ')';
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(')
                tmp += ')';
            else
                tmp += '(';
        }
        return tmp;
    }
}

string solution(string p) {
    string answer = "";
    answer = Devide(p);
    return answer;
}