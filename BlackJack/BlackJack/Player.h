#pragma once
#include "Hand.h"

// Player is an abstract base class for both UserPlayer and Dealer.
// It owns a Hand and provides common functions like addCard and clearHand.
// makeMove() is pure virtual so each derived class implements its own logic.
class Player {
protected:
    Hand* hand;

public:
    // Constructor
    Player(Hand* hand);

    // Virtual destructor to safely delete hand
    virtual ~Player();

    // Get the hand
    Hand* getHand();

    // Clear current hand and start fresh
    void clearHand();

    // Add a card to hand
    void addCard(Card* card);

    // Each derived class decides how to make a move
    virtual bool makeMove() = 0;
};
