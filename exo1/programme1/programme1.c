#include <stdio.h> // printf
#include <unistd.h> // fork()

// Programme 1
int main(int argc, char *argv[]) {
	int p1, p2, p3;
	p1 = fork();
	p2 = getpid();
	p3 = getppid();
	printf("p1=%d - p2=%d - p3=%d\n", p1, p2, p3);
	return 0;
}
