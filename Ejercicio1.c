#include <stdio.h>
#include <time.h>
#include <sys\timeb.h>
#define TAM 1000
#define true 1
#define false 0


int main(){
 // Calculate the time taken by take_enter()t
    /*time_t prg_begin, prg_end;
    prg_begin = clock();*/
    struct timeb start, end;
    int diff;
    int i = 0;

    // CREAR TABLA
    int tabla[TAM], tabla1[TAM], tabla2[TAM], tabla3[TAM], tabla4[TAM];
    for(int x = 0; x < TAM; x++){
        int num = rand() % 10000 - 4999; // de -5000 a 5000
        //int num = rand() % 1000;
        tabla[x] = num;
        //printf("%d\t",tabla[x]);
    }

    // BUSCAR ELEMENTO
    int numABuscar;
    printf ("Dame el elemento da buscar: ") ;
    scanf ("%d", &numABuscar ) ;
    //int numABuscar = 31880;
    int index = 0;

    ftime(&start);
    for(int x = 0; x < TAM; x++){
        if(tabla[x]==numABuscar){
            index = x;
            x = TAM; // break
        }
    }
    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
    if(index){
        printf("\n\nIndice %d, tardo %d milisegundos.\n", index, diff);
    } else {
        printf("\n\nNo encontrado, tardo %d milisegundos.\n", diff);
    }



    // DUPLICAR x4 LA TABLA
    memcpy(tabla1, tabla, sizeof tabla);
    memcpy(tabla2, tabla, sizeof tabla);
    memcpy(tabla3, tabla, sizeof tabla);
    memcpy(tabla4, tabla, sizeof tabla);

    // ORDENAR
    int j, indice_menor, salto, aux, cambios;

    // empieza contar
    ftime(&start);
    intercambio(tabla1);
    // ACABA
    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
    printf("\nOrdenado en %d milisegundos.\n", diff);


    // empieza contar
    ftime(&start);
    seleccion(tabla2);
    // ACABA
    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
    printf("\nOrdenado en %d milisegundos.\n", diff);

    // empieza contar
    ftime(&start);
    bubble(tabla3);
    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
    printf("\nOrdenado en %d milisegundos.\n", diff);

    // empieza contar
    ftime(&start);
    shell(tabla4);
    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
    printf("\nOrdenado en %d milisegundos.", diff);

    // BUSCAR POR BÚSQUEDA BINARIA
    printf("\n");
     ftime(&start);
    buscar_binaria(tabla1,numABuscar);
    ftime(&end);
    diff = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
    printf("\nEncontrado BINARIA en %d milisegundos.", diff);


    buscar_binaria(tabla2,numABuscar);
    buscar_binaria(tabla3,numABuscar);
    buscar_binaria(tabla4,numABuscar);
    printf("\n");

    // FIN
    return 0;
}


void shell(int[TAM]);
void shell(int tabla[TAM]){
    int salto, cambios, i, aux;
    for (salto = TAM/2; salto!=0;salto=salto/2){
        cambios = true;
        while (cambios==true){
            cambios = false;
            for (i=salto; i<TAM; i++){
                if (tabla[i-salto] > tabla[i])
                {
                    aux = tabla[i];
                    tabla[i] = tabla[i-salto];
                    tabla[i-salto] = aux;
                    cambios = true;
                }
            }
        }
    }
    printf ("\nLa tabla4 ordenada POR SHELL SHORT") ;
    /*for (i=0; i<TAM; i++)
    {
        printf ("%d\t", tabla[i]);
    }*/
}

void intertamcio(int[TAM]);
void intercambio(int tabla[TAM]){
    int i,j,aux;
    for(i=0; i<TAM-1; i++){
        for(j=i+1; j<TAM;j++){
            if(tabla[i] > tabla[j]){
                aux = tabla[i];
                tabla[i] = tabla[j];
                tabla[j] = aux;
            }
        }
    }
    printf ("\nLa tabla2 ordenada POR INTERCAMBIO") ;
}

void seleccion(int[TAM]);
void seleccion(int tabla[TAM]){
    int i,j,aux,indice_menor;
    for (i=0; i<TAM; i++){
        indice_menor = i;
        aux = tabla[i] ;
        for (j=i+1; j<TAM; j++){
            if (tabla [j] < tabla [indice_menor] ){
                indice_menor = j;
            }
        }
        aux = tabla[i] ;
        tabla[i] = tabla [indice_menor] ;
        tabla[indice_menor] = aux;

    }
    printf ("\nLa tabla2 ordenada POR SELECCION") ;
    /*for (i=0; i<TAM; i++)
    {
        printf ("%d\t", tabla[i]);
    }*/
}

void bubble(int[TAM]);
void bubble(int tabla[TAM]){
    int i,j, aux;
    for(i =0; i < TAM-1;i++){
        for(j=0;j<TAM-i-1;j++){
            if(tabla[j]>tabla[j+1]){
                aux = tabla[j];
                tabla[j] = tabla[j+1];
                tabla[j+1] = aux;
            }
        }
    }

    printf ("\nLa tabla3 ordenada POR BURBUJA") ;
    /*for (i=0; i<TAM; i++)
    {
        printf ("%d\t", tabla[i]);
    }*/
}

void buscar_binaria(int[TAM], int);
void buscar_binaria(int tabla[TAM], int elemento){

    int encontrado = 0;
    int inferior, superior, central;
    int pasos = 0;
    inferior = 0;
    superior = TAM-1;

    while (inferior<=superior){
        central = (inferior + superior) / 2;
        if (tabla[central] == elemento){
            encontrado = central;
            //printf("\n\nsi\n\n ");
            inferior = superior+1; // Para salir del bucle
        }else{
            if (elemento<tabla[central] ){
                superior = central - 1;
            }else{
                inferior = central + 1;
            }
        }
        pasos++;
    }

    if(encontrado){
        printf("\nPosicion %d en %d pasos", encontrado,pasos);
    } else {
    printf("\nNo encontrado en %d pasos",pasos);}

}
