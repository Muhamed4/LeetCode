

// Link Of Problem

// https://leetcode.com/problems/number-of-days-between-two-dates/

// 1360. Number of Days Between Two Dates




class Solution {
public:
    int Overall_Days(string date){
        int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = 0;
        string year = date.substr(0, 4);
        string month = date.substr(5 , 2);
        string day = date.substr(8, 2);
        if(month[0] == '0'){
            char p = month[1];
            month = "";
            month += p;
        }
        if(day[0] == '0'){
            char p = day[1];
            day = "";
            day += p;
        }
        int y = 0, m = 0, d = 0;
        y = stoi(year);
        m = stoi(month);
        d = stoi(day);
        for(int i = 1; i < y;i++){
            if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))days += 366;
            else days += 365;
        }
        for(int i = 0 ; i < m - 1;i++){
            if(i == 1){
                if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))days += 29;
                else days += 28;
            }
            else days += arr[i];
        }
        days += d;
        return days;
    }
    int daysBetweenDates(string date1, string date2) {
        int d1 = Overall_Days(date1);
        int d2 = Overall_Days(date2);
        return abs(d1 - d2);
    }
};