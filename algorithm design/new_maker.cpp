#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    string name;
    string add;
    int type;

    cout << "enter name of the new file : ";
    cin >> name >> type;
    
    name = name + ".cpp";

    if (type == 1) {
        add = "solver/Solver.cpp";
    } else {
        add = "solver/Light.cpp";
    }

    ifstream inFile(add.c_str());
    ofstream outFile(name.c_str());
    outFile << inFile.rdbuf();


}

