
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char* arg_v[], char* env_p[]) {
  sleep(5);
  cout << "stop sleep" << endl;
  
  cout << execve("bin/cat", arg_v, env_p) << endl;
  return 0;
}
