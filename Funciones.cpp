#include "Funciones.h"
#include "Lista.h"
#include <string.h>
#include <cstdio>
#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <conio.h>

/*-------------------------------------------------------------*/

void getCadena(char* s)
{
    fflush(stdin);
    fgets(s, 50, stdin);
    size_t ln = strlen(s) - 1;
    if (s[ln] == '\n')
    {
        s[ln] = '\0';
    }
}

/*-------------------------------------------------------------*/

void pausar(void)
{
    char* p = new char[500];
    std::cout << "Presione ENTER para continuar...";
    getCadena(p);
    delete p;

}

/*-------------------------------------------------------------*/

int getEntero(void)
{
    while (true)
    {
        // get line of text, returning INT_MAX on failure
        char * aux = new char[100];
        getCadena(aux);
        if (aux == NULL)
        {
            return INT_MAX;
        }

        // return an int if only an int (possibly with
        // leading and/or trailing whitespace) was provided
        int n;
        char c;
        if (sscanf(aux, " %d %c", &n, &c) == 1)
        {
            delete aux;
            return n;
        }
        else
        {
            delete aux;
            printf("Reintente: ");
        }
    }
}



void delay(int secs) {

      for(int i = (time(NULL) + secs);
        time(NULL) != i;
        time(NULL));
   }

void imprimirLstPartidos(Lista &lstPartidos){

    PtrNodoLista cursorAux=primero(lstPartidos);
    system ("cls");
    printf("Partidos Activos!: \n");
    while (cursorAux != fin()){

        printf("-> Id: %d",getIdPartido(cursorAux->dato));
        printf(" Nombre: %s \n",getNombre_partido(cursorAux->dato));
        cursorAux = siguiente(lstPartidos, cursorAux);

    }
    getch();


}


bool validarPartido(int idPartido, Lista &lstPartidos){
    bool encontrado = false;
    PtrNodoLista cursor = primero(lstPartidos);
    while(cursor != fin()){
        if(idPartido == getIdPartido(cursor->dato)){
            encontrado = true;
        }
        cursor = siguiente(lstPartidos,cursor);
    }
    return encontrado;
}

void imprimirLstCandidatos(Lista &lstCandidatos){

    PtrNodoLista cursorAux=primero(lstCandidatos);
    system ("cls");
    printf("*Lista de Candidatos: \n");
    while (cursorAux != fin()){

        printf("*Id: %d ",getIdCandidato(cursorAux->dato));
        printf(" Nombre: %s \n",getNombre_candidato(cursorAux->dato));
        cursorAux = siguiente(lstCandidatos, cursorAux);

        }
    getch();

}

void imprimirLstCandidatosConPartidoOP(Lista &lstPartidos){
    reordenar(lstPartidos);
    PtrNodoLista cursorAux = primero(lstPartidos);
    system("cls");
    while (cursorAux != fin()){
        PtrNodoLista cursor = primero(getLstCandidatos(cursorAux->dato));
        reordenar(getLstCandidatos(cursorAux->dato));
        printf("--> Partido: %s\n\n", getNombre_partido(cursorAux->dato));
        while(cursor != fin()){
            printf("*ID: %d",getIdCandidato(cursor->dato));
            printf(" Nombre y Apellido: %s\n\n", getNombre_candidato(cursor->dato));
            cursor = siguiente(getLstCandidatos(cursorAux->dato), cursor);
        }
        cursorAux = siguiente(lstPartidos,cursorAux);
    }
}

void imprimirLstCandidatosConPartidoOC(Lista &lstCandidatos,Lista &lstPartidos){
    reordenar(lstCandidatos);
    PtrNodoLista cursor = primero(lstCandidatos);
    system("CLS");
    while(cursor != fin()){

         PtrNodoLista partido = traerPartidoCandidato(getIdCandidato(cursor->dato),lstCandidatos,lstPartidos);
            if(partido != fin()){
                printf("->ID: %d ",getIdCandidato(cursor->dato));
                printf("Nombre y Apellido: %s ", getNombre_candidato(cursor->dato));
                printf("Partido: %s\n",getNombre_partido(partido->dato));
            }
        cursor = siguiente(lstCandidatos, cursor);
        }

}



bool verificarCandidatoConPartido(Lista &lstCandidatos,Lista &lstPartidos){
    bool noTienePartido = false;
    PtrNodoLista cursor = primero(lstCandidatos);
    while(cursor != fin()){
            PtrNodoLista partido = traerPartidoCandidato(getIdCandidato(cursor->dato),lstCandidatos,lstPartidos);
            if(partido == fin()){
                printf("%s no tiene partido\n",getNombre_candidato(cursor->dato));

                noTienePartido = true;
            }
        cursor = siguiente(lstCandidatos,cursor);
    }
    delay(6);
    return noTienePartido;
}


void imprimirLstProvinciasConMesas(Lista &lstProvincias){

    PtrNodoLista cursorAux=primero(lstProvincias);


    while (cursorAux != fin()){
        system ("cls");
        printf("Provincia: %s \n",getNombreProvincia(cursorAux->dato));
        imprimirLstMesas(getLstMesas(cursorAux->dato));
        system("PAUSE");
        cursorAux = siguiente(lstProvincias, cursorAux);

        }



}

