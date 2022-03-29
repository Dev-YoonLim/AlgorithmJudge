#include <string>
#include <vector>
#include <iostream>

// 핵심은 string.erase 를 쓸줄 아냐 모르냐

using namespace std;

string step1(string id) {
    for (int i = 0; i < id.size(); i++) {
        if ((int)id[i] > 64 && (int)id[i] < 91)
            id[i] = tolower(id[i]);
           // id[i] += 32;
            
    }
    return id;
}

string step2(string id) {
      for (int i = 0; i < id.size() ;) {
         if ((id[i] >= 'a' && id[i] <= 'z') || id[i] == '-' || id[i] == '_' || id[i] == '.' ||
           ( id[i] >= '0' && id[i] <= '9')) {
            i++;
        }
        else
            id.erase(id.begin() + i);
    }
    return id;
}

string step3(string id) {
    for (int i = 1; i < id.size();) {
        if (id[i] == '.' && id[i - 1] == '.') {
            id.erase(id.begin() + i);
        }
        else
            i++;
    }
    return id;
}

string step4(string id) {
    if (id[0] == '.')
        id.erase(id.begin());
    if (id[id.size() - 1] == '.')
        id.erase(id.end() - 1);
    return id;
}

string step5(string id) {
    if (id.empty() == true)
        id.push_back('a');
    return id;
}

string step6(string id) {
    if (id.size() > 15) {
        id.erase(id.begin() + 15, id.end());
        if (id.back() == '.')
            id.pop_back();
    }
    return id;
}

string step7(string id) {
    if (id.size() <= 2) {
        while (id.size() < 3){
            id.push_back(id.back());
        }
    }
    return id;
}

string solution(string new_id) {
    string id = new_id;
    id = step1(new_id);
    id = step2(id);
    id = step3(id);
    id = step4(id);
    id = step5(id);
    id = step6(id);
    id = step7(id);
    string answer = id;
    return answer;
}