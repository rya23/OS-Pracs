#include <bits\stdc++.h>
using namespace std;
int process = 5;
int resources = 3;

void calculateneed(vector<vector<int>> &need, vector<vector<int>> &maximum, vector<vector<int>> &allocated)
{

    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = maximum[i][j] - allocated[i][j];
        }
    }
}

void bankers(vector<int> processes, vector<int> available, vector<vector<int>> &maximum, vector<vector<int>> &allocated)
{
    vector<vector<int>> need(process, vector<int>(resources, 0));
    calculateneed(need, maximum, allocated);

    vector<bool> finish(process, 0);
    vector<int> sequence(process, 0);

    vector<int> work;
    work = available;
    int count = 0;

    while (count < process)
    {
        bool found = false;
        for (int i = 0; i < process; i++)
        {

            if (finish[i] == 0)
            {
                int j;
                for (j = 0; j < resources; j++)
                {

                    if (need[i][j] > work[j])
                        break;
                }
                if (j == resources)
                {
                    for (int k = 0; k < resources; k++)
                    {
                        work[k] += allocated[i][k];
                    }
                    sequence[count++] = i;
                    finish[i] = 1;
                    found = true;
                }
            }
        }
        if (found == false)
        {
            cout << "System is not in safe state" << endl;
            return;
        }
    }
    cout << "System is in Safe State : " << endl
         << "Sequence is : \t";
    for (int i = 0; i < process; i++)
    {
        cout << sequence[i] << "\t";
    }
}

int main()
{

    vector<int> processes = {0, 1, 2, 3, 4};
    vector<int> available = {3, 3, 2};
    vector<vector<int>> maximum = {{7, 5, 3},
                                   {3, 2, 2},
                                   {9, 0, 2},
                                   {2, 2, 2},
                                   {4, 3, 3}};

    vector<vector<int>> allocated = {{0, 1, 0},
                                     {2, 0, 0},
                                     {3, 0, 2},
                                     {2, 1, 1},
                                     {0, 0, 2}};

    bankers(processes, available, maximum, allocated);
}