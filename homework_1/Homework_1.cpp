#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string timeInput;

    char colon; // Will be used to capture ':' character

    // Definition for time structure
    struct timeStruct {
        int hours;
        int minutes;
        int seconds;
        long total_seconds;
    };

    while (1) {

        cout << "Please enter the time (HH:MM:SS format): ";

        cin >> timeInput;

        stringstream timeStream(timeInput);

        timeStruct time1;

        // Parsing the string to get time values
        timeStream >> time1.hours >> colon;
        timeStream >> time1.minutes >> colon;
        timeStream >> time1.seconds;

        // Checking if hours, minutes, and seconds are valid

        if ((time1.hours >= 24) || (time1.hours < 0)) {
            cout << "The entered hour value " << time1.hours << " is incorrect." << endl;
            continue;
        }
        if ((time1.minutes >= 60) || (time1.minutes < 0)) {
            cout << "The entered minute value " << time1.minutes << " is incorrect." << endl;
            continue;
        }
        if ((time1.seconds >= 60) || (time1.seconds < 0)) {
            cout << "The entered second value " << time1.seconds << " is incorrect." << endl;
            continue;
        }

        // If stringstream fails (invalid format entered)

        if (timeStream.fail()) {
            cout << "Invalid time format entered!" << endl;
            continue;
        }

        // If everything is valid, calculate the total seconds
        long total_seconds = time1.hours * 3600 + time1.minutes * 60 + time1.seconds;
        cout << "Total value in seconds: " << total_seconds << endl;

        // Break the loop after a valid input
        break;
    }
}
