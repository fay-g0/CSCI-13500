#include <iostream>
#include <string>
#include <ctime>

// Function prototypes
void DisplayWelcome();
std::string GetPlayerChoice();
std::string GetComputerChoice();
void UpdateScore(const std::string& player_move, const std::string& bot_pick, 
                 int& player_score, int& bot_score);
void DisplayRoundResult(const std::string& player_move, const std::string& bot_pick, 
                        int player_score, int bot_score);
void PauseRound();
void DisplayFinalResult(int player_score, int bot_score);
bool IsGameOver(int player_score, int bot_score);

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));  // Seed random number generator
    
    DisplayWelcome();
    
    int player_score = 0, bot_score = 0;
    int round = 1;
    
    // Main game loop - continues until someone wins 2 rounds
    while (!IsGameOver(player_score, bot_score)) {
        std::cout << "\n--- ROUND " << round << " ---\n";
        std::cout << "Score: You " << player_score << " - " << bot_score << " Bot\n";
        
        // Get and validate player's choice
        std::string player_move = GetPlayerChoice();
        
        // Generate computer's choice
        std::string bot_pick = GetComputerChoice();
        std::cout << "Bot chose: " << bot_pick << "\n";
        
        // Update scores and display round results
        UpdateScore(player_move, bot_pick, player_score, bot_score);
        DisplayRoundResult(player_move, bot_pick, player_score, bot_score);
        
        // Pause between rounds if game isn't over
        if (!IsGameOver(player_score, bot_score)) {
            PauseRound();
        }
        
        round++;
    }
    
    // Display final result
    DisplayFinalResult(player_score, bot_score);
    
    return 0;
}

/*
 * Displays the welcome message and game instructions
 */
void DisplayWelcome() {
    std::cout << "\nROCK PAPER SCISSORS Mini Game\n";
    std::cout << "First to win 2 rounds wins!\n\n";
    std::cout << "Instructions:\n";
    std::cout << "  - Enter 'r' or 'rock' for Rock\n";
    std::cout << "  - Enter 'p' or 'paper' for Paper\n";
    std::cout << "  - Enter 's' or 'scissors' for Scissors\n\n";
}

/*
 * Gets and validates the player's choice
 * @return validated player move as full string ("rock", "paper", or "scissors")
 */
std::string GetPlayerChoice() {
    std::string player_move;
    bool valid = false;
    
    while (!valid) {
        std::cout << "Enter r for rock, p for paper, s for scissors: ";
        std::cin >> player_move;
        
        // Convert to lowercase
        for (size_t i = 0; i < player_move.length(); i++) {
            if (player_move[i] >= 'A' && player_move[i] <= 'Z') {
                player_move[i] = player_move[i] + 32;
            }
        }
        
        // Convert shorthand and validate options
        if (player_move == "r" || player_move == "rock") {
            player_move = "rock";
            valid = true;
        } else if (player_move == "p" || player_move == "paper") {
            player_move = "paper";
            valid = true;
        } else if (player_move == "s" || player_move == "scissors") {
            player_move = "scissors";
            valid = true;
        } else {
            std::cout << "Invalid! Try again.\n";
        }
    }
    
    return player_move;
}

/*
 * Generates a random choice for the computer
 * @return computer's move as string ("rock", "paper", or "scissors")
 */
std::string GetComputerChoice() {
    std::string moves[3] = {"rock", "paper", "scissors"};
    return moves[rand() % 3];
}

/*
 * Updates the scores based on round result
 * @param player_move The player's move
 * @param bot_pick The computer's move
 * @param player_score Reference to player's score (updated)
 * @param bot_score Reference to computer's score (updated)
 */
void UpdateScore(const std::string& player_move, const std::string& bot_pick, 
                 int& player_score, int& bot_score) {
    // Only update if not a tie
    if (player_move != bot_pick) {
        if ((player_move == "rock" && bot_pick == "scissors") ||
            (player_move == "paper" && bot_pick == "rock") ||
            (player_move == "scissors" && bot_pick == "paper")) {
            player_score++;
        } else {
            bot_score++;
        }
    }
}

/*
 * Displays the result of a single round
 * @param player_move The player's move
 * @param bot_pick The computer's move
 * @param player_score Current player score
 * @param bot_score Current computer score
 */
void DisplayRoundResult(const std::string& player_move, const std::string& bot_pick, 
                        int player_score, int bot_score) {
    if (player_move == bot_pick) {
        std::cout << "Tie!\n";
    } else if ((player_move == "rock" && bot_pick == "scissors") ||
               (player_move == "paper" && bot_pick == "rock") ||
               (player_move == "scissors" && bot_pick == "paper")) {
        std::cout << "You win! " << player_move << " beats " << bot_pick << "\n";
    } else {
        std::cout << "Bot wins! " << bot_pick << " beats " << player_move << "\n";
    }
}

/*
 * Pauses the game until the player presses Enter
 */
void PauseRound() {
    std::cout << "\nPress Enter for next round...";
    std::cin.ignore();
    std::cin.get();
}

/*
 * Displays the final game result
 * @param player_score Final player score
 * @param bot_score Final computer score
 */
void DisplayFinalResult(int player_score, int bot_score) {
    std::cout << "\nFINAL SCORE: You " << player_score << " - " << bot_score << " Bot\n";
    
    if (player_score > bot_score) {
        std::cout << "YOU WIN! 🎉\n";
    } else if (bot_score > player_score) {
        std::cout << "BOT WINS! 🤖\n";
    } else {
        std::cout << "TIE GAME!\n";
    }
}

/*
 * Checks if the game is over (someone has won 2 rounds)
 * @param player_score Current player score
 * @param bot_score Current computer score
 * @return true if game is over, false otherwise
 */
bool IsGameOver(int player_score, int bot_score) {
    return (player_score >= 2 || bot_score >= 2);
}