#include "Player.h"


Player::Player() {
    name = "";
    playerN = 0;
    shots = 3;
}

Player::~Player() {
}

void Player::setName(string n) {
    name = n;
}

void Player::setBoard(Board b) {
    board = b;
}

void Player::setBoardView(Board bv) {
    boardView = bv;
}

void Player::setPlayerN(int n) {
    playerN = n;
}

void Player::setShots(int n) {
    shots = n;
}

string Player::getName() {
    return name;
}

int Player::getPlayerN() {
    return playerN;
}

int Player::getShots() {
    return shots;
}

Board &Player::getBoard() {
    return board;
}

Board& Player::getBoardView() {
    return boardView;
}