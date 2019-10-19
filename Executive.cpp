#include "Executive.h"
#include <fstream>

Executive::Executive()
{
  m_turn = 1;
    //create players
  m_player1 = new Admiral();
  m_player2 = new Admiral();

}

Executive::~Executive()
{
    delete m_player1;
    delete m_player2;

}

void Executive::saveGame(int turn, Admiral* player1, Admiral* player2, bool ai)
{
  fstream exists("saved.txt");
  if(exists) 
  {
    remove("saved.txt");
    remove("player_info.txt");
  }

  ofstream fileInfo;
  fileInfo.open("player_info.txt", ios::app); 

  cout<<"THIS IS THE CURRENT TURN "<<turn<<"\n";
  fileInfo<<turn;

  cout<<"THIS IS THE CURRENT AI "<<ai<<"\n";
  fileInfo<<ai;

  fileInfo.close();

  string** board1 = nullptr;
  string** board2 = nullptr;

  //board contains the 2D string array from the grid object from the current player
  // board1 = player1->getBoard()->getGrid();
  // board2 = player2->getBoard()->getGrid();

  writeBoard(board1, board2);
}

void Executive::writeBoard(string** player1_board, string** player2_board)
{
    ofstream gameFile;
    gameFile.open("saved.txt", ios::app); 

    string** board;

    //write board information to a text file
    for(int i = 0; i < 2; i++)
    {
        if(i==0)
        {
            board=player1_board;

        }
        if(i==1)
        {
            board=player2_board;
        } 

        for(int i = 0; i < m_BOARD_SIZE; i++)
        {
            for(int j = 0; j < m_BOARD_SIZE; j++)
            {
                char temp = '\0';
                if(board[i][j].length() > 1)
                {
                    temp = board[i][j].at(1);
                }else
                {
                    temp = board[i][j].at(0);
                }
                if(((int)temp >= 48 && (int)temp <= 57) || temp == 'O' || temp == 'X')
                {
                    gameFile<< temp;
                }
                else
                {
                    gameFile<< "~";
                }
                gameFile<<"\t";
            }
            gameFile<<"\n";
        }
        gameFile<<"\n";
    }

    gameFile<<"\n";

    gameFile.close();
}

