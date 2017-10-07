#include <iostream>
#include <sys/time.h>

using namespace std;

int main() {
    timeval a;
    
    gettimeofday(&a, NULL);
    
    cout << a.tv_sec;

    return 0;
}

