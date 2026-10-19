#include <../include/board.h>

void Board::init(int width, int height){

    width_ = width;
    height_ = height;

}

Cell& Board::cell(int row, int col) {
    return cells_[row * width_ + col];
}

Board::Board(){

}

Board::~Board(){
    
}

