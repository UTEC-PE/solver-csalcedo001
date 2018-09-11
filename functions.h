#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// TODO: Change switch for map

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
            return 0; // TODO: throw error
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
            return 0; // TODO: throw error
    }
}

#endif