void imprimirLstMesas(Lista &lstMesas){

    PtrNodoLista cursorAux=primero(lstMesas);

    if(longitud(lstMesas)==0){
        printf("Todavia no hay Mesas\n");
    }else{
        while (cursorAux != fin()){
            printf("*Id: %d",getIdMesa(cursorAux->dato));
            if(geturnaActiva(getUrna(cursorAux->dato))){
                printf("-> Urna Activa\n");
            }else{
                 printf("-> Urna Inactiva\n");
            }
            cursorAux = siguiente(lstMesas, cursorAux);
        }
    }

}


bool verificarMesaConProvincia(Lista &lstMesas,Lista &lstProvincias){
    bool noTienePartido = false;
    PtrNodoLista cursor = primero(lstMesas);
    while(cursor != fin()){
            PtrNodoLista partido = traerProvinciaMesa(getIdMesa(cursor->dato),lstMesas,lstProvincias);
            if(partido == fin()){
                printf("Mesa de ID: %d no tiene provincia\n",getIdMesa(cursor->dato));

                noTienePartido = true;
            }
        cursor = siguiente(lstMesas,cursor);
    }
    delay(6);
    return noTienePartido;
}

void imprimirLstVotos(Lista &lstVotos, Lista &lstCandidatos){

    PtrNodoLista cursorAux=primero(lstVotos);

    system ("cls");
    printf("Lista de Votos: \n");
    while (cursorAux != fin()){

        printf("\n\tId: %d\n",getIdVoto(cursorAux->dato));
        printf("\n\tId candidato: %d\n", getIdCandidatoVoto(cursorAux->dato));
        PtrNodoLista cursorNombre=buscarCandidatoPorId(getIdCandidatoVoto(cursorAux->dato), lstCandidatos);
        printf("\tnombre: %s \n",getNombre_candidato(cursorNombre->dato));
        cursorAux = siguiente(lstCandidatos, cursorAux);

        }
         system("PAUSE");

}

void imprimirLstProvincias(Lista &lstProvincias){
    reordenar(lstProvincias);
    PtrNodoLista cursorAux=primero(lstProvincias);

    while (cursorAux != fin()){
            printf("*Id: %d  ",getIdProvincia(cursorAux->dato));
            printf("*  Provincia : %s\n", getNombreProvincia(cursorAux->dato));
            cursorAux = siguiente(lstProvincias, cursorAux);
        }


}

int altaMesaEnFuncion(Lista &lstProvincia, Lista &lstMesas, Lista &lstCandidatos, Lista &lstPartidos,int idMesa){

     bool encontrado=false;
     Mesa *mesa = new Mesa;
     crearMesa(mesa);

     system ("CLS");

     PtrNodoLista cursor = primero(lstMesas);
     while ((cursor != fin( )) && (! encontrado)){
        if (getIdMesa(cursor->dato)==idMesa){
            encontrado=true;
            system("cls");
            printf("El numero de ID que ingreso ya esta siendo usado por una mesa en otra provincia\n\n");
            printf("Ingrese de nuevo el id: ");
            scanf("%d",&idMesa);
            encontrado = false;
            }

        else cursor = siguiente(lstMesas, cursor);
    }
        if (!encontrado){

         cursor=fin( );

         setIdMesa(mesa, idMesa);


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

         return idMesa;

     }

}


