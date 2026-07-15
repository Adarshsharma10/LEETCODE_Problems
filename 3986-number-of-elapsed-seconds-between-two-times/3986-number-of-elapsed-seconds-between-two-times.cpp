class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        auto timetoseconds = [](const string& time){
        int hh = stoi(time.substr(0, 2));
        int mm = stoi(time.substr(3, 2));
        int ss = stoi(time.substr(6, 2));
        return hh*3600 + mm * 60 + ss;
    };

    return timetoseconds(endTime) - timetoseconds(startTime);
    }
};