#include <stdio.h> // printf
#include <unistd.h> // fork(), pid_t
#include <stdlib.h> // exit()
#include <sys/wait.h> // wait
#include <sys/types.h> // types

void fils() {
	printf("Je suis dans le fils\n");
	exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1) {
		perror("Erreur lors de la creation du processus fils ");
		exit(EXIT_FAILURE);
	} else if (pid == 0) {
		fils();
	} else {
		printf("Je suis dans le pere et j'attends la fin du fils\n");
		if (waitpid(pid, &status, 0) == -1) {
			perror("Erreur lors de l'attente du fils ");
			exit(EXIT_FAILURE);
		} else {
			if (WIFEXITED(status)) {
				printf("Le fils a termine; valeur retournee = %d\n", WEXITSTATUS(status));
			} else {
				printf("Le fils a termine anormalement\n");
			}
		}
		return EXIT_SUCCESS;
	}
}
