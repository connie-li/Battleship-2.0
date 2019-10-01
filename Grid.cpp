#include "Grid.h"
#include <string>
#include <iostream>
#include <cstdlib>

Grid::Grid(){
    m_arr = new string*[m_BOARD_SIZE];
    for(int i = 0; i < m_BOARD_SIZE; i++){
            m_arr[i] = new string[m_BOARD_SIZE];
        for(int j = 0; j < m_BOARD_SIZE; j++){
            m_arr[i][j] = "~";
        }
    }
}

string Grid::getCoor(string coord){
    return m_arr[rowCoor(coord)][colCoor(coord)];
}

void Grid::setCoor(string coord, string value){
    m_arr[rowCoor(coord)][colCoor(coord)] = value;
}

string Grid::randCoor(bool allowOcc){
    int row = 0;
    int col = 0;
    if(allowOcc){
        row = rand() % m_BOARD_SIZE + 1;
        col = rand() % m_BOARD_SIZE + 1;
    }else{
        do{
            row = rand() % m_BOARD_SIZE + 1;
            col = rand() % m_BOARD_SIZE + 1;
        }while(getCoor(row + ":" + col) != "~");
    }
    return row + ":" + col;
}

void Grid::printGrid(bool isFiring){
    if(isFiring){
        printFiring();
    }else{
        printShip();
    }
}

Grid::~Grid(){
    for(int i = 0; i < m_BOARD_SIZE; i++){
        delete m_arr[i];
    }
    delete m_arr;
    m_arr = nullptr;
}

int Grid::colCoor(string coord){
    return stoi(coord.substr(coord.find(":") + 1)) - 1;
}

int Grid::rowCoor(string coord){
    return stoi(coord.substr(0, coord.find(":"))) - 1;
}

void Grid::printFiring(){}

void Grid::printShip(){}