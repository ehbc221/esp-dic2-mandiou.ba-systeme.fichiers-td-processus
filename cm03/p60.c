#include <stdio.h> // printf
#include <stdlib.h> // exit(), atexit()

void methode1() {
	printf("Je suis la methode 1\n");
}

void methode2() {
	printf("Je suis la methode 2\n");
}

int main(int argc, char *argv[]) {
	if(atexit(methode1) != 0) {
		perror("Probleme lors de l'enregistrement ");
		exit(EXIT_FAILURE);
	}

	if(atexit(methode2) != 0) {
		perror("Probleme lors de l'enregistrement ");
		exit(EXIT_FAILURE);
	}

	printf("Ok c'est termine\n");

	return EXIT_SUCCESS;
}
