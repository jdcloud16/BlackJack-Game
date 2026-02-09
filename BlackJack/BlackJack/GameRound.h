#pragma once
#include <iostream>
#include "UserPlayer.h"
#include "Dealer.h"
#include "Deck.h"

// GameRound controls a single round of Blackjack
class GameRound {
private:
    UserPlayer* player;   // the human player
    Dealer* dealer;       // the dealer (computer)
    Deck* deck;           // the deck of cards
    int userBet;
    bool doubleDownActive;

public:
    GameRound(UserPlayer* player, Dealer* dealer, Deck* deck);

    // Ask the player how much they want to bet
    int getBetUser();

    // Deal the initial two cards to player and dealer
    void dealInitialCards();

    // Clean up the round (clear hands, show balance and stats)
    void cleanupRound();

    // Main function to play one full round
    void play();
};
