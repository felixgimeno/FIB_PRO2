/** @file sector.hpp
    @brief Especificacion de la clase sector
*/

#ifndef _SECTOR_HPP_
#define _SECTOR_HPP_

#include <vector>
#include "dep.hpp"

/** @class sector
    @brief Datos invariantes de un sector

    Contiene datos de un sector que no dependen del pais
*/
class sector {
private:
	int energia; ///< porcentaje de energia
	int EUP; ///< Energia por unidad
	int prod_max_ciclo; ///< producción máxima por ciclo
	int num_dep; ///< numero de dependencias
	std::vector<dep> DEP; ///< vector de dependecias
public:
	/** @brief Lee un sector
		\pre Cierto
		\post Ha leido los datos de un sector
	*/
	void leer_sector(void);
	/** @brief Devuelve la energia
		\pre Ya ha leido un sector
		\post devuelve la energia que leyo
	*/	
	int consultar_energia(void) const;
	/** @brief Devuelve energia por unidad
		\pre Ya ha leido un sector
		\post devuelve la eup que leyo
	*/
	int consultar_EUP(void) const;
	/** @brief Devuelve la produccion maxima por ciclo
		\pre Ya ha leido un sector
		\post devuelve la prod_max_ciclo que leyo
	*/	
	int consultar_prod_max_ciclo(void) const;
	/** @brief Devuelve el numero de dependencias
		\pre Ya ha leido un sector
		\post devuelve la num_dep que leyo
	*/	
	int consultar_num_dep(void) const;
	/** @brief Devuelve la id_sector de la dep numero id_dep
		\pre Ya ha leido un sector y 0<= id_dep < num_dep
		\post devuelve la id_sector de la dep numero id_dep que leyo
	*/		
	int consultar_dep_id_sector(int id_dep) const;
	/** @brief Devuelve las unidades necesarias de la dep numero id_dep
		\pre Ya ha leido un sector y 0<= id_dep < num_dep
		\post devuelve las unid_necesa dep numero id_dep que leyo
	*/	
	int consultar_dep_unidades_necesarias(int id_dep) const;
};

#endif
