//
// Created by ganymed on 29/03/16.
//

#ifndef P1_TEXTSM_H
#define P1_TEXTSM_H

#endif //P1_TEXTSM_H

typedef enum State {
    BEFORE_WORD,
    IN_WORD,
    NO_WORD
} State;

typedef enum Category {
    LETTER,
    DIGIT,
    PUNCT,
    WHITESPACE
} Category;


Category charCat(char character);

State stateMachine(State currentState, Category category);