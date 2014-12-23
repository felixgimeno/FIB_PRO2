/** @file ListaPaises.cpp
    @brief Implementacion de la clase ListaPaises
*/

#include "ListaPaises.hpp"
#include "utils.PRO2"
ListaPaises::ListaPaises() {}
ListaPaises::ListaPaises(const int N) : Lista (N) {}
ListaPaises::~ListaPaises() {}

int ListaPaises::consultar_energia(const int id_pais) const {
	return Lista[id_pais].energia;
}

int ListaPaises::consultar_stock_sector(const int id_pais, const int id_sector) const {
	return Lista[id_pais].stocks[id_sector] ;
}

void ListaPaises::modificar_energia(const int id_pais, const int energia_nueva){
	Lista[id_pais].energia = energia_nueva;
}

void ListaPaises::modificar_stock_sector(const int id_pais, const int  id_sector, const int stock_nuevo){
	Lista[id_pais].stocks[id_sector] = stock_nuevo;
}

void ListaPaises::sumar_energia(const int id_pais, const  int energia_a_sumar){
	Lista[id_pais].energia += energia_a_sumar;
}
void ListaPaises::sumar_stock_sector(const int id_pais, const int id_sector, const int stock_a_sumar){
	Lista[id_pais].stocks[id_sector] += stock_a_sumar;
}
	
void ListaPaises::leer_pais(const int id_pais, const int M){
	Lista[id_pais].energia = readint();
    Lista[id_pais].stocks = std::vector<int> (M,0);
    for (int id_Sector = 0; id_Sector < M; ++id_Sector){
        Lista[id_pais].stocks[id_Sector] = readint();
    }
}
void ListaPaises::leer_lista(const int N, const int M) {
	for (int id_Pais = 0; id_Pais < N; ++id_Pais){
		leer_pais(id_Pais, M);
	}
}

void ListaPaises::sumar_energia_leyendo_datos() {
	const int id_pais = readint();
	const int energia_nueva = readint();
	sumar_energia(id_pais-1, energia_nueva);
}

void ListaPaises::sumar_stock_sector_leyendo_datos(){
	const int id_Pais = -1 + readint();
	const int id_Sector = -1 + readint();
	const int stock_a_sumar = readint();
    sumar_stock_sector(id_Pais, id_Sector, stock_a_sumar);
}

void ListaPaises::escribir_stocks(void) const {
	const int id_pais = -1 + readint();
    std::cout << "Stocks del pais " << id_pais+1 << ":\n";
	std::cout << consultar_stock_sector(id_pais, 0);
    for (int id_Sector = 1; id_Sector < (int)Lista[id_pais].stocks.size(); ++id_Sector){
        std::cout << " " << consultar_stock_sector(id_pais, id_Sector);
    }
    std::cout << "\n\n";
}
void ListaPaises::escribir_energias(void) const {
	std::cout << "Energia de todos los paises:" << std::endl;
	std::cout << consultar_energia(0) ;
    for (int id_pais = 1; id_pais < (int)Lista.size(); ++id_pais) 
		std::cout << " " << consultar_energia(id_pais);
    std::cout << std::endl << std::endl;
	
}

