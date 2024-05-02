#include <bits\stdc++.h>
using namespace std;
int disk_size = 200;
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

int scan(vector<int> &values, int head)
{
    sort(values.begin(), values.end());
    int i = 0;
    for (i = 0; i < values.size(); i++)
    {
        if (values[i] > head)
            break;
    }
    vector<int> newvalues;
    newvalues.push_back(head);
    for (int j = i; j < values.size(); j++)
    {
        newvalues.push_back(values[j]);
    }
    newvalues.push_back(disk_size);

    for (int j = i - 1; j >= 0; j--)
    {
        newvalues.push_back(values[j]);
    }
    int seek = 0;
    for (i = 0; i < newvalues.size(); i++)
    {
        seek += abs(newvalues[i] - head);
        head = newvalues[i];
    }
    return seek;
}
int cscan(vector<int> &values, int head)
{
    sort(values.begin(), values.end());
    int i = 0;
    for (i = 0; i < values.size(); i++)
    {
        if (values[i] > head)
            break;
    }
    vector<int> newvalues;
    newvalues.push_back(head);
    for (int j = i; j < values.size(); j++)
    {
        newvalues.push_back(values[j]);
    }
    newvalues.push_back(disk_size);
    newvalues.push_back(0);

    for (int j = 0; j < i; j++)
    {
        newvalues.push_back(values[j]);
    }
    int seek = 0;
    for (i = 0; i < newvalues.size(); i++)
    {
        seek += abs(newvalues[i] - head);
        head = newvalues[i];
    }
    return seek;
}

int main()
{
    vector<int> values = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;
    cout << "Seek Time by fcfs is : " << fcfs(values, head) << endl;
    cout << "Seek Time by Scan is : " << scan(values, head) << endl;
    cout << "Seek Time by CScan is : " << cscan(values, head);
}