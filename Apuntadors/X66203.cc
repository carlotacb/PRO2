// Archius complementaris: ArbreNIOint.hh, ArbreN.hh i utils.PRO2

T max_rec(node_arbreNari* m, int n) const {
  /* Pre: m es diferent de nul i n es el numero de fills de l'abre */
  /* Post: el resultat indica el valor més gran que conté el node n o qualsevol dels seus successors. */ 
  
  T max = m->info;
  for (int i = 0; i < n; ++i) {
    if (m->seg[i] != NULL) {
      T mc = max_rec(m->seg[i],n);
      if (max < mc) max = mc;
    }
  }
  return max;
}
  
T maxim() const {
  /* Pre: el p.i. no és buit */
  /* Post: el resultat indica el valor més gran que conté el p.i. */ 
  return max_rec(primer_node,N);
}