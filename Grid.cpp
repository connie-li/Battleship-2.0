#include "Grid.h"

Grid::Grid(){
    m_arr = new string*[m_BOARD_SIZE];
    for(int i = 0; i < m_BOARD_SIZE; i++){
            m_arr[i] = new string[m_BOARD_SIZE];
        for(int j = 0; j < m_BOARD_SIZE; j++){
            m_arr[i][j] = "~";
        }
    }
}

string Grid::getCoor(const string coord){
    int row = rowCoor(coord);
    int col = colCoor(coord);
    if(m_arr[row][col].at(0) == '$'){
        return m_arr[row][col].substr(1);
    }
    return m_arr[row][col];
}

void Grid::setCoor(const string coord, const string value){
    m_arr[rowCoor(coord)][colCoor(coord)] = value;
}

string Grid::randCoor(const bool allowOcc){
    int row = 0;
    int col = 0;
    if(allowOcc){
        row = rand() % m_BOARD_SIZE + 1;
        col = rand() % m_BOARD_SIZE + 1;
    }else{
        do{
            row = rand() % m_BOARD_SIZE + 1;
            col = rand() % m_BOARD_SIZE + 1;
        }while(m_arr[row][col] != "~");
    }
    return row + ":" + col;
}

void Grid::printGrid(const bool isFiring){
    if(isFiring){
        printFiring();
    }else{
        printShip();
    }
}

void Grid::readShip(const string* arr, const int length){
    for(int i = 0; i < length; i++){
        m_arr[rowCoor(arr[i])][colCoor(arr[i])] = length;
    }
}

Grid::~Grid(){
    if(m_arr != nullptr)
    {
        for(int i = 0; i < m_BOARD_SIZE; i++){
            delete[] m_arr[i];
        }
        delete[] m_arr;
        m_arr = nullptr;
    }
}

int Grid::colCoor(const string coord){
    return stoi(coord.substr(coord.find(":") + 1)) - 1;
}

int Grid::rowCoor(const string coord){
    return stoi(coord.substr(0, coord.find(":"))) - 1;
}

void Grid::printFiring(){
    for(int i = 0; i < m_BOARD_SIZE; i++){
        for(int j = 0; j < m_BOARD_SIZE; j++){
            if(m_arr[i][j] == "O" || m_arr[i][j] == "X"){
                cout<< m_arr[i][j];
            }else if(m_arr[i][j].substr(0, 1) == "$"){
                cout<< m_arr[i][j].substr(1);
            }else{
                cout<< "~";
            }
            cout<<"\t";
        }
        cout<<"\n";
    }
}

void Grid::printShip(){
    for(int i = 0; i < m_BOARD_SIZE; i++){
        for(int j = 0; j < m_BOARD_SIZE; j++){
            char temp = '\0';
            if(m_arr[i][j].length() > 1){
                temp = m_arr[i][j].at(1);
            }else{
                temp = m_arr[i][j].at(0);
            }
            if(((int)temp >= 48 && (int)temp <= 57) || temp == 'O' || temp == 'X'){
                cout<< temp;
            }else{
                cout<< "~";
            }
            cout<<"\t";
        }
        cout<<"\n";
    }
}
