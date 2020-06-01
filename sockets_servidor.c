#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int mi_socket, nuevo, tam;
  struct sockaddr_in mi_estructura;

  mi_estructura.sin_family = AF_INET;
  mi_estructura.sin_port = 0;
  mi_estructura.sin_addr = INADDR_ANY;
  memset(&(mi_estructura.sin_zero), '\0', 8);

  mi_socket = socket(AF_INET, SOCK_STREAM, 0);

  tam = sizeof(struct sockaddr);

  bind(mi_socket,(struct sockaddr *)&mi_estructura, tam);

  listen(mi_socket,5);

  while(1)
    {
      nuevo = accept(mi_socket, (struct sockaddr *)&mi_estructura, &tam);

      if(fork() == 0)
	{
	  close (mi_socket);
	  send(nuevo, "200 Bienvenido\n", 15,0);
	  close(nuevo);
	  exit(0);
	}
      else
	{
	  close(nuevo);
	}
    }
  return 0;
}
