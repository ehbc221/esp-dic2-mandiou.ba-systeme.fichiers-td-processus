#include <stdio.h> // printf
#include <unistd.h> // fork()
#include <stdlib.h> // exit()

// Programme 2
#define N 10
int main(int argc, char *argv[]) {
	int i = 1;
	while(fork() == 0 && i <= N) {
		i++;
		printf("DANS WHILE i=%d - pid=%d - ppid=%d\n", i, getpid(), getppid());
	}
	printf("i=%d - pid=%d - ppid=%d\n", i, getpid(), getppid());
	exit(0);
}
