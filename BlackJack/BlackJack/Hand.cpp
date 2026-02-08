#include "Hand.h"
#include <iostream>

Hand::Hand() {
    score = 0;
    cards.clear();
}

void Hand::addCard(Card* card) {
    cards.push_back(card);

    // Add card value, handle Ace as 11 if possible
    if (card->getName() == "A") {
        // Try to count Ace as 11 if it won't bust
        if (score + 11 <= 21) {
            score += 11;
        }
        else {
            score += 1;
        }
    }
    else {
        score += card->getValue();
    }

    // Extra check: if score > 21 and we have an Ace counted as 11, reduce score
    int aceCount = 0;
    for (Card* c : cards) {
        if (c->getName() == "A") aceCount++;
    }
    while (score > 21 && aceCount > 0) {
        score -= 10; // change one Ace from 11 to 1
        aceCount--;
    }
}

int Hand::getScore() {
    return score;
}

std::vector<Card*> Hand::getCards() {
    return cards;
}

void Hand::clear() {
    cards.clear();
    score = 0;
}

void Hand::print() {
    for (Card* card : cards) {
        card->print();
    }
}

bool Hand::canSplit() {
    if (cards.size() == 2) {
        // check if first two cards have same value
        return cards[0]->getValue() == cards[1]->getValue();
    }
    return false;
}
