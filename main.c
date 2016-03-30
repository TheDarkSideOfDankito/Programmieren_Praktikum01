#include <stdio.h>
#include "textsm.h"


int main() {
    int countWords = 0;
    int countLines = 0;

    State currentState = BEFORE_WORD;
    State newState = BEFORE_WORD;
    Category category;
    char character;
    char previousCharacter;

    do {
        character = getchar();
        category = charCat(character);
        newState = stateMachine(currentState, category);
        //printf("Category: %d\nCurrentState: %d\nNewState: %d\n", category, currentState, newState);

        if(currentState == IN_WORD && newState == BEFORE_WORD) {
            countWords++;
        }

        if(character == '\n' && previousCharacter != '\n') {
            countLines++;
        }

        currentState = newState;
        previousCharacter = character;
    } while(character != EOF);

    printf("Anzahl Woerter: %d\n", countWords);
    printf("Anzahl Zeilen: %d\n", countLines);

    return 0;

}
