#include <iostream>
#include <string>
#include <ctime>

int main() {
    srand(time(0));  // A more random number generator
    
    std::cout << "\nROCK PAPER SCISSORS Mini Game\nFirst to win 2 rounds wins!\n\n";
    
    int player_score = 0, bot_score = 0;
    std::string player_move, bot_pick;
    std::string moves[3] = {"rock", "paper", "scissors"};
    
    for (int round = 1; round <= 3 && player_score < 2 && bot_score < 2; round++) {
        std::cout << "\n--- ROUND " << round << " ---\n";
        std::cout << "Score: You " << player_score << " - " << bot_score << " Bot\n";
        
        bool valid = false; // Input validation; dpuble check
        while (!valid) {
            std::cout << "Enter r for rock, p for paper, s for scissors: ";
            std::cin >> player_move;
            
            // Convert to lowercase
            for (int i = 0; i < player_move.length(); i++) {
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
        
        // Bot moves randomly
        bot_pick = moves[rand() % 3];
        std::cout << "Bot chose: " << bot_pick << "\n";
        
        // Determine winner
        if (player_move == bot_pick) {
            std::cout << "Tie!\n";
        } else if ((player_move == "rock" && bot_pick == "scissors") ||
                   (player_move == "paper" && bot_pick == "rock") ||
                   (player_move == "scissors" && bot_pick == "paper")) {
            player_score++;
            std::cout << "You win! " << player_move << " beats " << bot_pick << "\n";
        } else {
            bot_score++;
            std::cout << "Bot wins! " << bot_pick << " beats " << player_move << "\n";
        }
        
        // Pause between rounds
        if (player_score < 2 && bot_score < 2 && round < 3) {
            std::cout << "\nPress Enter for next round...";
            std::cin.ignore();
            std::cin.get();
        }
    }
    
    // End result
    std::cout << "FINAL SCORE: You " << player_score << " - " << bot_score << " Bot\n";
    if (player_score > bot_score) {
        std::cout << "YOU WIN!";
    } else if (bot_score > player_score) {
        std::cout << "BOT WINS!";
    } else {
        std::cout << "TIE GAME!";
    }
    
    return 0;
}