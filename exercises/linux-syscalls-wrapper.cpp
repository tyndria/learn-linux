#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main(int argc, char* arg_v[], char* env_p[]) {
    int* status;
    pid_t my_pid;
    while (true) {
        string command;
        char* command_char;
        cout << "Please enter a syscall \n";
        getline(cin, command);
        command_char = strcpy((char*)malloc(command.length()+1), command.c_str());
        char *argv[64] = {};
        int i = 0;
        
        char* token = strtok(command_char, " ");
      
        while( token != NULL ) {
            argv[i] = token;
            i++;
            token = strtok(NULL, " ");
        }
        argv[i] = NULL;
         
    
        if (strcmp(argv[0], "exit") == 0) {
            break;
        }
        if (0 == (my_pid = fork())) {
            cout << "exec: "<< argv[0] << endl;
            if (-1 == execve(argv[0], &argv[0], NULL)) {
                perror("child process execve failed [%m]");
                exit(0);
            } 
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
