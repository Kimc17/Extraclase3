#include<iostream>
#include<cmath>
#include<cstdlib>
#include <sys/time.h>
#include <sys/resource.h>
#include <cstring>
#include "Secuencial.h"
#include "Binaria.h"
#include "Interpolacion.h"

using namespace std;



int main(){
    int aux = 0;
    int tamanio=5000;
    int arreglo[tamanio];

    srand(time(0));

    for(int i = 0; i < tamanio; i++){
        aux = (1 + rand() % tamanio);

        int aux2 = 0;

        while(aux2 < i){

            if(aux != arreglo[aux2])
                aux2++;

            else{
                aux = (1 + rand() %tamanio);
                aux2 = 0;

            }
        }

        arreglo[i] = aux;
    }

    struct rusage usage;
    struct timeval start, end;
    double startsec,endsec;


    int *array;
    array=arreglo;

    getrusage(RUSAGE_SELF, &usage);
    start = usage.ru_utime;
    startsec = start.tv_sec + (double)start.tv_usec/1000000;
    cout<<"Inicio:"<<startsec<<"\n";

    /*Secuencial* sec= new Secuencial;
    sec->BusSecuencial(67,arreglo);*/
   /* Binaria* bin= new Binaria();
    bin->ejecutar(array, 78, tamanio);*/
    Interpolacion* inter = new Interpolacion;
    inter->ejecutar(array, 56, tamanio);

    getrusage(RUSAGE_SELF, &usage);
    end = usage.ru_utime;
    endsec = end.tv_sec + (double)end.tv_usec/1000000;
    cout<<"Fin:"<<endsec<<" Diferencia: "<<endsec-startsec<<"\n";



}
