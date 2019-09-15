#include "exec.h"
#include "map.h"
#include <iostream>
#include <signal.h>

void exec::run()
{
  //First ask number of ships.
  //create playerOneMap with that number, allowing them to place.
  //repeat with playerTwoMap.
  //begin looping using while loop, using the gameOver() function to know when to stop.
  //each loop prints a shot map and their own map, then allows player to fire on the others board.
  //Once a gameOver() kills the loop, congratulate the winning player.
  //delete maps.
  //end code.
  bool gamerun = true;
  char* c = ""; //collums
  int row;
  int ship_num;
  bool working = false;
  int player_choice;
  while(gamerun == true)
    {
      std::cout << "\n\nWelcome to Battleship!\nMenu:\n 1) Start Game\n 2) Instructions\n 3) Quit Game\n 4) Segfault the program\n\nEnter option (1-4): ";
      std::cin >> player_choice;
      if(player_choice != 1 || player_choice != 2 ||player_choice != 3 || player_choice != 4)
      {
        std::cout << "\nError with player selection please choose 1, 2, 3 or, 4\n";
      }
      if(player_choice == 1)
      {
        while(working == false)
          {
            std::cout << "\nHow many ships would you like to play with? (1-5 ships): ";
            std::cin >> ship_num;
            if(ship_num == 1 || ship_num == 2 || ship_num == 3 || ship_num == 4 || ship_num == 5)
              {
                working = true;
                std::cout << "\nit worked";
              }
            else
            {
              std::cout << "\nError with number of ships, please enter a valid number 1, 2, 3, 4 or, 5\n";
            }
          }
        //send number of ships down to //map(shipnum)
        }
        if(player_choice == 2)
        {
          std::cout << "\nGoals of the game!: Sink all enemy ships\n\nHow to Play:\n - You, the player, will start by selecting how many ships you'd like to play with, 1 to 5 ships.";
          std::cout << "\n - You will walk through and place your ships and then take turns entering coordinates to attack the other players ships.\n - The game is over when all Enemy Ships have been sunk.";
        }
        if(player_choice == 3)
        {
          gamerun = false;
          std::cout << "\nHave a nice day!\n";
        }
        if(player_choice == 4)
        {
          std::cout << "\n\nIt's a feature not a bug :p\n\n";
          raise(SIGSEGV);
        }
      }
}
