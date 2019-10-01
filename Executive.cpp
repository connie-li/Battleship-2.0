#include "Executive.h"

Executive::Executive()
{

}

Executive::~Executive()
{
    delete m_player1;
    delete m_player2;
}

std::string  Executive::askCoord()
{

}

void Executive::run()
{
    int option = setup();
    if (option == 3)
    {
        return;
    }
}

int Executive::setup()
{
  std::chrono::seconds interval(2);
  bool menurun = true;
  bool working = false;
  std::string ship_num;
  std::string player_choice;
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
    else if (player_choice == "1")
    {
      while (working == false)
      {
        std::cout << "\nHow many ships would you like to play with? (1-5 ships): ";
        std::getline(std::cin,ship_num);
        if (ship_num == "1" || ship_num == "2" || ship_num == "3" || ship_num == "4" || ship_num == "5")
        {
          working = true;
          /// If input is good, cast to int for map creation and end loop for menu.
          m_numShips = std::stoi(ship_num);
          menurun = false;
          return 1;
        }
        else
        {
          std::cout << "\nError with number of ships, please enter a valid number 1, 2, 3, 4 or, 5\n";
        }
      }
    }
    else if (player_choice == "2")
    {
      std::cout << "\nGoals of the game!: Sink all enemy ships\n\nHow to Play:\n - You, the player, will start by selecting how many ships you'd like to play with, 1 to 5 ships.";
      std::cout << "\n - You will walk through and place your ships and then take turns entering coordinates to attack the other players ships.\n - The game is over when all Enemy Ships have been sunk.";
      std::cout << "\n - Here are the lists of symbols that will show up on the board with explanations: \n";
      //std::cout << "\t • ~: Water \n\t • O: Miss \n\t • X: Hit \n\t • C: 5x1 Carrier \n\t • B: 4x1 Battleship \n\t • D: 3x1 Destroyer \n\t • S: 2x1 Submarine \n\t • T: 1x1 Tug Boat";
      return 2;
    }
    else if (player_choice == "3")
    {
      menurun = false;
      std::cout << "\nHave a nice day!\n";
      /// Quitting the program by returning and skipping gameplay phase.
      return 3;
    }
  }
}

void Executive::setNumShips()
{

}
