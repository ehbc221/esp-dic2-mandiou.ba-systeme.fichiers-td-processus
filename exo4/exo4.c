#include <stdio.h> // printf
#include <stdlib.h> // exit(), atexit()

void procedure1() {
	printf("Je suis la procedure 1\n");
}

void procedure2() {
	printf("Je suis la procedure 2\n");
}

void procedure3() {
	printf("Je suis la procedure 3\n");
}

void procedure4() {
	printf("Je suis la procedure 4\n");
}

void procedure5() {
	printf("Je suis la procedure 5\n");
}

int main(int argc, char *argv[]) {
	if(atexit(procedure1) != 0 || atexit(procedure2) != 0 || atexit(procedure3) != 0 || atexit(procedure4) != 0 || atexit(procedure5) != 0) {
		perror("Probleme lors de l'enregistrement ");
		exit(EXIT_FAILURE);
	}

	printf("Le programme principal se termine:\n");

	return EXIT_SUCCESS;
}
