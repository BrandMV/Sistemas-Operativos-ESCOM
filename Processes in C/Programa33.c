#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> //Libreria necesaria para la llamada al sistema "wait()"
#include <unistd.h>
#include <string.h> //Libreria para el manejo de cadenas

#define Procesos 5 //Se define una variable Procesos con valor de 5

void proceso(int id, char cadena[], FILE* fichero){ //Funcion para crear un nuevo proceso

	fputs(cadena, fichero); //Escribe una cadena en el archivo
	sleep(2); //Duerme al proceso por 2 segundos

	exit(id); //Termina el proceso
}

int main(int argc, char const *argv[]){

	FILE* fichero; //Crea una variable de tipo FILE llamada fichero
	fichero = fopen("practica33.txt", "wt"); //Se declara la variable fichero, con el archivo
                                             //que se quiere editar  

	char cadena1[][9] = {"Hola ", "esta ", "es ", "mi ", "practica "}; 
	//Se declara un arreglo bidimensional de caracteres para la cadena "Hola esta es mi practica"

	int p;
	int id[Procesos] = {0, 1, 2, 3, 4}; //Declaracion de arreglo de id de procesos
	int pid;
	int salida;

	for(p = 0; p < Procesos; p++){ //for que itera del 0 al 4
		pid = fork(); 
		//Llamada al sistema fork() que crea un nuevo proceso y retorna un entero indicando si el este fue creado o no
		if(pid == -1){ //if que verifica si el nuevo proceso no se creo
			perror("Error al crear el proceso"); //Si el proceso no fue creado, regresa el siguiente error
			exit(-1); //Salida del proceso con error
		} else if(pid == 0){ //En otro caso verifica si el prceso fue creado con éxito 
			proceso(id[p], cadena1[p], fichero); //Crea un nuevo proceso
		}
	}

	for(p = 0; p < Procesos; p++){ //for que itera del 0 al 4
		pid = wait(&salida); //Llamada wait() que obliga al proceso padre a esperar a los hijos
		sleep(2); //el proceso se duerme por 2 segundos
	}

	fputs("uno", fichero); //El proceso padre escribe la ultima palabra de la cadena

	fclose(fichero); //Se cierra el archivo

}