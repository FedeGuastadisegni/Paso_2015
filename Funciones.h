#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

#include "Lista.h"
#include "PartidoPolitico.h"
#include "Mesa.h"
#include "Voto.h"
#include "Conteo.h"


/*
Pre: c debe tener una direccion valida para una cadena de hasta 50 caracteres
Post: Obtiene de patnalla una cadena hasta 50 caracteres y se lo asigna a c.
*/
void getCadena(char* c);

/**-----------------------------------------------------*/
/*
Post: Pausa la impresion en pantalla.
*/

void pausar(void);
/**-----------------------------------------------------*/
/*
Post: retorna el valor de un entero y solo un entero, con o sin espacios antes o despues
*/
int getEntero(void);

/* Pre: ---
 * Post: genera un delay.
*/

void delay(int secs);

/* Pre: la lista de partidos debe estar creada.
 * Post: imprime los partidos que tenga la lista de partidos.
*/

void imprimirLstPartidos(Lista &lstPartidos);

/* Pre: la lista de partidos debe estar creada.
 * Post: valida que el  partido ingresado se valido(exista o que cumpla con las condiciones).
*/
bool validarPartido(int idPartido, Lista &lstPartidos);

/* Pre: la lista de candidatos debe estar creada.
 * Post: imprime los candidatos que tenga la lista de candidatos.
*/

void imprimirLstCandidatos(Lista &lstCandidatos);

/* Pre: la lista de partidos debe estar creada.
 * Post: valida que el  candidato ingresado exista en la lista de partidos.
*/

bool verificarCandidatoConPartido(Lista &lstCandidatos,Lista &lstPartidos);

/* Pre: la lista de provincias y mesas deben estar creadas.
 * Post: imprime las mesas por provincia.
*/

void imprimirLstProvinciasConMesas(Lista &lstProvincias);

/* Pre: la lista de mesas debe estar creada.
 * Post: imprime las mesas que tenga la lista de mesa.
*/

void imprimirLstMesas(Lista &lstMesas);

/* Pre: la lista de provincias debe estar creada.
 * Post: valida que mesa ingresada pertenezca a una provincia.
*/

bool verificarMesaConProvincia(Lista &lstMesas,Lista &lstProvincias);

/* Pre: la lista de votos debe estar creada.
 * Post: imprime los votos que tenga la lista de votos.
*/

void imprimirLstVotos(Lista &lstVotos, Lista &lstCandidatos);

/* Pre: la lista de provincia debe estar creada.
 * Post: imprime las provincias que tenga la lista de provincias.
*/

void imprimirLstProvincias(Lista &lstProvincias);

/* Pre: las listas deben estar creadas.
 * Post: acceso al menu de la votacion.
*/

void registroVotos(Lista &lstProvincias, Lista &lstMesas, Lista &lstCandidatos, Lista &lstPartidos, int c);

/* Pre: abm de candidatos.
 * Post:control del menu del candidato.
*/

void abmCandidatos(Lista &lstCandidatos, Lista &lstPartidos);

/* Pre: abm de partidos.
 * Post:control del menu de los partidos.
*/

void abmPartidos(Lista &lstPartidos, Lista &lstCandidatos);

/* Pre: abm de las mesas.
 * Post:control del menu de la mesa.
*/

void abmMesas(Lista &lstMesas, Lista &lstProvincias);

/* Pre: los tda de partidos y candidatos debe estar creada.
 * Post: imprime los candidatos por partidos politicos ordenados por partido.
*/

void imprimirLstCandidatosConPartidoOP(Lista &lstPartidos);

/* Pre: los tda de partidos y candidatos debe estar creada.
 * Post: imprime los candidatos ordenados alfabeticamente.
*/

void imprimirLstCandidatosConPartidoOC(Lista &lstCandidatos,Lista &lstPartidos);

/* Pre: Las listas deben estar creadas.
 * Post: Da de alta una mesa dentro de la funcion, sin pedir nuevamente los datos.
 */

