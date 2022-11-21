#include <bits/stdc++.h>
using namespace std;
void input_burst_arrival_time(int burst_time[], int process[], int arrival_time[])
{
    cout << "Enter Burst time and arrival time in pairs for 5 processes : " << endl;
    for (int i = 0; i < 5; i++)
    {
        process[i] = i;
        cin >> burst_time[i];
        cin >> arrival_time[i];
    }
}

void sort_arrival_time(int arrival_time[], int process[], int burst_time[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (arrival_time[i] > arrival_time[j])
            {
                swap(process[i], process[j]);
                swap(arrival_time[i], arrival_time[j]);
                swap(burst_time[i], burst_time[j]);
            }
        }
    }
}
// Equal AT wala case
void sort_burst_time(int arrival_time[], int process[], int burst_time[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (arrival_time[i] == arrival_time[j])
            {
                if (burst_time[i] > burst_time[j])
                {

                    swap(process[i], process[j]);
                    swap(arrival_time[i], arrival_time[j]);
                    swap(burst_time[i], burst_time[j]);
                }
            }
        }
    }
}

void sjf(int arrival_time[], int waiting_time[], int burst_time[], int turn_around_time[], int completion_time[])
{
    int temp, value;
    completion_time[0] = arrival_time[0] + burst_time[0];
    turn_around_time[0] = completion_time[0] - arrival_time[0];
    waiting_time[0] = turn_around_time[0] - burst_time[0];

    for (int i = 1; i < 5; i++)
    {
        temp = completion_time[i - 1];
        int low = burst_time[i];
        for (int j = i; j < 5; j++)
        {
            if (temp >= arrival_time[j] && low >= burst_time[j])
            {
                low = burst_time[j];
                value = j;
            }
        }
        completion_time[value] = temp + burst_time[value];
        turn_around_time[value] = completion_time[value] - arrival_time[value];
        waiting_time[value] = turn_around_time[value] - burst_time[value];
    }
}
void PrintTable(int process[], int burst_time[], int waiting_time[], int turn_around_time[], int arrival_time[])
{
    cout << "Process"
         << " \t"
         << "Arrival Time"
         << " \t"
         << "Burst Time"
         << " \t"
         << "Waiting Time"
         << " \t"
         << "Turn Around Time" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << endl
             << endl;
        cout << process[i] << "\t\t" << arrival_time[i] << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turn_around_time[i] << endl;
    }
}
int main()
{
    int n = 5;
    int process[n], BurstTime[n], Waitingtime[n], CompletionTime[n], TurnAroundTime[n], ArrivalTime[n];
    input_burst_arrival_time(BurstTime, process, ArrivalTime);
    sort_arrival_time(ArrivalTime, process, BurstTime);
    sort_burst_time(ArrivalTime, process, BurstTime);

    sjf(ArrivalTime, Waitingtime, BurstTime, TurnAroundTime, CompletionTime);
    PrintTable(process, BurstTime, Waitingtime, TurnAroundTime, ArrivalTime);
    return 0;
}