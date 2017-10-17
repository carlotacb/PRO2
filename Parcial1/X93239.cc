#include "utils.PRO2"
#include <vector>

int comptatge_frontisses(const vector<int> &v){
 /* Pre: cert */
 /* Post: el resultat es el nombre d'elements frontissa de v */
 int fronti = 0;
 
 int sumas = 0;
 int sumap = v[0];
 
 for (int i = 1; i < v.size(); ++i) {
 	sumas += v[i];
 }
 
 if (sumas == sumap) ++fronti;
 
 for (int j = 1; j < v.size(); ++j) {
 	sumas -= v[j];
 	if ((sumas - sumap) == v[j]) ++fronti;
 	
 	sumap += v[j]; 
 }
 
 return fronti;
}