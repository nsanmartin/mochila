
%.o: %.cpp
	g++ -g -std=c++11 -c -o $@ $<

fuerza-bruta: mochila-fuerza-bruta.o mochila-meet-middle.o
	g++ -g -std=c++11 mochila.cpp $^

clean:
	find . -name "*.o" -exec rm {} \;
	find . -name "*.exe" -exec rm {} \;
	find . -name "*.out" -exec rm {} \;


