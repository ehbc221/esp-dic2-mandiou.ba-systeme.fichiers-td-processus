#include <stdio.h> // printf
#include <unistd.h> // fork(), pid_t
#include <stdlib.h> // exit, rand
#include <sys/wait.h> // wait

void execution(char *argve[]);

int main(int argc, char const *argv[], char *argve[])
{
	pid_t pid;

	if ((pid = fork()) == -1) {
		perror("Erreur lors de la creation du fils");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) {
		execution(argve);
	}
	if (waitpid(pid, NULL, 0) == -1) {
		perror("Erreur lors de l'attente de la fin du processus");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

void execution(char *argve[]) {
	char *arguments[6] = {"./helloworld", "Bonjour", "tout", "le", "monde", NULL};

	printf("Je demarre le programme...\n");
	if (execve(arguments[0], arguments, argve) == -1) {
		perror("Erreur lorss du chargement");
		exit(EXIT_FAILURE);
	} else {
		exit(EXIT_SUCCESS);
	}
}
