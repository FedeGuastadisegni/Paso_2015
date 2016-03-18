#ifndef _MESA_H_
#define _MESA_H_
#include "Cola.h"
#include "Lista.h"
#include "Provincia.h"
#include "Urna.h"

#ifndef NULL
#define NULL      0
#endif

/* Definicion de los tipos de datos */

typedef struct {
    int idMesa;
    Urna *urna;
    Cola colaUrnas;
}Mesa;

/* Pre: la instancia del TDA Mesa no tiene que estar creada.
 * Post: Instancia del TDA Mesa creada y lista para ser utilizada.
 * Mesa: estructura sobre la cual se invoca la primitiva.
*/

void crearMesa(Mesa *mesa);

/* Pre: La instancia TDA Mesa tiene que estar creada y no tiene que estar destruida.
 * Post: La instancia TDA Mesa sera destruida y ya no podra utilizarse.
 * Mesa: estructura sobre la cual se invoca la primitiva.
 */

void destruirMesa(Mesa mesa);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo el id de la Mesa.
 * Mesa: estructura sobre la cual se invoca la primitiva.
 * idMesa que va a tener el candidato.
*/

void setIdMesa(PtrDato mesa,int idMesa);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo que valor del id.
 * mesa: estructura sobre la cual se invoca la primitiva.
*/

int getIdMesa(PtrDato mesa);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo la cola de urnas de la mesa.
 * Mesa: estructura sobre la cual se invoca la primitiva.
 * colaUrnas: cola de urnas asignada.
*/

void setColaUrnas(PtrDato mesa,Cola &colaUrnas);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo la cola de urnas de la mesa.
 * mesa: estructura sobre la cual se invoca la primitiva.
*/

Cola &getColaUrnas(PtrDato mesa);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: Seteo la urna de la mesa.
 * Mesa: estructura sobre la cual se invoca la primitiva.
 * urna: urna que se le asigna a la mesa.
*/

void setUrna(PtrDato mesa, Urna *urna);

/* Pre: la instancia TDA tiene que estar creada y no tiene que estar destruida.
 * Post: obtengo la urna de la mesa.
 * mesa: estructura sobre la cual se invoca la primitiva.
*/

Urna* getUrna(PtrDato mesa);

/* Pre: la instancia del TDA Mesa tiene que estar creada.
 * Post: cargar una nueva mesa  en la lista.
 * lstMesas: listado de mesas.
 * lstProvincia: listado de provincias
*/

int altaMesa(Lista &lstMesas,Lista &lstProvincias);

/* Pre: la instancia del TDA mesa , TDA provincia tienen que estar creada.
 * Post: borra una mesa en dicha lista.
 * lstMesas: listado de candidatos
*/

void bajaMesa(Lista &lstMesas);

/* Pre: la instancia del TDA Mesa tiene que estar creada.
 * Post: encuentra a la mesa , por el id pedido.
 * lstMesas: listado de mesas.
 * id: identificador de la mesa deseada.
*/

PtrNodoLista buscarMesaPorId(int id, Lista &lstMesas);

/* Pre: la instancia del TDA Mesa , TDA Provincia tienen que estar creada.
 * Post: trae la provincia de la mesa especificada.
 * lstMesas: listado de mesas.
 * lstProvincias: listado de provincias.
 * idMesa: identificador de la mesa buscada.
*/

PtrNodoLista traerProvinciaMesa(int idMesa, Lista &lstMesas, Lista &lstProvincias);

/* Pre: la instancia del TDA Mesa , TDA Provincias tienen que estar creada.
 * Post: carga en la lista las mesas predefinidas en el archivo de texto.
 * lstMesas: listado de mesas.
 * lstProvincias: listado de provincias.
*/

void cargarMesas(Lista &lstProvincias, Lista &lstMesas);

/* Pre: la instancia del TDA Mesa , TDA Provincias tienen que estar creada.
 * Post: guarda las mesas en el archivo de texto.
 * lstMesas: listado de mesas.
 * lstProvincias: listado de provincias.
*/

void guardarMesa(Lista &lstMesas,Lista &lstProvincias);

/* Pre: la instancia de mesa debe estar creada.
 * Post: asigna una mesa a la provincia indicada.
 */

void agregarMesa(PtrDato provincia, Mesa *mesa);

/* Pre: las listas deben estar creadas.
 * Post: devuelve true si existe la mesa en la provincia.
*/

bool buscarProvinciaMesa(int idMesa, Lista &lstMesas, Lista &lstProvincias);


#endif // _MESA_H_
