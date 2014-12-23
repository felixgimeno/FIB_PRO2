/** @mainpage Página Principal
	\author Felix Axel Gimeno Gil
	\version 4
	\date 08/12/2014
	\copyright Copyright (C) 2014 Felix Gimeno GPLv3
	@section Contenido
	-# @ref Descripción: Práctica Pro2 Otoño 2014
	-# @ref Autor: Felix Axel Gimeno Gil 2014
	-# @ref Licencia: GPLv3
*/
/** @file pro2.cpp
	@brief Programa principal
 */
#include "ListaPaises.hpp"
#include "mini_red.hpp"
#include "mini_industria.hpp"
#include "utils.PRO2"
/** @brief Main de pro2.cpp
  \pre Lee una entrada correcta
  \post Ejecuta el comportamiento esperado
*/
int main(void){
	const int N = readint();
	const int C = readint();
	const int M = readint();
	mini_red red;
	mini_industria indus;

	
	red.leer_red(N,C);
	ListaPaises paises (N);
	paises.leer_lista(N,M);
	indus.leer_datos(M);

	bool s = true;
	while (s) {
		const int t = readint();
		if (t == -1) red.realizar_pedido(paises);
		if (t == -2) indus.ciclo_de_produccion(N,paises);
		if (t == -3) paises.sumar_energia_leyendo_datos();
		if (t == -4) paises.sumar_stock_sector_leyendo_datos();
		if (t == -5) paises.escribir_stocks();
		if (t == -6) paises.escribir_energias();
		if (t == -7) s = false;

	}

}

