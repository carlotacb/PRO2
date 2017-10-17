// Archius complementaris: ArbreGIOint.hh, ArbreG.hh i utils.PRO2

bool recbuscar (const T& x, node_arbreGen* m) const {
	if (m == NULL) return false;
	else if (m->info == x) return true;
	else {
		bool trobat = false;
		int i = 0;
		while (i < m->seg.size() and not trobat) {
			if (recbuscar(x,m->seg[i])) trobat = true;
			else ++i;
		}
		return trobat;
	}
}

bool buscar(const T& x) const {
	/* Pre: cert */
	/* Post: el resultat indica si x es troba al p.i. o no */
	return recbuscar(x, primer_node);
}