void altaUrnaEnFuncion(Lista &lstProvincia, Lista &lstMesas, Lista &lstCandidatos, Lista &lstPartidos, int idProvincia, int idMesa,int c){

    bool encontrado = true;
    int idUrna = 0;
    char horaApertura[40];
    char horaCierre[40];
    system("CLS");

    PtrNodoLista provincia = buscarProvinciaPorId(idProvincia,lstProvincia);

    PtrNodoLista nodoMesa = primero(getLstMesas(provincia->dato));

    while(nodoMesa != fin() && (encontrado)){
        if (getIdMesa(nodoMesa->dato)==idMesa){
            encontrado=false;
            }
        else nodoMesa = siguiente(getLstMesas(provincia->dato), nodoMesa);

        if(nodoMesa==fin() && encontrado)
        {
            printf("la Mesa que ingreso no es valida\n\n");
            printf("Ingrese de nuevo el id:  ");
            scanf("%d",&idMesa);
            encontrado = true;
            nodoMesa = primero(getLstMesas(provincia->dato));
        }
    }

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

    setUrna(nodoMesa->dato,urna);

    system("CLS");
    printf("Urna asignada!\n");
    printf("ID: %d\n", getIdUrna((((Mesa*)nodoMesa->dato)->urna)));
    printf("Hora de Apertura: %s HS\n", getHoraApertura((((Mesa*)nodoMesa->dato)->urna)));
    printf("Hora de Cierre: %s HS\n",getHoraCierre((((Mesa*)nodoMesa->dato)->urna)));

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


ResultadoComparacion compararCandidato(PtrDato dat1,PtrDato dat2){
    if(getNombre_candidato(dat1)[0] > getNombre_candidato(dat2)[0]){
        return MAYOR;
    }else if(getNombre_candidato(dat1)[0] < getNombre_candidato(dat2)[0]){
        return MENOR;
    }else{
        return IGUAL;
    }
}

ResultadoComparacion compararPartido(PtrDato dat1,PtrDato dat2){
    if(getNombre_partido(dat1)[0] > getNombre_partido(dat2)[0]){
        return MAYOR;
    }else if(getNombre_partido(dat1)[0] < getNombre_partido(dat2)[0]){
        return MENOR;
    }else{
        return IGUAL;
    }
}

ResultadoComparacion compararProvincia(PtrDato dat1,PtrDato dat2){
    if(getIdProvincia(dat1)> getIdProvincia(dat2)){
        return MAYOR;
    }else if(getIdProvincia(dat1)< getIdProvincia(dat2)){
        return MENOR;
    }else{
        return IGUAL;
    }
}

ResultadoComparacion compararMesa(PtrDato dat1,PtrDato dat2){
    if(getIdMesa(dat1)> getIdMesa(dat2)){
        return MAYOR;
    }else if(getIdMesa(dat1)< getIdMesa(dat2)){
        return MENOR;
    }else{
        return IGUAL;
    }
}

ResultadoComparacion compararVoto(PtrDato dat1,PtrDato dat2){
    if(getIdVoto(dat1)> getIdVoto(dat2)){
        return MAYOR;
    }else if(getIdVoto(dat1)< getIdVoto(dat2)){
        return MENOR;
    }else{
        return IGUAL;
    }
}


void registroVotos(Lista &lstProvincias, Lista &lstMesas, Lista &lstCandidatos, Lista &lstPartidos, int c)
{
    int opcion=0;
    system("cls");
    while(opcion!=4)
  {

    system("CLS");
    printf("\t\t*****Menu de Votacion!*****\n\n");
    printf("1.Alta urna\n");
    printf("2.Cierre de urna\n");
    printf("3.Votar\n");
    printf("4.Volver al menu principal\n\n");
    printf("Elija una de las opciones: ");
    scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
        altaUrna(lstProvincias,lstMesas,lstCandidatos,lstPartidos,c);
        reordenar(lstCandidatos);
    break;
    case 2:
        cierreUrna(lstProvincias,lstMesas,lstCandidatos,lstPartidos,c);
    break;
    case 3:
        votar(lstProvincias,lstMesas, lstCandidatos, lstPartidos,c);
    break;

    case 4:
        system("cls");
        printf("Volviendo al menu principal");
        delay(1);
        printf(".");
        delay(1);
        printf(".");
        delay(1);
        printf(".");
        delay(1);
        break;
    default: printf("Opcion no valida\n");
    }
  }
}


void abmCandidatos(Lista &lstCandidatos, Lista &lstPartidos){
      int opcion2=0;
      while(opcion2 != 5){
      system ("cls");
      printf("\t\t*****Menu de Candidatos!*****\n");
      printf("1. Alta Candidato\n");
      printf("2. Baja Candidato\n");
      printf("3. Modificar Candidato\n");
      printf("4. Mostrar todos los candidatos\n");
      printf("5. Volver\n");
      fflush(stdin);
      printf("\nSeleccione una de las opciones: ");
      scanf("%d",&opcion2);
      switch (opcion2){
        case 1:
            system("CLS");
            altaCandidato(lstCandidatos,lstPartidos);

        break;

        case 2:{
            system("CLS");
            bajaCandidato(lstCandidatos);
        }
        break;

        case 3:{
            system("CLS");
            modificarCandidato(lstCandidatos);
        }
        break;

        case 4:
            imprimirLstCandidatos(lstCandidatos);
            break;
        case 5:
            system("cls");
             printf("Volviendo al menu principal");
            delay(1);
            printf(".");
            delay(1);
            printf(".");
            delay(1);
            printf(".");
            delay(1);
            break;
        default: printf("Ingrese otra opcion!\n");

      }
    }
}

