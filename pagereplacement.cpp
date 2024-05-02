#include <bits\stdc++.h>
using namespace std;

int fifo(vector<int> &pages, int capacity)
{
    int n = pages.size();

    set<int> s;
    queue<int> index;

    int pagefaults = 0;
    for (int i = 0; i < n; i++)
    {

        if (s.size() < capacity)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                pagefaults++;
                index.push(pages[i]);
            }
        }

        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int value = index.front();
                index.pop();
                s.erase(value);
                s.insert(pages[i]);
                index.push(pages[i]);
                pagefaults++;
            }
        }

        for (auto it : s)
        {
            cout << it << "\t";
        }
        cout << endl;
    }
    return pagefaults;
}

int lru(vector<int> &pages, int capacity)
{
    vector<int> v;
    int pagefaults = 0;

    for (int i = 0; i < pages.size(); i++)
    {
        auto it = std::find(v.begin(), v.end(), pages[i]);
        if (it == v.end())
        {
            if (v.size() == capacity)
            {
                v.erase(v.begin());
            }
            v.push_back(pages[i]);
            pagefaults++;
        }
        else
        {
            v.erase(it);
            v.push_back(pages[i]);
        }
        for (auto it : v)
        {
            cout << it << "\t";
        }
        cout << endl;
    }

    return pagefaults;
}

int main()
{
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

    // vector<int> pages = {1, 2, 1, 4, 2, 3, 5};
    int capacity = 4;

    // int pagefault = fifo(pages, capacity);
    int pagefault = lru(pages, capacity);

    cout << "Page Fault is : " << pagefault << endl;
}
