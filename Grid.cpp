#include "Grid.h"

Grid::Grid(){
    srand(time(NULL));
    m_center = to_string(m_BOARD_SIZE / 2) + ":" + to_string(m_BOARD_SIZE / 2);
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
    int row = 1;
    int col = 1;
    if(allowOcc){
        row = rand() % m_BOARD_SIZE + 1;
        col = rand() % m_BOARD_SIZE + 1;
    }else{
        do{
            row = rand() % m_BOARD_SIZE + 1;
            col = rand() % m_BOARD_SIZE + 1;
        }while(m_arr[row - 1][col - 1] != "~");
    }
    return to_string(row) + ":" + to_string(col);
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
        setCoor(arr[i], to_string(length));
    }
}

void Grid::getPartialGrid(string** &arr, int size, string center){
    int upperBound = -1;
    int lowerBound = -1;
    int leftBound = -1;
    int rightBound = -1;
    
    if(size < 1 || rowCoor(center) < 1 || colCoor(center) < 1){
        size = m_BOARD_SIZE;
        center = m_center;
    }
    //Finding array bounds    
    lowerBound = rowCoor(center) + (size / 2);
    rightBound = colCoor(center) + (size / 2);
    if(size % 2 == 0){
        upperBound = rowCoor(center) - (size / 2 - 1);
        leftBound = colCoor(center) - (size / 2 - 1);
    }else{
        upperBound = rowCoor(center) - (size / 2);
        leftBound = colCoor(center) - (size / 2);
    }
    if(upperBound < 0){
        upperBound = 0;
    }else if(upperBound >= m_BOARD_SIZE){
        upperBound = m_BOARD_SIZE - 1;
    }
    if(lowerBound < 0){
        lowerBound = 0;
    }else if(lowerBound >= m_BOARD_SIZE){
        lowerBound = m_BOARD_SIZE - 1;
    }
    if(leftBound < 0){
        leftBound = 0;
    }else if(leftBound >= m_BOARD_SIZE){
        leftBound = m_BOARD_SIZE - 1;
    }
    if(rightBound < 0){
        rightBound = 0;
    }else if(rightBound >= m_BOARD_SIZE){
        rightBound = m_BOARD_SIZE - 1;
    }

    //Array creation
    //Junk values are *
    arr = new string*[size];
    for(int i = 0; i < size; i++){
        arr[i] = new string[size];
        for(int j = 0; j < size; j++){
            arr[i][j] = "*";
        }
    }


    for(int i = upperBound; i <= lowerBound; i++){
        for(int j = leftBound; j <= rightBound; j++){
            arr[i - upperBound][j - leftBound] = m_arr[i][j];
        }
    }
}

void Grid::readGrid(string** arr){
    if(m_arr != nullptr){
        for(int i = 0; i < m_BOARD_SIZE; i++){
            delete[] m_arr[i];
        }
        delete[] m_arr;
        m_arr = nullptr;
    }
    
    m_arr = new string*[m_BOARD_SIZE];
    for(int i = 0; i < m_BOARD_SIZE; i++){
        m_arr[i] = new string[m_BOARD_SIZE];
        for(int j = 0; j < m_BOARD_SIZE; j++){
            m_arr[i][j] = arr[i][j];
        }
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
    cout << "\tA\tB\tC\tD\tE\tF\tG\tH\n";
    for(int i = 0; i < m_BOARD_SIZE; i++){
        cout << i+1 << "\t";
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
    cout << "\n";
}

void Grid::printShip(){
    cout << "\tA\tB\tC\tD\tE\tF\tG\tH\n";
    for(int i = 0; i < m_BOARD_SIZE; i++){
        cout << i+1 << "\t";
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
    cout << "\n";
}
