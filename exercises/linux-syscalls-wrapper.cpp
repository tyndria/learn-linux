#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

 char* getTokens(char *c) {
    char *argv[64] = {};
    int i = 0;
    
    char* token = strtok(c, " ");
  
    while( token != NULL ) {
        argv[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
   argv[i] = NULL;
   return *argv;
}

int main(int argc, char* arg_v[], char* env_p[])
{
    int* status;
    pid_t my_pid;
    while (true) {
        char command[100] = {};
        cout << "Please enter a syscall \n";
        cin >> command;
        char *argv[64] = {};
        *argv = getTokens(command);
        if (strcmp(argv[0], "exit") == 0) {
            break;
        }
        if (0 == (my_pid = fork())) {
            cout << "exec: "<< argv[0] << endl;
            if (-1 == execve(argv[0], &argv[0], NULL)) {
                perror("child process execve failed [%m]");
            } 
            exit(0);
        } else {
            cout <<"wait" << endl;
            while (wait(status) == 0) {
                sleep(1);
            }
            cout <<"done wait" <<endl;
        }
    }
    return 0;
}

