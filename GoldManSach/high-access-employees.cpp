// You are given a 2D 0-indexed array of strings, access_times, with size n. For each i where 0 <= i <= n - 1, access_times[i][0] represents the name of an employee, and access_times[i][1] represents the access time of that employee. All entries in access_times are within the same day.

// The access time is represented as four digits using a 24-hour time format, for example, "0800" or "2250".

// An employee is said to be high-access if he has accessed the system three or more times within a one-hour period.

// Times with exactly one hour of difference are not considered part of the same one-hour period. For example, "0815" and "0915" are not part of the same one-hour period.

// Access times at the start and end of the day are not counted within the same one-hour period. For example, "0005" and "2350" are not part of the same one-hour period.

// Return a list that contains the names of high-access employees with any order you want.

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        sort(access_times.begin(),access_times.end());
        int size = access_times.size();
        unordered_set<string> s;
        vector<string> res;

        for(int i=2;i<size;i++){
            if(s.find(access_times[i][0])==s.end() && access_times[i][0]==access_times[i-2][0]){
                //check that whether entries made with in 59 min
                int t1 = stoi(access_times[i][1]);
                int t2 = stoi(access_times[i-2][1]);

                if(t1-t2<100){
                    res.push_back(access_times[i][0]);
                    s.insert(access_times[i][0]);
                    i++;
                }
            }
        }

        return res;
    }
};
