/*
Author: Michael Roberts
Class: CSI-140-52
Assignment: Lab 1
Date Assigned: 2/11/16
Due Date: 2/16/16

Description:
  This program is used to input a large amount seconds, and convert them into larger forms
  of time measurement (minutes,hours,days,months,years)

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
for the purpose of assessing this assignment:
  - Reproduce this assignment and provide a copy to another member of academic staff; and/or
  - Communicate a copy of this assignment to a plagiarism checking service
    (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include <iostream>

using namespace std;

uint seconds, minutes, hours, days, months, years; //starting at year 0

// Would be constant, except days change per month
uint secondsInMonth;

// Seconds we need to add for each leap year
uint secondsToAdd;

// Check if it's a leapyear
bool isLeapYear = false;

// Constants for common time amounts (in seconds)
const uint SECONDS_IN_HOUR   = 3600;
const uint SECONDS_IN_MINUTE = 60;
const uint SECONDS_IN_DAY    = 86400;
const uint SECONDS_IN_YEAR   = 31536000; // 31.5 million

// Setting the days for each month
const uint MONTH_DAYS [12] =
{
    31, // January
    28, // February
    31, // March
    30, // April
    31, // May
    30, // June
    31, // July
    31, // August
    30, // September
    31, // October
    30, // November
    31, // December
};

// Setting the days in each month for the leap year
const uint LEAPYEAR_MONTH_DAYS [12] =
{
    31, // January
    29, // February
    31, // March
    30, // April
    31, // May
    30, // June
    31, // July
    31, // August
    30, // September
    31, // October
    30, // November
    31, // December
};

//Entrance Function
int main(int argc, char const *argv[])
{

    // Get seconds via an input
    cout << "[?] What number of seconds would you like to convert?" << endl;
    cin >> seconds;
    cout << "\n" << seconds << " seconds is equal to:" << endl;
    cout << "-----------------------------" << endl;
    /*
        For each tier of time:
        Get current unit by / seconds input by the units conversion to seconds
        Get remainder of the previous calculation, then set seconds equal to it
        Continue until seconds can not have a remainder
    */

    years = seconds / SECONDS_IN_YEAR; // How many normal years do we have
    seconds %= SECONDS_IN_YEAR; // Set seconds equal to remainder
    secondsToAdd = (years/4) * SECONDS_IN_DAY; // Add back time for each leap year
    seconds += secondsToAdd;
    cout << "Years:   " << years << endl;


    // if divisble by 4, and not divisible by 100 unless its divisble by 400
    // then set isLeapYear to true
    if ((years + 1) % 4 == 0)
    {
      if ((years + 1) % 400 == 0 )
      {
        if ((years + 1) % 100 == 0)
        {
          isLeapYear = true;
        }
      }
    }

    // Loop through each month
    for (int i = 0; i < 11; i++)
    {

        //Set the seconds per month (by year type)
        if (isLeapYear)
        {
            secondsInMonth = LEAPYEAR_MONTH_DAYS[i] * SECONDS_IN_DAY;
        }
        else
        {
            secondsInMonth = MONTH_DAYS[i] * SECONDS_IN_DAY;
        }

        /*
            if the seconds we have in a month are greater then the current
            amount of seconds we having remaining, then break.

            If not then, calculate normally, and add a month
        */

        if (secondsInMonth > seconds)
        {
            break;
        }
        else
        {
            seconds %= secondsInMonth;
            months++;
        }
    }

    cout << "Months:  " << months << endl;


    days = seconds / SECONDS_IN_DAY;
    seconds %= SECONDS_IN_DAY;
    cout << "Days:    " << days << endl;

    hours = seconds / SECONDS_IN_HOUR;
    seconds %= SECONDS_IN_HOUR;
    cout << "Hours:   " << hours << endl;

    minutes = seconds / SECONDS_IN_MINUTE;
    seconds %= SECONDS_IN_MINUTE;
    cout << "Minutes: " << minutes << endl;

    // output however many seconds we have remaining
    cout << "Seconds: " << seconds << endl;
    return 0;
}
