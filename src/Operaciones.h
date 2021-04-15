/*
 * Operaciones.h
 *
 *  Created on: 15 abr. 2021
 *      Author: Dell
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#include <stdio.h>


/** \brief calculo el factoreal de un numero
 *
 * \param int ingreso el numero natural  a factorear
 * \return long long int el resultado del numero factoreado.
 *
 */
long long int CalcularFactorial(int);
/** \brief calcula la suma de dos numero flotantes
 *
 * \param float ingresa el primer numero.
 * \param float ingresa el segundo numero.
 * \return float la suma de dos numeros enteros.
 *
 */
float SumarNumeros(float, float);
/** \brief calcula la resta de dos numeros flotantes.
 *
 * \param float ingreso el primer numero
 * \param float ingreso el segundo numero
 * \return float el resultado de resta de los dos numeros flotantes.
 *
 */

float RestarNumeros(float, float);
/** \brief calculo la multiplicacion de dos numeros flotantes.
 *
 * \param float ingreso el primer numero flotante.
 * \param float ingreso el segundo numero flotante.
 * \return float el resultado de la multiplicacion de dos numero entero.
 *
 */
float MultiplicarNumeros(float,float);
/** \brief calcula la division de dos numeros enteros.
 *
 * \param float ingreso el primer numero
 * \param float ingreso el segundo numero
 * \return float el resultado de la division
 *
 */
float DividirNumeros(float, float);
/** \brief muestera el menu, donde se agregan los operando para sustituir los valores de X e Y.
 *
 * \param float pide las opciones
 * \param float pide opciones
 * \return void opcion del menu
 *
 */
void Menu(float,float);

#endif /* OPERACIONES_H_ */
