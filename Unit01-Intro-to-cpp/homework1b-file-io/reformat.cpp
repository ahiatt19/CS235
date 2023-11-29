#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// int argc " number of arguments"
// argv[] passed in arguments

// for loops are seperated by semi colons
    // sets value, if condition, then how to iterate through

int main(int argc, char const* argv[]) {
    string input = argv[1];
    string output = argv[2];
    // fp = open(input, 'r')
    ifstream ifp(input);
    ofstream ofp(output);
    if (!ifp) {
        cout << "file not found: " << input << endl;
        return -1;
    }
    string line, fname, lname;
    int points;
    double factor;
    while (!ifp.eof()) {
        getline(ifp, line);
        istringstream ss(line);
        ss >> fname;
        ss >> lname;
        ss >> points;
        ss >> factor;
        ofp << lname << ", " << fname << ": " << (points * factor) << endl;
        //if (ifp.eof()) {break;}

    }
    ofp.close();
    return 0;
}

//cout << "argc = " << argc << endl;
//for (i = 0; i < argc; i++) {
//    cout << argv[i] << endl;
//}