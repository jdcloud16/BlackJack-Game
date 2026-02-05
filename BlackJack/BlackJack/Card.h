#pragma once
#include <string>
#include <iostream>

// Enum for the four suits
enum CardSuit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

class Card {
private:
    CardSuit suit;     // Suit of the card
    int value;         // Numerical value used for scoring (1–10)
    std::string name;  // Display name like "A", "J", "Q", "K", or "2".."10"

public:
    // Constructor
    Card(CardSuit suit, int rawValue);

    // Getters
    CardSuit getSuit();
    int getValue();
    std::string getName();

    // Print the card nicely
    void print();
};
