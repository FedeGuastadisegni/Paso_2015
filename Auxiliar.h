#ifndef _AUXILIAR_H_
#define _AUXILIAR_H_

#ifndef NULL
#define NULL      0
#endif

typedef struct{
    int idCandidato;
    int idProvincia;
    int idPartido;
    int contVot;
}Auxiliar;

void crearAuxiliar(Auxiliar *auxiliar);







#endif // _AUXILIAR_H_
