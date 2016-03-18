#include "Candidato.h"
#include "Funciones.h"
#include "PartidoPolitico.h"
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/* Implementacion de primitivas */

void crearCandidato(Candidato  *candidato){
    candidato->idCandidato = -1;
    strcpy (candidato->nombre_candidato,"");
}

void destruirCandidato(Candidato  &candidato){
}

void setIdCandidato(PtrDato candidato,int idCandidato){
   ((Candidato*)candidato)->idCandidato = idCandidato;
}

int getIdCandidato(PtrDato candidato){
    return ((Candidato*)candidato)->idCandidato;
}

void setNombre_candidato(PtrDato candidato,char nombre[40]){
     strcpy((((Candidato*)candidato)->nombre_candidato), nombre);
}

char* getNombre_candidato(PtrDato candidato){
   return  ((Candidato*)candidato)->nombre_candidato;
}

/** ****************************************Alta de un Candidato ************************************************************* **/

void altaCandidato(Lista &lstCandidatos, Lista &lstPartidos){

    char rta='s';

    while(rta=='s'||rta=='S')
    {
     int id=0;
     char nombre[30];
     int idPartido=0;
     bool encontrado=false;
     bool partidoEncontrado = false;

     Candidato *candidato = new Candidato;
     crearCandidato(candidato);

     system ("CLS");

     system("cls");
     printf("Ingrese id:  ");
     scanf("%d",&id);


     PtrNodoLista cursor = primero(lstCandidatos);
     while (( cursor != fin( )) && (!encontrado)){
        if (getIdCandidato(cursor->dato)==id){
            encontrado=true;
            printf("El numero de ID que ingreso ya esta siendo usado por otro candidato, por favor, elija otro numero de ID \n\n");
            printf("Ingrese de nuevo el id:  ");
            scanf("%d",&id);
            encontrado = false;
            }else{ cursor = siguiente(lstCandidatos, cursor);}
    }
        if (!encontrado){

         cursor=fin( );

         setIdCandidato(candidato, id);
         system("cls");
         printf("Ingrese nombre y apellido del candidato:  \n");
         scanf(" %[^\n]s",nombre);
         setNombre_candidato(candidato, nombre);


         PtrNodoLista nodo = adicionarPrincipio(lstCandidatos, candidato);


         system ("CLS");
         printf("se ha registrado exitosamente \n\n");

         printf("Id: %d \n",getIdCandidato(nodo->dato));
         printf("Candidato: %s \n",getNombre_candidato(nodo->dato));
         delay(2);

        }
        system("cls");
        printf("Seguir registrando candidatos? S/N\n");
        fflush(stdin);
        scanf("%c", &rta);

    }
         system("CLS");
         printf("En instantes sera redirigido al menu de candidatos");

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


/** ************************************************ BAJA DE CANDIDATO ******************************************************* **/

void bajaCandidato(Lista &lstCandidatos){

     bool encontrado=false;
     int compararCandidato=0;
     char nombre[30];
     system("CLS");

     fflush(stdin);
     system("cls");
     printf("\n Nombre del candidato a borrar: ");
     fflush(stdin);
     gets(nombre);
     fflush(stdin);

     PtrNodoLista cursor = primero(lstCandidatos);

     while (( cursor != fin( )) && (! encontrado)){


           compararCandidato=strcmp(getNombre_candidato(cursor->dato) , nombre);
           if (compararCandidato == 0){
                     encontrado=true;
                     eliminarNodo(lstCandidatos, cursor);
                     printf("Candidato inhabilitado \n\n");
                     delay (2);
                }
           else cursor = siguiente(lstCandidatos, cursor);
     }
           if (! encontrado ){
               printf("Candidato inexistente \n\n");
               cursor=fin( );
               delay (2);
                   }


 }


 PtrNodoLista buscarCandidatoPorId(int id, Lista &lstCandidatos){

    bool encontrado=false;
    PtrNodoLista cursor = primero(lstCandidatos);


     while (( cursor != fin( )) && ( ! encontrado)){

           if (id==getIdCandidato(cursor->dato)){
                     encontrado=true;
                     }
           else cursor = siguiente(lstCandidatos, cursor);
     }
           if (! encontrado ){
               cursor=fin( );
                   }
    return cursor;
}

/** ***************************************************** MODIFICACION DE CANDIDATO ************************************************ **/

void modificarCandidato(Lista &lstCandidatos){

     system("CLS");
     imprimirLstCandidatos(lstCandidatos);
     bool encontrado=false;
     int compararId=0;
     bool flag=false;
     int id=0;
     char nombreCandidato[30];

     char opc;


     fflush(stdin);
     printf("\nId del Candidato a modificar: ");
     fflush(stdin);
     scanf("%d", &id);
     printf("\n\n");


     PtrNodoLista cursor=buscarCandidatoPorId(id, lstCandidatos);


    while (( cursor != fin( )) && ( ! encontrado)){

           if ((getIdCandidato(cursor->dato)==id)){

                     bool flag=false;
                     encontrado=true;


                  do{
                     system("CLS");
                     printf(" \n");
                     printf("Desea modificar id del Candidato? (s/n): ");
                     fflush(stdin);
                     opc=getchar();
                     printf(" \n");
                     if ((opc=='s')||(opc=='S')){
                          printf("              Ingrese el nuevo id del Candidato:  ");
                          scanf("%d",&id);
                          setIdCandidato(cursor->dato, id);
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
                     printf("Desea modificar el nombre del Candidato? (s/n): ");
                     fflush(stdin);
                     opc=getchar();
                     printf(" \n");
                     if ((opc=='s')||(opc=='S')){
                          printf("              Ingrese el nuevo nombre del Candidato:  ");
                          scanf(" %[^\n]s",nombreCandidato);
                          setNombre_candidato(cursor->dato, nombreCandidato);
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

            else cursor = siguiente(lstCandidatos, cursor);

           }

            if (! encontrado ){
               printf("ERROR: ID Candidato inexistente. \n\n");
               cursor=fin( );
               delay (2);
            }

        else{
           system("CLS");
           printf(" Candidato modificado exitosamente \n\n");
           printf("\tId: %d \n",getIdCandidato(cursor->dato));
           printf("\tNombre del candidato: %s \n",getNombre_candidato(cursor->dato));
          delay(2);
        }
 }


 bool buscarPartidoCandidato(int idCandidato, Lista &lstCandidatos, Lista &lstPartidos){

       PtrNodoLista cursor=primero(lstCandidatos);
       PtrNodoLista cursor3=fin();

       bool flag=false;

       PtrNodoLista cursor2=primero(lstPartidos);
       while (cursor2!=fin() && flag==false){
            PtrNodoLista cursor3 = primero(getLstCandidatos(cursor2->dato));
            while (cursor3!=fin() && flag==false){
                if(idCandidato==getIdCandidato(cursor3->dato)){
                    flag=true;
                }
                else cursor3=siguiente(getLstCandidatos(cursor2->dato), cursor3);

            }

            cursor2=siguiente(lstPartidos, cursor2);
       }
    return flag;
}

PtrNodoLista traerPartidoCandidato(int idCandidato, Lista &lstCandidatos, Lista &lstPartidos){

        if(idCandidato == 0){
            return fin();
        }
       PtrNodoLista cursor=primero(lstCandidatos);
       PtrNodoLista cursor3=fin();

       bool flag=false;

       PtrNodoLista cursor2=primero(lstPartidos);
       while (cursor2!=fin() && flag==false){
            PtrNodoLista cursor3 = primero(getLstCandidatos(cursor2->dato));
            while (cursor3!=fin() && flag==false){
                if(idCandidato==getIdCandidato(cursor3->dato)){
                    flag=true;
                }
                else cursor3=siguiente(getLstCandidatos(cursor2->dato), cursor3);

            }
        if(flag==false)
            cursor2=siguiente(lstPartidos, cursor2);
       }

       if(flag==false)
            cursor2=fin();

    return cursor2;
}

/** ********************************************** GUARDAR CANDIDATOS **************************************************** **/

void guardarCandidatos(Lista &lstCandidatos, Lista &lstPartidos){
      int idCandidato = 0;
      char nombre[40];
      int idPartido=0;
      bool flag=false;

      system("CLS");
      PtrNodoLista cursor=primero(lstCandidatos);
      FILE *pf;
      if((pf=fopen("Candidatos.txt","w"))==NULL)
        {perror("Error al abrir el fichero");
         system("PAUSE");
         }
      else{
           while(cursor!=fin()){
               idCandidato = getIdCandidato(cursor->dato);
               strcpy(nombre, getNombre_candidato(cursor->dato));


               idPartido = getIdPartido(traerPartidoCandidato(idCandidato, lstCandidatos, lstPartidos)->dato);
               fprintf(pf,"%i;%s;%i\n", idCandidato, nombre, idPartido);

               cursor=siguiente(lstCandidatos,cursor);
        }

      }
      fclose(pf);
}


/** *********************************************** CARGAR CANDIDATOS ****************************************************** **/

void cargarCandidatos(Lista &lstCandidatos, Lista &lstPartidos){
      int id=0;
      char nombre[30];
      int idPartido=0;

      FILE *candidatos;
      if((candidatos=fopen("Candidatos.txt","rt"))==NULL){
          perror("Error al abrir el fichero");
          system("PAUSE");
          }
      else{
           while(fscanf(candidatos,"%i;%[^;];%i",&id,&nombre,&idPartido)!= EOF){
              Candidato *candidato;
              candidato = new Candidato;
              crearCandidato(candidato);

              setIdCandidato(candidato, id);
              setNombre_candidato(candidato, nombre);

              //agrego al candidato


              PtrNodoLista partido = buscarPartidoPorId(idPartido, lstPartidos);
              if(partido != fin()){
                agregarCandidato(partido->dato, candidato);
              }else{
                  printf("ERROR: id %d de Partido Politico inexistente en candidato %s\n",idPartido,&nombre);
              }

              if(partido != fin()){
                    if(buscarCandidatoPorId(id, lstCandidatos)==fin()){
                        PtrNodoLista nodo=adicionarFinal(lstCandidatos,candidato);
                        }else{
                            printf("ERROR: candidato %s tiene id duplicado\n",&nombre);
              }
            }

           }
    }
}

