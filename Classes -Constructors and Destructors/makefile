ofiles	=	main.o	factory.o	drone.o
gpp_o	=	g++	-c	-std=c++11	-static

main:	$(ofiles)
	g++	-std=c++11	-static	$(ofiles)	-o	main

main.o:	main.cpp	factory.h	drone.h
	$(gpp_o)	main.cpp

Drone.o:	drone.cpp	drone.h
	$(gpp_o)	Drone.cpp

Factory.o:	factory.cpp	factory.h	drone.h
	$(gpp_o)	factory.cpp

run:	main
	./main

clean:
	rm	*.o	main

tar:
	tar	-cvz	*.cpp	*.h	makefile	-f	u19345993.tar.gz