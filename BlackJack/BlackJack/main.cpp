#include <iostream>
#include "GameRound.h"
#include "UserPlayer.h"
#include "Dealer.h"
#include "Deck.h"

int main() {
    std::cout << "===== Welcome to Blackjack! =====" << std::endl;

    // Create player with starting balance, dealer, and deck
    UserPlayer* player = new UserPlayer(1000, new Hand());
    Dealer* dealer = new Dealer(new Hand());
    Deck* deck = new Deck();

    bool keepPlaying = true;

    while (keepPlaying && player->getBalance() > 0) {
        GameRound round(player, dealer, deck);
        round.play();

        // After each round, ask if user wants to continue
        std::string choice;
        std::cout << "\nPlay another round? [y/n]: ";
        std::cin >> choice;
        if (choice != "y" && choice != "Y") {
            keepPlaying = false;
        }
    }

    std::cout << "\n===== Game Over =====" << std::endl;
    player->saveStatsToFile("player_stats.txt");

    // Cleanup
    delete player;
    delete dealer;
    delete deck;

    return 0;
}
