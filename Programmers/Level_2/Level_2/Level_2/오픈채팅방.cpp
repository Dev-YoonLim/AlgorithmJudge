#include <string>
#include <vector>
#include <sstream>
#include <map>
//일단 명령어, 사용자, 닉네임을 나누자
//명령어대로 실행해서 집어넣자
//아이디는 불변, 닉네임은 변환, 즉 아이디를 키로 밸류를 닉네임으로

using namespace std;

vector<string> OrderPlay(vector<string> record) {
    vector<string> ReturnValue;
    vector<string> OrderArray;
    vector<string> IdArray;
    map <string, string> IdToName;

    for (int i = 0; i < record.size(); i++) {
        stringstream SS(record[i]);
        string Order = "", Id = "", Name = "";
        string Replacetmp = "";
        SS.str(record[i]);
        SS >> Order;
        SS >> Id;
        if (Order != "Leave")
            SS >> Name;
        OrderArray.push_back(Order);
        IdArray.push_back(Id);
        if (Order == "Enter") {
            IdToName[Id] = Name;
        }
        /*else if (Order == "Leave") {
            IdToName[Id] = Name;
        }*/
        else if (Order == "Change") {
            IdToName[Id] = Name;
        }

    }


    for (int i = 0; i < record.size(); i++) {
        if (OrderArray[i] != "Change")
            if (OrderArray[i] == "Enter")
                ReturnValue.push_back(IdToName[IdArray[i]] + "님이 들어왔습니다.");
            else
                ReturnValue.push_back(IdToName[IdArray[i]] + "님이 나갔습니다.");
        else
            continue;
    }
    return ReturnValue;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    answer = OrderPlay(record);
    return answer;
}

/*
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <list>
#include <set>
#include <regex>
//일단 명령어, 사용자, 닉네임을 나누자
//명령어대로 실행해서 집어넣자
//아이디는 불변, 닉네임은 변환, 즉 아이디를 키로 밸류를 닉네임으로

using namespace std;

vector<string> OrderPlay(vector<string> record) {
    vector<string> ReturnValue;
    map<string, vector<int>> UserLog;
    map<string, string> UserLastName;
    for (int i = 0; i < record.size(); i++) {
        stringstream SS(record[i]);
        string Order = "", Id = "", Name = "";
        string Replacetmp = "";
        SS.str(record[i]);
        SS >> Order;
        SS >> Id;
        if (Order != "Leave")
            SS >> Name;
        if (Order == "Enter") {
            if (UserLastName[Id] != "" && UserLastName[Id] != Name && i != 0) {
                for (int j = 0; j < UserLog[Id].size(); j++) {
                    //Replacetmp = regex_replace(ReturnValue[UserLog[Id][j]], regex(UserLastName[Id]), Name);
                    Replacetmp = regex_replace("aabbcc", regex("aa"), "bb");
                    //ReturnValue[UserLog[Id][j]] = Replacetmp;
                }
            }
            UserLog[Id].push_back(i);
            UserLastName[Id] = Name;
            ReturnValue.push_back(Name + "님이 들어왔습니다.");
        }
        else if (Order == "Leave") {
            UserLog[Id].push_back(i);
            ReturnValue.push_back(UserLastName[Id] + "님이 나갔습니다.");
        }
        else {
            if (UserLastName[Id] != "" && UserLastName[Id] != Name && i != 0) {
                for (int j = 0; j < UserLog[Id].size(); j++) {
                    //Replacetmp = regex_replace(ReturnValue[UserLog[Id][j]], regex(UserLastName[Id]), Name);
                    Replacetmp = regex_replace("aaabbbccc", regex("aaa"), "bbb");
                    //ReturnValue[UserLog[Id][j]] = Replacetmp;
                }
                UserLastName[Id] = Name;
            }

        }

    }
    return ReturnValue;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    answer = OrderPlay(record);
    return answer;
}


*/
