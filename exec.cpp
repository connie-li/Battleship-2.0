#include "exec.h"
#include "map.h"
#include <iostream>

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
  std::string ship_num;
  int ship_int;
  bool working = false;
  std::string player_choice;
  while(gamerun == true)
    {
      std::cout << "\n\nWelcome to Battleship!\nMenu:\n 1) Start Game\n 2) Instructions\n 3) Quit Game\n\nEnter option (1-3): ";
      std::cin >> player_choice;
      if(player_choice != "1" && player_choice != "2" && player_choice != "3" )
      {
        std::cout << "\nError with player selection please choose 1, 2, or 3 \n";
      }
      if(player_choice == "1")
      {
        while(working == false)
          {
            std::cout << "\nHow many ships would you like to play with? (1-5 ships): ";
            std::cin >> ship_num;
            if(ship_num == "1" || ship_num == "2" || ship_num == "3" || ship_num == "4" || ship_num == "5")
              {
                working = true;
                ship_int = std::stoi(ship_num);
                std::cout << "\nit worked\n";
              }
            else
            {
              std::cout << "\nError with number of ships, please enter a valid number 1, 2, 3, 4 or, 5\n";
            }
          }
          std::cout << "Player 1 place your ships:\n\n";
          playerOneMap = new map(ship_int);
          std::cout << "\n\n\n\n\n\n\n\n\n\nPlayer 2 place your ships:\n\n";
          playerTwoMap = new map(ship_int);

        //send number of ships down to //map(shipnum)
        }
        if(player_choice == "2")
        {
          std::cout << "\nGoals of the game!: Sink all enemy ships\n\nHow to Play:\n - You, the player, will start by selecting how many ships you'd like to play with, 1 to 5 ships.";
          std::cout << "\n - You will walk through and place your ships and then take turns entering coordinates to attack the other players ships.\n - The game is over when all Enemy Ships have been sunk.";
        }
        if(player_choice == "3")
        {
          gamerun = false;
          std::cout << "\nHave a nice day!\n";
        }
      }
}
