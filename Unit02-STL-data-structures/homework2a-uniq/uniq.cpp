#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char const* argv[]) {
    vector<string> t;
    set<string> unq_vals;

    if (argc > 1) {
        string filename = argv[1];
        ifstream ifp(filename);

        if (!ifp) {
            cout << "ERROR: can't open " << filename << endl;
            return 1;
        }


        string line;

        while (ifp >> line) {
            //getline(ifp, line);
            //istringstream ss(line);
            //cout << line << endl;
            t.push_back(line);
            unq_vals.insert(line);

        }}

    else {
        string value;
        while (cin >> value) {
            t.push_back(value);
            unq_vals.insert(value);
        }
    }

    for (const string& val : t) {
        if (unq_vals.count(val) == 1) {
            cout << val << endl;
            unq_vals.erase(val);
        }
    }

 //this isn't printing anything out dummy
    return 0;
}
//USE VECTOR AND CHECK FOR DUPES !!!!