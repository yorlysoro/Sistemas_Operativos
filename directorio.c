#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
  char buffer[512];

  printf("Este es el directorio actual %s\n", getcwd(buffer,-1));

  //chdir("..");
  mkdir("./directori2", 0755);
  mkdir("./otrodir", 0755);
  rmdir("./directori2");
  
  return 0;
}
