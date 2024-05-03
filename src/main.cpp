#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


bool isValidLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


void printHangman(int incorrectGuesses) {
    switch (incorrectGuesses) {
        case 0:
            cout << "  _______" << endl;
            cout << " |       |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << "_|_________" << endl;
            break;
        case 1:
            cout << "  _______" << endl;
            cout << " |       |" << endl;
            cout << " |       O" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << "_|_________" << endl;
            break;
        case 2:
            cout << "  _______" << endl;
            cout << " |       |" << endl;
            cout << " |       O" << endl;
            cout << " |       |" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << "_|_________" << endl;
            break;
        case 3:
            cout << "  _______" << endl;
            cout << " |       |" << endl;
            cout << " |       O" << endl;
            cout << " |      /|" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << "_|_________" << endl;
            break;
        case 4:
            cout << "  _______" << endl;
            cout << " |       |" << endl;
            cout << " |       O" << endl;
            cout << " |      /|\\" << endl;
            cout << " |" << endl;
            cout << " |" << endl;
            cout << "_|_________" << endl;
            break;
        case 5:
            cout << "  _______" << endl;
            cout << " |       |" << endl;
            cout << " |       O" << endl;
            cout << " |      /|\\" << endl;
            cout << " |      /" << endl;
            cout << " |" << endl;
            cout << "_|_________" << endl;
            break;
        case 6:
            cout << "  _______" << endl;
            cout << " |       |" << endl;
            cout << " |       O" << endl;
            cout << " |      /|\\" << endl;
            cout << " |      / \\" << endl;
            cout << " |" << endl;
            cout << "_|_________" << endl;
            break;
    }
}

int main() {
    vector<string> words = {"bubblegum", "radiant", "coconut", "serendipity", "algorithm", "thunderstorm", "lagoon", "satchel", "chimera", "melancholy","whimsical", "gazelle", "cascade", "serenity", "effervescent", "harmony", "quixotic", "tranquility", "paradox", "eloquent","rhapsody", "cascade", "marvelous", "luminous", "enigma", "whisper", "serenade", "sapphire", "surreal", "ephemeral","countenance", "profound", "manifest", "serene", "sublime", "prodigious", "singular", "clamor", "visage", "abate", "allude", "grotesque", "undulate", "acute", "vivid", "venerate", "exquisite", "melancholy", "incredulous", "traverse", "repose", "lurid", "languid", "superfluous", "sagacity", "vulgar", "placid", "tremulous", "odious", "pallor", "abyss", "stolid", "condescend", "wistful", "prostrate", "remonstrate", "palpable", "vex", "amiable", "perplex", "portent", "peremptory", "somber", "importune", "audible", "expostulate", "subtle", "tangible", "vivacious", "despondent", "doleful", "pervade", "pensive", "apprehension", "procure", "abject", "austere", "magnanimous", "oppress", "oblique", "sallow", "ignominy", "eccentric", "resolute", "articulate", "furtive", "fain", "genial", "mien", "affect", "billow", "confound", "wan", "indolent", "maxim", "reproach", "morose", "latter", "conjure", "retort", "antipathy", "alacrity", "animated", "vestige", "verdure", "adjacent", "rebuke", "zenith", "inexorable", "livid", "din", "dilate", "fortnight", "abash", "profane", "imperious", "conjecture", "swarthy", "impute", "appellation"};


    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % words.size();
    string secretWord = words[randomIndex];

    int incorrectGuesses = 0;
    const int maxIncorrectGuesses = 6; 
    string guessedLetters;

    cout << "Welcome to Hangman!" << endl;


    string hiddenWord(secretWord.length(), '-');

    while (hiddenWord != secretWord && incorrectGuesses < maxIncorrectGuesses) {
        cout << endl;
        printHangman(incorrectGuesses);
        cout << "Secret Word: " << hiddenWord << endl;
        cout << "Incorrect Guesses Remaining: " << maxIncorrectGuesses - incorrectGuesses << endl;
        cout << "Guessed Letters: " << guessedLetters << endl;
        cout << "Enter a letter guess or type '*' to guess the entire word: ";

        string guess;
        cin >> guess;


        if (guess == "*") {
            string wordGuess;
            cout << "Enter your word guess: ";
            cin >> wordGuess;

            if (wordGuess == secretWord) {
                cout << "Congratulations! You guessed the word: " << secretWord << endl;
                return 0;
            } else {
                cout << "Sorry, that's incorrect!" << endl;
                ++incorrectGuesses;
                continue;
            }
        }


        char letterGuess = guess[0];
        if (!isValidLetter(letterGuess)) {
            cout << "Please enter a valid letter." << endl;
            continue;
        }


        if (guessedLetters.find(letterGuess) != string::npos) {
            cout << "You already guessed that letter. Try again." << endl;
            continue;
        }


        guessedLetters += letterGuess;


        bool correctGuess = false;
        for (int i = 0; i < secretWord.length(); ++i) {
            if (secretWord[i] == letterGuess) {
                hiddenWord[i] = letterGuess;
                correctGuess = true;
            }
        }


        if (!correctGuess) {
            ++incorrectGuesses;
            cout << "Incorrect guess!" << endl;
        }
    }

    cout << endl;
    printHangman(incorrectGuesses);


    if (hiddenWord == secretWord) {
        cout << "Congratulations! You guessed the word: " << secretWord << endl;
    } else {
        cout << "Sorry, you ran out of guesses. The word was: " << secretWord << endl;
    }

    return 0;
}