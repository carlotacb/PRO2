#include "agenda.hh"

Agenda::Agenda() { }

void Agenda::afegir_tasca(Comanda& c) {
  string d,h;
  
  h = c.hora();
  if (c.nombre_dates() == 1) d = c.data(1);
  else d = intern.consultar_data();
  Rellotge aux(d,h);
  if (aux < intern) cout << "No s'ha realitzat" << endl;
  else {
    list<Tasca>::iterator it = ltasques.begin();
    Tasca t;
    t.modifica_data(d);
    t.modifica_hora(h);
    if (c.te_titol()) t.modifica_titol(c.titol());
    int x = c.nombre_etiquetes();
    for (int i = 1; i <= x; ++i) {
      if (not t.existeix_etiqueta(c.etiqueta(i))) t.afegeix_etiquetes(c.etiqueta(i));
    }
    if (ltasques.empty()) ltasques.insert(it,t);
    else {
      bool posat = false;
      while (it != ltasques.end() and not posat) {
	Rellotge r = (*it).consulta_rellotge_tasca();
	if (aux < r) {
	  ltasques.insert(it,t);
	  posat = true;
	}
	else if (r < aux) ++it;
	else {
	  posat = true;
	  cout << "No s'ha realitzat" << endl;
	}
      }
      if (not posat) ltasques.insert(it,t);
    }
  }
}

void Agenda::modificar_tasca(Comanda& c) {
  int w = c.tasca() - 1;
  if (w >= menu.size()) cout << "No s'ha realitzat" << endl;
  else if (menu[w] == ltasques.end()) cout << "No s'ha realitzat" << endl;
  else if ((*menu[w]).consulta_rellotge_tasca() < intern) cout << "No s'ha realitzat" << endl; 
  else {
    list<Tasca>::iterator it = menu[w];
    Tasca aux = (*it);
    Tasca t = (*it);
    bool reordenar = false;
    if (c.te_titol()) t.modifica_titol(c.titol());
    if (c.te_hora()) {
      t.modifica_hora(c.hora());
      reordenar = true;
    }
    int n = c.nombre_dates();
    if (n == 1) {
      t.modifica_data(c.data(1));
      reordenar = true;
    }
    int x = c.nombre_etiquetes();
    if (x != 0) {
      for (int i = 1; i <= x; ++i) {
	if (not t.existeix_etiqueta(c.etiqueta(i))) t.afegeix_etiquetes(c.etiqueta(i));
      }
    }
    
    Rellotge r_aux = t.consulta_rellotge_tasca();
       
    if (reordenar) {
      if (intern < r_aux) {
	it = ltasques.erase(it);
	list<Tasca>::iterator it_aux = ltasques.begin();
	bool posat = false;
	while (it_aux != ltasques.end() and not posat) {
	  Rellotge r = (*it_aux).consulta_rellotge_tasca();
	  if (r < r_aux) ++it_aux;
	  else if (r_aux < r) {
	    ltasques.insert(it_aux,t);
	    posat = true;
	    --it_aux;
	    menu[w] = it_aux;
	  }
	  else {
	    posat = true;
	    cout << "No s'ha realitzat" << endl;
	    ltasques.insert(it,aux);
	    --it;
	    menu[w] = it;
	  }
	}
	if (not posat) {
	  ltasques.insert(it_aux,t);
	  --it_aux;
	  menu[w] = it_aux;
	}
      }
      else {
	cout << "No s'ha realitzat" << endl;
      }
    }
    
    else if (not reordenar) {
      (*it) = t;
    }
  }
}

void Agenda::modifica_rellotge(Comanda& c) {
  if (c.nombre_dates() == 0 and c.te_hora()) {
    if (c.hora() < intern.consultar_hora()) cout << "No s'ha realitzat" << endl;
    else intern.modifica_hora(c.hora());
  }
  else if (c.nombre_dates() == 1 and not c.te_hora()) {
    Rellotge aux(c.data(1),intern.consultar_hora());
    if (aux < intern) cout << "No s'ha realitzat" << endl;
    else intern.modifica_data(c.data(1));
  }
  else if (c.nombre_dates() == 1 and c.te_hora()) {
    Rellotge aux(c.data(1),c.hora());
    if (aux < intern) cout << "No s'ha realitzat" << endl;
    else {
      intern.modifica_hora(c.hora());
      intern.modifica_data(c.data(1));
    }
  }
}

void Agenda::esborra_tasca(int k) {
  if (k >= menu.size()) cout << "No s'ha realitzat" << endl;
  else if (menu[k] == ltasques.end()) cout << "No s'ha realitzat" << endl;
  else if ((*menu[k]).consulta_rellotge_tasca() < intern) cout << "No s'ha realitzat" << endl;
  else {
    list<Tasca>::iterator it = menu[k];
    menu[k] = ltasques.end();
    it = ltasques.erase(it);
  }
}

