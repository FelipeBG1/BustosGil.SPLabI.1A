#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include <time.h>
#include <string.h>
#include "paises.h"
#include "parser.h"
#include "informes.h"


int paisComparaInfectados(void* a, void* b)
{
    int retorno=0;
    ePais* e1;
    ePais* e2;

    if(a != NULL && b != NULL)
    {
        e1 = (ePais*)a;
        e2 = (ePais*)b;

        if(e1->infectados > e2->infectados)
        {
           retorno=1;
        }
        else
        {
            if(e1->infectados < e2->infectados)
            {
                retorno= -1;
            }
        }
    }
    return retorno;
}


int ordenarNivelInfeccion(LinkedList* lista)
{
    int todoOk = -1;

    if(lista != NULL)
    {
        if(ll_sort(lista,paisComparaInfectados,0)==0)
        {
            printf("Se ordenaron los datos\n");
            todoOk = 0;
        }
        else
        {
            printf("No se pudieron ordenar los datos\n");
            todoOk = 1;
        }
    }
    return todoOk;
}

int comparaPaisesExitoso(void* pais)
{
    int todoOk = 1;
    ePais* x = NULL;

    if(pais!=NULL)
    {
        x = (ePais*)pais;
        if(x->muertos<5000)
        {
            todoOk=0;
        }
    }
    return todoOk;
}

int comparaPaisesHorno(void* pais)
{
    int todoOk = 1;
    ePais* x = NULL;

    if(pais!=NULL)
    {
        x = (ePais*)pais;
        if(x->infectados >= x->recuperados*3)
        {
            todoOk=0;
        }
    }
    return todoOk;
}

void mostrarCastigados(LinkedList* lista)
{
    ePais* auxPais;
    int auxMuertos;
    int maximoMuertos = 0;
    int flag = 0;

    if(lista != NULL)
    {

        for(int i = 0; i < ll_len(lista); i++)
        {
            auxPais = (ePais*) ll_get(lista,i);
            pais_getMuertos(auxPais,&auxMuertos);
            if(auxMuertos > maximoMuertos || !flag)
            {
                maximoMuertos = auxMuertos;
                flag = 1;
            }
        }

        printf("Mayor cantidad de muertos: %d\n",maximoMuertos);
        printf("  Id       Nombre        Recuperados      Infectados       Muertos\n");

        for(int i = 0; i < ll_len(lista); i++)
        {
            auxPais = (ePais*) ll_get(lista,i);
            pais_getMuertos(auxPais,&auxMuertos);

            if(auxMuertos >= maximoMuertos)
            {
                mostrarPais(lista,i);
            }
        }

    }

}
