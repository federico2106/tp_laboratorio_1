/*
 * ArrayEmployees.c
 *
 *  Created on: 14 may. 2021
 *      Author: Dell
 */
#include <stdio.h>
#include <stdlib.h>


#include "ArrayEmployees.h"
#define ASC 0



int Menu()
{
    int opcion;
    system("cls");
    printf("\n\tElija una opcion:\n\t1. ALTAS\n\t2. MODIFICAR\n\t3. BAJAS\n\t4. INFORMAR\n\t5. SALIR\n");
    scanf("%d",&opcion);
    system("cls");

    return opcion;
}

int PromedioEmpleados(eEmpleado listaEmpleado[], int tam)
{
    float PromedioSalario;
    float SalarioTotal = 0;
    int contador = 0;
    int SuperaPromedio = 0;
    int i;
    int indice = -1;

    if(listaEmpleado != NULL && tam >= 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(listaEmpleado[i].isEmpty == 0)
            {
                contador++;
                SalarioTotal = SalarioTotal + listaEmpleado[i].salary;
            }

        }

        PromedioSalario = SalarioTotal / (float)contador;
        for(i = 0; i < tam; i++)
        {
            if(listaEmpleado[i].isEmpty == 0 && listaEmpleado[i].salary > PromedioSalario)
            {
                SuperaPromedio++;
            }
        }
        printf("\nTotal de salarios : %.2f\nPromedio de salarios : %.2f\n", SalarioTotal, PromedioSalario);
        printf("\nCantidad de empleados que superan el salario promedio : %d ", SuperaPromedio);
        indice = 0;
    }

    return indice;
}

int ModificarEmpleado(eEmpleado empleados[],int tam)
{
    int error = 1;
    int indice;
    int id;
    int opcion;
    eEmpleado nuevaModificacion;
    char confirma;
    printf("\n\n\t\t\t\t\t**Sistema de bajas**\n\n");
    MostrarNominaDeEmpleado(empleados,tam);

    printf("Ingrese ID \n");
    scanf("%d",&id);
    if(empleados !=NULL && tam > 0 && id > 0)
    {


        indice=buscarEmpleado(empleados,tam,id);


        if(indice == -1)
        {
            printf("No existe en nuestro sistema el ID\n");
        }
        else
        {
            MostrarNominaDeEmpleado(empleados,tam);

            nuevaModificacion=empleados[indice];
            printf("Que desea modificar?\n");
            printf("1)NOMBRE\n2)APELLIDO\n3)SALARIO\n4)SECTOR\n");
            fflush(stdin);
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese nombre a modificar ");
                fflush(stdin);
                gets(nuevaModificacion.name);

                break;

            case 2:
                printf("Ingrese apellido a modificar ");
                fflush(stdin);
                 gets(nuevaModificacion.lastName);

                break;

            case 3:
                printf("\nIngrese el salario a modificar:\n ");
                scanf("%f",&nuevaModificacion.salary);
                break;

            case 4:
                printf("Ingrese sector a modificar ");
                scanf("%d",&nuevaModificacion.sector);
                break;
            }
            printf("\nDesea efectuar el cambio? s/n?\n");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
            {
                empleados[indice].salary=nuevaModificacion.salary;
                empleados[indice].sector=nuevaModificacion.sector;
                strcpy(empleados [indice].name,nuevaModificacion.name);
                strcpy(empleados [indice].lastName,nuevaModificacion.lastName);
                error=0;
            }
            else
            {
                error =2;
            }
        }
    }
    return error;
}

