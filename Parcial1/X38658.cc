// #include "ArbIOint.hh"
// #include "stackIOint.hh"
#include "utils.PRO2"
#include <stack>
#include "Arbre.hh"

void i_cami_preferent(Arbre<int>& a, stack<int>& c, int& cont) {
  if (not a.es_buit()) {
    int arrel = a.arrel();
    Arbre<int> a1;
    Arbre<int> a2;
    a.fills(a1,a2);
    int cont1, cont2;
    stack<int> c2;
    i_cami_preferent(a1,c,cont1);
    i_cami_preferent(a2,c2,cont2);
    cont = cont1 + cont2 + 1;
    if (cont1 >= cont2) c.push(arrel);
    else {
      c = c2;
      c.push(arrel);
    }
  }
  else cont = 0;
}

/*void conta_nodes_fills(Arbre<int>& b, int& fd, int& fe) {
  // Pre: b = B.
  // Post: fd conte el numero de nodes del fill dret i fe conte el numero de nodes del fill esquerra.
  Arbre<int> b1;
  Arbre<int> b2;
  b.fills(b1,b2);
  if (not b1.es_buit() and not b2.es_buit()) {
    conta_nodes_fills(b1,fd,fe);
    ++fe;
    conta_nodes_fills(b2,fd,fe);
    ++fd;
  }
  else if (b1.es_buit() and not b2.es_buit()) {
    conta_nodes_fills(b2,fd,fe);
    ++fd;
  }
  else if (not b1.es_buit() and b2.es_buit()) {
    conta_nodes_fills(b1,fd,fe);
    ++fe;
  }
}*/

void cami_preferent(Arbre<int>& a, stack<int>& c) {
  // Pre: a = A, c es buida
  // Post: c conte el cami preferent d'A; si no es buit, el primer element del cami es el cim de c
  int cont;
  i_cami_preferent(a,c,cont);
}


/*int main() {
  Arbre<int> a;
  llegir_arbre_int(a,0);
  stack<int> p;
  cami_preferent(a,p);
  escriure_stack_int(p);
} */