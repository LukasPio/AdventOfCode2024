#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_GREEN  "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE   "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char* getRandomWord();
char* getUserInput();
int* assertWords(char* correctWord, char* givenWord);
void printHiddenWord(int* discoveredIndexes, char* correctWord);
void toLowerCase(char* wordToLower);

int main() {

    srand(time(NULL));
    char* correctWord = getRandomWord();
    int discoveredIndexes[5] = {0, 0, 0, 0, 0};
    int finishGame = 0;
    
    while (!finishGame)
    {
        char* givenWord = getUserInput();
        int* charsToShow = assertWords(correctWord, givenWord);

        if (strcmp(givenWord, correctWord) == 0) {
            finishGame = 1;
        }

        if (!finishGame) {
            for (int i = 0; i < 5; i++) {
            if (charsToShow[i] == 1) {
                printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, givenWord[i]);
                discoveredIndexes[i] = 1;
            }
            else if (charsToShow[i] == 2) {
                printf(ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET, givenWord[i]);
            }
            else {
                printf("%c", givenWord[i]);
            }
        }

        printf("\n");

        printHiddenWord(discoveredIndexes, correctWord);
        }
    }

    printf(ANSI_COLOR_GREEN "Congratulations You Win!\n" ANSI_COLOR_RESET);

    printf("Press 1 to play again");
    char playAgain;
    scanf("%c", playAgain);

    if (playAgain == '1') {
        main();
    }

    return 0;
}

char* getUserInput() {
    char* givenWord = (char*) malloc(6 * sizeof(char));

    printf(ANSI_COLOR_BLUE "Enter a five chars tech related word in english" ANSI_COLOR_RESET "\n");
    scanf("%s", givenWord);
    
    if (strlen(givenWord) != 5) {
        printf(ANSI_COLOR_RED "Only 5 char words are allowed" ANSI_COLOR_RESET "\n");
        free(givenWord);
        return getUserInput();
    }
    
    toLowerCase(givenWord);

    return givenWord;
}

char* getRandomWord() {
    char words[15][6] = {
    "array",
    "logic",
    "query",
    "debug",
    "stack",
    "class",
    "scope",
    "bytes",
    "input",
    "patch",
    "token",
    "linux",
    "float",
    "mutex",
    "shell"
    };

    int randomIndex = rand() % 15;
    
    char* randomWord = malloc(6 * sizeof(char));
    if (randomWord == NULL) {
        printf(ANSI_COLOR_RED "An error occurred alocating memory." ANSI_COLOR_RESET "\n");
        exit(1);
    } 

    for (int i = 0; i < 6; i++) {
        randomWord[i] = words[randomIndex][i];
    }

    return randomWord;
}

int* assertWords(char* correctWord, char* givenWord) {
    int* charsToShow = (int*) malloc(5 * sizeof(int));
    if (charsToShow == NULL) {
        printf(ANSI_COLOR_RED "An error occurred alocating memory." ANSI_COLOR_RESET "\n");
        exit(1);
    }
    // Shell
    // Hells

    for (int i = 0; i < 5; i++) {
        if (correctWord[i] == givenWord[i]) {
            charsToShow[i] = 1;
        }
        else {
            for (int j = 0; j < 5; j++) {
                if (givenWord[i] == correctWord[j]) {
                    charsToShow[i] = 2;
                }
            }
        }
    }

    return charsToShow;
}

void printHiddenWord(int* discoveredIndexes, char* correctWord) {
    printf("Correct word: ");
    for (int i = 0; i < 5; i++) {
        if (discoveredIndexes[i] == 1) {
            if (i == 0) printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, correctWord[i] - 32);
            else printf(ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET, correctWord[i]);
        }
        else printf("_");
    }
    printf("\n");
}

void toLowerCase(char* wordToLower) {
    for (int i = 0; i < 5; i++) {
        if (wordToLower[i] < 96) {
            wordToLower[i] = wordToLower[i] + 32;
        }
    }
}