/* TDA partido politico
 * archivo: PartidoPolitico.cpp
*/

#include "PartidoPolitico.h"
#include "Funciones.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

/* Implementacion de primitivas */

void crearPartido(PartidoPolitico *partidoPolitico){
    partidoPolitico->idPartido=-1;
    strcpy (partidoPolitico->nombre_partido,"");
    crearLista(partidoPolitico->lstCandidatos,(PFComparacion)compararCandidato);
}

void destruirPartido(PartidoPolitico &partidoPolitico){
}

void setIdPartido(PtrDato partidoPolitico,int idPartido){
    ((PartidoPolitico*)partidoPolitico)->idPartido = idPartido;
}

int getIdPartido(PtrDato partidoPolitico){
    return ((PartidoPolitico*)partidoPolitico)->idPartido;
}

void setNombre_partido(PtrDato partidoPolitico,char nombre_partido[40]){
    strcpy((((PartidoPolitico*)partidoPolitico)->nombre_partido), nombre_partido);
}

char* getNombre_partido(PtrDato partidoPolitico){
    return ( ((PartidoPolitico*)partidoPolitico)->nombre_partido);
}

void setLstCandidatos(PtrDato partidoPolitico,Lista &lstCandidatos){
    ((PartidoPolitico*)partidoPolitico)->lstCandidatos = lstCandidatos;
}

Lista &getLstCandidatos(PtrDato partidoPolitico){
    return (((PartidoPolitico*)partidoPolitico)->lstCandidatos);
}


/****************************************** ALTA PARTIDO POLITICO (nuevo) *****************************/

