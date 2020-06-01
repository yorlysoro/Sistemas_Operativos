#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
/*struct dirent {
  ino_t d_ino; // numero de i-node de la entrada de directorio
  off_t d_off; // offset
  wchar_t d_reclen; // longitud de este registro
  char d_name[MAX_LONG_NAME+1] // nombre de esta entrada
  }*/
int main(int argc, char *argv[])
{
  DIR *dir;
  struct dirent *mi_dirent;


  if(argc != 2)
    {
      printf("%s:%s directorio\n", argv[0], argv[0]);
      exit(-1);
    }
  if((dir = opendir(argv[1])) == NULL)
  {
    perror("opendir");
    exit(-1);
  }
  while((mi_dirent = readdir(dir)) != NULL)
	printf("%s\n", mi_dirent->d_name);

  close(dir);
	return 0;
	
}
