#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 512

int main(int argc, char **argv)
{
  pid_t pid;
  int a[2], b[2], readbytes;
  char buffer[SIZE];

  pipe(a);
  pipe(b);

  if((pid = fork()) == 0)
    {
      close(a[1]);//cierra el modo escritura del pipe
      close(b[0]);//cierra el modo lectura del pipe

      while((readbytes=read(a[0], buffer, SIZE)) > 0 )
	write(1,buffer,readbytes);
      close(a[0]);

      strcpy(buffer, "Soy tu hijo hablandote por la otra tuberia.\n");
      write(b[1], buffer, strlen(buffer));
      close(b[1]);
    }
  else
    {
      close(a[0]);
      close(b[1]);
      strcpy(buffer, "Soy tu padre hablandote por una tuberia.\n");
      write(a[1], buffer, strlen(buffer));
      close(a[1]);

      while((readbytes = read(b[0], buffer, SIZE)) > 0)
	write(1,buffer,readbytes);
      close(b[0]);
    }
  waitpid(pid, NULL, 0);
  exit(0);
}
