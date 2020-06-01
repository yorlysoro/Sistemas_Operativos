#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  pid_t pid;

  int sig;

  if(argc==3)
    {
      pid=(pid_t)atoi(argv[1]);
      sig=atoi(argv[2]);
      kill(pid,sig);
    }
  else
    {
      printf("%s: %s pid signal\n", argv[0], argv[0]);
      return -1;
    }
  return 0;
}
