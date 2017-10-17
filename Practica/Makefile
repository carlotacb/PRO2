
program.exe: program.o agenda.o tasca.o rellotge.o comanda.o token.o 
	g++ -o program.exe *.o

agenda.o: agenda.cc agenda.hh rellotge.hh comanda.hh tasca.hh token.hh
	g++ -c agenda.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
program.o: program.cc agenda.hh comanda.hh token.hh
	g++ -c program.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
tasca.o: tasca.cc tasca.hh rellotge.hh
	g++ -c tasca.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
rellotge.o: rellotge.cc rellotge.hh
	g++ -c rellotge.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

comanda.o: comanda.cc comanda.hh token.hh
	g++ -c comanda.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
token.o: token.cc token.hh
	g++ -c token.cc -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x
	
clean:	
	rm *.o
	rm *.exe

cleantar: 
	rm practica.tar
	
practica.tar: 
	tar -cvf practica.tar program.cc agenda.cc agenda.hh rellotge.cc rellotge.hh tasca.cc tasca.hh Makefile
