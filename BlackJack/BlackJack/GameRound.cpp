#include "GameRound.h"

GameRound::GameRound(UserPlayer* player, Dealer* dealer, Deck* deck) {
    this->player = player;
    this->dealer = dealer;
    this->deck = deck;
    this->userBet = 0;
    this->doubleDownActive = false;
}

int GameRound::getBetUser() {
    std::cout << "Enter bet amount: ";
    int bet;
    std::cin >> bet;
    userBet = bet;
    return bet;
}

void GameRound::dealInitialCards() {
    for (int i = 0; i < 2; ++i) {
        player->addCard(deck->draw());
        dealer->addCard(deck->draw());
    }

    std::cout << "\nPlayer's hand:\n";
    for (Card* card : player->getHand()->getCards()) {
        card->print();
    }

    std::cout << "\nDealer's first card:\n";
    dealer->getHand()->getCards()[0]->print();
}

void GameRound::cleanupRound() {
    player->clearHand();
    dealer->clearHand();
    std::cout << "\nBalance: $" << player->getBalance() << "\n";
    player->printStats();   // ? works because player is UserPlayer*
}

void GameRound::play() {
    deck->reshuffleIfNeeded();
    deck->shuffle();

    // Ask for bet
    int bet = getBetUser();
    player->placeBet(bet);

    // Deal starting cards
    dealInitialCards();

    // Player turn
    while (player->makeMove()) {
        Card* card = deck->draw();
        std::cout << "Player draws: ";
        card->print();
        player->addCard(card);
        std::cout << "Player score: " << player->getHand()->getScore() << "\n";
        if (doubleDownActive) break;
    }

    // Check if player busts
    if (player->getHand()->getScore() > 21) {
        std::cout << "Player busts! Dealer wins.\n";
        player->recordLoss();
        cleanupRound();
        return;
    }

    // Dealer turn
    dealer->updateTargetScore(player->getHand()->getScore());
    while (dealer->makeMove()) {
        dealer->addCard(deck->draw());
    }

    // Show dealer's final hand
    std::cout << "\nDealer's hand:\n";
    for (Card* card : dealer->getHand()->getCards()) {
        card->print();
    }
    std::cout << "Dealer score: " << dealer->getHand()->getScore() << "\n";

    // Decide winner
    int pScore = player->getHand()->getScore();
    int dScore = dealer->getHand()->getScore();

    if (dScore > 21 || pScore > dScore) {
        std::cout << "Player wins!\n";
        player->receiveWinnings(bet * 2);
        player->recordWin();
    }
    else if (dScore > pScore) {
        std::cout << "Dealer wins!\n";
        player->recordLoss();
    }
    else {
        std::cout << "It's a draw.\n";
        player->receiveWinnings(bet);
        player->recordDraw();
    }

    cleanupRound();
}
