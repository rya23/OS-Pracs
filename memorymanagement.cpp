#include <bits/stdc++.h>
using namespace std;

void bestfit(vector<int> &block, vector<int> &process)
{
    vector<int> allocatedblock(block.size(), -1);

    for (int i = 0; i < process.size(); i++)
    {
        int diff = INT_MAX;
        int index = -1;
        for (int j = 0; j < block.size(); j++)
        {
            if (block[j] - process[i] < diff && block[j] - process[i] >= 0 && allocatedblock[j] == -1)
            {
                diff = block[j] - process[i];
                index = j;
            }
        }
        if (index != -1)
        {
            allocatedblock[index] = process[i];
        }
    }
    for (int i = 0; i < allocatedblock.size(); i++)
    {
        cout << block[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < allocatedblock.size(); i++)
    {
        cout << allocatedblock[i] << "\t";
    }
    cout << endl;
}

void worstfit(vector<int> &block, vector<int> &process)
{
    vector<int> allocatedblock(block.size(), -1);

    for (int i = 0; i < process.size(); i++)
    {
        int diff = INT_MIN;
        int index = -1;
        for (int j = 0; j < block.size(); j++)
        {
            if (block[j] - process[i] > diff && block[j] - process[i] >= 0 && allocatedblock[j] == -1)
            {
                diff = block[j] - process[i];
                index = j;
            }
        }
        if (index != -1)
        {
            allocatedblock[index] = process[i];
        }
    }
    for (int i = 0; i < allocatedblock.size(); i++)
    {
        cout << block[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < allocatedblock.size(); i++)
    {
        cout << allocatedblock[i] << "\t";
    }
    cout << endl;
}

void firstfit(vector<int> &block, vector<int> &process)
{
    vector<int> allocatedblock(block.size(), -1);

    for (int i = 0; i < process.size(); i++)
    {
        for (int j = 0; j < block.size(); j++)
        {
            if (block[j] - process[i] >= 0 && allocatedblock[j] == -1)
            {
                allocatedblock[j] = process[i];
                break;
            }
        }
    }
    for (int i = 0; i < allocatedblock.size(); i++)
    {
        cout << block[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < allocatedblock.size(); i++)
    {
        cout << allocatedblock[i] << "\t";
    }
    cout << endl;
}

int main()
{
    vector<int> block = {100, 500, 200, 300, 600};
    vector<int> process = {212, 417, 112, 426};
    cout << "Bestfit = " << endl;
    bestfit(block, process);
    cout << "Worstfit = " << endl;
    worstfit(block, process);
    cout << "Firstfit = " << endl;
    firstfit(block, process);
}