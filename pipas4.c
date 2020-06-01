#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

#define SIZE PIPE_BUF

int main(int argc, char *argv[])
{
  FILE *file;
  char *command= "ls .";

  char buffer[SIZE];

  file = popen(command, "r");

  while(!feof(file))
    {
      fscanf(file, "%s", &buffer);
      printf("%s\n", buffer);
    }
  pclose(file);
  return 0;
}
