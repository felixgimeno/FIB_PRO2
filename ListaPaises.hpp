/** @file ListaPaises.hpp
    @brief Especificacion de la clase ListaPaises
*/

#ifndef _LISTA_PAISES_HPP_
#define _LISTA_PAISES_HPP_

#include <vector>

/** @class ListaPaises
    @brief Contiene paises

    Cada pais contenido contiene a su vez energia y stocks
*/
class ListaPaises{
	private:
		struct Pais /// definicion de un pais 
		{ 
			int energia; ///< La energia actual de este pais, >= 0
			std::vector<int> stocks; ///< Los stocks actuales de este pais, cada stock >= 0
		};
		std::vector<Pais> Lista; ///< La lista de paises
	public:
		//Creadoras
		/** @brief Creadora por defecto.
			\pre Cierto
			\post Crea una Lista vacia
		*/
		ListaPaises();
		
		/** @brief Crea N paises
			\pre N >= 1
			\post Lista contiene N paises
		*/
		ListaPaises(const int N);
		
		//Destructoras
		/** @brief Destructora por defecto
		 */
		~ListaPaises();
		
		//Consultoras
		/** @brief Devuelve la energia de un pais
			\pre Lista.size()-1 >= id_pais >= 0
			\post Devuelve la energia del pais id_pais
		*/
		int consultar_energia(const int id_pais) const;
		
		/** @brief Devuelve el stock de un sector de un pais
			\pre Lista.size() > id_pais >= 0,  Lista[0].stocks.size() > id_sector >= 0
			\post Devuelve el stock del sector id_Sector del pais id_pais
		*/
		int consultar_stock_sector(const int id_pais, const int id_sector) const;
		
		//Modificadoras
		/** @brief Modifica la energia de un pais
			\pre Lista.size() > id_pais >= 0,  energia_nuevo >= 0
			\post La energia del pais id_pais es energia_nueva
		*/
		void modificar_energia(const int id_pais, const int energia_nueva);
		
		/** @brief Modifica el stock de un sector de un pais
			\pre Lista.size() > id_pais >= 0,  Lista[0].stocks.size() > id_sector >= 0, stock_nuevo >= 0
			\post El stock de id_sector de id_pais es stock_nuevo
		*/
		void modificar_stock_sector(const int id_pais, const int  id_sector, const int stock_nuevo);
		
		/** @brief Suma energia a la de un pais 
			\pre Lista.size() > id_pais >= 0,  la energia de id_pais = X, X + energia_a_sumar >= 0
			\post la energia de id_pais es = X +energia_a_sumar
		*/
		void sumar_energia(const int id_pais, const int energia_a_sumar);
		
		/** @brief  Suma stock al de un sector de un pais
			\pre Lista.size() > id_pais >= 0,  Lista[0].stocks.size() > id_sector >= 0, stock del sector id_Sector del pais id_pais = X, X+stock_a_sumar >= 0
			\post stock del sector id_Sector del pais id_pais = X+stock_a_sumar
		*/	
		void sumar_stock_sector(const int id_pais, const int id_sector, const int stock_a_sumar) ;
		
		//Lectoras
		/** @brief Lee un pais
			\pre Lista.size() > id_pais >= 0,  M >= 0, en la entrada estandar hay energia y m stocks
			\post el pais id_pais contiene la energia leida y los M stocks leidos en orden
		*/
		void leer_pais(const int id_pais, const int M);
		
		/** @brief Lee una lista de paises
			\pre N,M >= 0, hay N paises con  M stocks por pais en la entrada estandar 
			\post Lista contiene la lista leida
		*/
		void leer_lista(const int N, const int M) ;
		
		/** @brief Igual que sumar_energia pero leyendo de la entrada estandar
			\pre Igual que sumar_energia pero leyendo de la entrada estandar
			\post Igual que sumar_energia pero leyendo de la entrada estandar
		*/
		void sumar_energia_leyendo_datos(void);
		
		/** @brief Igual que sumar_stock_sector pero leyendo de la entrada estandar
			\pre Igual que sumar_stock_sector pero leyendo de la entrada estandar
			\post Igual que sumar_stock_sector pero leyendo de la entrada estandar
		*/
		void sumar_stock_sector_leyendo_datos(void);
		
		//Escritoras
		
		/** @brief Escribe stocks de un pais
			\pre Lee id_pais entre 0 y Lista.size()
			\post Ha escrito los stocks del pais id_pais
		*/
		void escribir_stocks(void) const;
		
		/** @brief Escribe energias de los paises
			\pre Lista.size() > 0
			\post Ha escrito las energia de los paises de Lista
		*/
		void escribir_energias(void) const;
};
#endif


















