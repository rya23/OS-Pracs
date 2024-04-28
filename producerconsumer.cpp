#include <bits\stdc++.h>
using namespace std;
int filledSpace = 0;
int remainingSpace = 10;
int itemsproduced = 0;
int mutex = 1;
void producer()
{
    mutex--;
    filledSpace++;
    remainingSpace--;
    itemsproduced++;
    cout << "Producer produced Item No. " << itemsproduced << endl;
    mutex++;
}

void consumer()
{
    mutex--;
    filledSpace--;
    remainingSpace++;
    cout << "Consumer consumed Item No. " << itemsproduced << endl;
    itemsproduced--;
    mutex++;
}

int main()
{
    int n;
    while (1)
    {
        cout << "1. Producer 2.Consumer 3.Exit :  ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            if (remainingSpace != 0 && mutex == 1)
                producer();
            else
                cout << "Buffer is Full" << endl;
            break;
        }

        case 2:
        {
            if (filledSpace != 0 && mutex == 1)
                consumer();
            else
                cout << "Buffer is empty" << endl;

            break;
        }
        case 3:
        {
            cout << "Exiting";
            exit(0);
            break;
        }
        default:
        {
            cout << "Invalid Input" << endl;
            break;
        }
        }
    }
}