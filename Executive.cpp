#include "Executive.h"

Executive::Executive()
{
    //create players
  m_player1 = new Admiral();
  m_player2 = new Admiral();

}

Executive::~Executive()
{
    delete m_player1;
    delete m_player2;
}

void Executive::placeShip(int n)
{
    //currently, this does not add the ships to a fleet and does not save their location
    //that will need to be implemented after other classes are built

    bool taken [9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j<9; j++)
        {
            taken[i][j] = false;
        }
    }
    for (int size = 0; size< n; size++)
    {
        std::cout << "It's time to place your ship of size 1x" << size << ". Enter a starting coordinate\n";
        std::string start = askCoord();
        int temp = charCoordtoIntCoord(start.at(1));
        int r = start.at(0);
        int c = temp;
        string* coorArr = new string[size];
        std::cout << "Enter an ending coordinate (possible ending coordinates for this ship are: ";
        if (r+size <= 8)
        {
            bool flag = false;
            for (int j = 1; j<= size; j++)
            {
                if (taken[j+r][c])
                    flag = true;
            }
            if (!flag)
            {
                std::cout << r+size << start.at(1) << " ";
            }
        }
        if (r-size > 0)
        {
            bool flag = false;
            for (int j = 1; j<= size; j++)
            {
                if (taken[r-j][c])
                    flag = true;
            }
            if (!flag)
            {
                std::cout << r-size << start.at(1) << " ";
            }
        }
        if (c + size <= 8)
        {
            bool flag = false;
            for (int j = 1; j<= size; j++)
            {
                if (taken[r][c+j])
                    flag = true;
            }
            if (!flag)
            {
                char letter = char(64+c+size);
                cout<< r <<  letter << " ";
            }
        }
        if (c-size > 0)
        {
            bool flag = false;
            for (int j = 1; j<= size; j++)
            {
                if (taken[r][j-c])
                    flag = true;
            }
            if (!flag)
            {
                char letter = char(64+c+size);
                cout << r <<  letter << " ";
            }
        }

        std::cout << "\n Enter the ending coordinate from the list. ";
        std::string end = askCoord();

        //not done yet
    }

}

std::string Executive::askCoord()
{
    std::string coor = "";
    std::cout << "Please enter a coordinate in the form 1A: ";
    std::getline(std::cin, coor);
    bool valid = validPos(coor);
    while (!valid)
    {
        std::cout << "Invalid coordinate. Please enter a coordinate in the form 1A: ";
        std::cin >> coor;
        valid = validPos(coor);
    }
    return coor;
}


/// check length is 2, first coordinate, second coordinate.
bool Executive::validPos(std::string pos)
{
  if (pos.length() == 2)
  {
    if (pos[1] == 'A' || pos[1] == 'B' || pos[1] == 'C' || pos[1] == 'D' || pos[1] == 'E' || pos[1] == 'F' || pos[1] == 'G' || pos[1] == 'H')
    {
      if (pos[0] == '1' || pos[0] == '2' || pos[0] == '3' || pos[0] == '4' || pos[0] == '5' || pos[0] == '6' || pos[0] == '7' || pos[0] == '8')
      {
        return true;
      }
    }
  }
  return false;
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
        setNumShips();
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
  bool working = true;
  int ship_int = 0;
  bool menurun = false;
    std::string ship_num = "";
    while (working == false)
      {
        std::cout << "\nHow many ships would you like to play with? (1-5 ships): ";
        std::getline(std::cin,ship_num);
        if (ship_num == "1" || ship_num == "2" || ship_num == "3" || ship_num == "4" || ship_num == "5")
        {
          working = true;
          /// If input is good, cast to int for map creation and end loop for menu.
          ship_int = stoi(ship_num);
          menurun = false;
        }
        else
        {
          std::cout << "\nError with number of ships, please enter a valid number 1, 2, 3, 4 or, 5\n";
        }
      }
    m_numShips = ship_int;
    m_player1.setNumShips(m_numShips);
    m_player1.setNumAfloat(m_numShips);
    m_player2.setNumShips(m_numShips);
    m_player2.setNumAfloat(m_numShips);
}


int Executive::charCoordtoIntCoord(char c){
  return (int)c - 65;
  // if (c == 'A')
  // {
  //   return 0;
  // }
  // if (c == 'B')
  // {
  //   return 1;
  // }
  // if (c == 'C')
  // {
  //   return 2;
  // }
  // if (c == 'D')
  // {
  //   return 3;
  // }
  // if (c == 'E')
  // {
  //   return 4;
  // }
  // if (c == 'F')
  // {
  //   return 5;
  // }
  // if (c == 'G')
  // {
  //   return 6;
  // }
  // if (c == 'H')
  // {
  //   return 7;
  // }
  // return 0;
}

