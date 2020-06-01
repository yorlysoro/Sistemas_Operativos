#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void trapper(int);

int main(int argc, char *argv[])
{
  int i;

  signal(14,trapper);

  printf("Identificativo de proceso:%d\n", getpid());
  alarm(5);
  pause();
  alarm(3);
  pause();
  for(;;)
    {
      alarm(1);
      pause();
    }
  return 0;
}

void trapper(int sig)
{
  signal(sig,trapper);
  printf("RIIIING!\n");
}
