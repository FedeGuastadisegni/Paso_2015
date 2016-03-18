#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cctype>

#include "Candidato.h"
#include "Lista.h"
#include "Funciones.h"
#include "PartidoPolitico.h"
#include "Mesa.h"
#include "Urna.h"
#include "Voto.h"
#include "Provincia.h"


using namespace std;


void abmCandidatos(Lista &lstCandidatos, Lista &lstPartidos);
void abmPartidos(Lista &lstPartidos, Lista &lstCandidatos);
void abmMesas(Lista &lstMesas, Lista &lstProvincias);




int main()
{

    int c = 0;

    //Creacion de listas//
    Lista lstCandidatos, lstPartidos, lstMesas, lstProvincias, lstVotos,lstConteo;
    crearLista(lstCandidatos,(PFComparacion)compararCandidato);
    crearLista(lstPartidos,(PFComparacion)compararPartido);
    crearLista(lstProvincias,(PFComparacion)compararProvincia);
    crearLista(lstMesas,(PFComparacion)compararMesa);
    crearLista(lstVotos,(PFComparacion)compararVoto);
    crearLista(lstConteo,(PFComparacion)compararConteo);


    //Carga de datos desde los txt //
    cargarPartido(lstPartidos);
    cargarCandidatos(lstCandidatos,lstPartidos);
    cargarProvincias(lstProvincias);
    cargarMesas(lstProvincias,lstMesas);
    delay(2);

    printf("\t\tSe han cargado %d Candidatos exitosamente \n",longitud (lstCandidatos));
    printf("\t\tSe han cargado %d Partidos Politicos exitosamente \n",longitud (lstPartidos));
    printf("\t\tSe han cargado %d Provincias exitosamente \n",longitud (lstProvincias));
    printf("\t\tSe han cargado %d Mesas exitosamente \n",longitud (lstMesas));
    delay(1);
    printf("\t\t.");
    delay(1);
    printf("\t\t.");
    delay(1);
    printf("\t\t.");

    int opcion = 0;

    do{
             system("CLS");
             printf("\t\t* * * * * * PASO 2015! * * * * * *\n\n");
             printf("\n MENU PRINCIPAL\n");
             printf(" -------------- \n\n");
             printf("1. Administrar Partidos Politicos\n");
             printf("2. Administrar Candidatos\n");
             printf("3. Administrar Mesas\n");
             printf("4. Menu de Votacion\n");
             printf("5. Resultados\n");
             printf("6. Salir de la aplicacion\n");
             fflush(stdin);
             printf("\nSeleccione una de las opciones: ");
             scanf("%d",&opcion);
             switch (opcion)
             {

                case 1:
                    abmPartidos(lstPartidos,  lstCandidatos);
                    break;
                case 2:
                    abmCandidatos(lstCandidatos,lstPartidos);
                    break;

                case 3:
                    abmMesas(lstMesas,lstProvincias);
                    break;

                case 4:
                    registroVotos(lstProvincias,lstMesas, lstCandidatos,lstPartidos,c);
                    break;

                case 5:
                    Procesar(lstConteo,lstProvincias,lstPartidos,lstCandidatos);
                    menuResultados(lstConteo,lstProvincias,lstPartidos,lstCandidatos);


                    break;

                case 6:
                    if(verificarCandidatoConPartido(lstCandidatos,lstPartidos)){
                        system("CLS");
                        printf("El programa lo redireccionara al menu de partidos para que lo/s pueda asignar");
                        delay(3);
                        opcion = 0;
                        abmPartidos(lstPartidos,lstCandidatos);
                    }else if(verificarMesaConProvincia(lstMesas,lstProvincias)){
                         system("CLS");
                         printf("El programa lo redireccionara al menu de mesas para que lo/s pueda asignar");
                         delay(3);
                         opcion=0;
                         abmMesas(lstMesas,lstProvincias);
                    }else{
                    guardarCandidatos(lstCandidatos,lstPartidos);
                    guardarPartido(lstPartidos);
                    guardarMesa(lstMesas,lstProvincias);
                    eliminarLista(lstCandidatos);
                    eliminarLista(lstPartidos);
                    eliminarLista(lstProvincias);
                    eliminarLista(lstMesas);
                    eliminarLista(lstConteo);
                    eliminarLista(lstVotos);
                    }
                    break;

                    default:
                          {
                               system ("cls");
                               printf("Ingrese una opcion valida\n\n");
                               delay(2);
                               system("cls");
                            }
                 }


}while (opcion !=6);

    return EXIT_SUCCESS;
}




















