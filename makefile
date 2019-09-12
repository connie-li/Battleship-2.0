Battleship: main.o map.o ship.o exec.o
	g++ -std=c++11 -g -Wall main.o map.o ship.o exec.o -o Battleship

main.o: main.cpp map.h
	g++ -std=c++11 -g -Wall -c main.cpp

map.o: map.h map.cpp
	g++ -std=c++11 -g -Wall -c map.cpp

ship.o: ship.h ship.cpp
	g++ -std=c++11 -g -Wall -c ship.cpp

exec.o: exec.h exec.cpp
	g++ -std=c++11 -g -Wall -c exec.cpp

clean:
	rm *.o Battleship
