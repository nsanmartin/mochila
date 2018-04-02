
OBJECTS = mochila-fuerza-bruta.o mochila-meet-middle.o tests.o \
			mochila-backtracking.o mochila-dinamica.o mochila-aux.cpp \
			time.o entrada-salida.cpp
CFLAGS = -g -std=c++11 
%.o: %.cpp
	g++ -g -std=c++11 -c -o $@ $<


tdinamica: $(OBJECTS)
	g++ -o build/$@ $(CFLAGS) $@.cpp $^

tentrada-salida: $(OBJECTS)
	g++ -o build/$@ $(CFLAGS) $@.cpp $^
tbacktracking: $(OBJECTS)
	g++ -o build/$@ $(CFLAGS) $@.cpp $^

tfuerza_bruta_4: $(OBJECTS)
	g++ -o build/$@ $(CFLAGS) $@.cpp $^

tfuerza_bruta_3: $(OBJECTS)
	g++ -o build/$@ $(CFLAGS) $@.cpp $^

tmeet_in_the_middle: $(OBJECTS)
	g++ -o build/$@ $(CFLAGS) $@.cpp  $^

ttime: $(OBJECTS)
	g++  -o build/$@ $(CFLAGS) ttime.cpp $^


fuerza-bruta: mochila-fuerza-bruta.o mochila-meet-middle.o
	g++ -o build/$@ -g -std=c++11 mochila.cpp $^

clean:
	find . -name "*.o" -exec rm {} \;
	find . -name "*.exe" -exec rm {} \;
	find . -name "*.exe.stackdump" -exec rm {} \;
	find . -name "*.out" -exec rm {} \;
	rm build/*

