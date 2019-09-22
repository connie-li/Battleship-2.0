///  File Name: exec.cpp.
///  Assignment: EECS 448 Project 1.
///  Brief: This program is the .cpp file for the exec class. It runs the game.

#include "exec.h"
#include "map.h"
#include <iostream>
#include <chrono>
#include <thread>

void exec::run()
{

  /// First ask number of ships.
  /// create playerOneMap with that number, allowing them to place.
  /// repeat with playerTwoMap.
  /// begin looping using while loop, using the gameOver() function to know when to stop.
  /// each loop prints a shot map and their own map, then allows player to fire on the others board.
  /// Once a gameOver() kills the loop, congratulate the winning player.
  /// delete maps.
  /// end code.

  std::chrono::seconds interval(2);
  bool menurun = true;
  std::string ship_num;
  int ship_int;
  bool working = false;
  std::string player_choice;
  std::string player_shot = "";
  while (menurun == true)
  {
    /// ASCII conversion done with online generator, http://patorjk.com/software/taag/.
    std::cout << "\n\n  ____        _   _   _           _     _       \n";
    std::cout << " |  _ \\      | | | | | |         | |   (_)      \n";
    std::cout << " | |_) | __ _| |_| |_| | ___  ___| |__  _ _ __  \n";
    std::cout << " |  _ < / _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\ \n";
    std::cout << " | |_) | (_| | |_| |_| |  __/\\__ \\ | | | | |_) |\n";
    std::cout << " |____/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/ \n";
    std::cout << "                                         | |    \n";
    std::cout << "                                         |_|    \n";
    std::cout << "\nMenu:\n 1) Start Game\n 2) Instructions\n 3) Quit Game\n\nEnter option (1-3): ";
    std::getline(std::cin,player_choice);
    if (player_choice != "1" && player_choice != "2" && player_choice != "3")
    {
      std::cout << "\nError with player selection please choose 1, 2, or 3 \n";
    }
    if (player_choice == "1")
    {
      while (working == false)
      {
        std::cout << "\nHow many ships would you like to play with? (1-5 ships): ";
        std::getline(std::cin,ship_num);
        if (ship_num == "1" || ship_num == "2" || ship_num == "3" || ship_num == "4" || ship_num == "5")
        {
          working = true;
          /// If input is good, cast to int for map creation and end loop for menu.
          ship_int = std::stoi(ship_num);
          menurun = false;
        }
        else
        {
          std::cout << "\nError with number of ships, please enter a valid number 1, 2, 3, 4 or, 5\n";
        }
      }
    }
    if (player_choice == "2")
    {
      std::cout << "\nGoals of the game!: Sink all enemy ships\n\nHow to Play:\n - You, the player, will start by selecting how many ships you'd like to play with, 1 to 5 ships.";
      std::cout << "\n - You will walk through and place your ships and then take turns entering coordinates to attack the other players ships.\n - The game is over when all Enemy Ships have been sunk.";
    }
    if (player_choice == "3")
    {
      menurun = false;
      std::cout << "\nHave a nice day!\n";
      /// Quitting the program by returning and skipping gameplay phase.
      return;
    }
  }
  /// Start of gamplay phase.
  std::cout << "Player 1 place your ships:\n\n";
  /// Each player takes turns placing ships in the map class.
  playerOneMap = new map(ship_int);
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 2 place your ships:\n\n";
  playerTwoMap = new map(ship_int);
  std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  while (1)
  {
    /// player one start.
    std::cout << "Your shots:\n";
    /// Where they have shot.
    playerTwoMap->printEnemyShotMap();
    std::cout << "\n\nYour board:\n";
    /// Their own map.
    playerOneMap->printCurrentMap();
    /// Continually ask until valid coordinate is given.
    while (!playerOneMap->validPos(player_shot))
    {
      std::cout << "\nPlayer 1, input a valid coordinate to fire on: ";
      std::getline(std::cin,player_shot);
    }
    /// fire shot at given coordintate.
    playerTwoMap->incomingShot(player_shot);
    /// If the shot ended the game, break gameplay loop.
    if (playerTwoMap->gameOver())
    {
      break;
    }
    /// Reset coordinate to avoid infinite loop of both players firing on same spot.
    player_shot = "";

    std::this_thread::sleep_for(interval);
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    /// Player 2 start, repeating same process.
    std::cout << "Your shots:\n";
    playerOneMap->printEnemyShotMap();
    std::cout << "\n\nYour board:\n";
    playerTwoMap->printCurrentMap();
    while (!playerTwoMap->validPos(player_shot))
    {
      std::cout << "\nPlayer 2, input a valid coordinate to fire on: ";
      std::getline(std::cin,player_shot);
    }
    playerOneMap->incomingShot(player_shot);
    if (playerOneMap->gameOver())
    {
      break;
    }
    player_shot = "";

    std::this_thread::sleep_for(interval);
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  }
  std::cout << "\n\n\n";
  /// If all player 2 ships have been sunk, player 1 wins.
  if (playerTwoMap->gameOver())
  {
    std::cout << "Congratulations player 1, you are the winner!\n\n";
  }
  /// Opposite condition and player 2 has won.
  else if (playerOneMap->gameOver())
  {
    std::cout << "Congratulations player 2, you are the winner!\n\n";
  }
  std::cout << "                                  )___(\n";
  std::cout << "                           _______/__/_\n";
  std::cout << "                  ___     /===========|   ___\n";
  std::cout << " ____       __   [\\\\]___/____________|__[///]   __\n";
  std::cout << " \\   \\_____[\\\\]__/___________________________\\__[//]___\n";
  std::cout << "  \\448                                                 |\n";
  std::cout << "   \\                                                  /\n";
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
  /// de-allocate memory.
  delete playerOneMap;
  delete playerTwoMap;
}
