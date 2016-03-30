//
// Created by ganymed on 29/03/16.
//

#include "textsm.h"
#include <stdbool.h>


State determineNewStateAfterBeforeWord(Category category);

bool isPunctuationChar(char character) {
    return character == '.' ||
           character == '!' ||
           character == '?'
           ;
}

bool isWhitespaceChar(char character) {
    return character == ' ' ||
           character == '\n' ||
           character == '\t'
            ;
}


Category charCat(char character) {
    if( (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') ) {
        return LETTER;
    }
    else if(character >= '0' && character <= '9') {
        return DIGIT;
    }
    else if(isPunctuationChar(character)) {
        return PUNCT;
    }
    else if(isWhitespaceChar(character)) {
        return WHITESPACE;
    }

    return WHITESPACE; // TODO: define default category like UNKNOWN
}


State determineNewStateAfterBeforeWord(Category category) {
    switch(category) {
        case LETTER:
            return IN_WORD;
        case DIGIT:
        case PUNCT:
            return NO_WORD;
        case WHITESPACE:
            return BEFORE_WORD;
    }

    return NO_WORD; // should never come to this
}

State determineNewStateAfterInWord(Category category) {
    switch(category) {
        case LETTER:
        case DIGIT:
        case PUNCT:
            return IN_WORD;
        case WHITESPACE:
            return BEFORE_WORD;
    }

    return NO_WORD; // should never come to this
}

State determineNewStateAfterNoWord(Category category) {
    // TODO: what to do here?
    switch(category) {
        case LETTER:
        case DIGIT:
        case PUNCT:
            return NO_WORD;
        case WHITESPACE:
            return BEFORE_WORD;
    }

    return NO_WORD; // should never come to this
}

State stateMachine(State currentState, Category category) {
    switch(currentState) {
        case BEFORE_WORD:
            return determineNewStateAfterBeforeWord(category);
        case IN_WORD:
            return determineNewStateAfterInWord(category);
        case NO_WORD:
            return determineNewStateAfterNoWord(category);
    }

    return NO_WORD; // should never come to this
}