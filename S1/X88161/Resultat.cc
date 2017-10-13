#include "utils.PRO2"
#include <vector>
#include <algorithm>

struct parint {
  int x, y;
};

struct quatreint {
  int idequip;
  int punts;
  int golsmarcats;
  int golsrebuts;
};

typedef vector <vector<parint> > Matriu_part;

void llegirmatrius_parint(Matriu_part& m, int nequips) {
  
  m = Matriu_part (nequips, vector<parint>(nequips));
  for (int i = 0; i < nequips; ++i){
    for (int j = 0; j < nequips; ++j) {
	m[i][j].x = readint();
	m[i][j].y = readint();
    }
  }
}

void escriurevector(const vector<quatreint> clasi) {
  for (int i = 0; i < clasi.size(); ++i) {
    cout << clasi[i].idequip << " " << clasi[i].punts << " " << clasi[i].golsmarcats << " " << clasi[i].golsrebuts << endl;
  }
}

int calcul_punts (const Matriu_part& m, int equip, int& golsmarc, int& golsreb) {
  int punts = 0;
  for (int i = 0; i < m.size(); ++i) {
    for (int j = 0; j < m.size(); ++j) {
      if (i == equip and j != equip) {
	if (m[i][j].x == m[i][j].y) ++punts;
	else if (m[i][j].x > m[i][j].y) punts += 3;
	golsmarc += m[i][j].x;
	golsreb += m[i][j].y;
      }
      
      else if (j == equip and i != equip) {
	if (m[i][j].x == m[i][j].y) ++punts;
	else if (m[i][j].x < m[i][j].y) punts += 3;
	golsmarc += m[i][j].y;
	golsreb += m[i][j].x;
      }
    }
  }
  return punts;
}

void carregar_structquatre (vector<quatreint>& clasi, int nequips,const Matriu_part& m) {
  int golsmarc = 0;
  int golsreb = 0;
  
  clasi = vector<quatreint> (nequips);

  for (int i = 0; i < nequips; ++i) {
    clasi[i].idequip = i+1;
    clasi[i].punts = calcul_punts(m,i,golsmarc,golsreb);
    clasi[i].golsmarcats = golsmarc;
    clasi[i].golsrebuts = golsreb;

    golsmarc = golsreb = 0;
  }
}

bool comp(const quatreint& a, const quatreint& b) {
  if (a.punts == b.punts) {
    if (a.golsmarcats-a.golsrebuts == b.golsmarcats-b.golsrebuts) return a.idequip < b.idequip;
    else return a.golsmarcats-a.golsrebuts > b.golsmarcats-b.golsrebuts;
  }
  else return a.punts > b.punts;
}


int main() {
  
  int nequips = readint();
  Matriu_part taula;
  
  llegirmatrius_parint(taula,nequips);
  vector<quatreint> sol;  
  
  carregar_structquatre(sol,nequips,taula);
  
  sort (sol.begin(), sol.end(), comp);

  escriurevector(sol);
  
}