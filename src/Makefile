
OBJECTS = mochila-fuerza-bruta.o mochila-meet-middle.o \
			mochila-backtracking.o mochila-dinamica.o mochila-aux.o \
			time.o entrada-salida.o 
CFLAGS = -g -std=c++11 
%.o: %.cpp
	g++ -g -std=c++11 -c -o $@ $<


ttime: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) $@.cpp $^

ttime-bt-mm-din: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) $@.cpp $^

ttime-bt-din: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) $@.cpp $^

tentrada-salida: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) $@.cpp $^

tdin: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) $@.cpp $^


clean:
	find . -name "*.o" -exec rm {} \;
	find . -name "*.exe" -exec rm {} \;
	find . -name "*.exe.stackdump" -exec rm {} \;
	find . -name "*.out" -exec rm {} \;
	rm build/*

