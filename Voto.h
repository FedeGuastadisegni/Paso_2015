/* TDA voto
 * Archivo: Voto.cpp
 */

 #ifndef _VOTO_H_
 #define _VOTO_H_
 #include "Mesa.h"
 #include "Candidato.h"
 #include "PartidoPolitico.h"

#ifndef NULL
#define NULL      0
#endif

/* Definicion de los tipos de datos */


typedef struct {
    int idVoto;
    int idCandidato;
}Voto;


/* Pre: la instancia del TDA voto no tiene que estar creada.
 * Post: Instancia del TDA voto creada y lista para ser utilizada.
 * voto: estructura sobre la cual se invoca la primitiva.
*/

void crearVoto(Voto *voto);

/* Pre: La instancia TDA voto tiene que estar creada y no tiene que estar destruida.
 * Post: La instancia TDA voto sera destruida y ya no podra utilizarse.
 * voto: estructura sobre la cual se invoca la primitiva.
 */

void destruirVoto(Voto voto);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el id del voto.
 * voto: estructura sobre la cual se invoca la primitiva.
 * idVoto que va a tener el voto.
*/

void setIdVoto(PtrDato voto, int idVoto);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del id.
 * voto: estructura sobre la cual se invoca la primitiva.
*/

int getIdVoto(PtrDato voto);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el id del candidato del voto
 * voto: estructura sobre la cual se invoca la primitiva.
 * idCandidato que va a tener el candidato en el voto.
*/

void setIdCandidatoVoto(PtrDato voto,int idCandidato);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del id del candidato.
 * voto: estructura sobre la cual se invoca la primitiva.
*/

int getIdCandidatoVoto(PtrDato voto);

/* Pre: las listas deben estar creadas.
 * Post: permite, mediante la seleccion de una provincia y de una mesa, realizar un voto en una urna activa.
 */

void votar(Lista &lstProvincias, Lista &lstMesas, Lista &lstCandidatos, Lista &lstPartidos,int c);

 #endif // _VOTO_H_
