#include <stdio.h> // printf
#include <unistd.h> // fork(), pid_t
#include <stdlib.h> // exit, rand
#include <sys/wait.h> // wait

int nombre_fils = 10, min = 10000, max = 5000;
int main ( int argc, char *argv[] )
{
	pid_t child_pid, wpid;
	int status = 0, compteur = 0, n;
	// Crétation des processus fils
	for (int i = 0; i < nombre_fils; i++) {
		n = (rand() % (max - min) + min);
		child_pid = fork();
		if (child_pid == 0) {
			for (int j = 0; j < n; j++) {
				compteur++;
			}
			exit(EXIT_SUCCESS);
		}
	}
	// Attente de la fin de tous les processus fils + affichage par ordre de terminaison
	while((wpid = wait(&status)) > 0) {
		printf("Fin du Fils %d\n", wpid);
	}
}
