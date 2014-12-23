/** @file mini_red.hpp
    @brief Especificación de la clase mini_red
*/

#ifndef _MINI_RED_HPP_
#define _MINI_RED_HPP_

#include "Arbre.hpp"
#include <vector>
#include "ListaPaises.hpp"
/** @class mini_red
    @brief Representa una red de flujo

    Contiene una red de flujo de energia y una función que permita realizar un pedido.
*/
class mini_red{
private:
    int N,C; ///< N es el numero de paises, C el de consumidores, 0 < C < N
    Arbre<int> red; ///< Red de flujo de energia
    std::vector< int > 	pedido; ///< vector con lo que pide cada pais consumidor
	/** @brief Funcion inmersion de leer_red
	  \pre Por la entrada estandar hay un arbol en preorden
	  \post A es el arbol que estaba en la entrada estandar
	*/    
    void i_leer_red(Arbre<int> & A);
	/** @brief Funcion inmersion de realizar_pedido
	\pre ed >= 0 , ec = 0, paises contiene N > 1 paises, arbol A contiene enteros entre 0 y N-1 (no necesario todos), ed es la ETS del nodo de A que le pasa su padre
	\post ecn es la energia vendida al arbol A desde el exterior segun las reglas del enunciado , ed >= ecn >= 0, paises contiene las energia actualizadas al realizar el pedido de los paises que estan en el arbol A
	*/    
    void ii_rp(ListaPaises & paises, Arbre<int> & A, const int ed, int & ecn);
public:
	//Creadoras
	/** @brief Creadora por defecto
	 */
	mini_red();
	
	//Destructoras
	/** Destructora por defecto
	 */
	~mini_red();
	
	//Lectoras
	/** @brief Lee una red
	  \pre n > c > 0, hay un arbol correcto en la entrada estandar
	  \post N = n, C = c, red es el arbol de la entrada estandar
	*/	
    void leer_red(int n, int c);
 	
 	//Lectoras y modificadoras
 	/** @brief Realiza un pedido
	  \pre paises contiene N paises correctos, hay un pedido en la entrada estandar
	  \post paises es el resultado de realizar el pedido de la entrada estandar
	*/   
    void realizar_pedido(ListaPaises & paises);
};
#endif
