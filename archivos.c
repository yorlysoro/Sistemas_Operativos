#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/sysmacros.h>
#include <time.h>
#define STDOUT 1
#define SIZE 512
/*
struct stat{
  dev_t st_dev;//Dispositivo
  ino_t st_ino; //numero de inode
  mode_t st_mode; //modo del fichero
  nlink_t st_nlink; //numero de hard links
  uid_t st_uid; //uid del propietario
  gid_t st_gid; //gid del propietario
  dev_t st_rdev; //tipo del dispositivo
  off_t st_size; //tamaño total en bytes
  blksize_t st_blksize; //tamaño de bloque opreferido
  blkcnt_t st_blocks; //numero de bloques asignados
  time_t st_atime; //ultima hora de acceso
  time_t stmtime; //ultima hora de modificacion
  time_t st_ctime; //ultima hora de cambio en inodo
  };*/

int main(int argc, char *argv[])
{
  struct stat estructura;

  //  int fd, readbytes;
  // char buffer[SIZE];
  // if((fd = open(argv[1], O_RDWR)) == -1)
  if((lstat(argv[1], &estructura)) < 0)
  {
      perror("lstat");
      exit(-1);
    }
  /*lseek(fd,2,SEEK_SET);
  while((readbytes = read(fd,buffer,SIZE))!= 0)
    {
      //write(STDOUT,buffer,SIZE);
      write(STDOUT,buffer,readbytes);

      }*/

  printf("Propiedades del fichero <%s>\n", argv[1]);
  printf("i-inodo:%d\n", estructura.st_ino);
  printf( "dispositivo: %d, %d\n", major( estructura.st_dev ),minor( estructura.st_dev ) );
  printf( "modo: %#o\n", estructura.st_mode );
  printf( "vinculos: %d\n", estructura.st_nlink );
  printf( "propietario: %d\n", estructura.st_uid );
  printf( "grupo: %d\n", estructura.st_gid );
  printf( "tipo del dispositivo: %d\n", estructura.st_rdev );
  printf( "tamaño total en bytes: %ld\n", estructura.st_size );
  printf( "tamaño de bloque preferido: %d\n",estructura.st_blksize );
  printf( "numero de bloques asignados: %d\n",estructura.st_blocks );
  printf( "ultima hora de acceso: %s", ctime( &estructura.st_atime ) );
  printf( "ultima hora de modificación: %s",ctime( &estructura.st_mtime ) );
  printf( "ultima hora de cambio en inodo: %s", ctime( &estructura.st_ctime));

  //printf("El fichero abierto tiene es descriptor %d\n",fd);
  //close(fd);
  return 0;

}
