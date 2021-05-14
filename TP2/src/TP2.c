/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ArrayEmployees.h"

#define ASC 0
#define TAM 1000


int main()
{
    int opcionLista;
    int seguir='s';
    int flagAlta=0;
    setbuf(stdout,NULL);

    eEmpleado listaEmpleado[TAM];


    int i;
    for(i=0; i<TAM; i++)
    {
        listaEmpleado[i].isEmpty=1;
    }

    do
    {
        switch(Menu())
        {

        case 1:
            CargarTodosLosEmpleados(listaEmpleado,TAM);
            flagAlta=1;

            break;
        case 2:
            if(flagAlta==1)
            {
                ModificarEmpleado(listaEmpleado,TAM);
            }
            else
            {
                printf("Necesitas cargar un empleado\n");


            }
            system("pause");
            break;

        case 3:
            if(flagAlta==1)
            {
                bajaEmpleado(listaEmpleado,TAM);
            }
            else
            {
                printf("Necesitas cargar un empleado\n");
            }
            system("pause");
            break;
        case 4:
            if(flagAlta==1)
            {

                MostrarNominaDeEmpleado(listaEmpleado,TAM);
                printf("\nSeleccione que opcion desea\n\n 1 >Ordenar por apellido de A a la Z\n 2>Total y promedio de los salarios, cantidad de empleados que superan el salario promedio.\n");
                scanf("%d",&opcionLista);
                if (opcionLista == 1)
                {

                    OrdenarEmpleadosPorApellido(listaEmpleado,TAM, ASC);
                    MostrarNominaDeEmpleado(listaEmpleado,TAM);
                    system("pause");
                }
                else if(opcionLista==2)
                {

                    PromedioEmpleados(listaEmpleado,TAM);

                    system("pause");
                }
                else
                {
                    printf("\nOpcion invalida,\n");
                }


            }
            else
            {
                printf("\nPara listar necesitas cargar empleados\n");
            }
            system("pause");
            break;
        case 5:
            printf("Hasta Pronto\n");
            seguir='n';
            break;
        default:
            printf("\nOpcion invalida.\n");
            system("pause");
        }
        if(listaEmpleado->isEmpty)
        {
            flagAlta=0;
        }

    }
    while(seguir=='s');


    return 0;
}

