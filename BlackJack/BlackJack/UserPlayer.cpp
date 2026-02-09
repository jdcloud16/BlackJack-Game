#include "UserPlayer.h"
#include <iostream>

// Constructor
UserPlayer::UserPlayer(int balance, Hand* hand)
    : Player(hand), balance(balance), wins(0), losses(0), draws(0), maxBalance(balance) {
}

// Get current balance
int UserPlayer::getBalance() {
    return balance;
}

// Place a bet (subtracts from balance)
int UserPlayer::placeBet(int amount) {
    if (amount > balance) {
        throw std::runtime_error("Insufficient funds");
    }
    balance -= amount;
    return amount;
}

// Receive winnings (adds to balance)
void UserPlayer::receiveWinnings(int amount) {
    balance += amount;
    if (balance > maxBalance) {
        maxBalance = balance;
    }
}

// Record stats
void UserPlayer::recordWin() { wins++; }
void UserPlayer::recordLoss() { losses++; }
void UserPlayer::recordDraw() { draws++; }

// Print stats to console
void UserPlayer::printStats() {
    std::cout << "Wins: " << wins
        << ", Losses: " << losses
        << ", Draws: " << draws
        << ", Max Balance: $" << maxBalance
        << std::endl;
}

// Save stats to a text file
void UserPlayer::saveStatsToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Balance: " << balance << "\n";
        file << "Wins: " << wins << ", Losses: " << losses << ", Draws: " << draws << "\n";
        file << "Max Balance: " << maxBalance << "\n";
        file.close();
        std::cout << "Stats saved to " << filename << std::endl;
    }
    else {
        std::cerr << "Unable to open file to save stats.\n";
    }
}

// User decision logic
bool UserPlayer::makeMove() {
    std::string move;

    // If exactly 2 cards, offer more options
    if (getHand()->getCards().size() == 2) {
        std::cout << "Choose action: [d=draw, s=stand, x=double down, p=split, i=insurance]: ";
        std::cin >> move;

        if (move == "d") {
            return true; // draw
        }
        if (move == "x") {
            // Double down (simple demo logic)
            int additionalBet = 10;
            if (additionalBet <= balance) {
                placeBet(additionalBet);
                std::cout << "Double down! Extra bet placed.\n";
            }
            return true;
        }
        if (move == "p") {
            std::cout << "Split not implemented in this demo.\n";
            return false;
        }
        if (move == "i") {
            std::cout << "Insurance not implemented in this demo.\n";
            return false;
        }
        return false; // stand
    }
    else {
        // After initial moves, only draw or stand
        std::cout << "Draw card? [y/n]: ";
        std::cin >> move;
        return (move == "y");
    }
}
