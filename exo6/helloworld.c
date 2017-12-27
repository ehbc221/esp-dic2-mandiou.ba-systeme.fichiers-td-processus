#include <stdio.h> // printf
#include <stdlib.h> // exit, rand

int main(int argc, char const *argv[], char *argve[])
{
	int i;

	printf("******************************\nHello World!!!\n");

	printf("Les arguments :\n");
	for (int i = 0; i < argc; i++) {
		printf("%d : %s\n", i, argv[i]);
	}

	printf("\nLes variables d'environnement :\n");
	i = 0;
	while(argve[i] != NULL) {
		printf("%d : %s\n", i, argve[i]);
		i++;
	}
	if (i == 0) {
		printf("Aucune variable d'environnement\n");
	}

	printf("******************************\n");

	return EXIT_SUCCESS;
}
