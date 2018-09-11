#include <string>
#include <cstdlib>
#include <math.h>

#include "btree.h"

using namespace std;

void menu() {
      system("cls");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

      //char str[]="7/4*((a+b)*a)+3";
      //char str[]="7/4*((a+-+--b)*a)+3";
      //char str[]="2+(3)";
      // char str[]="7/4*((a+b)^4*a)+3";
      char str[] = "    (   18   -   - - - +++ -++-+    +     23      * 4 ^ (1 / 4 * 2))^( -+-0.5 * 1 / 3)";
      // char str[] = "--1";

      BinaryTree tree(str);

      tree.print_structure();

      cout << endl;

      tree.print_solution();
}

int main(int argc, char const *argv[]) {
    menu();

    cout << "\nPress enter to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
