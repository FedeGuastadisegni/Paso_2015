
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Conteo.h"

using namespace std;

void crearConteo(Conteo *conteo)
{
    conteo->idPartido=-1;
    conteo->idPartido=-1;
    conteo->idCandidato=-1;
    conteo->cantVotos=-1;
}

void destruirConteo(Conteo &conteo){
}

void setConteoIdProvincia(PtrDato conteo, int idProv)
{
    ((Conteo*)conteo)->idProvincia=idProv;
}

int getConteoIdProvincia(PtrDato conteo){
    return ((Conteo*)conteo)->idProvincia;
}

void setConteoIdPartido(PtrDato conteo, int idPart)
{
    ((Conteo*)conteo)->idPartido=idPart;
}

int getConteoIdPartido(PtrDato conteo)
{
    return ((Conteo*)conteo)->idPartido;
}

void setConteoIdCandidato(PtrDato conteo, int idCan)
{
    ((Conteo*)conteo)->idCandidato=idCan;
}

int getConteoIdCandidato(PtrDato conteo)
{
    return((Conteo*)conteo)->idCandidato;
}

void setcantVotos(PtrDato conteo, int cant)
{
    ((Conteo*)conteo)->cantVotos=cant;
}

int getcantVotos(PtrDato conteo)
{
    return ((Conteo*)conteo)->cantVotos;
}
