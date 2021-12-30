#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    string name;
    
    cout << "enter name of the new file : ";
    cin >> name;
    
    name = name + ".cpp";

    ifstream inFile("Solver.cpp");
    ofstream outFile(name.c_str());
    outFile << inFile.rdbuf();


}

