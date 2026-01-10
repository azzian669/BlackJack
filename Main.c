/*
 * FINAL PROJECT - BASIC PROGRAMMING (M-10T)
 * PROJECT NAME: BLACKJACK (Per PDF Specification)
 * Based on the specifications from the FP IUP.pdf document
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char suit[10];
    char rank[3];
    int value;
} Card;

void initializeDeck(Card deck[]);
void shuffleDeck(Card deck[], int size);
Card drawCard(Card deck[], int* deckTop);
int calculateTotal(Card hand[], int cardCount, int target);
void printHand(const char* title, Card hand[], int cardCount);
bool checkBust(int total, int target);

int main() {
    srand(time(NULL));

    Card deck[52];
    int deckTop = 0;

    Card playerHand[15];
    Card dealerHand[15];
    int playerCardCount = 0;
    int dealerCardCount = 0;

    int playerScore = 0;
    int dealerScore = 0;
    int round = 1;

    initializeDeck(deck);
    shuffleDeck(deck, 52);

    printf("Welcome to Blackjack!\n");
    printf("=================================\n\n");

    while (52 - deckTop >= 4) {
        printf("=================\n");
        printf("=== ROUND %d ===\n", round);
        printf("=================\n");

        playerCardCount = 0;
        dealerCardCount = 0;

        int target = (rand() % 21) + 15;
        printf("Target number: %d\n\n", target);

        playerHand[0] = drawCard(deck, &deckTop);
        playerHand[1] = drawCard(deck, &deckTop);
        playerCardCount = 2;

        dealerHand[0] = drawCard(deck, &deckTop);
        dealerHand[1] = drawCard(deck, &deckTop);
        dealerCardCount = 2;

        int playerTotal = calculateTotal(playerHand, playerCardCount, target);
        int dealerTotal = calculateTotal(dealerHand, dealerCardCount, target);

        while (true) {
            printHand("--- Player ---", playerHand, playerCardCount);
            printf("Total: %d\n", playerTotal);

            if (checkBust(playerTotal, target)) {
                printf("Player BUST! Total exceeded target.\n");
                break;
            }

            char choice;
            printf("Draw another card? (y/n): ");
            scanf(" %c", &choice);

            if (tolower(choice) == 'n') {
                break;
            }

            Card newCard = drawCard(deck, &deckTop);
            playerHand[playerCardCount] = newCard;
            playerCardCount++;
            printf("\nNew card: %s of %s (Value: %d)\n", newCard.rank, newCard.suit, newCard.value);

            int oldTotal = playerTotal;
            playerTotal = calculateTotal(playerHand, playerCardCount, target);

            if (newCard.value % 2 == 0) {
                printf("Even -> total added. (%d + %d)\n", oldTotal, newCard.value);
            } else {
                int baseTotal = calculateTotal(playerHand, 2, target);
                if (playerCardCount == 3) {
                   printf("Odd -> total multiplied. (%d * %d)\n", baseTotal, newCard.value);
                } else {
                   printf("Odd -> total multiplied. (%d * %d)\n", oldTotal, newCard.value);
                }
            }
            printf("Player's new total: %d\n\n", playerTotal);
        }

        printf("\n--- Dealer's Turn ---\n");
        double dealerThreshold = (double)target * 0.75;
        
        while (dealerTotal < dealerThreshold && !checkBust(dealerTotal, target)) {
            printf("Dealer draws a card...\n");
            Card newCard = drawCard(deck, &deckTop);
            dealerHand[dealerCardCount] = newCard;
            dealerCardCount++;
            dealerTotal = calculateTotal(dealerHand, dealerCardCount, target);
        }
        
        if (checkBust(dealerTotal, target)) {
             printf("Dealer BUST!\n");
        } else {
             printf("Dealer 'Stands'.\n");
        }

        printf("\n=== ROUND %d RESULTS ===\n", round);
        printf("Target: %d | Player: %d | Dealer: %d\n", target, playerTotal, dealerTotal);

        bool playerBust = checkBust(playerTotal, target);
        bool dealerBust = checkBust(dealerTotal, target);
        int roundWinner = 0; 

        if (playerBust && dealerBust) {
            printf("Result: Both Busted! DRAW!\n");
            roundWinner = 0;
        } else if (dealerBust) {
            printf("Result: Dealer Bust! Player wins!\n");
            playerScore++;
            roundWinner = 1;
        } else if (playerBust) {
            printf("Result: Player Bust! Dealer wins!\n");
            dealerScore++;
            roundWinner = 2;
        } else {
            int playerDiff = target - playerTotal;
            int dealerDiff = target - dealerTotal;

            if (playerDiff < dealerDiff) {
                printf("Result: Player is closer to target! Player wins!\n");
                playerScore++;
                roundWinner = 1;
            } else if (dealerDiff < playerDiff) {
                printf("Result: Dealer is closer to target! Dealer wins!\n");
                dealerScore++;
                roundWinner = 2;
            } else {
                printf("Result: Distance to target is equal! DRAW!\n");
                roundWinner = 0;
            }
        }

        printf("Cards left in deck: %d\n", 52 - deckTop);
        printf("Current Score -> Player: %d | Dealer: %d\n", playerScore, dealerScore);
        printf("========================\n\n");

        round++;

        printf("Press Enter to continue to the next round...");
        while(getchar() != '\n');
        getchar();
        printf("\n");
    }

    printf("\n=== GAME OVER ===\n");
    printf("Deck is empty!\n");
    printf("Final Score - Player: %d | Dealer: %d\n", playerScore, dealerScore);

    if (playerScore > dealerScore) {
        printf("Player wins the overall game!\n");
    } else if (dealerScore > playerScore) {
        printf("Dealer wins the overall game!\n");
    } else {
        printf("The game is an overall TIE!\n");
    }
    printf("===================\n");

    return 0;
}

void initializeDeck(Card deck[]) {
    char* suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    char* ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int k = 0;

    for (int s = 0; s < 4; s++) {
        for (int r = 0; r < 13; r++) {
            strcpy(deck[k].suit, suits[s]);
            strcpy(deck[k].rank, ranks[r]);

            if (r >= 0 && r <= 8) {
                deck[k].value = r + 2;
            } else if (r >= 9 && r <= 11) {
                deck[k].value = 10;
            } else {
                deck[k].value = 11;
            }
            k++;
        }
    }
}

void shuffleDeck(Card deck[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

Card drawCard(Card deck[], int* deckTop) {
    Card drawnCard = deck[*deckTop];
    (*deckTop)++;
    return drawnCard;
}

int calculateTotal(Card hand[], int cardCount, int target) {
    if (cardCount == 0) {
        return 0;
    }
    if (cardCount == 1) {
        return hand[0].value;
    }

    int total = hand[0].value + hand[1].value;
    
    if (total > target) return total;

    for (int i = 2; i < cardCount; i++) {
        int cardValue = hand[i].value;

        if (cardValue % 2 == 0) {
            total += cardValue;
        } else {
            total *= cardValue;
        }
        
        if (total > target) return total;
    }

    return total;
}

void printHand(const char* title, Card hand[], int cardCount) {
    printf("%s\n", title);
    printf("Cards: ");
    for (int i = 0; i < cardCount; i++) {
        printf("%s", hand[i].rank);
        if (i < cardCount - 1) {
            printf(" | ");
        }
    }
    printf("\n");
}

bool checkBust(int total, int target) {
    return total > target;

}
