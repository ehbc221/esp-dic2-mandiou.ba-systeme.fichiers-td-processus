#include <stdio.h> // printf
#include <unistd.h> // fork(), pid_t
#include <stdlib.h> // exit, rand
#include <sys/wait.h> // wait

int main ( int argc, char *argv[] )
{
	pid_t pid, wpid;
	int n = (rand() % 10 + 1), status = 0;
	if ((pid = fork()) == 0) {
		sleep(n);
		exit(EXIT_SUCCESS);
	}
	if((wpid = wait(&status)) > 0) {
		printf("Fin du Fils %d\n", wpid);
	}
	else {
		printf("Erreur lors de l'execution du fils\n");
		exit(EXIT_FAILURE);
	}
}
