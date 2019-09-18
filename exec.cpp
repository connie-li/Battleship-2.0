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
  bool menurun = true;
  std::string ship_num;
  int ship_int;
  bool working = false;
  std::string player_choice;
  std::string player_shot = "";
  while(menurun == true)
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
                ship_int = std::stoi(ship_num); //If input is good, cast to int for map creation and end loop for menu.
                menurun = false;
              }
            else
            {
              std::cout << "\nError with number of ships, please enter a valid number 1, 2, 3, 4 or, 5\n";
            }
          }
        }
        if(player_choice == "2")
        {
          std::cout << "\nGoals of the game!: Sink all enemy ships\n\nHow to Play:\n - You, the player, will start by selecting how many ships you'd like to play with, 1 to 5 ships.";
          std::cout << "\n - You will walk through and place your ships and then take turns entering coordinates to attack the other players ships.\n - The game is over when all Enemy Ships have been sunk.";
        }
        if(player_choice == "3")
        {
          menurun = false;
          std::cout << "\nHave a nice day!\n";
          return; //Quitting the program by returning and skipping gameplay phase.
        }
      } //Start of gamplay phase.
      std::cout << "Player 1 place your ships:\n\n";
      playerOneMap = new map(ship_int); //Each player takes turns placing ships in the map class.
      std::cout << "\n\n\n\n\n\n\n\n\n\nPlayer 2 place your ships:\n\n";
      playerTwoMap = new map(ship_int);
      while(1)
      { //player one start
        playerTwoMap->printEnemyShotMap(); //Where they have shot
        std::cout << "\n";
        playerOneMap->printCurrentMap(); //Their own map
        while(!playerOneMap->validPos(player_shot)) //Continually ask until valid coordinate is given.
        {
          std::cout << "\nPlayer 1, input a valid coordinate to fire on: ";
          std::cin >> player_shot;
        }
        playerTwoMap->incomingShot(player_shot); //fire shot at given coordintate.
        if(playerTwoMap->gameOver()) //If the shot ended the game, break gameplay loop.
        {
          break;
        }
        player_shot = ""; //Reset coordinate to avoid infinite loop of both players firing on same spot.

        std::cout << "\n\n\n\n";
        //Player 2 start, repeating same process
        playerOneMap->printEnemyShotMap();
        std::cout << "\n";
        playerTwoMap->printCurrentMap();
        while(!playerTwoMap->validPos(player_shot))
        {
          std::cout << "\nPlayer 2, input a valid coordinate to fire on: ";
          std::cin >> player_shot;
        }
        playerOneMap->incomingShot(player_shot);
        if(playerOneMap->gameOver())
        {
          break;
        }
        player_shot = "";

        std::cout << "\n\n\n\n";
      }
      std::cout << "\n\n\n";
      if(playerTwoMap->gameOver())//If all player 2 ships have been sunk, player 1 wins.
      {
        std::cout << "Congratulations player 1, you are the winner!\n\n";
      }
      else if(playerOneMap->gameOver())//Opposite condition and player 2 has won.
      {
        std::cout << "Congratulations player 2, you are the winner!\n\n";
      }
      delete playerOneMap; //de-allocate memory like a good boy.
      delete playerTwoMap;
}
