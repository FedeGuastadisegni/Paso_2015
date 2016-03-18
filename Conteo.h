
#ifndef CONTEO_H_INCLUDED
#define CONTEO_H_INCLUDED
#include "Lista.h"
#include "PartidoPolitico.h"


#ifndef NULL
#define NULL      0
#endif

/* Definicion de los tipos de datos */

typedef struct{
    int idProvincia;
    int idPartido;
    int idCandidato;
    int cantVotos;
}Conteo;

/* Pre: la instancia del TDA Conteo no tiene que estar creada.
 * Post: Instancia del TDA Conteo creada y lista para ser utilizada.
 * Conteo: estructura sobre la cual se invoca la primitiva.
*/

void crearConteo(Conteo *conteo);

/* Pre: La instancia TDA Conteo tiene que estar creada y no tiene que estar destruida.
 * Post: La instancia TDA Conteo sera destruida y ya no podra utilizarse.
 * Conteo: estructura sobre la cual se invoca la primitiva.
 */

void destruirConteo(Conteo &conteo);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el id del conteo provincia.
 * Conteo: estructura sobre la cual se invoca la primitiva.
 * idProv que va a tener el conteo provincia.
*/

void setConteoIdProvincia(PtrDato conteo, int idProv);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del id.
 * Conteo: estructura sobre la cual se invoca la primitiva.
*/

int getConteoIdProvincia(PtrDato conteo);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el id del conteo partido.
 * Conteo: estructura sobre la cual se invoca la primitiva.
 * idPar que va a tener el conteo partido.
*/

void setConteoIdPartido(PtrDato conteo, int idPar);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del id.
 * Conteo: estructura sobre la cual se invoca la primitiva.
*/

int getConteoIdPartido(PtrDato conteo);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el id del conteo candidato.
 * Conteo: estructura sobre la cual se invoca la primitiva.
 * idCan que va a tener el conteo candidato.
*/

void setConteoIdCandidato(PtrDato conteo, int idCan);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del id.
 * Conteo: estructura sobre la cual se invoca la primitiva.
*/

int getConteoIdCandidato(PtrDato conteo);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo la cantidad de votos.
 * Conteo: estructura sobre la cual se invoca la primitiva.
 * cant que va a tener el conteo provincia.
*/

void setcantVotos(PtrDato conteo, int cant);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor de la cantidad de votos.
 * Conteo: estructura sobre la cual se invoca la primitiva.
*/

int getcantVotos(PtrDato conteo);



#endif // CONTEO_H_INCLUDED
