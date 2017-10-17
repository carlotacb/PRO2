#include "utils.PRO2"
#include "Estudiant.hh"
#include <vector>

void tracta_estudiant(vector<Estudiant> &est, int n, const vector<int> &ass) {
  int dni;
  cin>>dni;
  vector<double> notas(n);
  for (int i=0; i<n; ++i) cin>>notas[i];
  double mitja=0.0;
  for (int i=0; i<ass.size(); ++i) mitja+=notas[ass[i]];
  mitja/=ass.size();
  Estudiant e(dni);
  e.afegir_nota(mitja);
  est.push_back(e);
}

int main() {
  int m, n, s;
  cin>>m>>n>>s;
  vector<Estudiant> est;
  vector<int> ass(s);
  for (int i=0; i<s; ++i) {
    cin>>ass[i];
    --ass[i];
  }
  for (int i=0; i<m; ++i) tracta_estudiant(est, n, ass);
  for (int i=0; i<m; ++i) est[i].escriure();
  return 0;
}

/*int main() {
  int m = readint(); // numero d'estudiants.
  int n = readint(); // numero d'assignatures.
  int s = readint(); // numero d'assignatures a seleccionar.

  vector<Estudiant> estudiants(m);
  
  vector<int> sel(s);
  for (int i = 0; i < s; ++i) sel[i] = readint();

  for (int i = 0; i < m; ++i) {
    double nota = 0;
    Estudiant est;
    est.llegir(); 

    estudiants[i] = est;
    
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
    
    estudiants[i] = est.modificar_nota(nota);
  }


} */