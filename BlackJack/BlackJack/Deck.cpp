#include "Deck.h"

// Constructor: fill the deck with 52 cards
Deck::Deck() {
    std::srand((unsigned int)std::time(nullptr)); // seed randomness
    refill();
}

// Fill with 52 cards
void Deck::refill() {
    cards.clear();
    for (int suit = CLUBS; suit <= SPADES; suit++) {
        for (int rawValue = 1; rawValue <= 13; rawValue++) {
            cards.push_back(new Card(static_cast<CardSuit>(suit), rawValue));
        }
    }
}

// Shuffle by swapping each card with a random one
void Deck::shuffle() {
    for (size_t i = 0; i < cards.size(); ++i) {
        int j = std::rand() % cards.size();
        std::swap(cards[i], cards[j]);
    }
}

// Draw from the back of the vector
Card* Deck::draw() {
    if (cards.empty()) {
        std::cerr << "Deck is empty! Refilling..." << std::endl;
        refill();
        shuffle();
    }
    Card* card = cards.back();
    cards.pop_back();
    return card;
}

// Reshuffle if low on cards
void Deck::reshuffleIfNeeded() {
    if (cards.size() < 15) {
        std::cout << "Deck is running low! Refilling and shuffling..." << std::endl;
        refill();
        shuffle();
    }
}
