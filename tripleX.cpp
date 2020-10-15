#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    std::cout << "\n\nYou are a secret agent breaking into a Level " << Difficulty;
    std::cout << " secure server room\nYou will need to enter the correct password to continue..\n";
}

bool PlayGame(int Difficulty){
    PrintIntroduction(Difficulty);

    const int FirstCode = rand() % Difficulty + Difficulty;
    const int SecondCode = rand() % Difficulty + Difficulty;
    const int ThirdCode = rand() % Difficulty + Difficulty;
 
    const int CodeSum = FirstCode + SecondCode + ThirdCode;
    const int CodeProduct = FirstCode + SecondCode + ThirdCode;

    std::cout << "There are three numbers in this code \n";
    std::cout << "The codes add up to: " << CodeSum;
    std::cout << "\nThe codes multiply to: " << CodeProduct << std::endl;

    // Stores player guesses
    int FirstCodeGuess, SecondCodeGuess, ThirdCodeGuess;
    std::cin >> FirstCodeGuess >> SecondCodeGuess >> ThirdCodeGuess;

    std::cout << "You entered: " << FirstCodeGuess << SecondCodeGuess << ThirdCodeGuess;

    int GuessSum = FirstCodeGuess + SecondCodeGuess + ThirdCodeGuess;
    int GuessProduct = FirstCodeGuess * SecondCodeGuess * ThirdCodeGuess;

    // Checks if player has guessed correctly
    if(GuessSum == CodeSum){
        std::cout << "\n You cracked the code, congrats. \n Time for the next level";
        return true;
    } else {
        std::cout << "\n Wrong code, busted, try again.";
        return false;
    }
}

int main(){
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxLevel = 10;

    while(LevelDifficulty <= MaxLevel){ // loop game until all levels are completed
        bool bLevelComplete = PlayGame(LevelDifficulty);

        std::cin.clear();
        std::cin.ignore();

        if(bLevelComplete){
            ++LevelDifficulty;
        }
        
    }
    
    std::cout << "\n Congrats, you hacked into the mainframe and got the filles. Now get out of there!";  

    return 0;
}
