#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //permite utilizar la llamada al sistema fork()
#include <wait.h> //define las declaraciones de espera
#include <sys/types.h> //tipos de datos, permite usar pid_t

/*
Programa32.c Realice un programa que cree un proceso hijo a partir de un proceso padre, 
el hijo creado a su vez creará tres procesos hijos más. A su vez cada uno de los tres
procesos creará dos procesos más. Cada uno de los procesos creados 
imprimirá en pantalla el PID de su padre y su propio PID.
*/

void codigoProceso(int id); //constructor de la función

void codigoProceso(int id)   /*Esta función imprimira el identificador de un proceso hijo
                                    y el identificador de su padre cada vez que sea creado*/
{

        printf("\nHola soy un proceso hijo\n");
        printf("Mi identificador es: %d\n", getpid()); //imprime el PID del proceso hijo
        printf("Mi proceso padre es: %d\n", getppid()); //imprime el PID del proceso padre
        exit(id); //Termina el proceso hijo
        
}

int main()
{
    int id[3]={1,2,3}, i;
    pid_t pid1, pid2, pid3; //pid_t es una redefinición de un entero, estas variables son para hacer la llamada a fork()
    int status;

    pid1 = fork(); //creamos el primer proceso

    if (pid1 == -1)
    {
        perror("\nError al crear el proceso\n"); //Verifica si se puede crear el proceso
        exit(-1);
    }
    else if(pid1==0) //este es el hijo del primer proceso
    {
       
        for ( i = 0; i < 3; i++)//aquí hacemos un for para crear 3 hijos del hijo previamente creado
        {
            pid2=fork(); //por cada iteración se crea un proceso
            if (pid2==-1)
            {
                perror("Error al crear el proceso");//Verifica si se puede crear el proceso
                exit(-1);
            }
            else if(pid2==0) //empieza el codigo de los hijos del primer hijo (nietos)
            {
                for ( i = 0; i < 2; i++) //de los 3 hijos del primer hijo se crearan dos hijos más por cada uno
                {
                    pid3=fork(); //por cada iteración se crea un proceso
                    if(pid3==-1)
                    {
                        perror("Error al crear el proceso");//Verifica si se puede crear el proceso
                        exit(-1);
                    }
                    else if(pid3==0) //codigo de los procesos hijos
                    {

                        codigoProceso(id[i]); /*manda a llamar a la función que imprime el
                                                PID del hijo y de su proceso padre*/
                        
                    }
                }

                for ( i = 0; i < 2 ;i++)
                {
                    pid3=wait(&status); //este for es para esperar a que terminen de ejecutarse los procesos hijos
                }
                
                
                codigoProceso(id[i]);/*manda a llamar a la función que imprime el
                                                PID del hijo y de su proceso padre*/
            }//termina el código de los procesos nietos
        }
            for ( i = 0; i < 3; i++)
            {
                pid2=wait(&status);//este for es para esperar a que terminen de ejecutarse los procesos hijos
                                    //para esperar se usa wait()
            }
            
        printf("\nHola soy el proceso abuelo (segundo padre)\n"); //PID del primer hijo y el de su padre
        printf("Mi identificador es: %d\n", getpid());
        printf("Mi proceso padre es: %d\n", getppid());
        
        
        exit(0);
    }//fin proceso abuelo
    
    pid1=wait(&status);
    printf("\nHola soy el proceso bisabuelo (primer padre)\n");//PID del primer proceso padre y de su padre
    printf("Mi identificador es: %d\n", getpid());
    printf("Mi proceso padre es: %d\n", getppid());

    
    return 0;
}
