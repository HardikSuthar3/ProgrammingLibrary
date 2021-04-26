#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input_time;
    getline(cin, input_time);

    int hour_time = stoi(input_time.substr(0, 2));

    string time_phase = input_time.substr(input_time.length() - 2, 2);
    string new_time;

    if (time_phase == "AM")
    {
        new_time = to_string(hour_time);
        if (hour_time == 12)
        {
            //replace 12 with 00
            new_time = "00";
        }
        else
        {
            new_time = "0" + new_time;
        }
        new_time.append(input_time.begin() + 2, input_time.end() - 2);
    }
    else
    {
        if (hour_time != 12)
        {
            hour_time += 12;
        }
        new_time = to_string(hour_time);
        new_time.append(input_time.begin() + 2, input_time.end() - 2);
    }
    cout << new_time;
}

//12:05:45AM
//01:00:46AM
//07:05:45PM
//11:55:00PM