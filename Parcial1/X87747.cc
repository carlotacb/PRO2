#include "utils.PRO2"
#include <vector>

int solitaris(const vector<int> &v) {
 /* Pre: v.size() > 0 */
 /* Post: el resultat es el nombre de solitaris a v */
 
 int n = 0;
 
 for (int i = 1; i < v.size()-1; ++i) {
   if (v[i-1] != v[i] and v[i] != v[i+1]) ++n;
 }
 if (v[0] != v[1]) ++n;
 if (v[v.size()-1] != v[v.size()-2]) ++n;
 return n;
 
}


/*int main() {
  
  int x = readint();
  vector<int> v(x);
  
  for (int i = 0; i < x; ++i) {
    cin >> v[i];
  }
  
  int n = solitaris(v);
  
  cout << n << endl;
}*/