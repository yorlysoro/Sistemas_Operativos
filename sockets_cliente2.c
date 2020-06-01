#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 255

int main(int argc, int *argv[])
{
  int mi_socket, tam, numbytes;
  char buffer[SIZE];
  struct sockaddr_in mi_estructura;

  if(argc != 3)
    {
      printf("error: modo de empleo: clientudp ip puerto\n");
      exit(-1);
    }

  mi_estructura.sin_family = AF_INET;
  mi_estructura.sin_port = htons(atoi(argv[2]));
  inet_aton(argv[1], &(mi_estructura.sin_addr));
  memset(&(mi_estructura.sin_zero),'\0', 8);

  mi_socket = socket(AF_INET, SOCK_DGRAM, 0);
  tam = sizeof(struct sockaddr);

  strcpy(buffer,"Hola mundo telematico!\n");
  numbytes = sendto(mi_socket, buffer, strlen(buffer),0,(struct sockaddr *)&mi_estructura, tam);
  printf("cliente udp: %d bytes enviados\n", numbytes);
  printf("cliente udp: enviado:%s\n", buffer);

  strcpy(buffer, "Este es otro paquete\n");
  numbytes = sendto(mi_socket, buffer, strlen(buffer),0,(struct sockaddr *)&mi_estructura, tam);
  printf("cliente udp: %d bytes enviados\n", numbytes);
  printf("cliente udp: enviado:%s\n", buffer);

  close(mi_socket);
  return 0;
}
