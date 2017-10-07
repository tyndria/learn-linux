#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
    cout << "pid: " << getpid() << endl;
    cout << "fork pid: " << fork() << endl;
    int* status;
    cout << "wait pid: " <<  wait(status) << endl;
   
    return 0;
}
