#include <stdio.h> // printf
#include <unistd.h> // fork(), pid_t

// Programme 4
int main(int argc, char *argv[]) {
	pid_t valeur, valeur1;
	printf("Affichage 1 ---> Processus pere [%d] : mon pere a moi est [%d]\n", getpid(), getppid());
	valeur = fork();
	printf("Affichage 2 ---> retour fork [%d] - Processus fils [%d] : mon pere est [%d]\n", valeur, getpid(), getppid());
	valeur1 = fork();
	printf("Affichage 3 ---> retour fork [%d] - Processus fils [%d] : mon pere est [%d]\n", valeur, getpid(), getppid());
	return 0;
}
