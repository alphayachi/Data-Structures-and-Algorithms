#include <bits/stdc++.h>
using namespace std;

void printSub(string s, string out)
{
    if (s.empty())
    {
        cout << out << endl;
        return;
    }
    //include the character
    printSub(s.substr(1), out + s[0]);

    //don't include the character
    printSub(s.substr(1), out);
}

int main()
{
    string output = "";
    string input = "abcd";

    printSub(input, output);

    return 0;
}