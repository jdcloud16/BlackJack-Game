#pragma once
#include "Player.h"

// Dealer is a type of Player that follows fixed rules:
// it keeps drawing cards until its score reaches or exceeds a target.
class Dealer : public Player {
private:
    int targetScore;  // the score the dealer tries to reach

public:
    // Constructor
    Dealer(Hand* hand);

    // Set the score dealer should try to beat
    void updateTargetScore(int score);

    // Dealer's decision: keep drawing if below target
    bool makeMove() override;
};
