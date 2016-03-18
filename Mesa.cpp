#include "Mesa.h"
#include "Funciones.h"
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>


void crearMesa(Mesa *mesa){
    mesa->idMesa = -1;
    mesa->urna = new Urna;
    crearUrna(mesa->urna);
    crearCola(mesa->colaUrnas);
}

void destruirMesa(Mesa mesa){
}

void setIdMesa(PtrDato mesa,int idMesa){
    ((Mesa*)mesa)->idMesa = idMesa;
}

int getIdMesa(PtrDato mesa){
    return ((Mesa*)mesa)->idMesa;
}

void setColaUrnas(PtrDato mesa, Cola &colaUrnas){
    ((Mesa*)mesa)->colaUrnas = colaUrnas;
}

Cola &getColaUrnas(PtrDato mesa){
    return ((Mesa*)mesa)->colaUrnas;
}

void setUrna(PtrDato mesa, Urna *urna){
    ((Mesa*)mesa)->urna = urna;
}

Urna* getUrna(PtrDato mesa){
    return ((Mesa*)mesa)->urna;
}


/***************************************** ALTA MESA **************************************/

int altaMesa(Lista &lstMesas,Lista &lstProvincias){


     int id=0;
     bool encontrado=false;

     Mesa *mesa = new Mesa;
     crearMesa(mesa);

     system ("CLS");


     printf("Ingrese id:  ");
     scanf("%d",&id);

     PtrNodoLista cursor = primero(lstMesas);
     while ((cursor != fin( )) && (! encontrado)){
        if (getIdMesa(cursor->dato)==id){
            encontrado=true;
            printf("El numero de ID que ingreso ya esta siendo usado por otra Mesa, por favor, elija otro numero de ID \n\n");
            printf("Ingrese de nuevo el id:  ");
            scanf("%d",&id);
            encontrado = false;
            }

        else cursor = siguiente(lstMesas, cursor);
    }
        if (!encontrado){

         cursor=fin( );

         setIdMesa(mesa, id);


         PtrNodoLista nodo=adicionarPrincipio(lstMesas, mesa);


         system ("CLS");
         printf("se ha registrado exitosamente \n\n");

         printf("Id: %d \n",getIdMesa(nodo->dato));
         printf("Por favor, espere");

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

         return id;

     }

}


/***************************************** BAJA MESA **************************************/

void bajaMesa(Lista &lstMesas){

     bool encontrado=false;
     int id;

     system("CLS");

     fflush(stdin);
     printf("\n Mesa a borrar: ");
     fflush(stdin);
     scanf("%d",&id);
     fflush(stdin);


     PtrNodoLista cursor = primero(lstMesas);


     while (( cursor != fin( )) && ( ! encontrado)){
           if (getIdMesa((cursor->dato)) == id){
                     encontrado=true;
                     eliminarNodo(lstMesas, cursor);
                     printf("Mesa inhabilitada \n\n");
                     delay (2);

                }

           else cursor = siguiente(lstMesas, cursor);

     }

           if (! encontrado ){
               printf("Mesa inexistente \n\n");
               cursor=fin( );
               delay (2);
                   }

 }

 PtrNodoLista buscarMesaPorId(int id, Lista &lstMesas){

    bool encontrado=false;
    PtrNodoLista cursor = primero(lstMesas);


     while ((cursor != fin( )) && (!encontrado)){

           if (id==getIdMesa(cursor->dato)){
                     encontrado=true;
        }else{
            cursor = siguiente(lstMesas, cursor);
        }
        if (! encontrado ){
               cursor=fin();
        }

    return cursor;

    }
 }




void cargarMesas(Lista &lstProvincias, Lista &lstMesas){

      int idMesa=0;
      int idProvincia=0;
      FILE *mesas;
      if((mesas=fopen("Mesas.txt","rt"))==NULL){
          perror("Error al abrir el fichero");
          system("PAUSE");
          }
      else{
           while(fscanf(mesas,"%i;%i\n",&idMesa,&idProvincia)!= EOF){

              Mesa *mesa;
              mesa = new Mesa;
              crearMesa(mesa);
              setIdMesa(mesa, idMesa);

              //agrego la mesa a la provincia correspondiente //




             bool encontrado = false;
             PtrNodoLista cursor = primero(lstMesas);
             while(cursor!= fin() && !encontrado){
                if(getIdMesa(cursor->dato)== getIdMesa(mesa)){
                    encontrado = true;
                }
                cursor = siguiente(lstMesas,cursor);
             }

             if(!encontrado){
                adicionarPrincipio(lstMesas,mesa);
            }else{
                printf("ID: %d duplicado",idMesa);
            }

            PtrNodoLista provincia = buscarProvinciaPorId(idProvincia,lstProvincias);
              if(provincia != fin()){
                    if(!encontrado){
                        agregarMesa(provincia->dato, mesa);
                    }
                //adicionarPrincipio(lstMesas,mesa);
              }else{
                   printf("ERROR: id %d de Provincia inexistente en Mesa %d\n",idProvincia,idMesa);
              }



        }
    }
}

PtrNodoLista traerProvinciaMesa(int idMesa, Lista &lstMesas, Lista &lstProvincias){

       PtrNodoLista cursor=primero(lstMesas);
       PtrNodoLista cursor3=fin();

       bool flag=false;

       PtrNodoLista cursor2=primero(lstProvincias);
       while (cursor2!=fin() && flag==false){
            PtrNodoLista cursor3 = primero(getLstMesas(cursor2->dato));
            while (cursor3!=fin() && flag==false){
                if(idMesa==getIdMesa(cursor3->dato)){
                    flag=true;
                }
                else cursor3=siguiente(getLstMesas(cursor2->dato), cursor3);

            }
        if(flag==false)
            cursor2=siguiente(lstProvincias, cursor2);
       }

       if(flag==false)
            cursor2=fin();

    return cursor2;
}




void guardarMesa(Lista &lstMesas,Lista &lstProvincias){
      int idMesa=0;
      int idProvincia=0;
      bool flag=false;

      system("CLS");
      PtrNodoLista cursor = primero(lstMesas);
      FILE *pf;
      if((pf=fopen("Mesas.txt","w"))==NULL)
        {perror("Error al abrir el fichero");
         system("PAUSE");
         }
      else{
           while(cursor!=fin()){

               idMesa = getIdMesa(cursor->dato);

               idProvincia = getIdProvincia(traerProvinciaMesa(idMesa, lstMesas, lstProvincias)->dato);
               fprintf(pf,"%i;%i\n", idMesa, idProvincia);

               cursor=siguiente(lstMesas,cursor);

        }

      }
      fclose(pf);
}

void agregarMesa(PtrDato provincia, Mesa *mesa){
    adicionarPrincipio(getLstMesas(provincia), mesa);
}

bool buscarProvinciaMesa(int idMesa, Lista &lstMesas, Lista &lstProvincias){

       PtrNodoLista cursor=primero(lstMesas);
       PtrNodoLista cursor3=fin();

       bool flag=false;

       PtrNodoLista cursor2=primero(lstProvincias);
       while (cursor2!=fin() && flag==false){
            PtrNodoLista cursor3 = primero(getLstMesas(cursor2->dato));
            while (cursor3!=fin() && flag==false){
                if(idMesa==getIdMesa(cursor3->dato)){
                    flag=true;
                }
                else cursor3=siguiente(getLstMesas(cursor2->dato), cursor3);

            }

            cursor2=siguiente(lstProvincias, cursor2);
       }
    return flag;
}

