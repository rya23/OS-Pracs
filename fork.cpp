#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int wait_func()
{
    int pid_1 = fork();
    if (pid_1 == 0)
    {
        cout << "process pid_1 succesfully created"
             << "\n";
        cout << "process pid_1 id: " << getpid() << "\n";
        exit(0);
    }
    waitpid(pid_1, NULL, 0);
    cout << "pid_1 process terminated."
         << "\n";
    return 0;
}
int main()
{
    int pid = fork();
    if (pid == 0)
    {
        cout << "child process created"
             << "\n";
        cout << "current child is: " << getppid() << "\n";
        cout << "current parents is: " << getpid() << "\n";
        exit(0);
    }
    wait(NULL);
    cout << "child process is terminated."
         << "\n";
    wait_func();
    return 0;
}