class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> v = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string max_arrive = max(arriveAlice, arriveBob);
        string min_leave = min(leaveAlice, leaveBob);
        int arrive_month = stoi(max_arrive.substr(0, 2));
        int arrive_date = stoi(max_arrive.substr(3, 2));

        int leave_month = stoi(min_leave.substr(0, 2));
        int leave_date = stoi(min_leave.substr(3, 2));
        int day = 0;
        if (arrive_month > leave_month) {
            return 0;
        } else if (arrive_month == leave_month) {
            if (arrive_date > leave_date) {
                return 0;
            }
            day = (leave_date - arrive_date) + 1;
        } else {
            for (int i = arrive_month; i <= leave_month; i++) {
                if (i == arrive_month) {
                    day += (v[i - 1] - arrive_date + 1);
                } else if (i == leave_month) {
                    day += leave_date;
                } else {
                    day += v[i - 1];
                }
            }
        }

        return day;
    }
};