#ifndef _URNA_H_
#define _URNA_H_

#include <string>
#include "Lista.h"

#ifndef NULL
#define NULL      0
#endif


/* Definicion de los tipos de datos */

typedef struct {
    int idUrna;
    char horaApertura[40];
    char horaCierre[40];
    bool urnaActiva;
    Lista lstVotos;
}Urna;

/* Pre: la instancia del TDA Urna no tiene que estar creada.
 * Post: Instancia del TDA Urna creada y lista para ser utilizada.
 * Urna: estructura sobre la cual se invoca la primitiva.
*/

void crearUrna(Urna *urna);

/* Pre: La instancia TDA Urna tiene que estar creada y no tiene que estar destruida.
 * Post: La instancia TDA Urna sera destruida y ya no podra utilizarse.
 * Urna: estructura sobre la cual se invoca la primitiva.
 */

void destruirUrna(Urna *urna);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el id de la Urna.
 * Urna: estructura sobre la cual se invoca la primitiva.
 * idUrna que va a tener la urna.
*/

void setIdUrna(PtrDato urna,int idUrna);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del id.
 * urna: estructura sobre la cual se invoca la primitiva.
*/

int getIdUrna(PtrDato urna);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo la hora de apertura de la Urna.
 * Urna: estructura sobre la cual se invoca la primitiva.
 * horaApertura que va a tener la urna
*/

void setHoraApertura(PtrDato urna,char horaApertura[40]);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo la hora de apertura
 * urna: estructura sobre la cual se invoca la primitiva.
*/

char* getHoraApertura(PtrDato urna);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo la hora de cierre de la Urna.
 * Urna: estructura sobre la cual se invoca la primitiva.
 * horaCierre que va a tener la urna
*/

void setHoraCierre(PtrDato urna,char horaCierre[40]);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo la hora de cierre
 * urna: estructura sobre la cual se invoca la primitiva.
*/

char* getHoraCierre(PtrDato urna);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo si la urna esta activa (true).
 * Urna: estructura sobre la cual se invoca la primitiva.
 * urnaActiva true o false segun corresponda.
*/

void seturnaActiva(PtrDato urna, bool urnaActiva);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo si esta activa o no
 * urna: estructura sobre la cual se invoca la primitiva.
*/

bool geturnaActiva(PtrDato urna);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo la lista de votos de una urna
 * Urna: estructura sobre la cual se invoca la primitiva.
 * lstVotos listado de votos.
*/

void setLstVotos(PtrDato urna, Lista &lstVotos);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo la lista de votos.
 * urna: estructura sobre la cual se invoca la primitiva.
*/

Lista &getLstVotos(PtrDato urna);

/* Pre: las listas deben estar creadas.
 * Post: cierro la urna, la encolo y la destruyo.
 */

void cierreUrna(Lista &lstProvincia,Lista &lstMesas, Lista &lstCandidatos, Lista &lstPartidos,int c);

/* Pre: Las listas deben estar creadas.
 * Post: abro una urna en la provincia y mesa seleccionada.
 */

void altaUrna(Lista &lstProvincia, Lista &lstMesas, Lista &lstCandidatos, Lista &lstPartidos,int c);



#endif // _URNA_H_

