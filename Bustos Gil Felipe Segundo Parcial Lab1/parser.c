#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include <time.h>
#include <string.h>
#include "paises.h"
#include "parser.h"
#include "informes.h"

int controller_loadFromText(char* path , LinkedList* pArrayListArticulos)
{
    int todoOk = 1;

    FILE* f = fopen(path,"r");

    if(f != NULL)
    {
        if(parser_PaisFromText(f,pArrayListArticulos)==0)
        {
            todoOk = 0;
            printf("Se cargaron los datos\n");
        }
        else
        {
            printf("No se pudieron cargar los datos\n");
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
    }

    fclose(f);

    return todoOk;
}

int parser_PaisFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    int cant;
    char cadena[5][51];
    //char genero;

    ePais* newPais = (ePais*) pais_new();

    if (pFile == NULL || pArrayListEmployee == NULL)
    {
        return todoOk;
    }
    else
    {
        ll_clear(pArrayListEmployee);
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]",cadena[0], cadena[1], cadena[2], cadena[3],cadena[4]);

    while(!feof(pFile))
    {

        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",cadena[0], cadena[1], cadena[2], cadena[3],cadena[4]);

        if (cant == 5)
        {
            newPais = pais_newParamS(cadena[0], cadena[1], cadena[2], cadena[3],cadena[4]);

            if (newPais != NULL)
            {
                ll_add(pArrayListEmployee, newPais);
                todoOk = 0;
            }
        }

    }


    return todoOk;

}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;

	FILE* pFile;
	int auxId;
	char auxNombre[51];
	int auxRecuperados;
	int auxInfectados;
	int auxMuertos;

	ePais* pPais;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{

			fprintf(pFile, "id ,Nombre,Recuperados,Infectados,Muertos\n");
			for(int i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				pPais = ll_get(pArrayListEmployee, i);

				if(!pais_getId(pPais, &auxId) &&
				   !pais_getNombre(pPais, auxNombre) &&
				   !pais_getRecuperados(pPais, &auxRecuperados) &&
				   !pais_getInfectados(pPais, &auxInfectados) &&
                   !pais_getMuertos(pPais, &auxMuertos))
				{
                    fprintf(pFile, "%d,%s,%d,%d,%d\n", auxId, auxNombre, auxRecuperados, auxInfectados, auxMuertos);
                    todoOk = 0;

				}
			}
			fclose(pFile);
		}
	}

    return todoOk;
}
