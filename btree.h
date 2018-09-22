#ifndef BTREE_H
#define BTREE_H

#include <iostream>

#include "node.h"



#ifndef DEF_MAP
#define DEF_MAP

map <string, float> def;

#endif





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
            double d;

            try {
                d = solve();
            } catch (int e) {
                if (e)
                    cout << "Invalid expression" << endl;
                else
                    cout << "Undefined variable" << endl;

                return;
            }

            print();

            cout << " = " << d << endl;
        }

        // void print_solution(map <string, float> m) {
        //     cout << "with" << endl;
        //
        //     for (map <string, float> :: iterator it = def.begin(); it != def.end(); it++)
        //         cout << it->first << " = " << it->second << endl;
        //
        //     cout << endl;
        //
        //     print();
        //
        //     cout << " = " << solve(m) << endl;
        // }

        double solve() {
            if (head)
                return head->solve();

            return 0; // TODO: throw
        }

        // double solve(map <string, float> m) {
        //     if (head)
        //         return head->solve(m);
        //
        //     return 0; // TODO: throw
        // }

        ~BinaryTree() {
            if (head)
                head->killSelf();
        }
};

#endif
