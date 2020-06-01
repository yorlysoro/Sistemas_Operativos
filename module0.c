#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>



int main(int argc, char *argv[])
{
	int i;
	char linea[80];
	printf("Hello from task:%d\n", argc);
	for(i=0;i<argc;i++)
		{
			printf("argv[%d] = %s\n", i, argv[i]);
		}
	strcpy(linea, "");

	strcat(linea, "hello");
	strcat(linea, " Wordl\n");
	puts(linea);

	sprintf(linea ,"Argc is:%d, Argv is at 0x%x\n", argc, &argv);

	puts(linea);
	printf("Bye from task PID = %d\n", getpid());
}
