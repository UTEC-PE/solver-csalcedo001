#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cctype>
#include <iostream>
#include <string>
#include <map>

using namespace std;

// TODO: Change switch for map
#ifndef DEF_MAP
#define DEF_MAP

map <string, float> def;

#endif

int op_value (char c) {
    switch(c) {
        case '+':
        case '-':
            return 4;
        case '*':
        case '/':
            return 3;
        case '^':
            return 2;
        case '(':
            return 1;
        case ')':
            return -1;
        default:
            return 0;
    }
}

float operate (char op, float x) {
    switch(op) {
        case '+':
        case '(':
            return x;
        case '-':
            return -x;
        default:
            throw 1;
    }
}

float operate (char op, float x, float y) {
    switch(op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '^':
            return pow(x, y);
        default:
            throw 0;
    }
}

//TODO: Check invalid variable names
bool constant_q(char *s) {
    for (int i = 0; s[i] != '\0'; i++)
        if (!isdigit(s[i]) && s[i] != '.')
          return false;

    return true;
}

#endif
