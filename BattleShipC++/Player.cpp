#include "Player.h"
#include "Submarine.h"


Player::Player() {
    name = "";
    playerN = 0;
    shots = 3;
    nShips = 0;
}

Player::~Player() {
}

void Player::putShip() {
    Submarine sub;
    cout << endl << endl;
    sub.getLocation().ask2Set();
    sub.getLocation().setC('O');
    getBoard().setMatrixCell(sub.getLocation());
    ships[nShips] = sub;
    nShips++;
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

void Player::setNShips(int n) {
    nShips = n;
}

void Player::setShips(Ship sh) {
    ships[nShips] = sh;
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

int Player::getNShips() {
    return nShips;
}

Ship Player::getShip(int n) {
    return ships[n];
}
