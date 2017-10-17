// Archius complementaris: ArbreIOint.hh, Arbre.hh i utils.PRO2

void rec_arb_sum(node_arbre* n, node_arbre*& m) const {
  /* Pre: cert */
  /* Post: m es null si n es null, en cas contrari, m apunta al primer node de l'arbre de sumes del
     subarbre, el primer node del cual esta apuntat per n. */
  if (n != NULL) {
    m = new node_arbre;
    m->info = n->info;
    rec_arb_sum(n->segD,m->segD);
    if(m->segD != NULL) m->info += m->segD->info;
    rec_arb_sum(n->segE,m->segE);
    if(m->segE != NULL) m->info += m->segE->info;
  }
  else {
    m = NULL;
  }
}

void arb_sumes(Arbre<int> &asum) const {
  /* Pre: cert */
  /* Post: l'arbre asum ĂŠs l'arbre suma del p.i. */
  rec_arb_sum(primer_node, asum.primer_node);
}