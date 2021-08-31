#include <iostream> //hash indicates a preprocessor directive in the code, like a package in python
#include <ctime> // computer time

void PrintIntroduction(int Difficulty) //this function (void) returns no data, so no 'return 0' has to be included
{//function is within these two curly brackets, called the function body
     // Print startup messages
    std::cout << "\n" << R"(++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++)" << "\n" ;
    std::cout << "  To authorise access to 'The Net' please enter the correct numerical codes." ; //std is standard, called a namespace and are accessed with the two colons, cout is character output
    std::cout << std::endl ; //endl instructs the code to end the line and makes the strings print onto different lines
    std::cout << "     Failure to authorise access will result in connection termination." ;
    std::cout << "\n                              Current Level: "  << Difficulty ;
    std::cout << "\n" << R"(++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++)" ;

}

bool PlayGame(int Difficulty) //turns datatype to a boolean, must return a boolean instead of data like return 0
{ 
    PrintIntroduction(Difficulty) ;

    // Declares 3 numbers
    const int CodeA = rand() % Difficulty + Difficulty ; //% is a modulus operator, its division and returning the remainder
    const int CodeB = rand() % Difficulty + Difficulty ; //const keeps the value of a variable constant throughout the code and will not allow it to be reassigned
    const int CodeC = rand() % Difficulty + Difficulty ;

    // a = 7 ; //can reassign variables if they are not prefixed with const

    const int CodeSum = CodeA + CodeB + CodeC ;
    const int CodeProduct = CodeA * CodeB * CodeC ;

    // Print end sum and product
    std::cout << std::endl ;
    std::cout << std::endl ; //this creates a paragraph-like spacing, alternatively, \n\n can be used
    std::cout << " + There are three numbers that need to be found." ;
    std::cout << "\n + The numbers add up to: " << CodeSum ; //this will print out the variable sum and also a string of text
    std::cout << "\n + The numbers multiply to make: " << CodeProduct << std::endl << std::endl ;// can end the line on the same line of code with cout

    //User input
    int GuessA, GuessB, GuessC ;
    std::cin >> GuessA ; //cin is character input and then requires input from the user. Note the < is the opposite way.
    std::cin >> GuessB ;
    std::cin >> GuessC ;

    // Player guess sum and product, these are to check if the player input is correct
    int GuessSum = GuessA + GuessB + GuessC ;
    int GuessProduct = GuessA * GuessB * GuessC ;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct) // == is a comparison operator, && is the and operator
    {
        std::cout << "\n *** Increasing Security Level... *** "; //\n does the same as std::endl
        return true ;
    }
    else
    {
        std::cout << "\n *** Access Denied. Retry. *** " ; //maybe add a certain number of lives?
        return false ;
    }
}

int main() //int is short for integer, main is the function name, parentheses pass arguments into the function
{ 
    srand(time(NULL)) ; //created new random sequence based on time of day
    int LevelDifficulty = 1 ;
    const int MaxDifficulty = 5 ;

    while(LevelDifficulty <= MaxDifficulty) //loops the game until all level are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty) ; //this runs the function above

        std::cin.clear() ; //this clears any errors
        std::cin.ignore() ; //discards the buffer

        if(bLevelComplete)
        {
            ++LevelDifficulty ; //increases difficulty by 1
            
        }
        
    }
    
    std::cout << "***Access Granted.***" ;

    return 0; //finishes running the program
}