void abmPartidos(Lista &lstPartidos, Lista &lstCandidatos){

     int opcion2=0;
     int opcion3=0;
     while(opcion2!=5){
     system ("cls");
     printf("\t\t*****Menu de Partidos!*****\n");
     printf("1. Alta Partido\n");
     printf("2. Baja Partido\n");
     printf("3. Modificar Partido\n");
     printf("4. Mostrar todos los Partidos\n");
     printf("5. Volver\n");
     fflush(stdin);
     printf("\nSeleccione una de las opciones: ");
     scanf("%d",&opcion2);
     switch (opcion2){
        case 1:{
            system("cls");
            altaPartido(lstPartidos);
            }
            break;
        case 2:{
            system("cls");
            bajaPartido(lstPartidos);
            }
            break;
        case 3:{
            system("cls");
            imprimirLstPartidos(lstPartidos);
            printf("\n1. Agregar Candidato \n");
            printf("2. Modificar Partido \n");
            printf("\nSeleccione la opcion deseada: ");
            fflush(stdin);
            scanf("%d", &opcion3);
            switch(opcion3){
                case 1:{
                    system("cls");
                    int idPar=0;
                    int idCan=0;
                    bool flag=false;
                    PartidoPolitico *par = new PartidoPolitico;
                    Candidato *can = new Candidato;

                    do{

                    system("cls");
                    printf("\n0 para salir\ningrese el id del Partido: ");
                    fflush(stdin);
                    scanf("%d", &idPar);
                    PtrNodoLista puntero=buscarPartidoPorId(idPar, lstPartidos);
                    if(puntero!=fin()){
                    par=(PartidoPolitico*) puntero->dato;
                    flag=true;
                    system("cls");
                    }

                    if(!flag){
                        printf("ERROR: Partido no encontrado.");
                        delay(2);
                    }

                    }while (!flag && idPar !=0);



                    if (idPar==0)
                       break;


                    flag=false;

                   do{

                    system("cls");
                    printf("\n0 para salir\ningrese el id del Candidato: ");
                    fflush(stdin);
                    scanf("%d", &idCan);

                    PtrNodoLista punteroCan=buscarCandidatoPorId(idCan, lstCandidatos);
                    if(punteroCan!=fin()){
                    can=(Candidato*) punteroCan->dato;
                    flag=true;
                    system("cls");
                    }

                     if(!flag){
                        printf("ERROR: Candidato no encontrado.");
                        delay(2);
                    }

                    }while (!flag && idCan !=0);

                    if(!buscarPartidoCandidato(idCan, lstCandidatos, lstPartidos)){

                        if (idCan==0)
                            break;
                        agregarCandidato(par, (Candidato*) buscarCandidatoPorId(idCan, lstCandidatos)->dato);
                    }
                    else printf("\nEl Candidato pertenece a otro Partido");
                    delay(3);

                }
                break;

                case 2:{
                    modificarPartido(lstPartidos);
                }
            }


            }
            break;

        case 4:
            imprimirLstPartidos(lstPartidos);
            break;

        case 5:
            system("cls");
            printf("Volviendo al menu principal");
            delay(1);
            printf(".");
            delay(1);
            printf(".");
            delay(1);
            printf(".");
            delay(1);
            break;

        default:{
            system ("cls");
            printf("Ingrese una opcion valida\n\n");
            delay(2);
            system("cls");
            }

         }
     }

}

void abmMesas(Lista &lstMesas, Lista &lstProvincias){

    int opcion2=0;
     int opcion3=0;
     while(opcion2!=5){
     system ("cls");
     printf("\t\t*****Menu de Mesas!*****\n");
     printf("1. Alta Mesa\n");
     printf("2. Baja Mesa\n");
     printf("3. Agregar Mesa a Provincia\n");
     printf("4. Mostrar todos las Provincias con sus Mesas\n");
     printf("5. Volver\n");
     fflush(stdin);
     printf("\nSeleccione una de las opciones: ");
     scanf("%d",&opcion2);
     switch (opcion2){
        case 1:{
            system("cls");
            altaMesa(lstMesas,lstProvincias);
            }
            break;
        case 2:{
            system("cls");
            bajaMesa(lstMesas);
            }
            break;
        case 3:{
                system("cls");
                int idPro=0;
                int idMes=0;
                bool flag=false;
                Provincia *pro = new Provincia;
                Mesa *mes = new Mesa;

                    do{

                    system("cls");
                    printf("\n0 para salir\ningrese el id de la Provincia: ");
                    fflush(stdin);
                    scanf("%d", &idPro);
                    PtrNodoLista puntero=buscarProvinciaPorId(idPro, lstProvincias);
                    if(puntero!=fin()){
                    pro=(Provincia*) puntero->dato;
                    flag=true;
                    system("cls");
                    }

                    if(!flag){
                        printf("ERROR: Provincia no encontrada.");
                        delay(2);
                    }

                    }while (!flag && idPro !=0);



                    if (idPro==0)
                       break;


                    flag=false;

                   do{

                    system("cls");
                    printf("\n0 para salir\ningrese el id de la Mesa: ");
                    fflush(stdin);
                    scanf("%d", &idMes);

                    PtrNodoLista punteroMes=buscarMesaPorId(idMes, lstMesas);
                    if(punteroMes!=fin()){
                    mes=(Mesa*) punteroMes->dato;
                    flag=true;
                    system("cls");
                    }

                     if(!flag){
                        printf("ERROR: Mesa no encontrada.");
                        delay(2);
                    }

                    }while (!flag && idMes !=0);

                    if(!buscarProvinciaMesa(idMes, lstMesas, lstProvincias)){

                        if (idMes==0)
                            break;
                        agregarMesa(pro, (Mesa*) buscarMesaPorId(idMes, lstMesas)->dato);
                    }
                    else printf("\nLa mesa pertenece a otra Provincia");
                    delay(3);

                }
                break;


        case 4:
            imprimirLstProvinciasConMesas(lstProvincias);
            break;
        case 5:
            system("cls");
            printf("Volviendo al menu principal");
            delay(1);
            printf(".");
            delay(1);
            printf(".");
            delay(1);
            printf(".");
            delay(1);
            break;


        default:{
            system ("cls");
            printf("Ingrese una opcion valida\n\n");
            delay(2);
            system("cls");
            }

         }
     }

}


