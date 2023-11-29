#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char const* argv[]) {
    //if (argc == 1) {
    //    cout << "you only got one dummy" << endl;
    //}

    int num;
    string filename;
    num = 10;


    int i;
    for (i = 1; argv[i]; i += 1)
        if (argv[i][0] == '-') {
            num = atoi(argv[i]+1);
            }
        else {filename = argv[i];}

    if (filename.empty()) {
        int t;
        string input;
        string line;

        for (t = 1; t <= num; t += 1) {
            cin >> input;
            getline(cin, line);
            cout << input << endl;
        }
        return 0;
    }

    ifstream input(filename);
    if (!input) {
        cerr << "ERROR: can't open " << filename << endl;
    }

    // look at hw01b
    //open the file



    string line;
    int u;

    for (u = 1; u <= num; u += 1) {

        getline(input, line);
        istringstream ss(line);
        if (line.empty()) {return -1;}
        cout << line << endl;
    }
    //print stuff if the file open succesfully
    // .length()

    //catches errors if not passed in

    return 0;
}