int altaMesaEnFuncion(Lista &lstProvincia, Lista &lstMesas, Lista &lstCandidatos, Lista &lstPartidos,int idMesa);

/* Pre: Las listas deben estar creadas.
 * Post: Da de alta una Urna dentro de la funcion, sin pedir nuevamente los datos.
 */

void altaUrnaEnFuncion(Lista &lstProvincia, Lista &lstMesas, Lista &lstCandidatos, Lista &lstPartidos, int idProvincia, int idMesa,int c);

/* Pre: Los TDA y listas correspondientes deben estar creados con la funcion de comparacion correspondiente
 * Post: Devuelve un resultadoComparacion segun sea mayor, menor o igual.
 * Compara letras.
*/

ResultadoComparacion compararCandidato(PtrDato dat1,PtrDato dat2);

/* Pre: Los TDA y listas correspondientes deben estar creados con la funcion de comparacion correspondiente
 * Post: Devuelve un resultadoComparacion segun sea mayor, menor o igual.
 * Compara letras.
*/

ResultadoComparacion compararPartido(PtrDato dat1,PtrDato dat2);

/* Pre: Los TDA y listas correspondientes deben estar creados con la funcion de comparacion correspondiente
 * Post: Devuelve un resultadoComparacion segun sea mayor, menor o igual.
 * Compara ID.
*/

ResultadoComparacion compararProvincia(PtrDato dat1,PtrDato dat2);

/* Pre: Los TDA y listas correspondientes deben estar creados con la funcion de comparacion correspondiente
 * Post: Devuelve un resultadoComparacion segun sea mayor, menor o igual.
 * Compara ID.
*/

ResultadoComparacion compararMesa(PtrDato dat1,PtrDato dat2);

/* Pre: Los TDA y listas correspondientes deben estar creados con la funcion de comparacion correspondiente
 * Post: Devuelve un resultadoComparacion segun sea mayor, menor o igual.
 * Compara ID.
*/

ResultadoComparacion compararVoto(PtrDato dat1,PtrDato dat2);

/* Pre: Los TDA y listas correspondientes deben estar creados con la funcion de comparacion correspondiente
 * Post: Devuelve un resultadoComparacion segun sea mayor, menor o igual.
 * Compara ID.
*/

ResultadoComparacion compararConteo(PtrDato dat1,PtrDato dat2);

/* Pre: Todas las listas deben estar creadas.
 * Post: Llena la lista de conteo con los datos procesados de la votacion.
 */

void Procesar(Lista &lstConteo,Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos);

/* Pre: Todas las listas deben estar creadas.
 * Post: Acceso al menu de resultados.
 */

void menuResultados(Lista &lstConteo,Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos);

/* Pre: Las listas deben estar creadas, y la lista de conteo ya debe estar procesada.
 * Post: cantidad de voto por candidato
 */

void generalesCandidato(Lista &lstConteo,Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos);

/* Pre: Las listas deben estar creadas, y la lista de conteo ya debe estar procesada.
 * Post: cantidad de voto por Partido y candidato.
 */

void generalesPartidos(Lista &lstConteo, Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos);

/* Pre: Las listas deben estar creadas, y la lista de conteo ya debe estar procesada.
 * Post: cantidad de voto por provincia y candidato
 */

void provincialesCandidatos(Lista &lstConteo,Lista &lstProvincias,Lista &lstPartidos,Lista &lstCandidatos);

/* Pre: Las listas deben estar creadas, y la lista de conteo ya debe estar procesada.
 * Post: cantidad de voto por provincia y partido.
 */

void provincialesPartidos(Lista &lstConteo, Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos);

/* Pre: Las listas deben estar creadas, y la lista de conteo ya debe estar procesada.
 * Post: Candidatos por partido que tienen mas del 1,5 % de los votos
 */

void resultadosPASO(Lista &lstConteo, Lista &lstProvincias, Lista &lstPartidos, Lista &lstCandidatos);

#endif // _FUNCIONES_H_
