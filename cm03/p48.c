#include <stdio.h> // printf
#include <unistd.h> // fork(), pid_t

int global = 1;
int main(int argc, char *argv[]) {
	int i = 1;
	if (fork() == 0) {
		global++;
		i++;
	} else {
		global --;
		i--;
	}
	printf("PID=%d, global=%d, i=%d\n", getpid(), global, i);
	return 0;
}
