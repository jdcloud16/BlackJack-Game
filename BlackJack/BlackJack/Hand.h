#pragma once
#include <vector>
#include "Card.h"

// A Hand holds cards for either the player or dealer
class Hand {
private:
    std::vector<Card*> cards; // cards currently in hand
    int score;                // cached score (updated as cards are added)

public:
    Hand();

    // Add a card and update score
    void addCard(Card* card);

    // Get total score of the hand
    int getScore();

    // Get all cards in the hand
    std::vector<Card*> getCards();

    // Clear cards (optional helper if needed externally)
    void clear();

    // Print all cards in this hand
    void print();

    // Check if first two cards are same value (for split option)
    bool canSplit();
};
