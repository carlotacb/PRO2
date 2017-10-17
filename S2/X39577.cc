#include "utils.PRO2"
#include "Estudiant.hh"
#include <vector>


int main() {
  int m = readint(); // numero d'estudiants.
  int n = readint(); // numero d'assignatures.
  int s = readint(); // numero d'assignatures a seleccionar.
  
  vector<int> sel(s);
  for (int i = 0; i < s; ++i) sel[i] = readint();
  
  for (int i = 0; i < m; ++i) {
    double nota = 0;
    Estudiant est;
    est.llegir(); 
    
    vector<double> notes(n-1);
    for (int j = 0; j < n-1; ++j) notes[j] = readdouble();
    
    for (int k = 0; k < s; ++k) {
      int pos = sel[k];
      
      if (pos == 1) nota += est.consultar_nota();
      else {
	nota += notes[pos-2];
      }
    }
    
    nota = nota/s;
    
    est.modificar_nota(nota);
    est.escriure();
  }
} 