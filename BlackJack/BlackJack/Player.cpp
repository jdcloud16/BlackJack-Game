#include "Player.h"

// Constructor
Player::Player(Hand* hand) {
    this->hand = hand;
}

// Destructor
Player::~Player() {
    delete hand;
}

// Return the hand pointer
Hand* Player::getHand() {
    return hand;
}

// Clear hand by deleting old hand and creating a new one
void Player::clearHand() {
    delete hand;
    hand = new Hand();
}

// Add card to hand
void Player::addCard(Card* card) {
    hand->addCard(card);
}
