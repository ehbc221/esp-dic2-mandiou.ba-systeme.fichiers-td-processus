#include <stdio.h> // printf
#include <unistd.h> // fork(), pid_t

int main(int argc, char *argv[]) {
	/* Avant */
	pid_t pid;
	pid = fork();
	if (pid > 0) {
		/* Exécuté par le processus père */
		printf("Execute par le processus pere\n");
	} else if (pid == 0) {
		/* Exécuté par le processus fils */
		printf("Execute par le processus fils\n");
	} else {
		/* Traitement d'erreur */
		printf("Traitement d'erreur\n");
	}
	/* Suite du code */
	printf("Suite du code\n");
}
