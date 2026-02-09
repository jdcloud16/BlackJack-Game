#pragma once
#include "Player.h"
#include <fstream>
#include <stdexcept>
#include <string>

// UserPlayer is the human player: manages balance, stats, and decisions.
class UserPlayer : public Player {
private:
    int balance;
    int wins;
    int losses;
    int draws;
    int maxBalance;

public:
    // Constructor
    UserPlayer(int balance, Hand* hand);

    // Money management
    int getBalance();
    int placeBet(int amount);
    void receiveWinnings(int amount);

    // Stats management
    void recordWin();
    void recordLoss();
    void recordDraw();
    void printStats();
    void saveStatsToFile(const std::string& filename);

    // Decision making (overrides abstract Player::makeMove)
    bool makeMove() override;
};
