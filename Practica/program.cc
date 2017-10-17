/** @mainpage Pràctica PRO2: Gestor de Tasques. CARLOTA CATOT BRAGÓS i PAU SUBÍAS MIQUEL
 
En aquest exercici es construeix un programa modular que ofrereix un menú de opcions utilitzant la clase <em>Comanda</em> per gestionar un Gestor de Tasques. 
S'introdueixen les clases <em>Agenda</em>, <em>Tasca</em> i <em>Rellotge</em>.

   Menu d'opcions que es poden realitzar al llarg del programa, desde la entrada que es dona a partir de la clase Comanda:
    
   1) Rellotge: modifica o consulta la hora i data del rellotge intern.

   2) Inserció: afegeix una tasca a l'agenda.
   
   3) Consulta: consulta les tasques d'una data en concret o d'un interval de dates.

   4) Modificació: modifica el títol, data o l'hora d'una tasca futura. També pot afegir etiquetes.
   
   5) Esborrat: Esborra alguna etiqueta de la tasca, o totes les etiquetes de la tasca o tota la tasca sencera.

   6) Acabament: la lectura de la comanda ens indicarà l'acabament, mitjançant un booleà.
   
*/

/** @file main.cc
    @brief Programa principal per l'exercici <em>Gestor de Tasques</em>.
*/

#include "comanda.hh"
#include "agenda.hh"

/** @brief Programa principal per la practica de PRO2 <em>Gestor de Tasques</em>
*/

int main() {
  
  Comanda c;
  Agenda a;
  bool entrar;
  
  while (c.llegir(entrar)) { 
    if (entrar) {
      if (c.es_rellotge()) {  
	if (c.es_consulta()) a.consulta_rellotge();
	else a.modifica_rellotge(c);
      }
      
      else if (c.es_insercio()) a.afegir_tasca(c);
      
      else if (c.es_consulta()) {
	if (c.es_passat()) a.consulta_tasques_passades();
	else {
	  int n = c.nombre_dates();
	  int x = c.nombre_etiquetes();
	  
	  if (x == 0 and not c.te_expressio()) {
	    if (n == 0) { // ?
	      a.consulta_tasques_futures();
	    }
	    else if (n == 1) { // entra una data
	      a.consulta_tasca_interval(c.data(1),c.data(1));
	    }
	    else if (n == 2) { // entra un interval de dates
	      a.consulta_tasca_interval(c.data(1),c.data(2)); 
	    }
	  }
	  
	  else if (x == 1 and not c.te_expressio()) {
	    if (n == 1) { // entra una data i una etiqueta
	      a.consulta_tasca_etiqexpre_interval(c.data(1),c.data(1),c.etiqueta(1));
	    }
	    else if (n == 2) { // entra un interval de dates i una etiqueta
	      a.consulta_tasca_etiqexpre_interval(c.data(1),c.data(2),c.etiqueta(1)); 
	    }
	    else if (n == 0) { // entra una etiqueta
	      a.consulta_tasca_etiqexpre(c.etiqueta(1));
	    }
	  }
	  
	  else if (x == 0 and c.te_expressio()) {
	    if (n == 1) { // entra una data i una expressio
	      a.consulta_tasca_etiqexpre_interval(c.data(1),c.data(2), c.expressio()); 
	    }
	    else if (n == 2) { // entra un interval de dates i una expressio
	      a.consulta_tasca_etiqexpre_interval(c.data(1),c.data(2),c.expressio()); 
	    }
	    else if (n == 0) { // entra una expressio
	      a.consulta_tasca_etiqexpre(c.expressio()); 
	    }
	  }
	}
      }
      
      else if (c.es_modificacio()) a.modificar_tasca(c);
      
      else if (c.es_esborrat()) {
	if (c.tipus_esborrat() == "tasca") a.esborra_tasca(c.tasca()-1);
	else a.esborra_etiquetes(c);
	
      }
    }
  }
} 
