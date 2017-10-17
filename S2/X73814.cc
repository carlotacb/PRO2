#include "utils.PRO2"
#include "Estudiant.hh"
#include <vector>

void simplificar_vector(const vector<Estudiant>& vesto, vector<Estudiant>& vestr, int& contador) {
  
  double nota = vesto[0].consultar_nota();
  int dni = vesto[0].consultar_DNI();
    
  for (int i = 1; i < vesto.size(); ++i) {  
    
    if (vesto[i].te_nota() and vesto[i].consultar_DNI() == dni) {
      if (vesto[i].consultar_nota() > nota) nota = vesto[i].consultar_nota();
    }
    if (vesto[i].consultar_DNI() != dni) {
      
      vestr[contador] = Estudiant(dni);
      if (nota != -1) vestr[contador].afegir_nota(nota);
      ++contador;
      
      dni = vesto[i].consultar_DNI();
      if (vesto[i].te_nota()) nota = vesto[i].consultar_nota();
      else nota = -1;
      
    }
  }
  vestr[contador] = Estudiant(dni);
  if (nota != -1) vestr[contador].afegir_nota(nota);
  ++contador;
}


int main() {
  int n = readint();
  vector<Estudiant> vesto(n);
  vector<Estudiant> vestr(n);
  for (int i = 0; i < n; ++i) vesto[i].llegir();
  int cont = 0;
  simplificar_vector(vesto,vestr,cont);
  for (int j = 0; j < cont; ++j) vestr[j].escriure();
}