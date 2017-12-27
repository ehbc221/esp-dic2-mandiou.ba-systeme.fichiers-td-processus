#include <stdio.h> // printf
#include <unistd.h> // fork()

// Programme 3
int main(int argc, char *argv[]) {
	int pid[3], i;
	for (int i = 0; i < 3; ++i) {
		pid[i] = fork();
	}
	printf("%d %d %d\n", pid[0], pid[1], pid[2]);
	return 0;
}
