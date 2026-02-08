#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Card.h"

// A Deck holds 52 cards, can shuffle, draw, and be refilled if needed.
class Deck {
private:
    std::vector<Card*> cards;

public:
    // Constructor
    Deck();

    // Refill the deck with 52 cards
    void refill();

    // Shuffle the deck
    void shuffle();

    // Draw one card from the top of the deck
    Card* draw();

    // If deck is running low, automatically refill and shuffle
    void reshuffleIfNeeded();
};
