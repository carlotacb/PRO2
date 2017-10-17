/** @file Rellotge.hh
    @brief Classe Rellotge
 */

#ifndef RELLOTGE_HH
#define RELLOTGE_HH

#include <string>  // Comentar a l'hora de fer Doxigen
#include "utils.PRO2"

/** @class Rellotge
    @brief Representa el rellotge intern del gestor de tasques, amb la Data i la Hora.
 */

class Rellotge {
  
  // Descripcion: Conté la Data i la Hora en forma de strings
  
private:
  
  /* Un Rellotge es representa mitjançant dos strings: la data i la hora */
  
  /** @brief Hora del Rellotge en forma de string (**:**) */
  string hora;
  /** @brief Data del Rellotge en forma de string (**.**.**) */
  string data;

public:
    // Constructores:
  
    /** @brief Constructora per defecte.
    
    S'executara automaticament al declarar un rellotge.
    \pre cert 
    \post s'ha inicialitzat un rellotge sense data i hora */
    
    Rellotge(); 
    
    /** @brief Constructora per valors.
    
    \pre cert 
    \post s'ha inicialitzat un rellotge amb data = d i hora = h */
    
    Rellotge(string d, string h); 
    
    // Modificadores:
    
    /** @brief Modifica la hora del rellotge intern en el cas que sigui posterior a la actual.
    
    \pre newhora >= hora
    \post la hora del parametre implicit ha quedat modificada prenent per valor "newhora" */
    void modifica_hora(string newhora);
    
    /** @brief Modifica la data del rellotge intern en el cas que sigui posterior a la actual.
    
    \pre newdata >= data 
    \post la data del parametre implicit ha quedat modificada prenent per valor "newdata" */
    void modifica_data(string newdata);
    
    /** @brief Compara dos rellotges.
    
    \pre cert
    \post retorna cert en el cas de que es cumpleixi la expressio (<) */
    
    bool operator<(const Rellotge &r) const;
       
    // Consultores:
    
     /** @brief Consulta la hora del rellotge intern.
    
    \pre cert 
    \post retorna la hora del parametre implícit */
    string consultar_hora();
    
     /** @brief Consulta la data del rellotge intern.
    
    \pre cert 
    \post retorna la hora del parametre implícit */
    string consultar_data();
    
    // Escriptura:
    
    /** @brief Escriu la hora i la data del rellotge
      
    \pre cert
    \post escriu pel canal estandard de sortida el parametre implicit */
    void escriure_rellotge();
    
    
};

#endif 
