#ifndef BTREE_H
#define BTREE_H

#include <iostream>

#include "node.h"

using namespace std;

class BinaryTree {
    private:
        Node *head;

    public:
        BinaryTree(char *str) {
            head = new Node(str);
        }

        void print() {
            if (head)
                head->print();
        }

        void print_structure() {
            if (head) {
                head->print_structure();
                cout << endl;
            }
        }

        void print_solution() {
            print();

            cout << " = " << solve() << endl;
        }

        double solve() {
            if (head)
                return head->solve();

            return 0; // TODO: throw
        }

        ~BinaryTree() {
            if (head)
                head->killSelf();
        }
};

#endif
