/** @file mini_red.cpp
    @brief Implementación de la clase mini_red
*/
#include "mini_red.hpp"
#include "utils.PRO2"
mini_red::mini_red(){}
mini_red::~mini_red(){}
void mini_red::i_leer_red(Arbre<int>& A){
	const int t = readint();
	if (t != 0) {
		Arbre <int> fe, fd;
		i_leer_red(fe);
		i_leer_red(fd);
		A.plantar(t-1, fe, fd);
	}
}

void mini_red::leer_red(int n, int c){
	N = n;
	C = c;
	i_leer_red(red);
}

void mini_red::realizar_pedido(ListaPaises& paises){
	pedido = std::vector <int> (N, 0);
	for (int i = 0; i < C; i += 1) pedido[i] = readint();
	int ed = 0;
	int ec = 0;
	ii_rp(paises, red, ed, ec);
}

int min(int a, int b){
	int ret = b;
	if (a < b) ret = a;
	return ret;
}

bool es_productor(int id_pais, int C){
	bool productor = true;
	if (id_pais < C) productor = false;
	return productor;
}

void mini_red::ii_rp(ListaPaises& paises, Arbre<int>& A, const int ed, int& ecn){
	if (A.es_buit()) ecn = 0;
	else {
		const int raiz = A.arrel();
		
		int er = 0;
		if (es_productor(raiz, C)) er = paises.consultar_energia(raiz);
		
		int ed1, ed2, ec1, ec2;
		ed1 = ed2 = (ed + er) / 2;
		ec1 = ec2 = 0;
		if (ed1 + ed2 < ed + er) ed1 += 1;

		Arbre <int> fe, fd;
		A.fills(fe, fd);
		
		const bool solo_un_sucesor = fe.es_buit() or fd.es_buit();
		if (solo_un_sucesor) ed2 = ed1 = ed + er;

		ii_rp(paises, fe, ed1, ec1);
		ii_rp(paises, fd, ed2, ec2);
		A.plantar(raiz, fe, fd);

		if (es_productor(raiz, C)) {
	
			int er1, er2;
			er1 = er2 = er / 2;
			if (er1 + er2 < er) er1 += 1;
			if (solo_un_sucesor) er1 = er2 = er;

			int s1 = min(ec1, er1);
			paises.sumar_energia(raiz, -s1);
			er -= s1;
			ec1 -= s1;

			int s2 = min(ec2, er2);
			paises.sumar_energia(raiz, -s2);
			er -= s2;
			ec1 -= s2;

			ecn = ec1 + ec2;
		} 
		else {
			int s = min(ed - ec1 - ec2, pedido[raiz]);
			paises.sumar_energia(raiz, s);
			ecn = s + ec1 + ec2;
		}

	}
}
