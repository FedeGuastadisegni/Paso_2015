/* TDA Candidato
 * archivo: Candidato.cpp
*/

#ifndef _CANDIDATO_H_
#define _CANDIDATO_H_

#include "Lista.h"

#ifndef NULL
#define NULL      0
#endif

/* Definicion de los tipos de datos */


typedef struct{
    int idCandidato;
    char nombre_candidato[40];
}Candidato;



/* Pre: la instancia del TDA Candidato no tiene que estar creada.
 * Post: Instancia del TDA Candidato creada y lista para ser utilizada.
 * Candidato: estructura sobre la cual se invoca la primitiva.
*/

void crearCandidato(Candidato  *candidato);

/* Pre: La instancia TDA Candidato tiene que estar creada y no tiene que estar destruida.
 * Post: La instancia TDA Candidato sera destruida y ya no podra utilizarse.
 * Candidato: estructura sobre la cual se invoca la primitiva.
 */

void destruirCandidato(Candidato  &candidato);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el id del candidato.
 * Candidato: estructura sobre la cual se invoca la primitiva.
 * id que va a tener el candidato.
*/

void setIdCandidato(PtrDato candidato,int idCandidato);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del id. Tiene que ser mayor que 0.
 * Candidato: estructura sobre la cual se invoca la primitiva.
*/

int getIdCandidato(PtrDato candidato);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el nombre del candidato.
 * Candidato: estructura sobre la cual se invoca la primitiva.
 * nombre que va a tener el partido.
*/

void setNombre_candidato(PtrDato candidato,char* nombre_candidato);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del nombre.
 * Candidato: estructura sobre la cual se invoca la primitiva.
*/

char* getNombre_candidato(PtrDato candidato);

/* Pre: la instancia del TDA Candidato tiene que estar creada.
 * Post: cargar un nuevo candidato  en la lista.
 * lstCandidatos: listado de candidatos
 * lstPartidos: listado de partidos
*/

void altaCandidato(Lista &lstCandidatos,Lista &lstPartidos);

/* Pre: la instancia del TDA Candidato , TDA Partidos tienen que estar creada.
 * Post: borra un  candidato en dicha lista.
 * lstCandidatos: listado de candidatos
*/

void bajaCandidato(Lista &lstCandidatos);

/* Pre: la instancia del TDA Candidato tiene que estar creada.
 * Post: encuentra al candidato , por el id pedido.
 * lstCandidatos: listado de candidatos.
 * id: identificador del candidato deseado.
*/

PtrNodoLista buscarCandidatoPorId(int id, Lista &lstCandidatos);

/* Pre: la instancia del TDA Candidato tiene que estar creada.
 * Post: realiza la modificacion especificada en dicha lista del candidato.
 * lstCandidatos: listado de candidatos.
*/

void modificarCandidato(Lista &lstCandidatos);

/* Pre: la instancia del TDA Candidato , TDA Partidos tienen que estar creada.
 * Post: busca el partido del candidato especificado.
 * lstCandidatos: listado de candidatos.
 * lstPartidos: listado de partidos.
 * idCandidato: identificador del candidato buscado.
*/

bool buscarPartidoCandidato(int idCandidato, Lista &lstCandidatos, Lista &lstPartidos);

/* Pre: la instancia del TDA Candidato , TDA Partidos tienen que estar creada.
 * Post: trae el partido del candidato especificado.
 * lstCandidatos: listado de candidatos.
 * lstPartidos: listado de partidos.
 * idCandidato: identificador del candidato buscado.
*/

PtrNodoLista traerPartidoCandidato(int idCandidato, Lista &lstCandidatos, Lista &lstPartidos);

/* Pre: la instancia del TDA Candidato , TDA Partidos tienen que estar creada.
 * Post: guarda al candidato en un nodo de la lista.
 * lstCandidatos: listado de candidatos.
 * lstPartidos: listado de partidos.
*/

void guardarCandidatos(Lista &lstCandidatos, Lista &lstPartidos);

/* Pre: la instancia del TDA Candidato , TDA Partidos tienen que estar creada.
 * Post: carga en la lista los candidatos predefinidos en el archivo de texto.
 * lstCandidatos: listado de candidatos.
 * lstPartidos: listado de partidos.
*/

void cargarCandidatos(Lista &lstCandidatos, Lista &lstPartidos);



#endif // _CANDIDATO_H_
