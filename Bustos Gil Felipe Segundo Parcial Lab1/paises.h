#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    int recuperados;
    int infectados;
    int muertos;

}ePais;

void mostrarPais( LinkedList* lista,int indice);
int mostrarPaises( LinkedList* lista);
int menuPrincipal();
ePais* pais_new();

ePais* pais_newParametros(int id,char* nombre,int recuperados, int infectados,int muertos);
int pais_setId(ePais* this,int id);
int pais_getId(ePais* this,int* id);
int pais_setNombre(ePais* this,char* nombre);
int pais_getNombre(ePais* this,char* nombre);
int pais_setRecuperados(ePais* this,int recuperados);
int pais_getRecuperados(ePais* this,int* recuperados);
int pais_setInfectados(ePais* this,int infectados);
int pais_getInfectados(ePais* this,int* infectados);
int pais_setMuertos(ePais* this,int muertos);
int pais_getMuertos(ePais* this,int* muertos);
ePais* pais_newParamS(char* idStr, char* nombreStr, char* recuperadosStr,char* infectadosStr,char* muertosStr);
ePais* aplicarDatos(void* pElement);
int getDatosAleatorios(int desde,int hasta);
int pais_setCampos(LinkedList* lista);
void* asignarCamposPiases(void* pElement);
int getRandomMuertos(void);
int getRandomInfectados(void);
int getRandomRecuperados(void);
void muertosSet(void*muertos);
void infectadosSet(void*infectados);
void recuperadosSet(void*recuperados);


#endif // PAISES_H_INCLUDED
