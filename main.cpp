#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

using namespace std;

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

        int level = 0, max_op = 0; // level represents
        char *max_ptr = begin;

        for (char *i = begin; i < end; i++) {
            int value = op_value(*i);

            if (!level && value >= max_op) {
                max_op = value;
                max_ptr = i;
            }

            if (*i == '(' || *i == ')')
                level += value;
            else if (*i == '-' || *i == '+')
                while (*(i + 1) == '-' || *(i + 1) == '+') {
                    i++;
                }
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
            // left->recurse();

            return;
        }

        if (max_ptr == begin) {
            right = new Node(begin + 1, end);

            return;
        }

        left = new Node(begin, max_ptr);
        // left->recurse();

        right = new Node(max_ptr + 1, end);
        // right->recurse();
    };

    void killSelf() {
        if (left)
            left->killSelf();

        if (right)
            right->killSelf();

        delete this;
    }

    void print() {
        for (char *i = begin; i < end; i++)
            cout << *i;

        cout << endl;
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
        } else {
              for (char *i = begin; i < end; i++)
                  cout << *i;
        }

        cout << ']';
    }

    float solve() {
        if (op_type == 'v') {
            char tmp = *end;

            *end = '\0';

            float result = atof(begin);

            *end = tmp;

            return result;
        }

        if (!right)
            return 0; //TODO: throw

        if (!left)
            return operate(op_type, right->solve());

        return operate(op_type, left->solve(), right->solve());
    }
};

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

        float solve() {
            if (head)
                return head->solve();

            return 0; // TODO: throw
        }

        ~BinaryTree() {
            if (head)
                head->killSelf();
        }
};

void menu() {
      system("cls");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

      //TODO: Allow variables
      //char str[]="7/4*((a+b)*a)+3";
      //char str[]="7/4*((a+-+--b)*a)+3";
      //char str[]="2+(3)";
      // char str[]="7/4*((a+b)^4*a)+3";
      char str[] = "7/4*((1+-+--2)^(2^2-1)*4)+3*(((-++-2-(+--(4)))))";
      // char str[] = "--1";

      BinaryTree tree(str);

      tree.print_structure();

      cout << endl;

      tree.print();

      cout << "= " << tree.solve() << endl;
}

int main(int argc, char const *argv[]) {
    menu();

    cout << "\nPress enter to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
