_OBJS = mochila-fuerza-bruta.o mochila-meet-middle.o \
			mochila-backtracking.o mochila-dinamica.o mochila-aux.o \
			time.o entrada-salida.o
ODIR=obj
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJS))

CFLAGS = -g -std=c++11 

.PHONY = clean

obj/%.o: %.cpp
	g++ -g -std=c++11 -c -o $@ $<

tests: ttime ttime-bt-mm-din ttime-bt-din tentrada-salida tdin tbt tmm 

ttime: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

ttime-bt-mm-din: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

ttime-bt-din: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

tentrada-salida: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

tdin: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

tbt: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

tmm: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

clean:
	rm obj/*
	rm build/*

