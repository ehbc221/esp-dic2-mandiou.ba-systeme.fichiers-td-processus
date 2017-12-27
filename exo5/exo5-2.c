#include <stdio.h> // printf
#include <unistd.h> // fork(), pid_t
#include <stdlib.h> // exit, rand
#include <sys/wait.h> // wait

int nombre_fils = 5, min = 7, max = 2;
int main ( int argc, char *argv[] )
{
	pid_t child_pid, wpid, pid[nombre_fils];
	int status = 0, compteur = 0, n;
	// Crétation des processus fils
	for (int i = 0; i < nombre_fils; i++) {
		n = (rand() % (max - min) + min);
		child_pid = fork();
		if (child_pid == 0) {
			sleep(n);
			exit(EXIT_SUCCESS);
		}
		else {
			pid[i] = child_pid;
		}
	}
	// Attente de la fin de tous les processus fils + affichage par ordre de création
	for (int i = 0; i < nombre_fils; i++) {
		if ((wpid = waitpid(pid[i], &status, 0)) > 0) {
			printf("Fin du Fils %d\n", wpid);
		}
		else {
			printf("Erreur lors de l'attente du fils numero %i\n", i);
			exit(EXIT_FAILURE);
		}
	}
}
