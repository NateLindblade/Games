/* Name: Nathan Lindblade
Date: 3/2/2023
About this project: Allows user to play 3 games and view their statistics
Assumptions: Assumes user enters valid numbers
All work below was performed by Nathan Lindblade */

//Headers and Libraries
#include <iostream> 
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function Declarations
void printRules();
void menu();
bool guessNumber();
bool highLow();
bool collectPairs();
void viewStats(int wins, int losses);

int main()
{
    int choice, wins, losses;
    
    //Seed Time
    srand(time(0));
    do 
    {
        menu();
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
           cout << "Enter an item on the Menu: "; 
           cin >> choice;
        }
        switch (choice)
        {
            case 1:
                if (guessNumber())
                    wins++;
                else
                    losses++;
                break;
            case 2:
                if (highLow())
                    wins++;
                else
                    losses++;
                break;
            case 3:
                if (collectPairs())
                    wins++;
                else
                    losses++;
                break;
            case 4:
                viewStats(wins, losses);
                break;
            case 5:
                cout << "Statistics Reset!\n\n";
                wins = 0;
                losses = 0;
                break;
            case 6:
                printRules();
                break;
        }
         
    }while (choice != 0);
     
     viewStats(wins, losses);
     
     cout << "Thanks for playing!\n";
     return 0;
}

/*Function definition for COLLECTPAIRS
this function is invoked whenever the user wants to play Collect Pairs.
this function returns true/false depending on if the user wins the game or not*/
bool collectPairs()
{
    int dice1, dice2, sum, score1 = 0, score2 = 0, score3 = 0, score4 = 0, 
    score5= 0, score6= 0;
    cout << "\nRolling a pair of dice 100 times for pairs!" << endl;
    
    for (int x = 1; x <= 100; x++)
    {
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        
        if (dice1 == 1 && dice2 == 1 && score1 == 0)
        {
          cout << "PAIR OF ONES found\n";
          score1++;
        }
        else if (dice1 == 2 && dice2 == 2 && score2 == 0)
        {
          cout << "PAIR OF TWOS found\n";
          score2++;
        }
        else if (dice1 == 3 && dice2 == 3 && score3 == 0)
        {
          cout << "PAIR OF THREES found\n";
          score3++;
        }
        else if (dice1 == 4 && dice2 == 4 && score4 == 0)
        {
          cout << "PAIR OF FOURS found\n";
          score4++;
        }
        else if (dice1 == 5 && dice2 == 5 && score5 == 0)
        {
          cout << "PAIR OF FIVES found\n";
          score5++;
        }
        else if (dice1 == 6 && dice2 == 6 && score6 == 0)
        {
            cout << "PAIR OF SIXES found\n";
            score6++;
        }
    }
     sum = score1 + score2 + score3 + score4 + score5 + score6;
     
     if (sum != 6)
    {
      cout << "Sorry, You Lose.\n\n";
      return false;
    }
     else if (sum == 6)
    {
     cout << "You Win!\n\n";
     return true;
    }
    return true;
}
/*Function definition for GUESSNUMBER
this function is invoked whenever the user wants to play Guess Number.
this function returns true/false depending on if the user wins the game or not*/
bool guessNumber()
{
    int guess, attempt = 1, number = rand() % 100 + 1;
    cout << "\n\n";
    cout << "Guess the Number, 1 --> 100!\n";

    while (attempt <= 6)
    {
        cout << "Attempt " << attempt << "/6 : ";
        cin >> guess;
        if (guess > number)
        {    cout << "TOO BIG" << endl;
            attempt++;
        }
        else if (guess < number)
        {    cout << "TOO SMALL" << endl;
            attempt++;
        }
        else if (guess == number)
        {
            cout << "You WIN!\n" << endl;
            return true;
        }
    }
    cout << "Sorry, you lose. The number was " << number << "\n\n";
    
    return false;
}

/*Function definition for HIGHLOW
this function is invoked whenever the user wants to play high low.
this function returns true/false depending on if the user wins the game or not*/
bool highLow()
{
    int rounds = 1, number1 = rand() % 1000 + 1, number2 = rand() % 1000 + 1;
    char guess;
    cout << "\n\nHigh or Low! Stay alive for 5 rounds to win! (Numbers range from ";
    cout << "1 to 1000)\n";
    
    do 
    {
        cout << "Round " << rounds << " of 5. The number is " << number1;
        cout << "\n\t...is the next number [H]igher or [L]ower: ";
        cin >> guess;
        while (guess != 'H' && guess != 'h' && guess != 'L' && guess != 'l')
        {
            cout << "\tEnter H or L: ";
            cin >> guess;
        }
        
        if (guess == 'H' || guess == 'h')
        {
            if (number1 > number2)
            {
                cout << "The next number is " << number2 << endl;
                cout << "Sorry, You lose\n\n";
                return false;
            }
            else if (number1 < number2)
            {
                cout << "Correct!\n";
                number1 = number2;
                number2 = rand() % 1000 + 1;
                rounds++;
            }
        }
        else if (guess == 'L' || guess == 'l')
        {
            if (number1 > number2)
            {
                cout << "Correct!\n";
                number1 = number2;
                number2 = rand() % 1000 + 1;
                rounds++;
                
            }
            else if (number1 < number2)
            {
                cout << "The next number is " << number2 << endl;
                cout << "Sorry, You lose\n\n";
                return false;
            }
           
        }
        
    }while (rounds <= 5);
    cout << "The next number is: " << number2;
    cout << "\nCorrect!\nYou WIN!\n\n";

    return true;
}

/*Function definition for VIEWSTATS
this function takes in the number of wins, and losses that the user had while playing their games
this function then prints the win and loss stats neatly to the screen, and returns no value*/
void viewStats(int wins, int losses)
{
    cout << "\nSTATISTICS\n--------------------------\n";
    cout << "Wins: " << wins << "\t" << "Losses: " << losses;
    cout << fixed << showpoint << setprecision (1);
   
    cout << " \nTotal Win Percent: " << ((wins * 1.0) / (wins + losses)) * 100 
    << "%\n\n";
    
    return;
}

/*Function definition for MENU 
this function should print the menu for the user and ask/obtain their menu choice.
this function will return the user's menu choice after verifying it's a valid choice on the menu.*/
void menu()
{
    cout <<"GAME MENU:\n--------------------------\n1: PLAY Guess the Number\n";
    cout <<"2: PLAY High Low\n3: PLAY Collect Pairs\n4: VIEW Statistics\n";
    cout <<"5: RESET Statistics\n6: RULES\n0: QUIT\n--------------------------";
    cout <<"\n> ";
    return;
}

/*Function definition for PRINTRULES
this function prints the rules of all of the games available to the user in this program
that is all this function is responsible for. DO NOT CHANGE this function.*/
void printRules()
{
    cout << "\nRULES:\n\nGuess the Number Game:\nYou'll only get 6 tries to guess a number between 1 and 100!";
    cout << "\nGuess Wisely!\n\nHigh/Low Game:\nMake it through 5 rounds of guessing whether the next random number\n";
    cout << "between 1 and 1,000 is higher or lower than the previous, and you win!\n\n";
    cout << "Collect the Pairs Game:\nRoll two dice 100 times. If in the 100 times you roll a pair\n";
    cout << "of each type (1's, 2's, 3's, 4's, 5's, 6's) at least once, then YOU WIN!\n\n";
    return;
}

