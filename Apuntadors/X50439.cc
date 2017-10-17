// Archius complementaris: PilaIOint.hh, Pila.hh i utils.PRO2

node_pila* copia_node_pila_it(node_pila* m) {
    /* Pre: cert */
    /* Post: si m és NULL, el resultat és NULL; en cas contrari, el
       resultat apunta al primer node d'una cadena de nodes que són
       còpia de de la cadena que té el node apuntat per m com a primer */
    
    if (m == NULL) return NULL;
    else {
      node_pila* n; // S'ha de retornar el primer node de la copia, per això la guardem.
      node_pila* ult; // S'ha de tenir copiat l'ultim element copiat per poder apuntar-lo com a seguent.
      node_pila* aux; 
      
      n = new node_pila;
      n->info = m->info;
      n->seguent = NULL;
      m = m->seguent;
      ult = n;
      
      while (m != NULL) {
	aux = new node_pila;
	aux->info = m->info;
	aux->seguent = NULL;
	ult->seguent = aux;
	ult = aux;
	m = m->seguent;
      }
      return n;
    }
} 
    
Pila& operator=(const Pila& original) {
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
    
    primer_node = copia_node_pila_it(original.primer_node);
    return *this;
}