void altaPartido(Lista &lstPartidos){


     bool encontrado=false;

     int id = 0;
     char nombrePartido[30];


     PartidoPolitico *par=new PartidoPolitico;
     crearPartido(par);

     system("CLS");

     printf("Ingrese id:  ");
     scanf("%d",&id);

     PtrNodoLista cursor = primero(lstPartidos);
     while (( cursor != fin( )) && ( ! encontrado)){
        if (getIdPartido(cursor->dato)==id){
            encontrado=true;
            printf("El numero de ID que ingreso ya esta siendo usado por otro Partido Politico, por favor, elija otro numero de ID \n\n");
            printf("Ingrese de nuevo el id:  ");
            scanf("%d",&id);
            encontrado = false;
            }
        else cursor = siguiente(lstPartidos, cursor);
    }
        if (!encontrado){

         cursor=fin( );

         setIdPartido(par, id);
         printf("Ingrese nombre del Partido Politico:  ");
         scanf(" %[^\n]s",nombrePartido);
         setNombre_partido(par, nombrePartido);

         PtrNodoLista nodo=adicionarPrincipio(lstPartidos, par);


         system ("CLS");
         printf("se ha registrado exitosamente \n\n");

         printf("Id: %d \n",getIdPartido(nodo->dato));
         printf("Partido Politico: %s \n",getNombre_partido(nodo->dato));

         printf("En instantes sera redirigido al menu de partidos");

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

/******************************************* BAJA PARTIDO POLITICO ************************************/

void bajaPartido(Lista &lstPartidos){

     bool encontrado=false;
     int idPartido=0;
     system("CLS");

     fflush(stdin);
     printf("\n Id Partido a borrar: ");
     fflush(stdin);
     scanf("%d", &idPartido);
     fflush(stdin);


     PtrNodoLista cursor = primero(lstPartidos);


     while (( cursor != fin( )) && ( ! encontrado)){

           if (getIdPartido(cursor->dato)==idPartido){


                     encontrado=true;
                     eliminarNodo(lstPartidos, cursor);
                     printf("\n\tPartido eliminado! \n\n");
                     delay (2);

                }

           else cursor = siguiente(lstPartidos, cursor);
     }
           if (! encontrado ){
               printf("Partido inexistente \n\n");
               cursor=fin( );
               delay (2);
                   }

 }


/********************************* MODIFICAR PARTIDO POLITICO ******************************************/

void modificarPartido(Lista &lstPartido){

     bool encontrado=false;
     int compararId=0;


     int id=0;
     char nombrePartidoo[30];

     char opc;

     system("CLS");

     fflush(stdin);
     printf("\n Id del Partido a modificar: ");
     fflush(stdin);
     scanf("%d", &id);
     printf("\n\n");

     PtrNodoLista cursor = primero(lstPartido);

    if(cursor==fin()){
        printf("ERROR: El ID del Partido es inexistente.");
        delay(2);
    }

     while (( cursor != fin( )) && ( ! encontrado)){

           if ((getIdPartido(cursor->dato)==id)){

                     bool flag=false;
                     encontrado=true;

                    do{
                     system("CLS");
                     printf(" \n");
                     printf("Desea modificar id del Partido? (s/n): ");
                     fflush(stdin);
                     opc=getchar();
                     printf(" \n");
                     if ((opc=='s')||(opc=='S')){
                          printf("              Ingrese el nuevo id del Partido:  ");
                          scanf("%d",&id);
                          setIdPartido(cursor->dato, id);
                          flag=true;
                               }
                     else if((opc=='n')||(opc=='N'))
                        flag=true;
                     else{
                          printf("Opcion incorrecta, ingrese nuevamente");
                          delay(2);
                               }
                        }while(flag==false);

                     flag=false;


                    do{
                     system("CLS");
                     printf(" \n");
                     printf("Desea modificar el nombre del Partido? (s/n): ");
                     fflush(stdin);
                     opc=getchar();
                     printf(" \n");
                     if ((opc=='s')||(opc=='S')){
                          printf("              Ingrese el nuevo nombre del Partido:  ");
                          scanf(" %[^\n]s",nombrePartidoo);
                          setNombre_partido(cursor->dato, nombrePartidoo);
                          flag=true;
                               }
                     else if((opc=='n')||(opc=='N'))
                        flag=true;
                     else{
                          printf("Opcion incorrecta, ingrese nuevamente");
                          delay(2);
                               }
                        }while(flag==false);

                     flag=false;


          }

           else cursor = siguiente(lstPartido, cursor);

           }

           if (! encontrado ){
               printf("id/Nombre Partido inexistentes \n\n");
               cursor=fin( );
               delay (2);
                   }

           else{
           system("CLS");
           printf(" Partido Politico modificado exitosamente \n\n");
           printf("\tId: %d \n",getIdPartido(cursor->dato));
           printf("\tNombre del Partido: %s \n",getNombre_partido(cursor->dato));
           delay(4);
              }

 }


/********************************** CARGAR PARTIDO (txt)**************************************/

void cargarPartido(Lista &lstPartidos){

     int id=0;
     char nombrePartido[30];

     FILE *partidos;
     if((partidos = fopen("Partidos.txt","rt")) == NULL)
        {
              perror("Error al abrir el fichero");
              system("PAUSE");
              }
     else {

              while(fscanf(partidos,"%i;%[^\n]", &id, &nombrePartido) != EOF) {

                      PartidoPolitico *par=new PartidoPolitico;
                      crearPartido(par);
                      setIdPartido(par, id);
                      setNombre_partido(par, nombrePartido);

                      if(buscarPartidoPorId(id, lstPartidos)==fin()){
                            PtrNodoLista nodo = adicionarPrincipio(lstPartidos, par);
                      }else{
                          printf("ERROR: partido %s tiene id duplicado\n",&nombrePartido);
                     }
            }

    }
}

/********************************* GUARDAR PARTIDO (txt) ************************************/

void guardarPartido(Lista &lstPartidos){

     int id=0;
     char nombrePartido[30];

       system("CLS");

       PtrNodoLista cursor = ultimo(lstPartidos);
       FILE *pf;

       if((pf = fopen("Partidos.txt","w")) == NULL)
           {
            perror("Error al abrir el fichero");
            system("PAUSE");
           }
        else {
        while (cursor != fin()) {

             id=getIdPartido(cursor->dato);
             strcpy(nombrePartido, getNombre_partido(cursor->dato));

             fprintf(pf,"%i;%s\n", id, nombrePartido);
             cursor = anterior(lstPartidos, cursor);
            }
       }
    fclose(pf);
}


/*************************************************************************/

PtrNodoLista buscarPartidoPorId(int id, Lista &lstPartidos){

    bool encontrado=false;
    PtrNodoLista cursor = primero(lstPartidos);


     while (( cursor != fin( )) && ( ! encontrado)){

           if (id==getIdPartido(cursor->dato)){
                     encontrado=true;
                     }

           else cursor = siguiente(lstPartidos, cursor);
     }
           if (! encontrado ){
               cursor=fin();
                   }

    return cursor;

}


void agregarCandidato(PtrDato partido, Candidato *candidato){
    adicionarPrincipio(getLstCandidatos(partido), candidato);
}



