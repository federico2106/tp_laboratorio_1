/*
 * Operaciones.c
 *
 *  Created on: 15 abr. 2021
 *      Author: Dell
 */


#include "Operaciones.h"
float SumarNumeros(float primerNumero, float segundoNumero)
{
    float suma;
    suma = primerNumero + segundoNumero;
    return suma;
}
float RestarNumeros(float primerNumero,float segundoNumero)
{
    float resta;
    resta = primerNumero - segundoNumero;
    return resta;
}
float MultiplicarNumeros(float primerNumero, float segundoNumero)
{
    float multiplicar;
    multiplicar = primerNumero * segundoNumero;
    return multiplicar;
}
float DividirNumeros(float primerNumero, float segundoNumero)
{
    float dividir;

    dividir =primerNumero/segundoNumero;
    return dividir;
}

long long int CalcularFactorial(int numero)
{
  long long  int resultado;

    if(numero == 0 || numero==1)
    {
        resultado = 1;
    }
    else
    {
         resultado = numero * CalcularFactorial(numero - 1);
    }

    return resultado;

}
void Menu( float primerOperando,float segundoOperando){

    int opcion;
     system("cls");

        printf("***Menu de operaciones***\n\n\n");
         fflush(stdin);
        printf("1. Ingresar 1er operando (A=%.2f)\n",primerOperando);
        printf("2. Ingresar 2do operando (B=%.2f)\n",segundoOperando);
        printf("3. Calcular todas las operaciones \n\n");
                printf( "a) Calcular la suma (A+B) \n ");
                printf( "b) Calcular la resta (A-B) \n ");
                printf( "c) Calcular la division (A/B) \n ");
                printf( "d) Calcular la multiplicacion (A*B)\n ");
                printf( "e) Calcular el factorial (A!) \n ");
        printf("4. Informar resultados \n\n");
                printf( "a) El resultado de A+B es: r \n ");
                printf( "b) El resultado de A-B es: r \n ");
                printf( "c) El resultado de A/B es: r \n ");
                printf( "d) El resultado de A*B es: r \n ");
                printf( "e) El factorial de A es: r1 y El factorial de B es: r2 \n ");
       printf("5. Salir \n ");



}
