#ifndef _PARTIDOPOLITICO_H_
#define _PARTIDOPOLITICO_H_

#include "Lista.h"
#include "Candidato.h"


#ifndef NULL
#define NULL      0
#endif

/* Definicion de los tipos de datos */


typedef struct {
    int idPartido;
    char nombre_partido[40];
    Lista lstCandidatos;
}PartidoPolitico;


/* Pre: la instancia del TDA PartidoPolitico no tiene que estar creada.
 * Post: Instancia del TDA PartidoPolitico creada y lista para ser utilizada.
 * PartidoPolitico: estructura sobre la cual se invoca la primitiva.
*/

void crearPartido(PartidoPolitico *partidoPolitico);

/* Pre: La instancia TDA PartidoPolitico tiene que estar creada y no tiene que estar destruida.
 * Post: La instancia TDA PartidoPolitico sera destruida y ya no podra utilizarse.
 * PartidoPolitico: estructura sobre la cual se invoca la primitiva.
 */

void destruirPartido(PartidoPolitico &partidoPolitico);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el id del partido.
 * PartidoPolitico: estructura sobre la cual se invoca la primitiva.
 * id que va a tener el partido (posiblemente deberia autogenerarla cuando este en la lista).
*/

void setIdPartido(PtrDato partidoPolitico,int idPartido);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del id.
 * PartidoPolitico: estructura sobre la cual se invoca la primitiva.
*/

int getIdPartido(PtrDato partidoPolitico);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el nombre del partido.
 * PartidoPolitico: estructura sobre la cual se invoca la primitiva.
 * nombre que va a tener el partido.
*/

void setNombre_partido(PtrDato partidoPolitico,char* nombre_partido);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del nombre.
 * PartidoPolitico: estructura sobre la cual se invoca la primitiva.
*/

char* getNombre_partido(PtrDato partidoPolitico);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: seteo la lista de candidatos al partido
*/

void setLstCandidatos(PtrDato partidoPolitico,Lista &lstCandidatos);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo la lista de candidatos del partido seleccionado.
 */

Lista &getLstCandidatos(PtrDato partidoPolitico);

/* Pre: la instancia del TDA partidoPolitico tiene que estar creada.
 * Post: cargar un nuevo Partido politico  en la lista.
 * lstPartidos: listado de partidos.
*/

void altaPartido(Lista &lstPartidos);

/* Pre: la instancia del TDA partido debe estar creada.
 * Post: borra un  partido de la lista.
 * lstPartidos: listado de candidatos
*/

void bajaPartido(Lista &lstPartidos);

/* Pre: la instancia del TDA partido tiene que estar creada.
 * Post: realiza la modificacion especificada en dicha lista del partido.
 * lstPartido: listado de candidatos.
*/

void modificarPartido(Lista &lstPartido);

/* Pre: la instancia del TDA partido debe estar creada
 * Post: carga en la lista los partidos predefinidos en el archivo de texto.
 * lstPartidos: listado de partidos.
*/

void cargarPartido(Lista &lstPartidos);

/* Pre: la instancia del TDA partido debe estar creada
 * Post: guarda al partido en un nodo de la lista.
 * lstPartidos: listado de partidos.
*/

void guardarPartido(Lista &lstPartidos);

/* Pre: la instancia del TDA partido tiene que estar creada.
 * Post: encuentra al partido , por el id pedido.
 * lstPartidos: listado de candidatos.
 * id: identificador del candidato deseado.
*/

PtrNodoLista buscarPartidoPorId(int id, Lista &lstPartidos);

/* Pre: la instancia de partido debe estar creada.
 * Post: asigna un candidato al partido indicado.
 */

void agregarCandidato(PtrDato partido, Candidato *candidato);






#endif // _PARTIDOPOLITICO_H_