void Procesar(Lista &lstConteo,Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos)
{
    int idCand=0;
    int cont=0;
    int idPart=0;
    bool encontrado = false;
    PtrNodoLista nodoProv=primero(lstProvincias);

    system("cls");
    while(nodoProv != fin())
    {
        printf("->Procesando %s\n",getNombreProvincia(nodoProv->dato));
        delay(1);
        PtrNodoLista nodoMesa = primero(getLstMesas(nodoProv->dato));
            while (nodoMesa!=fin())
            {
                printf("Procesando Mesa %d\n",getIdMesa(nodoMesa->dato));
                delay(1);
                while(!colaVacia(getColaUrnas(nodoMesa->dato)))
                {
                    PtrDato urn = desencolar(getColaUrnas(nodoMesa->dato));
                    printf("Procesando Urna %d\n",getIdUrna(urn));
                    delay(1);
                    PtrNodoLista nodoVoto = primero(getLstVotos(urn));

                    while(nodoVoto != fin())
                    {

                          PtrNodoLista nodoConteo = primero(lstConteo);
                          encontrado = false;
                          while(nodoConteo != fin() && !encontrado){
                            if(getIdCandidatoVoto(nodoVoto->dato)== getConteoIdCandidato(nodoConteo->dato))
                            {
                              int i = getcantVotos(nodoConteo->dato);
                              setcantVotos(nodoConteo->dato,i+1);
                              encontrado = true;
                            }
                            nodoConteo = siguiente(getLstVotos(urn),nodoConteo);
                          }
                          if(!encontrado)
                          {
                            Conteo *conteo;
                            conteo = new Conteo;
                            setConteoIdProvincia(conteo, getIdProvincia(nodoProv->dato));
                            PtrNodoLista partido = traerPartidoCandidato(getIdCandidatoVoto(nodoVoto->dato),lstCandidatos,lstPartidos);
                            if(partido == fin()){
                                setConteoIdPartido(conteo,0);
                            }else{
                                setConteoIdPartido(conteo,getIdPartido(partido->dato));
                            }

                            setConteoIdCandidato(conteo,getIdCandidatoVoto(nodoVoto->dato));
                            setcantVotos(conteo,1);
                            adicionarFinal(lstConteo, conteo);

                          }


                          nodoVoto = siguiente(getLstVotos(urn),nodoVoto);
                        }

                }
                nodoMesa = siguiente(getLstMesas(nodoProv->dato),nodoMesa);
            }
             nodoProv = siguiente(lstProvincias,nodoProv);
        }

}

ResultadoComparacion compararConteo(PtrDato dat1,PtrDato dat2){
    if(getConteoIdCandidato(dat1)> getConteoIdCandidato(dat2)){
        return MAYOR;
    }else if(getConteoIdCandidato(dat1)< getConteoIdCandidato(dat2)){
        return MENOR;
    }else{
        return IGUAL;
    }
}


void menuResultados(Lista &lstConteo,Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos){
      int opcion2=0;

      while(opcion2 != 6){
      system ("cls");
      printf("\t\t*****Menu de Resultados***** \n\n");
      printf("1. Resultado de elecciones generales Candidatos \n");
      printf("2. Resultado de elecciones generales Partidos \n");
      printf("3. Resultado de las PASO\n");
      printf("4. Resultado de las elecciones a nivel provincial Candidatos \n");
      printf("5. Resultado de las elecciones a nivel provincial Partidos\n");
      printf("6. Volver\n");
      fflush(stdin);
      printf("\nSeleccione una de las opciones: ");
      scanf("%d",&opcion2);
      switch (opcion2){
        case 1:
            system("CLS");
            generalesCandidato(lstConteo,lstProvincias,lstPartidos,lstCandidatos);

        break;

        case 2:{
            system("CLS");
            generalesPartidos(lstConteo,lstProvincias,lstPartidos,lstCandidatos);
        }
        break;

        case 3:{
            system("CLS");
            resultadosPASO(lstConteo,lstProvincias,lstPartidos,lstCandidatos);
        }
        break;

        case 4:
            provincialesCandidatos(lstConteo,lstProvincias,lstPartidos,lstCandidatos);
            break;
        case 5:
            provincialesPartidos(lstConteo,lstProvincias,lstPartidos,lstCandidatos);
        break;
        case 6:
            system("cls");
            printf("Volviendo al menu principal");
            delay(1);
            printf(".");
            delay(1);
            printf(".");
            delay(1);
            printf(".");
            delay(1);
            break;
        default: printf("Ingrese otra opcion!\n");
      }
    }
}

