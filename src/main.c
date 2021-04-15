/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"


int main()
{

    float primerOPerando=0;
    float segundoOperando=0;
    float suma;
    float restar;
    float multiplicar;
    float dividir;
    int factorialPrimerOperando;
    int factorialSegundoOperando;
    int banderaPrimerOperando;
    int banderaSegundoOperando;
    int banderaOperaciones;
    char respuesta;
    char salir;
    int opcionSeleccioanda;
    int flagFactorialPrimerOperando=0;
    int flagFactorialSegundoOperando=0;
    setbuf(stdout,NULL);



    banderaSegundoOperando=0;
    banderaPrimerOperando=0;
    banderaOperaciones=0;
    respuesta='s';

    do
    {
        Menu(primerOPerando,segundoOperando);
        printf("Seleccione opcion:");
        fflush(stdin);
        scanf("%d", &opcionSeleccioanda);
        switch(opcionSeleccioanda)
        {

        case 1:
            printf("ingrese un numero:\n");
            scanf("%f",&primerOPerando);
            banderaPrimerOperando=1;
            break;
        case 2:
            if(banderaPrimerOperando==1)
            {
                printf("ingrese otro numero:\n");
                scanf("%f",&segundoOperando);
                banderaSegundoOperando=1;
            }
            else
            {
                printf("Primero debe ingresar el primer operando.");
                system("pause");
            }

            break;
        case 3:
            if(banderaPrimerOperando==1 && banderaSegundoOperando==1)
            {
                suma= SumarNumeros(primerOPerando, segundoOperando);
                restar= RestarNumeros(primerOPerando, segundoOperando);
                dividir= DividirNumeros(primerOPerando, segundoOperando);
                multiplicar=MultiplicarNumeros(primerOPerando, segundoOperando);

                if(primerOPerando>=0)
                {
                    factorialPrimerOperando=CalcularFactorial(primerOPerando);
                    flagFactorialPrimerOperando=1;
                }
                if(segundoOperando>=0)
                {
                    factorialSegundoOperando= CalcularFactorial(segundoOperando);
                    flagFactorialSegundoOperando=1;
                }

                banderaOperaciones=1;
            }
            else
            {
                printf("debes ingresar los operandos.");
                system("pause");
            }

            break;
        case 4:
            if(banderaPrimerOperando==1 && banderaSegundoOperando==1 && banderaOperaciones==1)
            {
                printf("El resultado de %.2f+ %.2f es: %.2f\n",primerOPerando, segundoOperando, suma);

                printf("El resultado de %.2f - %.2f es: %.2f\n",primerOPerando,segundoOperando,restar);

                printf("El resultado de %.2f * %.2f es: %.2f\n",primerOPerando,segundoOperando,multiplicar);

                if(segundoOperando==0)
                {
                    printf("No se puede dividir por 0.\n");
                }
                else
                {
                    dividir= DividirNumeros(primerOPerando, segundoOperando);
                    printf("El resultado de %.2f / %.2f es: %.2f\n",primerOPerando,segundoOperando, dividir);
                }
                if(flagFactorialPrimerOperando==1 && primerOPerando-(int)primerOPerando==0)
                {
                       printf("el factorial de %f es: %d\n",primerOPerando, factorialPrimerOperando);
                }
                else
                {

                    printf("No se puede hacer el factorial de un numero menor a  0 o decimal.\n");
                }
                if(flagFactorialSegundoOperando==1 && segundoOperando-(int)segundoOperando==0)
                {
                   printf("el factorial de %f es: %d\n",segundoOperando, factorialSegundoOperando);
                }
                else
                {

                     printf("No se puede hacer el factorial de un numero menor a 0 o decimal.\n");
                }

                banderaPrimerOperando=0;
                banderaSegundoOperando=0;
                banderaOperaciones=0;
                flagFactorialPrimerOperando=0;
                flagFactorialSegundoOperando=0;
                system("pause");
            }
            else
            {
                printf("Primero debe calcular las operaciones en el item 3\n");

                system("pause");
            }
            break;
        case 5:

            printf("confirma salida? :\n");
            fflush(stdin);
            scanf("%c", &salir);
            if(salir == 's')
            {
                respuesta = 'n';
            }
            break;
        default:
            printf("Opcion invalida!!!\n\n");
            break;

        }

    }

    while(respuesta=='s');

    return 0;
}


