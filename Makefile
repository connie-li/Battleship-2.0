Battleship: main.o map.o exec.o
	g++ -std=c++11 -g -Wall main.o map.o exec.o -o Battleship
        
exec.o: Executive.h Executive.cpp Admiral.h
        g++ -std=c++11 -g -Wall -c Executive.cpp

admiral.o: Admiral.h Admiral.cpp Grid.h Ship.h PowerUps.h
    g++ -std=c++11 -g -Wall -c Admiral.cpp

grid.o: Grid.h Grid.cpp
        g++ -std=c++11 -g -Wall -c Grid.cpp

ship.o: Ship.h Ship.cpp
    g++ -std=c++11 -g -Wall -c Ship.cpp

power.o: PowerUps.h PowerUps.cpp Grid.h Ship.h
        g++ -std=c++11 -g -Wall -c PowerUps.cpp


clean:
    rm *.o Battleship