void Agenda::esborra_etiquetes(Comanda& c) {
  int k = c.tasca()-1;
  if (k >= menu.size()) cout << "No s'ha realitzat" << endl;
  else if (menu[k] == ltasques.end()) cout << "No s'ha realitzat" << endl;
  else if ((*menu[k]).consulta_rellotge_tasca() < intern) cout << "No s'ha realitzat" << endl;
  else {
    list<Tasca>::iterator it = menu[k];
    string s = c.tipus_esborrat();
    if (s == "etiquetes") (*it).esborra_totes_etiquetes();
    else if (s == "etiqueta") {
      string eti = c.etiqueta(1);
      (*it).esborra_etiqueta(eti);
    }
  }
}
  
bool Agenda::consultar_data_valida(string data) {
  Rellotge aux(data, intern.consultar_hora());
  if (aux < intern) return false;
  else return true;
}
      
void Agenda::consulta_rellotge() { 
  intern.escriure_rellotge();
  cout << endl;
}

void Agenda::consulta_tasques_passades() {
  list<Tasca>::iterator it = ltasques.begin();
  bool present = false;
  int contador = 1;
  menu.clear();
  while (not present and it != ltasques.end()) {
    Rellotge r = (*it).consulta_rellotge_tasca();
    if (r < intern) {
      menu.push_back(it);
      cout << contador << " ";
      (*it).escriure_tasca();
      ++contador;
    }
    else present = true;
    ++it;
  }
}

void Agenda::consulta_tasques_futures() { 
  list<Tasca>::iterator it = ltasques.begin();
  int contador = 1;
  menu.clear();
  while (it != ltasques.end()) {
    Rellotge r = (*it).consulta_rellotge_tasca();
    if (r < intern) ++it;
    else  {
      menu.push_back(it);
      cout << contador << " ";
      (*it).escriure_tasca();
      ++contador;
      ++it;
    }
  }
}


void Agenda::consulta_tasca_interval(string data1, string data2) {
  Rellotge auxi(data1,"00:00");
  Rellotge auxf(data2,"23:59");
  
  if (auxi < intern and intern < auxf) {
    list<Tasca>::iterator it = ltasques.begin();
    bool trobat = false;
    int contador = 1;
    menu.clear();
    while (not trobat and it != ltasques.end()) {
      Rellotge r = (*it).consulta_rellotge_tasca();
      if (r < intern) ++it;
      else if (r < auxf) {
	menu.push_back(it);
	cout << contador << " ";
	(*it).escriure_tasca();
	++contador;
	++it;
      }
      if (auxf < r) trobat = true;
    }
  }
    
  else if (intern < auxi and intern < auxf) {
    list<Tasca>::iterator it = ltasques.begin();
    bool trobat = false;
    int contador = 1;
    menu.clear();
    while (not trobat and it != ltasques.end()) {
      Rellotge r = (*it).consulta_rellotge_tasca();
      if (auxi < r and r < auxf) {
	menu.push_back(it);
	cout << contador << " ";
	(*it).escriure_tasca();
	++contador;
      }
      if (auxf < r) trobat = true; 
      ++it;
    }
  }
}

void Agenda::consulta_tasca_etiqexpre(string expre) {
  
  list<Tasca>::iterator it = ltasques.begin();
  int contador = 1;
  menu.clear();
  while (it != ltasques.end()) {
    Rellotge r = (*it).consulta_rellotge_tasca();
    if (r < intern) ++it;
    else {
      if ((*it).satisfa_expressio(expre)) {
	menu.push_back(it);
	cout << contador << " ";
	(*it).escriure_tasca();
	++contador;
      }
      ++it;
    }
  }
}

void Agenda::consulta_tasca_etiqexpre_interval(string data1, string data2, string expre) {
  Rellotge auxi(data1,"00:00");
  Rellotge auxf(data2,"23:59");
  
  if (auxi < intern and intern < auxf) {
    list<Tasca>::iterator it = ltasques.begin();
    bool trobat = false;
    int contador = 1;
    menu.clear();
    while (not trobat and it != ltasques.end()) {
      Rellotge r = (*it).consulta_rellotge_tasca();
      if (r < intern) ++it;
      else if (r < auxf) {
	if ((*it).satisfa_expressio(expre)) {
	  menu.push_back(it);
	  cout << contador << " ";
	  (*it).escriure_tasca();
	  ++contador;
	} 
	++it;
      }
      if (auxf < r) trobat = true;
    }
  }
  
  if (intern < auxi and intern < auxf) {
    list<Tasca>::iterator it = ltasques.begin();
    bool trobat = false;
    int contador = 1;
    menu.clear();
    while (not trobat and it != ltasques.end()) {
      Rellotge r = (*it).consulta_rellotge_tasca();
      if (auxi < r and r < auxf) {
	if ((*it).satisfa_expressio(expre)) {
	  menu.push_back(it);
	  cout << contador << " ";
	  (*it).escriure_tasca();
	  ++contador;
	} 
      }
      if (auxf < r) trobat = true; 
      ++it;
    }
  }
}