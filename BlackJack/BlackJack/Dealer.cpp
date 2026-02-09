#include "Dealer.h"

// Constructor: initialize the dealer with a hand and default target score
Dealer::Dealer(Hand* hand) : Player(hand) {
    targetScore = 17; // Default if not updated
}

// Update the score the dealer should aim to reach (usually the player's score)
void Dealer::updateTargetScore(int score) {
    targetScore = score;
}

// Dealer keeps drawing cards while under the target score
bool Dealer::makeMove() {
    return getHand()->getScore() < targetScore;
}
