//
// Created by ganymed on 29/03/16.
//

#include "textsm.c"
#include <gtest/gtest.h>



void testCharCatLetters() {
    assert(charCat('A') == LETTER);
    assert(charCat('Z') == LETTER);
    assert(charCat('a') == LETTER);
    assert(charCat('z') == LETTER);
}

void testCharCatDigits() {
    assert(charCat('0') == DIGIT);
    assert(charCat('1') == DIGIT);
    assert(charCat('2') == DIGIT);
    assert(charCat('3') == DIGIT);
    assert(charCat('4') == DIGIT);
    assert(charCat('5') == DIGIT);
    assert(charCat('6') == DIGIT);
    assert(charCat('7') == DIGIT);
    assert(charCat('8') == DIGIT);
    assert(charCat('9') == DIGIT);
}

void testCharCatPunctuation() {
    assert(charCat('.') == PUNCT);
    assert(charCat('!') == PUNCT);
    assert(charCat('?') == PUNCT);
}

void testCharCatWhitespace() {
    assert(charCat(' ') == WHITESPACE);
    assert(charCat('\n') == WHITESPACE);
    assert(charCat('\t') == WHITESPACE);
}

void testCharCat() {
    testCharCatLetters();
    testCharCatDigits();
    testCharCatPunctuation();
    testCharCatWhitespace();
}


void testStateMachineBeforeWord() {
    assert(stateMachine(BEFORE_WORD, LETTER) == IN_WORD);
    assert(stateMachine(BEFORE_WORD, DIGIT) == NO_WORD);
    assert(stateMachine(BEFORE_WORD, PUNCT) == NO_WORD);
    assert(stateMachine(BEFORE_WORD, WHITESPACE) == BEFORE_WORD);
}

void testStateMachineInWord() {
    assert(stateMachine(IN_WORD, LETTER) == IN_WORD);
    assert(stateMachine(IN_WORD, DIGIT) == IN_WORD);
    assert(stateMachine(IN_WORD, PUNCT) == IN_WORD);
    assert(stateMachine(IN_WORD, WHITESPACE) == BEFORE_WORD);
}

void testStateMachineNoWord() {
    assert(stateMachine(NO_WORD, LETTER) == NO_WORD);
    assert(stateMachine(NO_WORD, DIGIT) == NO_WORD);
    assert(stateMachine(NO_WORD, PUNCT) == NO_WORD);
    assert(stateMachine(NO_WORD, WHITESPACE) == BEFORE_WORD);
}

void testStateMachine() {
    testStateMachineBeforeWord();
    testStateMachineInWord();
    testStateMachineNoWord();
}


int main2() {
    testCharCat();
    testStateMachine();

    return 0;
}




/*
TEST(SquareRootTest, PositiveNos) {
    //ASSERT_EQ (LETTER, charCat('A'));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
*/