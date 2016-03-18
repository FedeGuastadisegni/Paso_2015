#ifndef _PROVINCIA_H_
#define _PROVINCIA_H_
#include "Lista.h"
#include "Mesa.h"
#include "Funciones.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <cstdlib>

#ifndef NULL
#define NULL      0
#endif

/* Definicion de los tipos de datos */

typedef struct {
    int idProvincia;
    char nombreProvincia[50];
    Lista lstMesas;
}Provincia;

/* Pre: la instancia del TDA provincia no tiene que estar creada.
 * Post: Instancia del TDA provincia creada y lista para ser utilizada.
 * provincia: estructura sobre la cual se invoca la primitiva.
*/

void crearProvincia(Provincia *provincia);

/* Pre: La instancia TDA Provincia tiene que estar creada y no tiene que estar destruida.
 * Post: La instancia TDA Provincia sera destruida y ya no podra utilizarse.
 * Provincia: estructura sobre la cual se invoca la primitiva.
 */

void destruirProvincia(Provincia provincia);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el id de la provincia.
 * provincia: estructura sobre la cual se invoca la primitiva.
 * idProvincia que va a tener el candidato.
*/

void setIdProvincia(PtrDato provincia, int idProvincia);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del id.
 * provincia: estructura sobre la cual se invoca la primitiva.
*/

int getIdProvincia(PtrDato provincia);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el nombre de la provincia.
 * provincia: estructura sobre la cual se invoca la primitiva.
 * nombre que va a tener el partido.
*/

void setNombreProvincia(PtrDato provincia, char* nombre);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del nombre.
 * provincia: estructura sobre la cual se invoca la primitiva.
*/

char* getNombreProvincia(PtrDato provincia);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: seteo la lista de mesas de la provincia.
*/

void setLstMesas(PtrDato provincia, Lista &lstMesas);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo la lista de mesas de la provincia.
*/

Lista &getLstMesas(PtrDato provincia);

/* Pre: la instancia del TDA provincias tiene que estar creada.
 * Post: carga en la lista las provincias predefinidas en el archivo de texto.
 * lstProvincias: listado de provincias.
*/

void cargarProvincias(Lista &lstProvincias);

/* Pre: la instancia del TDA Provincia tiene que estar creada.
 * Post: encuentra a la provincia , por el id pedido.
 * lstProvincias: listado de provincias.
 * id: identificador de la provincia deseada.
*/

PtrNodoLista buscarProvinciaPorId(int id, Lista &lstProvincias);


#endif // _PROVINCIA_H_
