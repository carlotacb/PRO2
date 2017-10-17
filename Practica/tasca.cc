#include "tasca.hh"

Tasca::Tasca() { }

Tasca::Tasca(string tit, string data, string hora) { 
  titol = tit;
  dataihora = Rellotge(data,hora);
}
      
void Tasca::modifica_hora(string newhora) { dataihora.modifica_hora(newhora); }

void Tasca::modifica_data(string newdata) { dataihora.modifica_data(newdata); }  

void Tasca::modifica_titol(string newtitol) { titol = newtitol; }

void Tasca::afegeix_etiquetes(string newetiqueta) {
  
  list<string>::iterator it = etiquetes.begin();
  if (etiquetes.empty()) etiquetes.insert(it, newetiqueta);
  else {
    bool posat = false;
    while (not posat and it != etiquetes.end()) {
      if ((*it) > (newetiqueta)) {
	etiquetes.insert(it,newetiqueta);
	posat = true;
      }
      else ++it;
    }
    if (not posat) etiquetes.insert(it,newetiqueta);
  }
}

void Tasca::esborra_etiqueta(string etiqueta) {
  list<string>::iterator it = etiquetes.begin();
  bool trobat = false;
  while (not trobat and it != etiquetes.end()) {
    if ((*it) == etiqueta) trobat = true;
    else ++it;
  }
  if (trobat) it = etiquetes.erase(it);
  else cout << "No s'ha realitzat" << endl;
}

void Tasca::esborra_totes_etiquetes() { etiquetes.clear(); }

Rellotge Tasca::consulta_rellotge_tasca() { return dataihora; }

bool Tasca::i_satisfa_expressio(const string& expre, int& i) {
  bool trobat; 
  if (expre[i] == '#') {
    string etiq;
    while (i < expre.size() and expre[i] != '.' and expre[i] != ',' and expre[i] != ')') {
      char c = expre[i];
      etiq = etiq + c;
      ++i;
    }
    trobat = existeix_etiqueta(etiq);
  }

  else {
    int cont = 1;
    ++i;
    trobat = i_satisfa_expressio(expre, i);
    char c = expre[i]; 
    if (c == ',') {
      if (trobat) avancar(expre,i,cont);
      else {
	++i;
	trobat = i_satisfa_expressio(expre,i);
	++i;
      }
    }
    else if (c == '.') {
      if (not trobat) avancar(expre,i,cont);
      else {
	++i;
	trobat = i_satisfa_expressio(expre,i);
	++i;
      }  
    }    
  }
  return trobat;
} 
   
void Tasca::avancar(const string& expre, int& i, int& cont) {
  
  while (cont != 0) {
    if (expre[i] == ')') --cont;
    else if (expre[i] == '(') ++cont;
    ++i;
  }
}


bool Tasca::satisfa_expressio(string expre) {
  int i = 0;
  return i_satisfa_expressio(expre, i);
}

bool Tasca::existeix_etiqueta(string eti) {
  list<string>::iterator it = etiquetes.begin();
  bool trobat = false;
  while (not trobat and it != etiquetes.end()) {
    if ((*it) == eti) trobat = true;
    else ++it;
  }
  return trobat;
}

void Tasca::escriure_tasca() {  
  cout << titol << " " ;
  dataihora.escriure_rellotge();
  
  if (not etiquetes.empty()) {
    list<string>::iterator it;
    for (it = etiquetes.begin(); it != etiquetes.end(); ++it) {
      cout << " " << (*it);
    }
  } 
  cout << endl;
}