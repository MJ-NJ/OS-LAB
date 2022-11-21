#include <iostream>
using namespace std;
void WaitingTime(int process[], int n, int bt[], int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}
void TurnAroundTime(int process[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
void AverageTime(int process[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    WaitingTime(process, n, bt, wt);
    TurnAroundTime(process, n, bt, wt, tat);
    cout << "Process  "
         << "Burst Time  "
         << "Waiting Time  "
         << "Turn Around Time  \n";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i + 1 << "\t\t" << bt[i] << "\t  " << wt[i] << "\t\t  " << tat[i] << endl;
    }
    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\n Average turn around time = " << (float)total_tat / (float)n;
}
int main()
{
    int process[] = {1, 2, 3};
    int n = sizeof process / sizeof process[0];
    int BurstTime[] = {10, 5, 8};
    AverageTime(process, n, BurstTime);
    return 0;
}
