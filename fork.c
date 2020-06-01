#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	printf("hola desde el programa %d\n", getpid());

	printf("Esto es fork...\n");
	pid = fork(); //fork hace una copia del proceso

	if(pid == 0)
		{
			printf("NOOOOO\n");
		}
	else
		{
			printf("I AM YOUR FATHER\n");
			execl("/bin/ls", "/bin/ls","-l", (char *)0);
		}
	//printf("Pid is %d\n", pid);
	printf("Bye from program %d\n", getpid());


}
