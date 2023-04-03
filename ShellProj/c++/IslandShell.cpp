#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
     
    string command;
    cin >> command;
    cout << command;

    // Vector of string to save tokens
    vector <string> tokens;
     
    // stringstream class check1
    stringstream check1(command);
     
    string intermediate;
     
    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }
     
    // Printing the token vector
    for(int i = 0; i < tokens.size(); i++)
        cout << tokens[i] << '\n';
}