int bajaEmpleado(eEmpleado empleados[],int tam)
{
    int error = 1;
    int indice;
    int id;
    char confirma;
    printf("\n\n\t**Sistema de bajas**\n\n");
    MostrarNominaDeEmpleado(empleados,tam);

    printf("Ingrese ID \n");
    scanf("%d",&id);
    if(empleados !=NULL && tam > 0 && id > 0)
    {


        indice=buscarEmpleado(empleados,tam,id);

        if(indice == -1)
        {
            printf("No existe en nuestro sistema el ID\n");
        }
        else
        {
            MostrarNominaDeEmpleado(empleados,tam);
            printf("\nDESEA CONFIRMAR LA BAJA s/n?\n");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
            {
                empleados[indice].isEmpty =1;
                error=0;
            }
            else
            {
                error =2;
            }
        }
    }
    return error;
}

int buscarEmpleado(eEmpleado empleados[],int tam,int id)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(empleados[i].id==id && empleados[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
float GetFloat(eEmpleado listaEmpleado[],char mensaje[],char mensajeError[],float valores1,float valores2)
{
    float auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&auxiliar);
    while(auxiliar<valores1 || auxiliar>valores2)
    {
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%f",&auxiliar);

    }
    return auxiliar;
}
int getInt(eEmpleado listaEmpleado[],char mensaje[],char mensajeError[])
{
    int auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxiliar);
    while(auxiliar<1 || auxiliar>3)
    {
        printf("%s",mensajeError);
        fflush(stdin);
        scanf("%d",&auxiliar);

    }
    return auxiliar;
}

int BuscarLibre(eEmpleado listaEmpleados[],int cant)
{
    int index=-1;
    int i;
    for(i=0; i<cant; i++)
    {
        if(listaEmpleados[i].isEmpty==1)
        {
            index=i;
            break;
        }
    }

    return index;
}

void OrdenarEmpleadosPorApellido(eEmpleado listaEmpleado[],int cant, int criterio)
{

    int i;
    int j;
    eEmpleado auxEmpleado;
    for(i=0; i<cant-1; i++)
    {
        for(j=i+1; j<cant; j++)
        {


            if(strcmp(listaEmpleado[i].lastName,listaEmpleado[j].lastName)>0 && criterio==0)
            {
                auxEmpleado=listaEmpleado[i];
                listaEmpleado[i]=listaEmpleado[j];
                listaEmpleado[j]=auxEmpleado;
            }

        }
    }

}

void CargarTodosLosEmpleados(eEmpleado listaEmpleados[], int cant)

{
    int i;


    i = BuscarLibre(listaEmpleados, cant);
    if(i!=-1)
    {
        listaEmpleados[i]= CargarEmpleado();

        listaEmpleados[i].isEmpty=0;
        listaEmpleados[i].id=i+1;

    }
    else
    {
        printf("\nNo hay espacio\n");
    }


}

eEmpleado CargarEmpleado()
{
    eEmpleado miEmpleado;



    printf("Ingrese nombre:");
    fflush(stdin);
    scanf("%[^\n]", miEmpleado.name);
    printf("Ingrese apellido:");
    fflush(stdin);
    scanf("%[^\n]", miEmpleado.lastName);
    miEmpleado.salary=GetFloat(CargarEmpleado,"Ingrese sueldo","Ingrese salario mayor a 0",1,100000000);
    miEmpleado.sector=getInt(CargarEmpleado,"Ingrese sector","Error reingrese sector: ");



    miEmpleado.isEmpty=0;

    return miEmpleado;
}
void MostrarUnEmpleado(eEmpleado miEmpleado)
{
    printf("\n%18d |%10s| %15s |%15f |%10d\n",miEmpleado.id,miEmpleado.name,miEmpleado.lastName,miEmpleado.salary,miEmpleado.sector);
}
void MostrarNominaDeEmpleado(eEmpleado listaEmpleados[],int cant)
{
    int i;

    printf("\n\t\t\t**lista de empleados**\n");
    printf("\n\t\tID********NOMBRE*********APELLIDO*********SALARIO*********SECTOR\n");
    for(i=0; i<cant; i++)
    {
        if(listaEmpleados[i].isEmpty==0)
        {
            MostrarUnEmpleado(listaEmpleados[i]);

        }


    }

}


