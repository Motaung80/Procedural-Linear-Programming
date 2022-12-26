ofiles	=	main.o	ingredient.o	cauldron.o
gpp_o	=	g++	-c	-std=c++98	-static

main:	$(ofiles)
	g++	-std=c++98	-static	$(ofiles)	-o	main

main.o:	main.cpp	ingredient.h	cauldron.h
	$(gpp_o)	main.cpp

ingredient.o:	ingredient.cpp	cauldron.h
	$(gpp_o)	ingredient.cpp

cauldron.o:	cauldron.cpp	cauldron.h	ingredient.h
	$(gpp_o)	cauldron.cpp

run:	main
	./main

clean:
	rm	*.o	main

tar:
	tar	-cvz	*.cpp	*.h	makefile	-f	u19345993.tar.gz
