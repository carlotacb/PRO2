/** @file Agenda.hh
    @brief Classe Agenda
 */

#ifndef AGENDA_HH
#define AGENDA_HH

#include <list>
#include <vector>
#include "utils.PRO2"
#include "tasca.hh"
#include "rellotge.hh"
#include "comanda.hh"

/** @class Agenda
    @brief Representa la Agenda del nostre Gestor de Tasques
 */

class Agenda {
  
  // Descripcion: Conté el rellotge intern de la Ageda, la llista de tasques i un menú amb les tasques actuals.

private:
  
  /* Una Agenda es representa mitjançant un Rellotge, una llista de tasques i un menú amb les tasques demanades (futures o passades) */
  
  /** @brief Rellotge amb la data i la Hora actuals */
  Rellotge intern;
  /** @brief Llista amb totes les tasques (passades i futures) de l'agenda */
  list<Tasca> ltasques;
  /** @brief Vector d'iteradors que conté les posicions de les tasques demanades de l'agenda depenen de la consulta realitzada */
  vector<list<Tasca>::iterator> menu;
  
public:
    
    // Constructores:
  
      /** @brief Constructora per defecte: s'executara automaticament al declarar una agenda.
      
      \pre cert
      \post  S'ha inicialitzat una agenda buida*/
      
      Agenda();
  
      
    // Modificadora:
      
      /** @brief Afegeix una tasca a la agenda.
      
      \pre cert 
      \post La Tasca llegida a la funció, s'ha afegit a la agenda */
      
      void afegir_tasca(Comanda& c);
      
      /** @brief Modifica una tasca de l'agenda.
      
      \pre cert
      \post La tasca llegida a la funció, ha quedat modificada pels nous valors llegits */
      
      void modificar_tasca(Comanda& c);
      
      /** @brief Modifica el rellotge intern de l'agenda.
      
      \pre n indica la modificació del rellotge: 1-hora; 2-data; 3-data_i_hora. 
      \post El rellotge intern de l'agenda ha quedat modificat pels nous valors llegits segons el parametre n */
      
      void modifica_rellotge(Comanda& c);
      
      /** @brief Esborra la tasca.
      
      \pre k indica la posicio de la agenda on es troba la tasca a esborrar
      \post La tasca de la posició k ha estat esborrada de l'agenda */
      
      void esborra_tasca(int k);
      
      /** @brief Esborra totes les etiquetes d'una tasca de la agenda.
      
      \pre "k" es un valor inferior al tamany del menu i "tot" es cert si les elimina totes i "s", en el cas de "tot" false, es la etiqueta a esborrar. 
      \post totes les etiquetes de la tasca que es troba en la posicio "k" del menu han estat esborrades */
      
      void esborra_etiquetes(Comanda& c);
      
    // Consultores:
      
      /** @brief Consulta si la data es posterior a la data del rellotge intern.
      
      \pre cert.
      \post cert en el cas de que la data sigui valida, es a dir, posterior a la actual */
      
      bool consultar_data_valida(string data);
      
      /** @brief Consulta el rellotge intern.
      
      \pre cert.
      \post imprimeix la data i hora del rellotge intern */
      
      void consulta_rellotge();

      void consulta_tasques_passades();
      
      void consulta_tasques_futures();
      
      /** @brief Consulta la tasca de un interval de dates en concret.
      
      \pre "data1" i "data2" es un interval valid i són posteriors a la data actual.
      \post  Retorna el els paramtres de la tasca del interval de dates pasats com a paramtres */
      
      void consulta_tasca_interval(string data1, string data2);      
      
      /** @brief Consulta la tasca a partir d'una etiqueta.
      
      \pre cert
      \post imprimeix les tasques futures que contenen la etiqueta o expressio "expre" */
      
      void consulta_tasca_etiqexpre(string eti);
      
      /** @brief Consulta la tasca a partir d'un interval de dates i una etiqueta o expressio d'etiquetes booleanes.
      
      \pre cert
      \post imprimeix les tasques que estan contingudes a l'interval de les dates demanades i que contenen la etiqueta o expressio "expre"  */
      
      void consulta_tasca_etiqexpre_interval(string data1, string data2, string expre);


      
};

#endif 
