#include <iostream>

#include "calculator.h"

using namespace std;

int main()
{
    calculator<float> c;
    c.sum(1);
    c.sum(2);
    c.get_total();

    return 0;

    int score;

    //Vraag de score
    cout << "Score:";
    cin >> score;
}