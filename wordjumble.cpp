//Word Jumble Game


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    bool play_again = true;
    while (play_again)
    {
        
    //Initializing 2-dimensional array
    enum fields {WORD, HINT, NUM_FIELDS};
    const int NUM_WORDS = 4;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"wall", "what do you put pictures on?"},
        {"glasses", "these help you see"},
        {"labored", "working hard, breathing hard"},
        {"jumble", "the name of the game"}
        
    };

    //Pick a random word
    srand(static_cast<unsigned>(time(0)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];  //word to guess
    string theHint = WORDS[choice][HINT];  //hint for word

    //Jumbles the word
    string jumble = theWord; // jumbled version in a variable
    int length = jumble.size();
    for (int i = 0; i < length; ++i)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1]= jumble[index2];
        jumble[index2]= temp;
    }

    //Welcome the player
    cout << "\t\t\tWelcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to make a word.\n";
    cout << "Enter hint for a hint.\n";
    cout << "Enter quit to quit the game.\n\n";
    cout << "The jumble is: " << jumble;

    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;

    //Start game loop
    while ((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
        {
            cout << theHint;
        }
        else
        {
            cout << "Sorry, that's not it.";
        }

        cout << "\n\nYour guess: ";
        cin >> guess;
    }

    //Saying goodbye
    if(guess == theWord)
    {
        cout << "\nThat's it! You guessed it!\n";
    }

    
        
        cout << "\nWant to play again (y / n)?";
        char answer;
        cin >> answer;
        if (tolower(answer) != 'y')
        {
            play_again = false;
        }
    }

    cout << "\nThanks for playing. \n";

    return 0;

}