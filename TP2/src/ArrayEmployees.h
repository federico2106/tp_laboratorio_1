/*
 * ArrayEmployees.h
 *
 *  Created on: 14 may. 2021
 *      Author: Dell
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmpleado;
/** \brief Muestra menu.
 *
 * \return devuevlve un int.
 *
 */
int Menu();
/** \brief suma los salario y saca el promedio,
 *
 * \param listaEmpleado[] eEmpleado
 * \param tam int recibe valore flotantes.
 * \return int promedio, total de salarios y cantidad de salario promedio.
 *
 */
int PromedioEmpleados(eEmpleado listaEmpleado[], int tam);
/** \brief modifica de la lista de empelados un empleado por id
 *
 * \param empleados[] eEmpleado modifica un empleado
 * \param tam cambia el valor del nombre, apellido, salario y sector.
 * \return el cambio efectuado.
 *
 */
int ModificarEmpleado(eEmpleado empleados[],int tam);
/** \brief da la baja de un empleado por id.
 *
 * \param empleados[] eEmpleado baja de empleado
 * \param tam int da la baja del empleado por id.
 * \return int la baja del empleado.
 *
 */
int bajaEmpleado(eEmpleado empleados[],int tam);
/** \brief busca el empleado para poder hacer modificaciones
 *
 * \param empleados[] eEmpleado lista de empleados
 * \param tam int pasa el tamanio de la lista
 * \param id int pasa el id que esta buscando
 * \return int efectua la busqueda del empleado
 *
 */
int buscarEmpleado(eEmpleado empleados[],int tam,int id);
/** \brief toma el ingreso del salio del empleado
 *
 * \param listaEmpleado[] eEmpleado lista de empelados
 * \param mensaje[] char mensaje para que ingrese el salario
 * \param mensajeError[] char mensaje de error si ingresa un salario menor a cero
 * \param valores1 float parametro minimo de referencia con recpecto al salario
 * \param valores2 float parametro maximo de referencia con recpecto al salario
 * \return float
 *
 */
float GetFloat(eEmpleado listaEmpleado[],char mensaje[],char mensajeError[],float valores1,float valores2);
/** \brief toma el ingreso del salio del empleado
 *
 * \param listaEmpleado[] eEmpleado lista de empleado
 * \param mensaje[] char mensaje para que ingrese el sector
 * \param mensajeError[] char mensaje de error si ingreso mal el sector
 * \return int
 *
 */
int getInt(eEmpleado listaEmpleado[],char mensaje[],char mensajeError[]);
/** \brief busca el espcacio libre para poder cargar un empleado
 *
 * \param listaEmpleados[] eEmpleado lista de empleado
 * \param buscar el lugar libre con el isEmpty
 * \return lugar libre
 *
 */
int BuscarLibre(eEmpleado listaEmpleados[],int cant);
/** \brief ordena los empleados de A a la Z
 *
 * \param listaEmpleado[] eEmpleado lista de empleados
 * \param cant toma lalista y la ordena por apellido
 * \param criterio A a Z
 * \return void
 *
 */
void OrdenarEmpleadosPorApellido(eEmpleado listaEmpleado[],int cant, int criterio);
/** \brief carga todos los empleados cargados
 *
 * \param listaEmpleados[] eEmpleado lkista de empleados
 * \param cant carga los empleados
 * \return void
 *
 */
void CargarTodosLosEmpleados(eEmpleado listaEmpleados[], int cant);
/** \brief muesta todos los empleados
 *
 * \param listaEmpleados[] eEmpleado lista de empleados
 * \param cant muestra la lista cargada
 * \return
 *
 */
void MostrarNominaDeEmpleado(eEmpleado listaEmpleados[],int cant);
/** \brief cargs los empleado
 *
 * \return eEmpleado empleado
 *
 */
eEmpleado CargarEmpleado();



#endif /* ARRAYEMPLOYEES_H_ */
