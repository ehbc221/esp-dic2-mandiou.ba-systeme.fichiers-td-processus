#include <stdio.h> // printf
#include <unistd.h> // fork(), pid_t
#include <stdlib.h> // exit
#include <sys/wait.h> // wait

int main ( int argc, char *argv[] )
{
	int i, pid;
	if (argc != 2) {
		printf("Nombre de paramètres incorrects (2 parametres requis).\n");
	} else {
		int N = atoi(argv[1]);
		for(i = 0; i < N; i++) {
			pid = fork();
			if(pid < 0) {
				printf("Error");
				exit(1);
			} else if (pid == 0) {
				printf("Fils numero %d: pid=%d\n", i + 1, getpid());
				exit(0); 
			} else {
				wait(NULL);
			}
		}
	}
}
