#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const* argv[]) {
    // Write your code here
    string input = argv[1];
    ifstream ifp(input);

    string line;

    string LongLine = "";
    int highest_num = 0;

    while (!ifp.eof()) {
        getline(ifp, line);
        istringstream ss(line);
        string oneWord;
        //ss >> oneWord;
        int counter = 0;
        while(ss >> oneWord) {
            counter += 1;
            //ss >> oneWord;
        }
        if (counter > highest_num) {
            LongLine = line;
            highest_num = counter;
        }

    }

    cout << LongLine << endl;
    return 0;
}
