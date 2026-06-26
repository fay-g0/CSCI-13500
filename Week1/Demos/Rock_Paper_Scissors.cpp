#include<iostream>
#include<random>

int main (){
    int player_score = 0;
    int bot_score = 0;
    int bot_pick = 0;
    std::string move = "";
    std::string winner = "";


// game loop
    for(int rounds = 0; rounds < 3; rounds ++)
        if (player_score >= 2){
            winner = "Player";
            break;
        }
        else if (bot_score >= 2){
            winner = "Bot";

        }

    //check early for winner
    //ask for user input
    //generate bot input
   
    bot_move = rand()% 3;
    if (bot_move == 0) {
        bot_pick = "Rock";
    }
    else if (bot_move == 1 ){
        both_pick = "Paper";
    }
    else (bot_move == 2 ){

    } 
    *bot_move == 3

    }
{

}
    //figure out the score