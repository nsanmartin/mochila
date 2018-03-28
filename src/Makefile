
OBJECTS = mochila-fuerza-bruta.o mochila-meet-middle.o tests.o mochila_random.cpp

%.o: %.cpp
	g++ -g -std=c++11 -c -o $@ $<

tmeet_in_the_middle: $(OBJECTS)
	g++ -o $@ -g -std=c++11 $@.cpp  $^

tests: mochila-fuerza-bruta.o mochila-meet-middle.o tests.o
	g++ -g -std=c++11 mochila.cpp $^


fuerza-bruta: mochila-fuerza-bruta.o mochila-meet-middle.o
	g++ -g -std=c++11 mochila.cpp $^

clean:
	find . -name "*.o" -exec rm {} \;
	find . -name "*.exe" -exec rm {} \;
	find . -name "*.exe.stackdump" -exec rm {} \;
	find . -name "*.out" -exec rm {} \;


