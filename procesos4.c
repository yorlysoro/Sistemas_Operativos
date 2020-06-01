#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  char *args[] = { "/bin/ls", NULL};

  execv("/bin/ls", args);

  printf("Se ha producido un error al ejecutar execv()\n");

  return 0;
}