void Executive::placeShip(int n, Admiral* player, bool ai)
{
    bool taken [9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j<9; j++)
        {
            taken[i][j] = false;
        }
    }
    for (int size = 1; size<= n; size++)
    {
        std::string start = "";
        if(!ai)
        {
          std::cout << "It's time to place your ship of size 1x" << size << ". Enter a starting coordinate\n";
          start = askCoord();
        }
        else
        {
          int x = rand() % 8+1;
          int y = rand() % 8+ 1;
          start = std::to_string(x) + ":" + std::to_string(y);
        }
        
        
        int temp = charCoordtoIntCoord(start.at(1));
        int r = std::stoi(start.substr(0,1));
        int c = temp;
        while(taken[r][c] == true)
        {
          if(!ai)
          {
            std::cout << "Error you already placed a ship there. Try a different coordinate. ";
            start = askCoord();
            temp = charCoordtoIntCoord(start.at(1));
            r = std::stoi(start.substr(0,1));
            c = temp;
          }
          else
          {
            r = rand() % 8+1;
            c = rand() % 8+ 1;
          }
          
        }
        bool north = false;
        bool south = false;
        bool west = false;
        bool east = false;
        std::string option_n = "";
        std::string option_s = "";
        std::string option_w = "";
        std::string option_e = "";

    if (size != 1)
    {
      if(!ai)
        {
          std::cout << "Enter an ending coordinate (possible ending coordinates for this ship are: ";
        }
        if (r+(size-1) <= 8)
        {
            bool flag = false;
            for (int j = 1; j< size; j++)
            {
                if (taken[j+r][c])
                    flag = true;
            }
            if (!flag)
            {
                south = true;
                option_s = std::to_string(r+(size-1))+start.at(1);
                std::cout << r+(size-1) << start.at(1) << " ";
            }
        }
        if (r-(size-1) > 0)
        {
            bool flag = false;
            for (int j = 1; j< size; j++)
            {
                if (taken[r-j][c])
                    flag = true;
            }
            if (!flag)
            {
                north = true;
                option_n = std::to_string(r-(size-1))+start.at(1);
                std::cout << r-(size-1) << start.at(1) << " ";
            }
        }
        if (c + (size-1) <= 8)
        {
            bool flag = false;
            for (int j = 1; j< size; j++)
            {
                if (taken[r][c+j])
                    flag = true;
            }
            if (!flag)
            {
                east = true;
                char letter = char(64+c+(size-1));
                option_e = std::to_string(r)+letter;
                cout<< r <<  letter << " ";
            }
        }
        if (c-(size-1) > 0)
        {
            bool flag = false;
            for (int j = 1; j< size; j++)
            {
                if (taken[r][j-c])
                    flag = true;
            }
            if (!flag)
            {
                west = true;
                char letter = char(64+(c-(size-1)));
                option_w = std::to_string(r)+letter;
                cout << r <<  letter << " ";
            }
        }
        std::string end = "";
        if(!ai)
        {
          std::cout << "\n Enter the ending coordinate from the list. ";
          end = askCoord();
        }
        else
        {
            int randOpt = rand()%4;
            if (randOpt == 0)
            {
              end = option_e;
            }
            if (randOpt == 1)
            {
              end = option_n;
            }
            if (randOpt ==2)
            {
              end = option_s;
            }
            if (randOpt == 3)
            {
              end = option_w;
            }
        }
        
        while (end !=option_e && end!=option_n && end!=option_s && end!=option_w)
        {
            std::cout << "\n Error. Enter one of the coordinates listed above. ";
            end = askCoord();
        }

        if(south && (std::stoi(end.substr(0,1))== r+(size-1)))
        {
          std::string* arr = new std::string[size];
          int index = r;
          for(int i = 0; i<size; i++)
          {
            taken[index][charCoordtoIntCoord(start.at(1))] = true;
            std::string coor = std::to_string(index) + ":" + std::to_string(charCoordtoIntCoord(start.at(1)));
            arr[i] = coor;
            index++;
          }
           player->addShip(size, arr);
        }
        else if (north && (std::stoi(end.substr(0,1)) == r-(size-1)))
        {
          std::string* arr = new std::string[size];
          int index = r;
          for(int i = size-1; i>=0; i--)
          {
            taken[index][charCoordtoIntCoord(start.at(1))] = true;
            std::string coor = std::to_string(index) + ":" + std::to_string(charCoordtoIntCoord(start.at(1)));
            arr[i] = coor;
            index--;
          }
           player->addShip(size, arr);

        }
        else if (east && (end.at(1) > start.at(1)))
        {
            std::string* arr = new std::string[size];
            int index = c;
            for (int i = 0; i<size; i++)
            {
                taken[r][index] = true;
                std::string coor = std::to_string(r) + ":" + std::to_string(index);
                arr[i] = coor;
                index++;
            }
             player->addShip(size, arr);
        }
        else if (west && (end.at(1) < start.at(1)))
        {
            std::string* arr = new std::string[size];
            int index = c;
            for (int i = size-1; i>=0; i--)
            {
                taken[r][index] = true;
                std::string coor = std::to_string(r) + ":" + std::to_string(index);
                arr[i] = coor;
                index--;
            }
             player->addShip(size, arr);
        }
      }
      else //if size is 1x1 don't ask for ending coor
      {
            std::string* arr = new std::string[size];
            arr[0] = std::to_string(r) + ":" + std::to_string(c);
            taken[r][c] = true;
            player->addShip(size, arr);
      }
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
  int winner = 0;
    int menu = setup();
    if (menu == 4)
    {
      return;
    }
    if (menu == 2)
    {
        std::cout<< "Player 1: It's time to place your ships.\n";
        placeShip(m_numShips, m_player1, false);
        std::cout << "Thanks for placing your ships player 1! \nNow it's player 2's turn";
        std::chrono::seconds interval(2);
        std::cout<< "\n\n\n\n\n\n\n\n\n\n\nPlayer 2: It's time to place your ships.\n";
        placeShip(m_numShips, m_player2, false);
        //saveGame(m_player1, m_player2, false);
        std::cout << "Thanks for placing your ships. Time to start the game";
        winner = gameplay(false);
        printGameOver(winner);
    }
    if (menu == 3)
    {
        std::cout<< "Player 1: It's time to place your ships.";
        placeShip(m_numShips, m_player1, false);
        std::cout << "Thanks for placing your ships. The AI's ships have been placed randomly. Time to start the game\n";
        placeShip(m_numShips, m_player2, true);
        winner = gameplay(true);
        printGameOver(winner);
    }

}

