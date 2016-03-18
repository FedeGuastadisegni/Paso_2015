#include "Urna.h"
#include "Funciones.h"
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>

void crearUrna(Urna *urna){
    urna->idUrna = -1;
    strcpy (urna->horaApertura,"");
    strcpy (urna->horaCierre,"");
    crearLista(urna->lstVotos,(PFComparacion)compararVoto);
    urna->urnaActiva = false;
}


void destruirUrna(Urna *urna){
    /*urna->idUrna=-1;
    delete urna->horaApertura;
    delete urna->horaCierre;
    eliminarLista(urna->lstVotos);
    delete urna;
    */
}

void setIdUrna(PtrDato urna,int idUrna){
   ((Urna*)urna)->idUrna = idUrna;
}

int getIdUrna(PtrDato urna){
    return ((Urna*)urna)->idUrna;
}

void setHoraApertura(PtrDato urna,char horaApertura[40]){
     strcpy((((Urna*)urna)->horaApertura), horaApertura);
}

char* getHoraApertura(PtrDato urna){
    return ((Urna*)urna)->horaApertura;
}

void setHoraCierre(PtrDato urna,char horaCierre[40]){
     strcpy((((Urna*)urna)->horaCierre), horaCierre);
}

char* getHoraCierre(PtrDato urna){
    return ((Urna*)urna)->horaCierre;
}

void seturnaActiva(PtrDato urna, bool urnaActiva){
    ((Urna*)urna)->urnaActiva = urnaActiva;
}

bool geturnaActiva(PtrDato urna)
{
    return ((Urna*)urna)->urnaActiva;
}

void setLstVotos(PtrDato urna,Lista &lstVotos){
    ((Urna*)urna)->lstVotos = lstVotos;
}

Lista &getLstVotos(PtrDato urna){
    return ((Urna*)urna)->lstVotos;
}

void altaUrna(Lista &lstProvincia, Lista &lstMesas, Lista &lstCandidatos, Lista &lstPartidos,int c){

    bool encontrado = true;
    int idProvincia = 0;
    int idUrna = 0;
    char horaApertura[40];
    char horaCierre[40];
    int idMesa = 0;
    system("CLS");

    imprimirLstProvincias(lstProvincia);
    printf("De que provincia es la urna? (Ingrese ID)\n");
    scanf("%d",&idProvincia);
     PtrNodoLista cursor = primero(lstProvincia);
     while (( cursor != fin( )) && (encontrado)){
        if (getIdProvincia(cursor->dato)==idProvincia){
            encontrado=false;
            }
        else cursor = siguiente(lstProvincia, cursor);

        if(cursor==fin() && encontrado)
        {
            printf("la provincia que ingreso no es valida\n\n");
            printf("Ingrese de nuevo el id:  ");
            scanf("%d",&idProvincia);
            encontrado = true;
            cursor = primero(lstProvincia);
        }

    }

    PtrNodoLista provincia = buscarProvinciaPorId(idProvincia,lstProvincia);

    system("CLS");
    reordenar(getLstMesas(provincia->dato));
    imprimirLstMesas(getLstMesas(provincia->dato));
    printf("\nEn que mesa se encuentra la Urna? (Ingrese ID)\n");
    scanf("%d",&idMesa);
    PtrNodoLista cursor2 = primero(getLstMesas(provincia->dato));
    encontrado = true;
     while (( cursor2 != fin( )) && (encontrado)){
        if (getIdMesa(cursor2->dato)==idMesa){
            encontrado=false;
            }
        else cursor2 = siguiente(getLstMesas(provincia->dato), cursor2);

        if(cursor2==fin() && encontrado)
        {
            printf("la Mesa que ingreso no es valida\n\n");
            printf("Ingrese de nuevo el id:  ");
            scanf("%d",&idMesa);
            encontrado = true;
            cursor2 = primero(getLstMesas(provincia->dato));
        }

    }




    //PtrNodoLista mesa = buscarMesaPorId(idMesa,getLstMesas(provincia->dato));

    /*if(mesa == fin()){

        printf("NULO");
        system("PAUSE");
    }*/


    if(geturnaActiva((((Mesa*)cursor2->dato)->urna))){
        printf("*La mesa seleccionada ya tiene una urna asignada, debe cerrarla para poder asignar una nueva.\n");
        delay(5);
        registroVotos(lstProvincia,lstMesas, lstCandidatos,lstPartidos,c);
    }else{

    Urna *urna = new Urna;
    crearUrna(urna);
    system("CLS");
    printf("Ingrese el ID que va a tener la Urna\n");
    scanf("%d",&idUrna);
    setIdUrna(urna,idUrna);
    printf("Ingrese la hora de apertura en formato HH:MM:SS\n");
    scanf("%s",horaApertura);
    setHoraApertura(urna,horaApertura);
    printf("Ingrese la hora de cierre en formato HH:MM:SS\n");
    scanf("%s",horaCierre);
    setHoraCierre(urna,horaCierre);
    bool urnaActiva=true;
    seturnaActiva(urna,urnaActiva);
    setUrna(cursor2->dato,urna);

    system("CLS");
    printf("Urna asignada!\n");
    printf("ID: %d\n", getIdUrna((((Mesa*)cursor2->dato)->urna)));
    printf("Hora de Apertura: %s HS\n", getHoraApertura((((Mesa*)cursor2->dato)->urna)));
    printf("Hora de Cierre: %s HS\n",getHoraCierre((((Mesa*)cursor2->dato)->urna)));

    printf("En instantes sera redirigido al Menu de Votos");

         delay(1);
         printf(".");
         delay(1);
         printf(".");
         delay(1);
         printf(".");
         delay(1);
         printf(".");
         delay(1);
         printf(".");
    }
}

