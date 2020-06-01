#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

#define COMMAND1 "/bin/cat"
#define COMMAND2 "/usr/bin/wc"

int main(int argc, char **argv)
{
  pid_t pid;
  int p[2];

  pipe(p);

  if((pid = fork()) == 0)
    {
      close(p[0]);
      dup2(p[1],1); //stdout = extremo de la salida del pipe
      close(p[1]);

      execlp(COMMAND1, COMMAND1, argv[1], NULL);
      perror("error");
       exit(1);
    }
  else
    {
      close(p[1]);
      dup2(p[0],0);//stdin = extremo de entrada del pipe
      close(p[0]);

      execlp(COMMAND2, COMMAND2, NULL);

      perror("Error");
      exit(1);
    }
  return 0;
}
      
      