int Executive::setup()
{
  std::chrono::seconds interval(2);
  bool menurun = true;
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
    std::cout << "\nMenu:\n 1) Instructions\n 2) Start Game: Player vs. Player\n 3) Start Game: Player vs. AI\n 4) Quit Game\n\nEnter option (1-4): ";
    std::getline(std::cin,player_choice);
    if (player_choice == "1")
    {
      std::cout << "There are two game modes: a 1v1 game with two players, or a player vs. AI mode. In Player vs. AI mode, you can choose Easy, Medium, or Hard AI difficulty.\n";
      std::cout << "\nGoals of the game!: Sink all enemy ships\n\nHow to Play:\n - You, the player, will start by selecting how many ships you'd like to play with, 1 to 5 ships.";
      std::cout << "\n - You will walk through and place your ships and then take turns entering coordinates to attack the other players ships.\n - The game is over when all Enemy Ships have been sunk.";
      std::cout << "\n - Here are the lists of symbols that will show up on the board with explanations: \n";
      std::cout << "\t • ~: Water \n\t • O: Miss \n\t • X: Hit \n\t • 5: 5x1 Carrier \n\t • 4: 4x1 Battleship \n\t • 3: 3x1 Destroyer \n\t • 2: 2x1 Submarine \n\t • 1: 1x1 Tug Boat\n";
    }
    else if (player_choice == "2")
    {
      cout << "Starting a Player vs. Player game!\n";
      setNumShips();
      return 2;
    }
    else if (player_choice == "3")
    {
      cout << "Starting a Player vs. AI game!\n";
      //m_player2 = new AI(); 
      setNumShips();
      return 3;
    }
    else if (player_choice == "4")
    {
      std::cout << "\nHave a nice day!\n";
      return 4;
    }
    else
    {
      cout << "Please enter a valid input.\n";
      menurun = true;
    }
  }
}

void Executive::setNumShips()
{
  bool working = false;
  int ship_int = 0;
    std::string ship_num = "";
    while (working == false)
      {
        std::cout << "\nHow many ships would you like to play with? (1-5 ships): ";
        std::getline(std::cin,ship_num);
        if (ship_num == "1" || ship_num == "2" || ship_num == "3" || ship_num == "4" || ship_num == "5")
        {
          working = true;
          /// If input is good, cast to int for map creation and end loop for menu.
          ship_int = std::stoi(ship_num);
        }
        else
        {
          std::cout << "\nError with number of ships, please enter a valid number: 1, 2, 3, 4 or, 5\n";
        }
      }
    m_numShips = ship_int;
    m_player1->setNumShips(m_numShips);
    m_player1->setNumAfloat(m_numShips);
    m_player2->setNumShips(m_numShips);
    m_player2->setNumAfloat(m_numShips);
}

void Executive::switchTurn()
{
  if(m_turn == 1)
  {
    m_turn = 2;
  }
  else
  {
    m_turn = 1;
  }
}

bool Executive::handleTurn(const int player, const bool AI)
{
  string powerup;
  string targetCoord;
  string turnResult;
  if(AI)  // AI player
  {
    // waiting on AI method
    // targetCoord = m_player2->chooseTarget();
    turnResult = m_player1->incomingShot(targetCoord);
    return(m_player1->getNumAfloat() < 1);
  }
  else
  {
    if(player == 1)
    {
      cout<<"\nDo you want to save and quit the game? Hit S/s to save and quit. Hit enter to continue.\n";
      cin>>quit_choice;
      if(quit_choice=='s'||quit_choice=='S')
      {
        saveGame(m_turn, m_player1, m_player2, AI);
        exit(0);
      }
      else
      {
        printMaps(player);
        printEnemyAction(); //TODO
        if(m_powerups.hasAPowerup(true))
        {
          powerup = askForPowerUp(1);
        }
        targetCoord = askForFireCoord(m_turn);
        turnResult = m_player2->incomingShot(targetCoord);
        // TODO: add powerups
        // if(turnResult == "T" || turnResult == "R" || turnResult == "U" || turnResult == "S")
        //   {

        //   }
        printTurnResult(turnResult);
        return(m_player2->getNumAfloat() < 1);
      }
    }
    else  // player 2
    {
      cout<<"\nDo you want to save and quit the game? \nHit S/s to save and quit. Hit C/c to continue.\n";
      cin>>quit_choice;
      if(quit_choice=='s'||quit_choice=='S')
      {
        saveGame(m_turn, m_player1, m_player2, AI);
        exit(0);
      }
      else
      {
        printMaps(player);
        printEnemyAction(); //TODO
        if(m_powerups.hasAPowerup(false))
        {
          powerup = askForPowerUp(2);
        }
        targetCoord = askForFireCoord(m_turn);
        turnResult = m_player1->incomingShot(targetCoord);
        // TODO: add powerups
        printTurnResult(turnResult);
        return(m_player1->getNumAfloat() < 1);
      }
    }
  }
}

