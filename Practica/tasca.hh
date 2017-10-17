/** @file Tasca.hh
    @brief Classe Tasca
 */

#ifndef TASCA_HH
#define TASCA_HH

#include "rellotge.hh"
#include <list>

/** @class Tasca
    @brief Representa una tasca de l'agenda.
 */

class Tasca {
  
  // Descripcion: conté el Rellotge, el titol i les etiquetes d'una tasca.

private:
  
  /* Una tasca es representa mitjançant el titol, la data i la hora que son de la
   forma de rellotge i les etiquetes de forma de llista */
  
  /** @brief Titol de la Tasca */
  string titol;
  /** @brief Data i Hora de la Tasca */
  Rellotge dataihora;
  /** @brief Llista de les etiquetes de la tasca */
  list<string> etiquetes;
  /** @brief Funció d'inmersio per comprovar si la expressio booleana satisfa l'expresio per la tasca 
  
  \pre i = I i "i" pot tenir dos valors inicials # o ( 
  \post si "I" es # "i" acabarà essent el valor seguent a l'ultim caracter de la etiqueta, en el cas de que I sigui ( inicialment, "i" acabarà essent el 
  valor seguent despres del parentesi que tancarà el primer parentesi incial de "I".
  */
  bool i_satisfa_expressio(const string& expre, int& i);
  
  static void avancar(const string& expre, int& i, int& cont);
  
public:
      // Constructores:

      /** @brief Constructora per defecte.

      S'executara automaticament al declarar una tasca.
      \pre cert 
      \post s'ha inicialitzat una tasca*/

      Tasca();
      
      /** @brief Constructora per valors.
    
      \pre cert 
      \post s'ha inicialitzat una tasca amb titol, data, hora*/

      Tasca(string tit, string data, string hora);
            
      // Modificadores:
      
      /** @brief Modifica la data de la tasca actual.
    
      \pre newdata >= data
      \post la hora del parametre implicit ha quedat modificada prenent per valor "newhora" */

      void modifica_data(string newdata);
      
      /** @brief Modifica la data del rellotge intern en el cas que sigui posterior a la actual.
      
      \pre newdata >= hora
      \post la data del parametre implicit ha quedat modificada prenent per valor "newdata" */
      
      void modifica_hora(string newhora);    
      
      /** @brief Modifica el titol de la tasca actual.
      
      \pre cert
      \post el titol del parametre implicit ha quedat modificat prenent un titol "newtitol"*/
      
      void modifica_titol(string newtitol);
      
      /** @brief Afegeix una etiqueta a la nostre tasca.
      
      \pre cert
      \post "newetiqueta" s'ha afegit al parametre implicit. */
      
      void afegeix_etiquetes(string newetiqueta);
      
      /** @brief Esborra una etiqueta de la nostre tasca.
      
      \pre La etiqueta existeix i es troba en el parametre implicit
      \post S'ha esborrat "etiqueta" */
            
      void esborra_etiqueta(string etiqueta);
      
      /** @brief Esborra totes les etiquetes de la nostre tasca.
      
      \pre cert
      \post s'han esborrat totes les etiquetes del parametre implicit */
      
      void esborra_totes_etiquetes();

      // Consultores:

      /** @brief Consulta el dia i la hora de la tasca
      
      \pre cert
      \post retorn el rellotge de la tasca */
      
      Rellotge consulta_rellotge_tasca();
      
      /** @brief Consulta si la expressió es certa 
      
      \pre cert
      \post retorna true en el cas de que la tasca del parametre implicit satisfa de l'expressió */
      
      bool satisfa_expressio(string expre);
      
      /** @brief Consulta si la etiqueta pertany a la tasca
      
      \pre cert
      \post retorna cert en el cas de que la etiqueta "eti" pertanyi a la tasca */
      
      bool existeix_etiqueta(string eti); 

      // Escriure:

      /** @brief Escriu la tasca completa (id, titol, data, hora, etiquetes.
      
      \pre cert
      \post Imprimeix pel canal estandard de sortida la tasca */
      
      void escriure_tasca();

};

#endif 
