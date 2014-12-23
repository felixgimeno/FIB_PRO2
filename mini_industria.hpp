/** @file mini_industria.hpp
    @brief Especificación de la clase mini_industria
*/

#ifndef MINI_INDUSTRIA_HPP_
#define _MINI_INDUSTRIA_HPP_

#include <vector>
#include "sector.hpp"
#include "ListaPaises.hpp"
/** @class mini_industria
    @brief Para realizar un ciclode de produccion 

    Contiene datos que no dependen del pais, y funciones para realizar un ciclo de producción
*/
class mini_industria {
private:
	int M; ///< Cantidad de sectores
	std::vector<int> prioridades; ///< vector de prioridades
	std::vector<sector> datos;
	ListaPaises* p;
	int nueva_energia;
	std::vector<int> nuevo_stock;
	/** @brief Auxiliar de i_cdp: cdp de un sector de un pais
		\pre 0 <= id_pais <= N-1 0<= id_sector <= M-1, p del p.i. contiene N paises de M sectores
		\post el sector id_Sector del pais id_pais ha sufrido un ciclo de produccion 
	*/
	void ii_cdp(int id_pais, int id_sector) ;
	/** @brief Auxiliar de ciclo_de_produccion: Ciclo de un pais
		\pre 0 <= id_pais <= N-1
		\post al pais id_pais se le ha realizado un ciclo de produccion 
	*/
	void i_cdp(int id_pais);
public:
	/** @brief Creadora por defecto
	 */
	mini_industria();
	
	/** Destructora por defecto
	 */
	~mini_industria();

	/** @brief Lee los datos de los sectores
		\pre m > 0 . hay m sectores en la entrada
		\post datos es el vector de los m sectores
	*/
	void leer_datos(int m);
	
	/** @brief Realiza un ciclo de producción
		\pre paises contiene N Pais correctos, 
		\post paises contiene los Pais originales, a los que se les ha realizado un ciclo de producción
	*/	
	void ciclo_de_produccion(int N, ListaPaises & paises);
};
#endif
