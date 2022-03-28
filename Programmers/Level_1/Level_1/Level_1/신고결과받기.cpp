#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	
	string FromReport;
	string ToReport;
	map<string, int> ReportCount;
	map<string, set<string>> ReportLog;

	for (string Reportstr: report) {
		int blank = Reportstr.find(' ');
		FromReport = Reportstr.substr(0, blank);
		ToReport = Reportstr.substr(blank);
		
		if (ReportLog[FromReport].find(ToReport) == ReportLog[FromReport].end()) {
			ReportCount[ToReport]++;
			ReportLog[FromReport].insert(ToReport);
		}
	}

	for (string Userstr: id_list ) {
		int res = 0;
		for (string Logstr : ReportLog[Userstr])
			if (ReportCount[Logstr] >= k)
				res++;

		answer.push_back(res);
	}

	return answer;
}