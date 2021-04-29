#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>	
#include <wait.h>
#include <unistd.h>
#define procesos 10

void main()
{
	int x,salida,p;
	int pid;
	
	for(x=0;x<procesos;x++)
	{ 	
		pid= fork();
		if(pid==-1)
		{
			perror("\nError al crear el proceso\n");
			exit(-1);
		}
		if(pid==0)
		{
			printf("\n%d.Hola soy el proceso con pid %d y mi padre es %d\n",x+1,getpid(),getppid());
			exit(0);
		}
	}
	sleep(2);
		for(p=0;p<procesos;p++)
		{
			pid=wait(&salida);
			printf("\nProceso %d terminado\n",pid);
			sleep(1);	
		}
					
	printf("\nEl proceso padre con PID: %d ha terminado\n", getpid());	
	
}
