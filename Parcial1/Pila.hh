#ifndef PILA
#define PILA

#include "utils.PRO2"


template <class T> class Pila {

private:
  struct node_pila {
    T info;
    node_pila* seguent;
  }; 
 
  int altura;
  node_pila* primer_node;

static node_pila* copia_node_pila(node_pila* m) 
    /* Pre: cert */
    /* Post: si m �s NULL, el resultat �s NULL; en cas contrari, el
       resultat apunta al primer node d'una cadena de nodes que s�n
       c�pia de de la cadena que t� el node apuntat per m com a primer */
  { 
    node_pila* n;
    if (m==NULL) n=NULL;
    else {
      n = new node_pila;
      n->info = m->info;
      n->seguent = copia_node_pila(m->seguent);
    }
    return n;
  }
  
static node_pila* copia_node_pila_it(node_pila* m)
  {
    node_pila* n;
    node_pila* np;
    if (m == NULL)
      np = NULL;
    else {
      n = new node_pila;
      np = n;
      while (m->seguent != NULL) {
        node_pila* t = new node_pila;
        n->info = m->info;
        n->seguent = t;
        n = t;
        m = m->seguent;
      }
      n->info = m->info;
      n->seguent = NULL;
    }
    return np;
  }

static void esborra_node_pila(node_pila* m) 
    /* Pre: cert */
    /* Post: no fa res si m �s NULL, en cas contrari, allibera espai
       dels nodes de la cadena que t� el node apuntat per m com a
       primer */
  {  
    if (m != NULL) {
      esborra_node_pila(m->seguent);
      delete m;
    }
  }

public:

  Pila() 
    /* Pre: cert */
    /* Post: El resultat �s una pila sense cap element */
  {
    altura= 0;
    primer_node= NULL;
  }

  
  Pila(const Pila& original) 
    /* Pre: cert */
    /* Post: El resultat �s una c�pia d'original */
  {
    altura= original.altura;
    primer_node = copia_node_pila_it(original.primer_node);
  }
  

  ~Pila() 
    // Destructora: Esborra autom�ticament els objectes locals en
    // sortir d'un �mbit de visibilitat
  {
    esborra_node_pila(primer_node);
  }


  
  Pila& operator=(const Pila& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una c�pia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
  {
    if (this != &original) {
      altura= original.altura;
      esborra_node_pila(primer_node);
      primer_node = copia_node_pila_it(original.primer_node);
    }
    return *this;
  }


  void p_buida() 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una pila sense elements i qualsevol
       contingut anterior del p.i. ha estat esborrat */
{
    esborra_node_pila(primer_node);
    altura= 0;
    primer_node= NULL;
  }
        
  void empilar (const T& x) 
    /* Pre: cert */
    /* Post: El p.i. �s com el p.i. original amb x afegit
       com a darrer element */
  {
    node_pila* aux;
    aux= new node_pila; // reserva espai pel nou element
    aux->info= x;
    aux->seguent= primer_node;
    primer_node= aux;
    ++altura;
  }

  void desempilar () 
    /* Pre: el p.i. �s una pila no buida (<=> primer_node != NULL) */ 
    /* Post: El p.i. �s com el p.i. original per� sense el darrer
       element afegit al p.i. original */
  {
    node_pila* aux;
    aux= primer_node; // conserva l'acc�s al primer node abans
    //   d'avan�ar
    primer_node= primer_node->seguent; // avan�a
    delete aux; // allibera l'espai de l'antic cim
    --altura;
  }

  T cim() const 
    /* Pre: el p.i. �s una pila no buida (<=> primer_node != NULL) */
    /* Post: el resultat �s el darrer element afegit al p.i. */ 
  { 
    return primer_node->info;
  }

  bool es_buida() const 
    /* Pre: cert */
    /* Post: El resultat indica si el p.i. �s una pila buida o no */
  {
    return primer_node==NULL;
  }

  int mida() const 
    /* Pre: cert */
    /* Post: El resultat �s el nombre d'elements del p.i. */
  {
    return altura;
  }

  // extensi�n -------------------------------------------------

  bool cerca_pila (const T &x) {
    /* Pre: cert (T ha d'estar dotat de l'operaci� ==) */
    /* Post: el resultat indica si existeix un element x a la pila p.i. */
    return cerca_pila_node(primer_node, x); 
  }

  static bool cerca_pila_node (node_pila* n, const T &x) {
    /* Pre: cert */
    /* Post: el resultat diu si x �s l'info de *n o d'un dels seus seg�ents */
    bool b;
    if (n==NULL) b=false;
    else if (n->info==x) b=true;
    else b=cerca_pila_node(n->seguent, x);
    return b;
  }

  bool cerca_pila_it (const T &x) {
    /* Pre: cert */
    /* Post: el resultat indica si existeix un element x a la pila p.i. */
    node_pila* act;
    act= primer_node;
    bool b= false;
    /*Inv: b= x hi �s a la part visitada del p.i. <=> 
      b= x hi �s a algun node anterior a act */
    while (act!=NULL and not b) {
      b= (act->info == x);
      act= act->seguent;
    }
    return b;
  }

};

#endif
