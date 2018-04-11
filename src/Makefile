
CPP_FILES = $(wildcard *.cpp)
_OBJS = $(subst .cpp,.o, $(CPP_FILES))
ODIR=obj
OBJECTS = $(patsubst %,$(ODIR)/%,$(_OBJS))

CFLAGS = -g -std=c++11 

.PHONY = clean

build:
	if [ ! -d build ]; then mkdir build; fi

obj: build
	if [ ! -d obj ]; then mkdir obj; fi


obj/%.o: %.cpp obj
	g++ -g -std=c++11 -c -o $@ $<

tests: ttime ttime-bt-mm-din ttime-bt-din tentrada-salida tdin tbt tmm 


ttime: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

ttime-bt-mm-din: $(OBJECTS) 
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

ttime-bt-din: $(OBJECTS) 
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

ttime-bt-bt2: $(OBJECTS) 
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

tentrada-salida: $(OBJECTS) 
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

tdin: $(OBJECTS) 
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

tbt: $(OBJECTS) 
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

tbt2: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

tmm: $(OBJECTS) 
	g++  -o build/$@ $(CFLAGS) tests/$@.cpp $^

clean:
	rm obj/*
	rm build/*

