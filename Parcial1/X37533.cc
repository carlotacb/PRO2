#include "utils.PRO2"
#include "Arbre.hh"
// #include "ArbIOint.hh"

int max(int x, int y) {
  if (x > y) return x;
  else return y;
}

void i_agd(Arbre<int>&a, int& alt) {
  // Pre: a = A
  // Post: a serĹ un arbol con la misma estructura de A, y cada nodo de a serĹ el grado de desequilibrio del correspondiente nodo de A, y alt es la profundidad de A
  
  if (not a.es_buit()) {
    Arbre<int> ai;
    Arbre<int> ad;
    a.fills(ai,ad);
    int alti, altd;
    i_agd(ai,++alti);
    i_agd(ad,++altd);
    int raiz = alti - altd;
    alt = max(alti,altd) + 1;
    a.plantar(raiz,ai,ad);
  }
  else alt = 0;
}

void arbre_graus_desequilibri(Arbre<int>& a, Arbre<int>& agd) {
  // Pre: a = A
  // Post: agd es un arbre amb la mateixa estructura que A on cada node conte el grau de desequilibri del subarbre d'A corresponents
  int alt;
  agd = a;
  i_agd(agd,alt);
}

/*int main() {
  Arbre<int> a;
  llegir_arbre_int(a,0);
  Arbre<int> b;
  
  arbre_graus_desequilibri(a,b);
  cout << "Fa algo" << endl;
  escriure_arbre_int(b);
  cout << "xq no t'imprimeixes cagun..." << endl;
}*/