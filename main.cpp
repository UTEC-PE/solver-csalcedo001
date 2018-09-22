#include <string>
#include <cstdlib>
#include <math.h>
#include <map>
#include <cstring>

#include "btree.h"

#ifndef DEF_MAP
#define DEF_MAP

map <string, float> def;

#endif

using namespace std;

void menu() {
      system("cls");
      cout<<"==========================================================="<<endl;
      cout<<"\t\tPractica Operaciones"<<endl;
      cout<<"==========================================================="<<endl;

      // char str[]="7/4*((a+b)*a)+3";
      // char str[]="7/4*((a+-+--b)^4*a)+3";
      // char str[]="2+(3)";
      // char str[]="7/4*((a+b)^4*a)+3";
      // char str[] = "    (   18   -   - - - +++ -++-+    +     23      * 4 ^ (a / 4 * 2))^( -+-0.5 * 1 / 3)";
      // char str[] = " -+-0.5 * 1 / 3";


      // Expression to be solved
      // char str[] = "(v1 + v2) ^ 2 / (v1 + v2)";

      // Variables
      // def["v1"] = 1.5;
      // def["v2"] = 4;
      // def["v3"] = 16;

      string s;

      cout << endl << "Type 'help' to get the list of all commands";
      cout << endl << "Type 'exit' to exit execution mode";
      cout << endl << endl << "> ";

      getline(cin, s);

      while (strcmp(s.c_str(), "exit")) {
          if (!strcmp(s.c_str(), "help")) {
              cout << endl;
              cout << "help         :prints all commands" << endl;
              cout << "exit         :ends program" << endl;
              cout << "variables    :prints all defined variables" << endl << endl;
              cout << "Define variables:" << endl;
              cout << "Execute 'main' with arguments:" << endl;
              cout << "./main [varname1]=[value1] [varname2]=[value2] ..." << endl;
          } else if (!strcmp(s.c_str(), "variables")) {
              if (!def.empty()) {
                  cout << endl;

                  for (map <string, float> :: iterator it = def.begin(); it != def.end(); it++)
                      cout << it->first << " = " << it->second << endl;

                  cout << endl;
              }
          } else {
              char str[s.length() + 1];

              strcpy(str, s.c_str());

              BinaryTree tree(str);

              tree.print_solution();
          }

          cout << endl << "> ";

          getline(cin, s);
      }
}

int main(int argc, char *argv[]) {
    try {
        for (int i = 1, l = argc; i < l; i++) {
            char *c = argv[i];

            while(*c != '=' && *c != '\0')
                c++;

            if (*c == '=') {
                char *var_i = argv[i], *var_f = c, *val_i = c + 1, *val_f;

                while (*var_i == ' ')
                    var_i++;

                while (*(var_f - 1) == ' ')
                    var_f--;


                if (var_i >= var_f)
                    throw 1; // Bad usage


                while (*val_i == ' ')
                    val_i++;

                val_f = val_i;

                while (*val_f != ' ' && *val_f != '\0')
                    val_f++;

                if (val_i >= val_f)
                    throw 1; // Bad usage

                *var_f = *val_f = '\0';

                def[var_i] = atof(val_i);
            } else
                throw 1; // Bad usage
        }
    } catch (int e) {
        if (e)
            cerr << "Usage: /.main [variable1]=[value1] [variable2]=[value2] ..." << endl;
        else
            cerr << "Unknown error" << endl;

        return 1;
    }

    menu();

    cout << "\nPress enter to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