void generalesCandidato(Lista &lstConteo,Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos){

    int total = 0;
    int opc;
    PtrNodoLista nodoConteo = primero(lstConteo);

    while(nodoConteo != fin()){
        total = total + getcantVotos(nodoConteo->dato);
        nodoConteo = siguiente(lstConteo,nodoConteo);
    }

    nodoConteo = primero(lstConteo);

    printf("1- Ordenado por candidato\n");
    printf("2- Ordenado por Cantidad de votos\n");
    scanf("%d",&opc);

    if(opc == 1){

        reordenar(lstConteo);

        while(nodoConteo != fin()){

         if(getConteoIdCandidato(nodoConteo->dato)!=0){

            PtrNodoLista candidato = buscarCandidatoPorId(getConteoIdCandidato(nodoConteo->dato),lstCandidatos);
            PtrNodoLista provincia = buscarProvinciaPorId(getConteoIdProvincia(nodoConteo->dato),lstProvincias);
            PtrNodoLista partido = buscarPartidoPorId(getConteoIdPartido(nodoConteo->dato),lstPartidos);

            printf("-> ID: %d", getConteoIdCandidato(nodoConteo->dato));
            printf(" Nombre: %s",getNombre_candidato(candidato->dato));
            printf(" Partido: %s ",getNombre_partido(partido->dato));
            printf(" Votos: %d \n",getcantVotos(nodoConteo->dato));
         }
        nodoConteo = siguiente(lstConteo,nodoConteo);
    }
    getch();

    }else if (opc == 2){

     PtrNodoLista actual,sig;
     actual = primero(lstConteo);
     int aux;
     PtrDato auxDato;
     while(siguiente(lstConteo,actual)!=NULL){
          sig=siguiente(lstConteo,actual);
          while(sig!=NULL){

                if(getcantVotos(actual->dato) > getcantVotos(sig->dato)){
                    aux = MAYOR;
                }else if(getcantVotos(actual->dato) < getcantVotos(sig->dato)){
                    aux = MENOR;
                }else{
                    aux = IGUAL;
                }

                if(aux==MENOR){
                   auxDato=actual->dato;
                   actual->dato=sig->dato;
                   sig->dato=auxDato;
                }
                sig=siguiente(lstConteo,sig);
          }
     actual=siguiente(lstConteo,actual);
     sig=siguiente(lstConteo,actual);
     }

     nodoConteo = primero(lstConteo);

     while(nodoConteo != fin()){

        if(getConteoIdCandidato(nodoConteo->dato)!=0){

            PtrNodoLista candidato = buscarCandidatoPorId(getConteoIdCandidato(nodoConteo->dato),lstCandidatos);
            PtrNodoLista provincia = buscarProvinciaPorId(getConteoIdProvincia(nodoConteo->dato),lstProvincias);
            PtrNodoLista partido = buscarPartidoPorId(getConteoIdPartido(nodoConteo->dato),lstPartidos);

            printf("-> ID: %d", getConteoIdCandidato(nodoConteo->dato));
            printf(" Nombre: %s",getNombre_candidato(candidato->dato));
            printf(" Partido: %s ",getNombre_partido(partido->dato));
            printf(" Votos: %d \n",getcantVotos(nodoConteo->dato));
         }

        nodoConteo = siguiente(lstConteo,nodoConteo);
    }
    getch();


    }



}

void generalesPartidos(Lista &lstConteo, Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos){

    reordenar(lstConteo);

    int total = 0;
    PtrNodoLista nodoConteo = primero(lstConteo);

    while(nodoConteo != fin()){
        total = total + getcantVotos(nodoConteo->dato);
        nodoConteo = siguiente(lstConteo,nodoConteo);
    }

    int opc;
    printf("1- Ordenado por Partido\n");
    printf("2- Ordenado por Partido y cantidad de votos\n");
    scanf("%d",&opc);

    if(opc == 1){

    PtrNodoLista nodoPart=primero(lstPartidos);
    reordenar(lstPartidos);
    system("cls");
    while(nodoPart!=fin())
    {
        bool entro = false;
        if(getIdPartido(nodoPart->dato)!=0){
        int idPart=getIdPartido(nodoPart->dato);
        nodoConteo=primero(lstConteo);

        printf("\nPartido: %s\n", getNombre_partido(nodoPart->dato));
        while(nodoConteo != fin()){

            PtrNodoLista candidato = buscarCandidatoPorId(getConteoIdCandidato(nodoConteo->dato),lstCandidatos);
            if(getConteoIdPartido(nodoConteo->dato)==idPart)
            {
            entro = true;
            printf("-> Nombre: %s",getNombre_candidato(candidato->dato));
            printf(" Votos: %d \n",getcantVotos(nodoConteo->dato));
            }
            nodoConteo = siguiente(lstConteo,nodoConteo);
        }

        }
        if(!entro){
            printf("-> No hubo votos en este partido!\n");
        }
    nodoPart=siguiente(lstPartidos,nodoPart);
    }
    getch();
    }else if(opc == 2){

    PtrNodoLista actual,sig;
     actual = primero(lstConteo);
     int aux;
     PtrDato auxDato;
     while(siguiente(lstConteo,actual)!=NULL){
          sig=siguiente(lstConteo,actual);
          while(sig!=NULL){

                if(getcantVotos(actual->dato) > getcantVotos(sig->dato)){
                    aux = MAYOR;
                }else if(getcantVotos(actual->dato) < getcantVotos(sig->dato)){
                    aux = MENOR;
                }else{
                    aux = IGUAL;
                }

                if(aux==MENOR){
                   auxDato=actual->dato;
                   actual->dato=sig->dato;
                   sig->dato=auxDato;
                }
                sig=siguiente(lstConteo,sig);
          }
     actual=siguiente(lstConteo,actual);
     sig=siguiente(lstConteo,actual);
     }

      PtrNodoLista nodoPart=primero(lstPartidos);
    reordenar(lstPartidos);
    while(nodoPart!=fin())
    {
        bool entro = false;
         if(getIdPartido(nodoPart->dato)!=0){
        int idPart=getIdPartido(nodoPart->dato);
        nodoConteo=primero(lstConteo);

        printf("\nPartido: %s\n", getNombre_partido(nodoPart->dato));
        while(nodoConteo != fin()){

            PtrNodoLista candidato = buscarCandidatoPorId(getConteoIdCandidato(nodoConteo->dato),lstCandidatos);
            if(getConteoIdPartido(nodoConteo->dato)==idPart)
            {
                entro = true;
            printf("-> Nombre: %s",getNombre_candidato(candidato->dato));
            printf(" Votos: %d \n",getcantVotos(nodoConteo->dato));
            }
            nodoConteo = siguiente(lstConteo,nodoConteo);
        }
      }
      if(!entro){
        printf("-> No hubo votos para este Partido!\n");
      }
        nodoPart=siguiente(lstPartidos,nodoPart);
    }
    getch();

    }
}

