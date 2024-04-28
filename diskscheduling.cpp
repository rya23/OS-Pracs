#include <bits\stdc++.h>
using namespace std;

int fcfs(vector<int> &values, int head)
{
    int seek = 0;
    for (int i = 0; i < values.size(); i++)
    {
        seek += abs(values[i] - head);
        head = values[i];
    }
    return seek;
}

int fcfs(vector<int> &values, int head)
{
    int seek = 0;
    for (int i = 0; i < values.size(); i++)
    {
        seek += abs(values[i] - head);
        head = values[i];
    }
    return seek;
}

int main()
{
    vector<int> values = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    cout << "Seek Time by fcfs is : " << fcfs(values, head);
}