void cierreUrna(Lista &lstProvincia,Lista &lstMesas, Lista &lstCandidatos, Lista &lstPartidos,int c){


    bool encontrado = true;
    int idProvincia = 0;
    int idMesa = 0;
    system("CLS");
    imprimirLstProvincias(lstProvincia);
    printf("De que provincia es la urna? (Ingrese ID)\n");
    scanf("%d",&idProvincia);
     PtrNodoLista cursor = primero(lstProvincia);
     while (( cursor != fin( )) && (encontrado)){
        if (getIdProvincia(cursor->dato)==idProvincia){
            encontrado=false;
            }
        else cursor = siguiente(lstProvincia, cursor);

        if(cursor==fin() && encontrado)
        {
            printf("la provincia que ingreso no es valida\n\n");
            printf("Ingrese de nuevo el id:  ");
            scanf("%d",&idProvincia);
            encontrado = true;
            cursor=primero(lstProvincia);
        }

    }

    PtrNodoLista provincia = buscarProvinciaPorId(idProvincia,lstProvincia);
    system("CLS");
    imprimirLstMesas(getLstMesas(provincia->dato));
    printf("En que mesa se encuentra la Urna? (Ingrese ID)\n");
    scanf("%d",&idMesa);
    PtrNodoLista cursor2 = primero(getLstMesas(provincia->dato));
    encontrado = true;
     while (( cursor2 != fin( )) && (encontrado)){
        if (getIdMesa(cursor2->dato)==idMesa){
            encontrado=false;
            }
        else cursor2 = siguiente(getLstMesas(provincia->dato), cursor2);

        if(cursor2==fin() && encontrado)
        {
            printf("la Mesa que ingreso no es valida\n\n");
            printf("Ingrese de nuevo el id:  ");
            scanf("%d",&idMesa);
            encontrado = true;
            cursor2=primero(getLstMesas(provincia->dato));
        }

    }



    //PtrNodoLista mesa = buscarMesaPorId(idMesa,getLstMesas(provincia->dato));

    char resp;
    if(!geturnaActiva((((Mesa*)cursor2->dato)->urna))){
        printf("*La mesa seleccionada no tiene una urna asignada, desea asignar una? s/n \n");
        scanf(" %c",&resp);
        if(resp == 's' || resp == 'S'){
            altaUrna(lstProvincia,lstMesas,lstCandidatos,lstPartidos,c);
        }else{
            registroVotos(lstProvincia,lstMesas,lstCandidatos,lstPartidos,c);
        }
    }else{
    bool urnaActiva=false;
    seturnaActiva((((Mesa*)cursor2->dato)->urna),urnaActiva);
    encolar(getColaUrnas(cursor2->dato),getUrna(cursor2->dato));
    destruirUrna (((Mesa*)cursor2->dato)->urna);
    system("CLS");
    printf("Urna dada de baja! (Encolada y destruida)\n");

     printf("En instantes sera redirigido al Menu de Votos");

         delay(1);
         printf(".");
         delay(1);
         printf(".");
         delay(1);
         printf(".");
         delay(1);
         printf(".");
         delay(1);
         printf(".");
    }
}
