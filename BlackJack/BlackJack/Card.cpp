#include "Card.h"

// Constructor: set suit, value, and human-readable name
Card::Card(CardSuit suit, int rawValue) {
    this->suit = suit;

    // Score value: anything over 10 (J, Q, K) becomes 10
    if (rawValue > 10) {
        this->value = 10;
    }
    else {
        this->value = rawValue;
    }

    // Assign a display name
    switch (rawValue) {
    case 1:  this->name = "A"; break;
    case 11: this->name = "J"; break;
    case 12: this->name = "Q"; break;
    case 13: this->name = "K"; break;
    default: this->name = std::to_string(rawValue); break;
    }
}

CardSuit Card::getSuit() {
    return suit;
}

int Card::getValue() {
    return value;
}

std::string Card::getName() {
    return name;
}

// Print the card, e.g., "A of Hearts"
void Card::print() {
    std::cout << name << " of ";
    switch (suit) {
    case CLUBS:    std::cout << "Clubs"; break;
    case DIAMONDS: std::cout << "Diamonds"; break;
    case HEARTS:   std::cout << "Hearts"; break;
    case SPADES:   std::cout << "Spades"; break;
    }
    std::cout << std::endl;
}
