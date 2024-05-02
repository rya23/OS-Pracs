#include <bits/stdc++.h>
using namespace std;

void fcfs(vector<int> &arrivaltime, vector<int> &bursttime)
{
    vector<int> waitingtime(arrivaltime.size(), -1);
    vector<int> turnaround(arrivaltime.size(), -1);
    waitingtime[0] = 0;
    turnaround[0] = waitingtime[0] + bursttime[0];

    cout << "ID\t\tArrivalTime\tBurstTime\tWaitingTime\tTurnaroundTime\n";
    for (int i = 1; i < arrivaltime.size(); i++)
    {
        waitingtime[i] = (arrivaltime[i - 1] + bursttime[i - 1] + waitingtime[i - 1]) - arrivaltime[i];
        turnaround[i] = waitingtime[i] + bursttime[i];
    }
    for (int i = 0; i < arrivaltime.size(); i++)
    {
        cout << i << "\t\t" << arrivaltime[i] << "\t\t" << bursttime[i] << "\t\t" << waitingtime[i] << "\t\t" << turnaround[i] << endl;
    }
}

int main()
{
    vector<int> arrivaltime = {0, 1, 2, 3, 4};
    vector<int> bursttime = {3, 5, 2, 5, 5};
    fcfs(arrivaltime, bursttime);
}