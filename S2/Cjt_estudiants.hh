#ifndef CONJ_EST_HPP
#define CONJ_EST_HPP

#include "Estudiant.hh"
#include <vector>

using namespace std;

class Cjt_estudiants {

private:

  // Tipus de m�dul: dades
  // Descripci� del tipus:  Representa un conjunt ordenat per DNI d'estudiants.
  // Es poden consultar i modificar els seus elements (de tipus Estudiant) 
  // donat un DNI o per posici� en l'ordre.

  vector<Estudiant> vest;
  int nest;
  static const int MAX_NEST = 30000;
  /* 
     Invariant de la representaci�: 
     - vest[0..nest-1] est� ordenat creixentment pels DNI dels estudiants i
       no cont� estudiants repetits
     - 0 <= nest <= vest.size() = MAX_NEST
  */

  void ordenar_cjt_estudiants ();
  /* Pre: cert */
  /* Post: els elements rellevants del par�metre impl�cit estan ordenats 
     creixentment pels seus DNI */

  static int cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x);
  /* Pre: vest[left..right] est� ordenat creixentment per DNI,  
     0<=left, right<vest.size() */
  /* Post: si a vest[left..right] hi ha un element amb DNI = x, el resultat �s 
     una posici� que el cont�; si no, el resultat �s -1 */

public:

  //Constructores

  Cjt_estudiants();
  /* Pre: cert */
  /* Post: el resultat �s un conjunt d'estudiants buit */

  //Destructora

  ~Cjt_estudiants();
   
  //Modificadores

  void afegir_estudiant(const Estudiant &est);
  /* Pre: el par�metre impl�cit no cont� cap estudiant amb el dni d'est; el
     nombre d'estudiants del p.i. es menor que la mida maxima permesa */
  /* Post: s'ha afegit l'estudiant est al par�metre impl�cit */

  void modificar_estudiant(const Estudiant &est);
  /* Pre: existeix un estudiant al par�metre impl�cit amb el DNI d'est  */
  /* Post: l'estudiant del par�metre impl�cit original amb el dni
     d'est, ha quedat substitu�t per est */
		
  void modificar_iessim(int i, const Estudiant &est);
  /* Pre: 1 <= i <= nombre d'estudiants del par�metre impl�cit,
     l'element i-�ssim del conjunt en ordre creixent per DNI cont� 
     un estudiant amb el mateix DNI que est */
  /* Post: l'estudiant est ha substitu�t l'estudiant i-�ssim
     del par�metre impl�cit */

  //Consultores
	
  int mida() const;
  /* Pre: cert */
  /* Post: el resultat �s el nombre d'estudiants del par�metre impl�cit */

  static int mida_maxima();
  /* Pre: cert */
  /* Post: el resultat �s el nombre maxim d'estudiants que pot arribar
     a tenir el par�metre impl�cit */

  bool existeix_estudiant(int dni) const;
  /* Pre: dni >= 0 */
  /* Post: el resultat indica si existeix un estudiant al par�metre impl�cit
     amb DNI = dni */

  Estudiant consultar_estudiant(int dni) const;
  /* Pre: existeix un estudiant al par�metre impl�cit amb DNI = dni */
  /* Post: el resultat �s l'estudiant amb DNI = dni que cont� el 
     par�metre impl�cit */

  Estudiant consultar_iessim(int i) const;
  /* Pre: 1 <= i <= nombre d'estudiants que cont� el par�metre impl�cit */
  /* Post: el resultat �s l'estudiant i-�ssim del par�metre impl�cit 
     en ordre creixent per DNI */
		
  // Lectura i escriptura
	
  void llegir();
  /* Pre: estan preparats al canal est�ndar d'entrada un enter (entre 0 i la
     mida m�xima permesa per a la classe), que representa el nombre d'elements 
     que llegirem, i les dades de tal nombre d'estudiants diferents */
  /* Post: el par�metre impl�cit cont� el conjunt d'estudiants llegits
     del canal est�ndard d'entrada */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit pel canal est�ndard de sortida els estudiants del
     par�metre impl�cit en ordre ascendent per DNI */
};
#endif
