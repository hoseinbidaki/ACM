#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream    inFile("Light.cpp");

    cout << "enter name of the new file : ";
    string s;
    cin >> s;
    s += ".cpp";
    ofstream    outFile(s.c_str());
    outFile << inFile.rdbuf();
} 