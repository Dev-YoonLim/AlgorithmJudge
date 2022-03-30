#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<string, string> Chstr;

//map.find È°¿ë

string findstring(string str) {
    string newstr;
    string check;
    newstr.clear();
    check.clear();

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            newstr += str[i];
        }
        else {
            check += str[i];
            if (Chstr.find(check) != Chstr.end()) {
                newstr += Chstr[check];
                check.clear();
            }
        }
    }
    return newstr;
    /* if (str.find('one') != str.npos) {
         str.erase(str.begin() + str.find('one'), str.begin() + str.find('one') + 2);
         str[str.find('one')] = '1';
     }*/
}

int solution(string s) {
    Chstr["one"] = "1";
    Chstr["two"] = "2";
    Chstr["three"] = "3";
    Chstr["four"] = "4";
    Chstr["five"] = "5";
    Chstr["six"] = "6";
    Chstr["seven"] = "7";
    Chstr["eight"] = "8";
    Chstr["nine"] = "9";
    Chstr["zero"] = "0";

    //findstring(s);
    int answer = 0;
    answer = stoi(findstring(s));
    return answer;
}

/*
#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    return stoi(s);
}
*/

