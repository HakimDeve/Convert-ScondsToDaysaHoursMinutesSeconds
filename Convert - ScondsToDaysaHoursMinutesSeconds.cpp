#include <iostream>
#include <string>
using namespace std;

struct stTaskDuration
{
    int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

int ReadPositiveNumber(string MSG)
{
    float Number = 0;

    do
    {
        cout << MSG << endl;
        cin >> Number;

    } while (Number <= 0);

    return Number;

}

stTaskDuration ConvertSecondsToDuration(int TotalSeconds)
{
    stTaskDuration TaskDuration;

    const int ScondPerDay = 24 * 60 * 60;
    const int ScondPerHour = 60 * 60;
    const int ScondPerMinute = 60;

    int Remainder = 0;

    TaskDuration.NumberOfDays = floor(TotalSeconds / ScondPerDay);
    Remainder = TotalSeconds % ScondPerDay;
    TaskDuration.NumberOfHours = floor(Remainder / ScondPerHour);
    Remainder %= ScondPerHour;
    TaskDuration.NumberOfMinutes = floor(Remainder / ScondPerMinute);
    Remainder %= ScondPerMinute;
    TaskDuration.NumberOfSeconds = Remainder;

    return TaskDuration;
}

void PrintTaskDurationDetails(stTaskDuration TaskDuration)
{
    cout << endl;
    cout << TaskDuration.NumberOfDays << " : "
        << TaskDuration.NumberOfHours << " : "
        << TaskDuration.NumberOfMinutes << " : "
        << TaskDuration.NumberOfSeconds << "\n ";
}


int main()
{
    int TotalSconds = ReadPositiveNumber("Please Enter Total Sconds ?");
    PrintTaskDurationDetails(ConvertSecondsToDuration(TotalSconds));

    return 0;