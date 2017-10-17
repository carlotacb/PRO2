#include "rellotge.hh"

Rellotge::Rellotge() {
  data = "20.04.15";
  hora = "00:00";
}

Rellotge::Rellotge(string d, string h) {
  data = d;
  hora = h;
}


void Rellotge::modifica_hora(string newhora) {
  hora = newhora;
}

void Rellotge::modifica_data(string newdata) {
  data = newdata; 
}

bool Rellotge::operator<(const Rellotge &r) const {
  int any = r.data[7]-'0' + 10*(r.data[6]-'0');
  int mes = r.data[4]-'0' + 10*(r.data[3]-'0');
  int dia = r.data[1]-'0' + 10*(r.data[0]-'0');
  
  int a1 = data[7] -'0' + 10*(data[6]-'0');
  int m1 = data[4] -'0' + 10*(data[3]-'0');
  int d1 = data[1] -'0' + 10*(data[0]-'0');
  
  if (any < a1) return false;
  else if (any > a1) return true;
  else {
    if (mes < m1) return false;
    else if (mes > m1) return true;
    else {
      if (dia < d1) return false;
      else if (dia > d1) return true;
      else {
	return (hora < r.hora);
      }
    }
  }
}  

string Rellotge::consultar_hora(){ 
  return hora;
}

string Rellotge::consultar_data() { 
  return data;
}

void Rellotge::escriure_rellotge() {
  cout << data << " " << hora;
}
