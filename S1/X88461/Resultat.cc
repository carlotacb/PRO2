#include "utils.PRO2"
#include <vector>

struct parint {
	int prim, seg;
};

parint max_min (const vector<int> &v){
/* Pre: v.size() > 0 */
/* Post: el primer componente del resultado es el valor máximo de v; 
   el segundo componente del resultado es el valor mínimo de v */
	
	parint mm;
	
	int x = v[0];
	int y = v[0];

	for (int i = 1; i < v.size(); ++i) {
		if (v[i] > x) x = v[i];
		else if (v[i] < y) y = v[i];
	}

	mm.prim = x;
	mm.seg = y;

	return mm;
}

int main() {
	
	//cout << "Indicar tamany del vector:" << endl;

	int tam = readint();
	vector<int> v(tam);
	
	//cout << "Introduir elements del vector:" << endl;
	
	for (int i = 0; i < tam; ++i) v[i] = readint();

	parint mm;
	
	mm = max_min(v);

	//cout << "El máxim i el mínim són:" << endl;

	cout << mm.prim << " " << mm.seg << endl;
}