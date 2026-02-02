# Console Blackjack Simulation ♠️

> A robust, text-based implementation of the classic casino game, developed to demonstrate mastery of fundamental programming logic, state management, and algorithm design in [C / C++].

---

## 📖 About The Project

This project is a simulation of **Blackjack** that runs entirely in the console. The primary goal of this development was not just to recreate the game, but to apply core computer science concepts such as memory management (pointers/arrays), randomization algorithms, and conditional logic in a structured way.

The player competes against an automated "Dealer" bot that strictly adheres to real-world casino rules, offering a realistic probability experience.

##  Key Features

* ** Smart Dealer Logic:** The dealer is programmed to make decisions automatically (e.g., hitting on soft 16, standing on 17) without user intervention.
* ** Dynamic Deck System:** Simulates a real deck of cards using Random Number Generation (RNG) to ensure fair probability and non-repetitive draws.
* ** Betting Mechanics:** Includes a virtual economy system where users can place bets, track their balance, and manage risk across multiple rounds.
* ** Win/Loss Evaluation:** precise algorithms to instantly evaluate "Blackjack", "Bust", "Push", and standard win conditions.

##  Tech Stack

* **Language:** [C / C++]
* **Core Concepts:**
    * Multi-dimensional Arrays & Pointers
    * Structs / Classes for Card & Player Management
    * Control Flow & State Machines
    * Random Number Generation (RNG)

##  Getting Started

### Prerequisites
You need a [C / C++] compiler (like GCC or G++) installed on your machine.

### Installation & Run

1.  **Clone the repository**
    ```bash
    https://github.com/azzian669/BlackJack.git
    ```

2.  **Compile the code**
    For C++:
    ```bash
    g++ main.cpp -o blackjack
    ```
    For C:
    ```bash
    gcc main.c -o blackjack
    ```

3.  **Run the game**
    ```bash
    ./blackjack
    ```

##  How to Play

1.  **Place your bet:** Enter the amount of virtual chips you want to wager.
2.  **Initial Deal:** You and the dealer will receive two cards. One of the dealer's cards remains hidden.
3.  **Make your move:**
    * Type `H` to **Hit** (take another card).
    * Type `S` to **Stand** (hold your current hand).
4.  **Dealer's Turn:** The dealer will reveal their card and play according to the rules.
5.  **Result:** The winner is declared, and chips are updated.

##  What I Learned

Building this project helped solidify my understanding of:
* **Algorithmic Thinking:** Breaking down complex game rules into executable logical steps.
* **Memory Management:** Handling arrays efficiently to represent a deck of cards.
* **Edge Case Handling:** Ensuring the game doesn't crash on invalid inputs or rare card combinations (like Ace being 1 or 11).

##  Future Improvements

* Implement a "Split" and "Double Down" feature.
* Add a GUI using a simple graphics library.
* Save/Load game state to a local file.

---

**Developed by Izzan Ahmad
*Electrical Engineering Student at ITS*
www.linkedin.com/in/izzanahmad
