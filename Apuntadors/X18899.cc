// Archius complementaris: ArbreNIOint.hh, ArbreN.hh i utils.PRO2

void rec_arbsuma(node_arbreNari* n, node_arbreNari*& m) const {
  /* Pre: cert */
  /* Post: m es null si n es null, en cas contrari, m apunta al primer node de l'arbre de sumes del
     subarbre, el primer node del cual esta apuntat per n. */  
  
  if (n != NULL) {
    m = new node_arbreNari;
    m->info = n->info;
    m->seg = vector<node_arbreNari*> (N);
    for (int i = 0; i < N; ++i) {
      rec_arbsuma(n->seg[i],m->seg[i]);
      if (m->seg[i] != NULL) m->info += m->seg[i]->info;
    }
  }
  else {
    m = NULL;
  }
}


void arbsuma(ArbreNari& asum) const {
  /* Pre: cert */
  /* Post: asum ĂŠs l'arbre suma del p.i.*/
  rec_arbsuma(primer_node, asum.primer_node);
}  