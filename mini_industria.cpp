/** @file mini_industria.cpp
    @brief Implementación de la clase mini_industria
*/
#include "mini_industria.hpp"
#include "utils.PRO2"
mini_industria::mini_industria(){}
mini_industria::~mini_industria(){}
int minint(int a, int b) {
	if (a < b) return a;
	return b;
}
void mini_industria::ii_cdp(int id_pais, int id_sector) {
	const sector & ds = datos[id_sector]; //ds son los datos del sector actual

	int t; //prod max que podria producir
	const int energia_total = p->consultar_energia(id_pais); //energia del pais
	const int energia_disponible = (((ds.consultar_energia())* energia_total)/100 )/ ds.consultar_EUP();//energia que puede utilizar el sector
	t = minint(energia_disponible, ds.consultar_prod_max_ciclo()); //cota energetica a la produccion

	int id_dep = 0;
	while (id_dep < ds.consultar_num_dep() and t != 0 ){
		const int stock_dep = p->consultar_stock_sector(id_pais, ds.consultar_dep_id_sector(id_dep));
		const int cota_prod_dep = stock_dep / ds.consultar_dep_unidades_necesarias(id_dep);
		t = minint(t, cota_prod_dep);//cota por las dependencias a la produccion 
		id_dep += 1;
	}
	if (t != 0){
		nueva_energia += -t*ds.consultar_EUP();//guardamos la energia gastada  
		for (int id_dep = 0; id_dep < ds.consultar_num_dep(); ++id_dep){
			const int id_dep_sector = ds.consultar_dep_id_sector(id_dep);
			const int id_dep_stock = ds.consultar_dep_unidades_necesarias(id_dep);
			p->sumar_stock_sector(id_pais, id_dep_sector, -id_dep_stock*t);
		}
	}
	nuevo_stock.at(id_sector) = t; //guardamos el stock producido en un vector privado de la clase
}

void mini_industria::i_cdp(int id_pais) {
	nueva_energia = 0;
	
	for (int i = 0; i < M; ++i){
		ii_cdp(id_pais, prioridades[i]);
	}
	for (int id_sector = 0; id_sector < M; ++id_sector){
		p->sumar_stock_sector(id_pais, id_sector, nuevo_stock.at(id_sector));
	}
	p->sumar_energia(id_pais, nueva_energia);		
}

void mini_industria::leer_datos(int m){
	M = m;
	datos = std::vector<sector> (M);
	prioridades = std::vector<int> (M);
	nuevo_stock = std::vector<int> (M , 0);
	for (int id_sector = 0; id_sector < M; ++id_sector){
		prioridades[id_sector] = -1+readint();
	}
	for (int id_sector = 0; id_sector < M; ++id_sector){
		datos[id_sector].leer_sector();
	}
}

void mini_industria::ciclo_de_produccion(int N, ListaPaises & paises) {
	p = &paises;
	//invariante del bucle 0 <= id_pais < N , 
	//a los paises de id entre 0 y id_pais se les ha realizado un ciclo de produccion
	for (int id_pais = 0; id_pais < N; ++id_pais){
		i_cdp(id_pais);
		}
}
		

