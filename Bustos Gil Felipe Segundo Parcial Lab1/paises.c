#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include <time.h>
#include <string.h>
#include "paises.h"
#include "parser.h"
#include "informes.h"

void mostrarPais( LinkedList* lista,int indice)
{
    ePais* pais;
    pais = ll_get(lista, indice);

    printf("%4d    %10s   %12d     %12d   %12d\n", pais->id, pais->nombre,pais->recuperados, pais->infectados,pais->muertos);

}

int mostrarPaises( LinkedList* lista)
{
    int todoOk = 1;
    int tam;

    if(lista != NULL)
    {
        todoOk = 0;
        printf("  Id        Nombre        Recuperados      Infectados      Muertos\n");
        tam = ll_len(lista);

        for (int i=0; i<tam; i++)
        {
            mostrarPais(lista, i);
        }
    }
    else
    {
        printf("No hay paises que listar\n");
    }
    return todoOk;
}



int menuPrincipal()
{
    int opcion;
    system("cls");
    printf("**** MENU DE OPCIONES ****\n\n");
    printf("1- Cargar archivo\n");
    printf("2- Imprimir lista\n");
    printf("3- Asignar estadisticas\n");
    printf("4- Filtrar por paises exitosos\n");
    printf("5- Filtrar por paises en el horno\n");
    printf("6- Ordenar por nivel de infeccion\n");
    printf("7- Mostrar mas castigado\n");
    printf("8- Salir\n\n");
    printf("Indique la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);


    return opcion;
}

ePais* pais_new()
{
    ePais* newPais = (ePais*) malloc(sizeof(ePais));

    return newPais;
}
ePais* pais_newParamS(char* idStr, char* nombreStr, char* recuperadosStr,char* infectadosStr,char* muertosStr)
{
    return pais_newParametros(atoi(idStr),nombreStr,atoi(recuperadosStr),atoi(infectadosStr),atoi(muertosStr));
}



ePais* pais_newParametros(int id, char* nombre, int recuperados,int infectados,int muertos)
{
    ePais* newPais = pais_new();

        if(newPais != NULL)
        {
            pais_setId(newPais,id);
            pais_setNombre(newPais,nombre);
            pais_setRecuperados(newPais, recuperados);
            pais_setInfectados(newPais, infectados);
            pais_setMuertos(newPais, muertos);

        }
        else
        {
            free(newPais);
            newPais=NULL;
        }
        return newPais;
}

int pais_setId(ePais* this,int id)
{
    int todoOk = 1;
    if(this != NULL && id>0)
    {
        this->id = id;
        todoOk=0;
    }
    return todoOk;
}

int pais_getId(ePais* this,int* id)
{
    int todoOk = 1;

    if(this != NULL && id != NULL)
    {
       *id = this->id;
       todoOk = 0;
    }
    return todoOk;
}

int pais_setNombre(ePais* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL && strlen(nombre) <= 50)
    {
        strcpy(this->nombre,nombre);
        todoOk = 0;
    }
    return todoOk;
}

int pais_getNombre(ePais* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 0;
    }
    return todoOk;
}

int pais_setRecuperados(ePais* this,int recuperados)
{
    int todoOk = 1;

    if(this != NULL && recuperados >= 0)
    {
        this->recuperados = recuperados;
        todoOk = 0;
    }
    return todoOk;
}

int pais_getRecuperados(ePais* this,int* recuperados)
{
    int todoOk = 1;

    if(this != NULL && recuperados != NULL)
    {
        *recuperados = this->recuperados;
        todoOk = 0;
    }
    return todoOk;
}

int pais_setInfectados(ePais* this,int infectados)
{
    int todoOk = 1;

    if(this != NULL  && infectados>=0)
    {
        this->infectados = infectados;
        todoOk = 0;
    }
    return todoOk;
}

int pais_getInfectados(ePais* this,int* infectados)
{
    int todoOk = 1;

    if(this != NULL && infectados != NULL)
    {
        *infectados = this->infectados;
        todoOk = 0;
    }
    return todoOk;
}

int pais_setMuertos(ePais* this,int muertos)
{
    int todoOk = 1;

    if(this != NULL && muertos>=0)
    {
        this->muertos=muertos;
        todoOk = 0;
    }
    return todoOk;
}

int pais_getMuertos(ePais* this,int* muertos)
{
    int todoOk = 1;

    if(this != NULL && muertos != NULL)
    {
        *muertos = this->muertos;
        todoOk = 0;
    }
    return todoOk;
}

void* asignarCamposPiases(void* pElement)
{
    ePais* auxPais;
    auxPais = (ePais*) pElement;

    recuperadosSet(auxPais);
    infectadosSet(auxPais);
    muertosSet(auxPais);

    return auxPais;
}

int getRandomMuertos(void)
{
    int muertos;

    muertos = rand()% (1000-50000+1) + 1000;

    return muertos;
}

int getRandomInfectados(void)
{
    int infectados;

    infectados = rand()% (40000-2000000 + 1) + 40000;

    return infectados;
}

int getRandomRecuperados(void)
{
    int recuperados;
    recuperados = rand()% (50000 - 1000000 + 1) + 50000;

    return recuperados;
}

void muertosSet(void*muertos)
{

    ePais* muertes = NULL;

    if(muertos!=NULL){
        muertes = (ePais*)muertos;
        pais_setMuertos(muertes, getRandomMuertos());

    }

}

void infectadosSet(void*infectados)
{
    ePais* infectado = NULL;

    if(infectados!=NULL){
        infectado = (ePais*)infectados;
        pais_setInfectados(infectado, getRandomInfectados());

    }

}

void recuperadosSet(void*recuperados)
{

    ePais* recuperado = NULL;

    if(recuperados!=NULL){
        recuperado = (ePais*)recuperados;
       pais_setRecuperados(recuperado, getRandomRecuperados());

    }

}

int pais_setCampos(LinkedList* lista)
{
    int todoOk = 1;
    LinkedList* listaAsignada;

    if(lista != NULL)
    {
        listaAsignada = ll_map(lista,asignarCamposPiases);
        if(listaAsignada != NULL)
        {
            todoOk = 0;
            printf("Se asignaron los campos a los paises\n");
        }
        else
        {
            printf("No se pudieron asignar los campos a los paises\n");
        }
    }
    return todoOk;
}
