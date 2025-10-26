#include <bits/stdc++.h>
using namespace std;

class HighAccessEmployee2933 {
    int timeDiffMin(string start, string end) {
        int startHour = (start[0]-'0')*10 + (start[1]-'0');
        int startMin = (start[2]-'0')*10 + (start[3]-'0');
        int endHour = (end[0]-'0')*10 + (end[1]-'0');
        int endMin = (end[2]-'0')*10 + (end[3]-'0');
        
        int totalMins = 0;
        if (endHour > startHour + 1)
            totalMins += (endHour - startHour - 1) * 60;

        totalMins += (startHour == endHour)? endMin - startMin: 60 - startMin + endMin;
        return totalMins;
    }

    bool isHigh(vector<string> logins) {
        // printf("\t\t"); for (auto a: logins) printf("%s ", a.c_str()); printf("\n");
        if (logins.size() < 3) return false;

        sort(logins.begin(), logins.end());
        for (int i = 2; i < logins.size(); ++i) {
            // printf("\t\t Time Diff %s and %s: ", logins[i-2].c_str(), logins[i].c_str());
            int timeDiff = timeDiffMin(logins[i-2], logins[i]);
            // printf("%d\n", timeDiff);
            if (timeDiff < 60)
                return true;
        }
        return false;
    }

public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> highEmployees;
        if (access_times.empty()) return highEmployees;

        accessByEmployee.clear();
        for (auto access: access_times) {
            string emp = access[0];
            if (accessByEmployee.find(emp) == accessByEmployee.end()) 
                accessByEmployee.insert({emp, {access[1]}});
            else
                accessByEmployee[emp].push_back(access[1]);
        }

        for (auto [emp, accesses]: accessByEmployee) {
            // printf("\t Checking for %s:\n", emp.c_str());
            if (isHigh(accesses))
                highEmployees.push_back(emp);
            // printf("\n");
        }
        return highEmployees;
    }
private:
    unordered_map<string, vector<string>> accessByEmployee;
};