// Archius complementaris: CuaNIOint.hh, Cua.hh i utils.PRO2

void concat(Cua &c) {
/* Pre: c = C */
/* Post: el p.i. passa a ser la concatenaciĂł de C al parĂ metre implĂ­cit, 
   c ĂŠs buida */
  if (c.longitud > 0) {
    if (longitud == 0) {
      primer_node = c.primer_node;
      ultim_node = c.ultim_node;
      longitud = c.longitud;
    }
    else {
      ultim_node -> seguent = c.primer_node;
      ultim_node = c.ultim_node;
      longitud += c.longitud;
    }
    c.primer_node = NULL;
    c.ultim_node = NULL;
    c.longitud = 0;
  }
} 