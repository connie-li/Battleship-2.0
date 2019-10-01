Battleship: main.o map.o exec.o
	g++ -std=c++11 -g -Wall main.o map.o exec.o -o Battleship

main.o: main.cpp map.h
	g++ -std=c++11 -g -Wall -c main.cpp

map.o: map.h map.cpp
	g++ -std=c++11 -g -Wall -c map.cpp

exec.o: exec.h exec.cpp
	g++ -std=c++11 -g -Wall -c exec.cpp

clean:
	del *.o Battleship.exe