int Executive::gameplay(const bool AI)
{
  bool gameOver = false;
  int winner = 0;
  while(!gameOver)
  {
    if(m_turn == 1)
    {
      gameOver = handleTurn(1, false);
    }
    else
    {
      gameOver = handleTurn(2, AI);
    }

    if(gameOver)
    {
      if(m_turn == 1)
      {
        winner = 1;
      }
      else
      {
        if(AI)
        {
          winner = 3;
        }
        else
        {
          winner = 2;
        }
      }
    }
    switchTurn();
  }
  return(winner);
}

string Executive::askForPowerUp(const int player)
{
  bool goodInput = false;
  vector<string>* playerPUs = getPowerups(player);
  vector<string>::iterator it = playerPUs->begin();
  string choice = "";
  do {
      cout << "Player " << player << ", would you like to use a powerup?\n";
      it = playerPUs->begin();
      while(it != playerPUs->end())
      {
        if(*it == "T")
        {
          cout << "Enter T to use your Torpedo.\n";
        }
        if(*it == "R")
        {
          cout << "Enter R to use your Radar.\n";
        }
        if(*it == "U")
        {
          cout << "Enter U to use your Uber Commander.\n";
        }
        if(*it == "S")
        {
          cout << "Enter S to use your Scattershot.\n";
        }
        ++it;
      }  
      cout << "Or enter N to not use a powerup this turn.\n";
      cout << "Your choice: ";
      cin >> choice;
      // check whether the choice is in the vector
      it = find(playerPUs->begin(), playerPUs->end(), choice);
      if(it != playerPUs->end())
      {
        goodInput = true;
      }
  } while(!goodInput);
  return(choice);
}

string Executive::askForFireCoord(const int player)
{
  string coord = "";
  do {
    cout << "Player " << player << ", input a valid coordinate to fire on: ";
    cin >> coord;
  } while(!validPos(coord));
  return(coord);
}

vector<string>* Executive::getPowerups(const int player) const
{
//   vector<string>* powerups = m_powerups.getPowerUps(player);
}

void Executive::printTurnResult(const string result) const
{
  if(result == "hit")
  {
    cout << "You hit their ship!\n";
  }
  else if(result == "sunk")
  {
    cout << "You hit and sank their ship!\n";
  }
  else if(result == "miss")
  {
    cout << "You missed.\n";
  }
  else if(result == "X")
  {
    cout << "You already fired on that location.\n";
  }
  else
  {
    cout << "You got a powerup!\n";
  }
}

// --- HELPER FUNCTIONS ---
int Executive::charCoordtoIntCoord(char c){
  return (int)c - 64;
}

string Executive::convertCoord(string orig)
{
  int row = charCoordtoIntCoord(orig.at(0));
  int col = charCoordtoIntCoord(orig.at(1));
  string newCoord = to_string(row) + ":" + to_string(col);
  return(newCoord);
}

void Executive::printGameOver(const int player) const
{
  cout << "GAME OVER!\n";
  if(player == 3)
  {
    cout << "The AI won the game.  Better luck next time!\n";
  }
  else
  {
    cout << "Congratulations player " << player << ", you are the winner!\n\n";
    cout << "                                  )___(\n";
    cout << "                           _______/__/_\n";
    cout << "                  ___     /===========|   ___\n";
    cout << " ____       __   [\\\\]___/____________|__[///]   __\n";
    cout << " \\   \\_____[\\\\]__/___________________________\\__[//]___\n";
    cout << "  \\448                                                 |\n";
    cout << "   \\                                                  /\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
  }
}

void Executive::printMaps(const int player) const
{
  if(player == 1)
  {
    cout << "Your firing map:\n";
    m_player2->getBoard()->printGrid(true);
    cout << "Your ship map:\n";
    m_player1->getBoard()->printGrid(false);
  }
  else
  {
    m_player1->getBoard()->printGrid(true);
    m_player2->getBoard()->printGrid(false);
  }
}

void Executive::printEnemyAction() const
{
}