#include "tool.h"

Letter CreatLetter(char letter, int exponent)
{
    return Letter{letter, exponent};
}

void Print(Letter L)
{
    cout << L.letter;
    cout << '^';
    cout << L.exponent;
}
