#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void rutina(void);

void * thread1(void * arg);

int main(int argc, char *argv[])
{
  pthread_t t;
  pthread_attr_t attr;
	printf("Hello from program\n");
	//rutina();
	//thread1(0);//invoca la rutina
	pthread_create(&t, 0,
		       thread1, 0);//ejecuta la rutina en un hilo
	rutina();
	
	printf("Bye from programa\n");
}

void rutina(void)
{
	int i;
	printf("Entering rutina\n");

	for(i= 0;i < 10;i++)
	{
		printf("%d ", i);
	
	fflush(stdout);
	sleep(1);
	}
}


void * thread1(void * arg)
{
  char i;
  printf("Thread crated\n");
  printf("Thread finished\n");
  for(i = 'a'; i <= 'z'; i++)
    {
      printf("%c ", i);
      fflush(stdout);
      sleep(2);
    }
}
