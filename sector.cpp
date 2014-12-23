/** @file sector.cpp
    @brief Implementación de la clase sector
*/

#include "sector.hpp"
#include "utils.PRO2"
void sector::leer_sector(){
	energia = readint();
	EUP = readint(); 
	prod_max_ciclo = readint();
	num_dep = readint();
	DEP = std::vector<dep> (num_dep);
	for (int id_dep = 0; id_dep < num_dep; id_dep += 1){
		DEP[id_dep].id_sector = -1 + readint();
		DEP[id_dep].unidades_necesarias = readint();
	}
}
int sector::consultar_energia(void) const  {
	return this->energia;
}
int sector::consultar_EUP(void) const {
	return this->EUP;
}
int sector::consultar_prod_max_ciclo(void) const {
	return prod_max_ciclo;
}
int sector::consultar_num_dep(void) const {
	return num_dep;
}
int sector::consultar_dep_id_sector(int id_dep) const {
	return DEP[id_dep].id_sector;
}
int sector::consultar_dep_unidades_necesarias(int id_dep) const {
	return DEP[id_dep].unidades_necesarias;
}
