#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "functions.h"

#ifndef DEF_MAP
#define DEF_MAP

map <string, float> def;

#endif

using namespace std;

struct Node {
    Node *left;   // Left child node
    Node *right;  // Right child node

    char *begin;  // Pointer to the beginning of the expression
    char *end;    // Pointer to the end of the expression

    char op_type; // Type of operator of the node.
                  // Can be equal to +, -, *, /, ^, (, or v. v stands for variable

    Node(char *str) : Node(str, &str[strlen(str)]) {};
    Node(char *data_begin, char *data_end) : begin(data_begin), end(data_end) {
        left = right = nullptr;

        // Errase spaces in the beginning of the string
        while (*begin == ' ' && begin < end)
            begin++;

        // Errase spaces at the end of the string
        while (*(end - 1) == ' ' && begin < end)
            end--;

        int level = 0, max_op = 0; // level = 0 => no parenthesis
        char *max_ptr = begin;

        for (char *i = begin; i < end; i++) {
            if (*i == ' ')
                continue;

            int value = op_value(*i);

            if (!level && value >= max_op) {
                max_op = value;
                max_ptr = i;
            }

            if (*i == '(' || *i == ')')
                level += value;
            else if (*i == '-' || *i == '+')
                while (*(i + 1) == '-' || *(i + 1) == '+' || *(i + 1) == ' ')
                    i++;
        }

        if (max_op)
            op_type = *max_ptr;
        else
            op_type = 'v';

        if (level)
            throw 1;

        if (!max_op || begin >= end - 1)
            return;

        if (max_op == 1) {
            right = new Node(begin + 1, end - 1);

            return;
        }

        if (max_ptr == begin) {
            right = new Node(begin + 1, end);

            return;
        }

        left = new Node(begin, max_ptr);

        right = new Node(max_ptr + 1, end);
    };

    void killSelf() {
        if (left)
            left->killSelf();

        if (right)
            right->killSelf();

        delete this;
    }

    void print() {
        if (op_type != 'v') {
            if (left)
                left->print();

            cout << op_type;

            if (right)
                right->print();

            if (op_type == '(')
                cout << ')';
        } else
              for (char *i = begin; i < end; i++)
                  cout << *i;
    }

    void print_structure() {
        cout << '[';

        if (op_type != 'v') {
            if (left)
                left->print_structure();
            cout << op_type;

            if (right)
                right->print_structure();

            if (op_type == '(')
                cout << ')';
        } else
              for (char *i = begin; i < end; i++)
                  cout << *i;

        cout << ']';
    }

    double solve() {
        if (op_type == 'v') {
            char tmp = *end;

            *end = '\0';

            if (constant_q(begin)) {
                double result = atof(begin);

                *end = tmp;

                return result;
            } else if (!def.empty() && def.find(begin) != def.end()) {
                double result = def[begin];

                *end = tmp;

                return result;
            }

            throw 0; // Undefined variable
        }

        if (!right)
            throw 1; // Invalid expression

        if (!left)
            return operate(op_type, right->solve());

        return operate(op_type, left->solve(), right->solve());
    }
};

#endif
