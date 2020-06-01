#include <stdio.h>
//Programa de prueba para fork()
int main(int argc, char *argv[])
{
	int i;
	printf("I AM SAM\n");

	for(i = 0; i < argc; i++)
		{
			printf("Argv[%d] is %s\n", i, argv[i]);
		}
	printf("Bye\n");
}
