#include "Provincia.h"


void crearProvincia(Provincia *provincia){
    provincia->idProvincia = -1;
    crearLista(provincia->lstMesas,(PFComparacion)compararMesa);
}

void destruirProvincia(Provincia provincia){
}

void setIdProvincia(PtrDato provincia, int idProvincia){
    ((Provincia*)provincia)->idProvincia = idProvincia;
}

int getIdProvincia(PtrDato provincia){
    return ((Provincia*)provincia)->idProvincia;
}

void setNombreProvincia(PtrDato provincia, char* nombre){
    strcpy((((Provincia*)provincia)->nombreProvincia), nombre);
}

char* getNombreProvincia(PtrDato provincia){
    return  ((Provincia*)provincia)->nombreProvincia;
}


void setLstMesas(PtrDato provincia, Lista &lstMesas){
    ((Provincia*)provincia)->lstMesas = lstMesas;
}

Lista &getLstMesas(PtrDato provincia){
    return ((Provincia*)provincia)->lstMesas;
}


PtrNodoLista buscarProvinciaPorId(int id, Lista &lstProvincias){

    bool encontrado=false;
    PtrNodoLista cursor = primero(lstProvincias);


     while ((cursor != fin( )) && ( ! encontrado)){

           if (id==getIdProvincia(cursor->dato)){
                     encontrado=true;
                     }

           else cursor = siguiente(lstProvincias, cursor);
     }
           if (! encontrado ){
               cursor=fin();
                   }
    return cursor;

}




void cargarProvincias(Lista &lstProvincias){
      int id=0;
      char nombre[50];


      FILE *provincias;
      if((provincias=fopen("Provincias.txt","rt"))==NULL){
          perror("Error al abrir el fichero");
          system("PAUSE");
          }
      else{
           while(fscanf(provincias,"%i;%s\n",&id,&nombre)!= EOF){
              Provincia *provincia;
              provincia = new Provincia;
              crearProvincia(provincia);

              setIdProvincia(provincia, id);
              setNombreProvincia(provincia, nombre);

              //agrego a provincias

              if(buscarProvinciaPorId(id, lstProvincias)==fin()){
                    PtrNodoLista nodo = adicionarPrincipio(lstProvincias,provincia);
              }else{
                  printf("ERROR: Provincia %s tiene id duplicado\n",&nombre);
              }
            }

        }
}



