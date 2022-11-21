#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the number of processes : ";
    cin >> n;
    cout << "Enter the number of resources : ";
    cin >> m;

    int avail[m], max[n][m], need[n][m], allocation[n][m];

    cout << "Enter the available array\n";
    for (int i = 0; i < m; i++)
    {
        cin >> avail[i];
    }

    cout << "Enter the max matrix \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> max[i][j];
        }
    }

    cout << "Enter the allocation matrix \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> allocation[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    cout << "Need matrix \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << need[i][j] << " ";
        }
        cout << "\n";
    }

    int work[m], finish[n], safeSequence[n], idx = 0;
    for (int i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }
    for (int i = 0; i < n; i++)
    {
        finish[i] = false;
    }
    while (true)
    {
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                bool flag = true;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = true;
                    found = true;
                    safeSequence[idx++] = i;
                    break;
                }
            }
        }
        if (!found)
        {
            break;
        }
    }
    bool safe = true;
    for (int i = 0; i < m; i++)
    {
        if (!finish[i])
        {
            safe = false;
            break;
        }
    }
    if (safe)
    {
        cout << "\nSafe state\n";
        for (idx = 0; idx < n; idx++)
        {
            cout << safeSequence[idx] << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "\nUnsafe state\n";
        return 0;
    }
}