void provincialesCandidatos(Lista &lstConteo, Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos)
{

    reordenar(lstConteo);
    int total = 0;
    PtrNodoLista nodoConteo = primero(lstConteo);
    PtrNodoLista nodoProv = primero(lstProvincias);
    while(nodoConteo != fin()){
        total = total + getcantVotos(nodoConteo->dato);
        nodoConteo = siguiente(lstConteo,nodoConteo);
    }

    nodoConteo = primero(lstConteo);

    system("cls");
    while(nodoProv!=fin())
    {
        bool entro = false;
        nodoConteo=primero(lstConteo);
        printf("\nID:%d\tNombre: %s\n", getIdProvincia(nodoProv->dato),getNombreProvincia(nodoProv->dato));
        int idProv=getIdProvincia(nodoProv->dato);
        while(nodoConteo != fin()){
            if(getConteoIdCandidato(nodoConteo->dato)!=0){
            PtrNodoLista candidato = buscarCandidatoPorId(getConteoIdCandidato(nodoConteo->dato),lstCandidatos);
            PtrNodoLista partido = buscarPartidoPorId(getConteoIdPartido(nodoConteo->dato),lstPartidos);
            if(idProv==getConteoIdProvincia(nodoConteo->dato))
            {
                entro = true;
                printf("-> Nombre: %s",getNombre_candidato(candidato->dato));
                printf(" Partido: %s ",getNombre_partido(partido->dato));
                printf(" Votos: %d \n",getcantVotos(nodoConteo->dato));
            }

        }
         nodoConteo = siguiente(lstConteo,nodoConteo);
    }
        if(!entro){
            printf("-> No hubo votos en esta provincia!\n");
        }
        nodoProv=siguiente(lstProvincias,nodoProv);
    }
    getch();

}

void provincialesPartidos(Lista &lstConteo, Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos)
{
     reordenar(lstConteo);

    int total = 0;
    PtrNodoLista nodoConteo = primero(lstConteo);

    while(nodoConteo != fin())
    {
        total = total + getcantVotos(nodoConteo->dato);
        nodoConteo = siguiente(lstConteo,nodoConteo);
    }

    PtrNodoLista nodoProv=primero(lstProvincias);
    PtrNodoLista nodoPart=primero(lstPartidos);
    reordenar(lstPartidos);
    system("cls");
    while(nodoProv!=fin())
    {

        int idProv=getIdProvincia(nodoProv->dato);
        nodoPart=primero(lstPartidos);
        printf("\nID:%d\tProvincia: %s\n", getIdProvincia(nodoProv->dato),getNombreProvincia(nodoProv->dato));

        while(nodoPart!=fin())
        {
            bool entro2 = false;
            int idPart=getIdPartido(nodoPart->dato);
            nodoConteo=primero(lstConteo);

            printf("\nPartido: %s\n", getNombre_partido(nodoPart->dato));
            while(nodoConteo != fin())
            {
                if(getConteoIdCandidato(nodoConteo->dato)!=0){

                PtrNodoLista candidato = buscarCandidatoPorId(getConteoIdCandidato(nodoConteo->dato),lstCandidatos);
                if(getConteoIdProvincia(nodoConteo->dato)==idProv)
                {

                    if(getConteoIdPartido(nodoConteo->dato)==idPart)
                    {
                        entro2=true;
                        printf("-> Nombre: %s",getNombre_candidato(candidato->dato));
                        printf(" Votos: %d \n",getcantVotos(nodoConteo->dato));
                    }
                }
                }
                nodoConteo = siguiente(lstConteo,nodoConteo);
            }
            if(!entro2){
                printf("-> No hubo votos para %s en este partido!\n",getNombre_partido(nodoPart->dato));
            }
            nodoPart=siguiente(lstPartidos,nodoPart);
        }

        nodoProv=siguiente(lstProvincias,nodoProv);
    }
    getch();


}

