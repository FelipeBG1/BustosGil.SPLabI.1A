#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include <time.h>
#include <string.h>
#include "paises.h"
#include "parser.h"
#include "informes.h"


int main()
{
    char seguir = 's';
    char confirma;
    int flagCarga=0;
    int flagCargaConDatos=0;
    srand (time(NULL));
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaPaisesExitosos=ll_newLinkedList();
     LinkedList* listaPaisesHorno=ll_newLinkedList();


    do
    {
        switch(menuPrincipal())
        {
       case 1:
           if(controller_loadFromText("pandemia.csv",lista)==0)
           {
               flagCarga=1;
           }
        break;
       case 2:
           if(flagCarga || flagCargaConDatos)
           {
                mostrarPaises(lista);
           }
           else
           {
               printf("Primero debe cargar los datos\n\n");
           }


        break;
       case 3:
           if(flagCarga)
           {
               if(pais_setCampos(lista)==0)
               {
                   flagCargaConDatos=1;
               }
           }
           else
           {
               printf("Primero debe cargar los datos\n\n");
           }

        break;
       case 4:
           if(flagCargaConDatos)
           {
               listaPaisesExitosos=ll_filter(lista,comparaPaisesExitoso);
                if(listaPaisesExitosos!=NULL)
                {
                    if(controller_saveAsText("paisesExitosos.csv",listaPaisesExitosos)==0)
                    {
                        printf("Se creo el archivo con los paises exitosos\n\n");
                    }
                }
           }
           else
           {
               printf("Primero debe relizar la carga de los datos de las cantidades de muertos,infectados y recuperados(opcion 4)\n\n");
           }

        break;
       case 5:
           if(flagCargaConDatos)
           {
               listaPaisesHorno=ll_filter(lista,comparaPaisesHorno);
                if(listaPaisesHorno!=NULL)
                {
                    if(ll_isEmpty(listaPaisesHorno)==0)
                    {
                        if(controller_saveAsText("paisesHorno.csv",listaPaisesExitosos)==0)
                        {
                            printf("Se creo el archivo con los paises exitosos\n\n");
                        }
                    }
                    else
                    {
                        printf("La lista esta vacia\n\n");
                    }
                }
           }
           else
           {
               printf("Primero debe relizar la carga de los datos de las cantidades de muertos,infectados y recuperados(opcion 4)\n\n");
           }

        break;
        case 6:
            if(flagCargaConDatos)
            {
                if(ordenarNivelInfeccion(lista)==0)
                {
                    mostrarPaises(lista);
                }
            }
            else
            {
                printf("Primero debe relizar la carga de los datos de las cantidades de muertos,infectados y recuperados(opcion 4)\n\n");
            }

        break;
        case 7:
            if(flagCargaConDatos)
            {
                mostrarCastigados(lista);
            }
            else
            {
                printf("Primero debe relizar la carga de los datos de las cantidades de muertos,infectados y recuperados(opcion 4)\n\n");
            }


        break;
       case 8:
            printf("Confirma salida: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
        break;
       default:
        printf("Ingrese una opcion valida\n");
        }
        system("pause");
    }while(seguir=='s');

    ll_deleteLinkedList(lista);
    return 0;
}
