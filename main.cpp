#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    string input_line;
    vector<string> latex;
    int numberSign=0;
    string latexChar="";
    latex.clear();
    while( getline(cin, input_line) ) {
        stringstream sep(input_line);

        if(input_line.length() <= 1)
            break;

        string newLine="";
        
        int length = input_line.length();

        for(int i=0; i<length ; i++) {
            if ( input_line[i] == '"' ) {
                numberSign++;
                if ( numberSign % 2 != 0 )
                    latexChar = "``";
                else
                    latexChar = "''";
                newLine = newLine + latexChar;
            } else {
                newLine = newLine + input_line[i];
            }
        }

        latex.push_back(newLine);
    }

    for(auto element: latex) {

        cout << element << "\n";
    }

    return 0;
}