void resultadosPASO(Lista &lstConteo, Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos)
{
    reordenar(lstConteo);

    int total = 0;
    PtrNodoLista nodoConteo = primero(lstConteo);

    while(nodoConteo != fin())
    {
        total = total + getcantVotos(nodoConteo->dato);
        nodoConteo = siguiente(lstConteo,nodoConteo);
    }
    nodoConteo=primero(lstConteo);
    float porc = 0;
    int opc;
    printf("1- Candidatos que superan el 1,5 porciento\n");
    printf("2- Candidatos que no superan el 1,5 porciento\n");
    scanf("%d",&opc);

    if(opc == 1){

    PtrNodoLista nodoProv=primero(lstProvincias);
    PtrNodoLista nodoPart=primero(lstPartidos);
    reordenar(lstPartidos);
    system("cls");
    printf("*Candidatos que superaron el 1,5 porciento de los votos: \n\n\n");
    while(nodoPart!=fin())
        {
            int idPart=getIdPartido(nodoPart->dato);
            int totalp=0;
            nodoConteo=primero(lstConteo);
            while(nodoConteo!=fin())
            {
                if(getConteoIdPartido(nodoConteo->dato)==idPart && getConteoIdPartido(nodoConteo->dato)!=0)
                {
                    totalp=totalp + getcantVotos(nodoConteo->dato);
                }
                nodoConteo=siguiente(lstConteo,nodoConteo);
            }
            nodoConteo=primero(lstConteo);
            printf("\nPartido: %s\n", getNombre_partido(nodoPart->dato));

            if(totalp==0)
            {
                printf("No hubo votos en este partido\n");
            }
            while(nodoConteo != fin())
            {

                PtrNodoLista candidato = buscarCandidatoPorId(getConteoIdCandidato(nodoConteo->dato),lstCandidatos);

                    if(getConteoIdPartido(nodoConteo->dato)==idPart)
                    {


                        int v = getcantVotos(nodoConteo->dato);
                        porc = (v*100)/totalp;
                        if(porc > 1.5)
                        {

                            printf("-> Nombre: %s",getNombre_candidato(candidato->dato));
                            printf(" Votos: %d ",getcantVotos(nodoConteo->dato));
                            printf(" Porcentaje: %.2f\n", porc);
                        }
                }

                nodoConteo = siguiente(lstConteo,nodoConteo);
            }
            nodoPart=siguiente(lstPartidos,nodoPart);
            porc = 0;
        }
        getch();

    }else if(opc == 2){

    PtrNodoLista nodoProv=primero(lstProvincias);
    PtrNodoLista nodoPart=primero(lstPartidos);
    reordenar(lstPartidos);
    system("cls");
    printf("*Candidatos que no superan el 1,5 porciento de los votos: \n\n\n");
    while(nodoPart!=fin())
        {
            int idPart=getIdPartido(nodoPart->dato);
            int totalp=0;
            nodoConteo=primero(lstConteo);
            while(nodoConteo!=fin())
            {
                if(getConteoIdPartido(nodoConteo->dato)==idPart  && getConteoIdPartido(nodoConteo->dato)!=0)
                {
                    totalp=totalp + getcantVotos(nodoConteo->dato);
                }
                nodoConteo=siguiente(lstConteo,nodoConteo);
            }
            nodoConteo=primero(lstConteo);
            printf("\nPartido: %s\n", getNombre_partido(nodoPart->dato));

            if(totalp==0)
            {
                printf("No hubo votos en este partido\n");
            }

            while(nodoConteo != fin())
            {

                PtrNodoLista candidato = buscarCandidatoPorId(getConteoIdCandidato(nodoConteo->dato),lstCandidatos);

                    if(getConteoIdPartido(nodoConteo->dato)==idPart)
                    {


                        int v = getcantVotos(nodoConteo->dato);
                        porc = (v*100)/totalp;
                        if(porc < 1.5)
                        {

                            printf("-> Nombre: %s",getNombre_candidato(candidato->dato));
                            printf(" Votos: %d ",getcantVotos(nodoConteo->dato));
                            printf(" Porcentaje: %.2f\n", porc);
                        }else{
                            printf("El candidato %s de este partido supero el 1,5 porciento!\n",getNombre_candidato(candidato->dato));
                        }
                }

                nodoConteo = siguiente(lstConteo,nodoConteo);
            }
            nodoPart=siguiente(lstPartidos,nodoPart);
            porc = 0;
        }
        getch();
    }


}


