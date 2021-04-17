#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MARCOS 8;
#define PAGINAS 16;

typedef struct tabla{
    int indice;
    int referencia;
    int estado;
    // int m;
    // int r;
    struct tabla *sig;
}tabla;


int pgs; //indica el total de paginas en marcos
void bitsPagina(int indiceP){
    int bits=3;
    while(bits >= 0){
        if(indiceP & (((long int)1) << bits))
            printf("1");
        else 
            printf("0");
        bits--;
    }
}
void bitsMarco(int indiceM){
    int bits=2;
    while(bits >= 0){
        if(indiceM & (((long int)1) << bits))
            printf("1");
        else 
            printf("0");
        bits--;
    }
}
void desplazamiento(int n){
    int bits = 12;
    while(bits >= 0){
        if(n & (((long int)1) << bits))
            printf("1");
        else 
            printf("0");
        bits--;
    }
}
void printDesp(int indiceP, int indiceM){
    int i;

    for(i=0;i<4096;i++){
        bitsPagina(indiceP);
        printf("\t");
        desplazamiento(i);
        printf("\t ------ \t");
        bitsMarco(indiceM);
        printf("\t");
        desplazamiento(i);
        printf("\n");
    }
}
tabla *iniTabla(){
    return NULL;
}

tabla *crearPag(int i){
    tabla *aux = (tabla*) malloc(sizeof(tabla)); //reservo memoria para la pagina
    aux->indice = i; //se asigna el indice de las paginas en memoria virtual
    aux->estado = 1; //esta en la tabla de paginas
    aux->referencia = 5; //de inicio no esta en ningun marco de pagina
    aux->sig = NULL; 
    return aux;
}
tabla *agregarPag(tabla *tblPaginas, tabla *nuevaPag){
    if(tblPaginas == NULL){
        tblPaginas = nuevaPag;
    }else{
        nuevaPag->sig = tblPaginas;
        tblPaginas = nuevaPag;
    }
    return tblPaginas;
}
void mostrarT(tabla *tblPaginas){
    tabla *aux = tblPaginas; //usamos aux para recorrer la tabla e imprimirla
    while(aux!=NULL){
        printf("\t\tindice: %d\t\tEstado: %d\t\tMarco referenciado: %d\n", aux->indice, aux->estado, aux->referencia);
        aux=aux->sig;
    }
}
void mostrarTM(tabla *tblPaginas){
    tabla *aux = tblPaginas; //usamos aux para recorrer la tabla e imprimirla
    while(aux!=NULL){
        printf("\t\tindice: %d\t\tPagina referenciada: %d\n", aux->indice, aux->referencia);
        aux=aux->sig;
    }
}
tabla *insertP(int dire){
    if(pgs < 8){
        tabla *aux = (tabla*) malloc(sizeof(tabla)); //reservo memoria para la pagina
        aux->indice = pgs;
        aux->estado = 1;
        aux->referencia = dire;
        aux->sig == NULL;
        pgs++;
        return aux;

    }else{
        printf("Memoria fisica llena, se hara un remplazo de marco de pagina\n");
    }
    
}

tabla *busca(tabla *tblPaginas, int marco, int indi){
    tabla *aux, *ant;
    if(tblPaginas != NULL &&  (marco == tblPaginas->indice)){
       // printf("indi %d marco%d\n",tblPaginas->indice, marco);
        aux = tblPaginas;
        aux->referencia = indi;
        tblPaginas = aux;
        printDesp(tblPaginas->indice, indi);
    }else{
        aux = tblPaginas;
        while((aux != NULL) && (marco != aux->indice)){
            ant =aux;
            aux = aux->sig;
           // printf("indi %d marco%d\n",aux->indice, marco);
        }
        if(aux!=NULL){
            aux->referencia = indi;
            aux->estado = 0;
            printDesp(aux->indice, indi);
        }

        return tblPaginas; 
    }

    
}
tabla *agregarMarco(tabla *tblMarcos, tabla *nuevoMarco){
    if(tblMarcos == NULL)
        tblMarcos = nuevoMarco;
    else{
        nuevoMarco->sig = tblMarcos;
        tblMarcos = nuevoMarco;
    }
    return tblMarcos;
}
int verifica(tabla *tblPaginas, int dire){
    tabla *aux, *ant;
    if(tblPaginas != NULL && (dire == tblPaginas->indice)){
        if(tblPaginas->estado == 1)
            return 1;
        else
            return 0;
    }else{
        while((tblPaginas != NULL) && (dire != tblPaginas->indice)){
            tblPaginas = tblPaginas->sig;
        }
        if(tblPaginas != NULL){
            if(tblPaginas->estado==1)
                return 1;
            else
                return 0;
        }
    }
}

int main(){
    int opc, i, dire, esta;
    tabla *tblPaginas = iniTabla();
    tabla *tblMarcos = iniTabla();

    for(i=0;i<16;i++){
        tabla *nuevaPag = crearPag(i);
        tblPaginas = agregarPag(tblPaginas, nuevaPag);
    }
    //tblPaginas=tblPaginas->sig;
    //printf("1aver %d\n", tblPaginas->indice);
    
    while(opc >= 0){
        printf("Operaciones con la memoria:\n");
        printf("1. Ver tablas\n");
        printf("2. Mover pagina a memoria fisica\n");
        printf("3. Salir\n");
        scanf("%d",&opc);
        if(opc > 4)
            printf("Opcion no valida\n");

        switch (opc)
        {
        case 1:
            system("clear");
            printf("\t\tTabla de paginas\n\n");
            mostrarT(tblPaginas);
            printf("\n\t\tTabla de Marcos de pagina\n\n");
            mostrarTM(tblMarcos);
            break;
        
        case 2:
            system("clear");
            printf("Ingrese la pagina a mover a RAM 0-15\n");
            scanf("%d", &dire);
            if(dire>15){
                printf("Solo hay 16 paginas en memoria virtual\n");
                break;
            }
                
            else{
                esta = verifica(tblPaginas, dire); //verifica si la pagina esta en la tabla de paginas
                if(esta == 1){
                    tabla *nuevoMarco = insertP(dire);
                    tblMarcos = agregarMarco(tblMarcos, nuevoMarco);
                    tblPaginas = busca(tblPaginas, tblMarcos->referencia, tblMarcos->indice);
                    break;
                }else{
                    printf("Ya se ha movido esta pagina\n");
                    break;
                }
                
            }

        case 3:
            return 0;
        }
    }

    return 0;
}
