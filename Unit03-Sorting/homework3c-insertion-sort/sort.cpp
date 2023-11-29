#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
#include <array>

using namespace std;

int main(int argc, char const* argv[]) {
    string line;

    vector<string> arr;
    if (argc > 1) {
        string filename = argv[1];
        ifstream ifp(filename);
        while (ifp >> line) {
            arr.push_back(line);
        }
    }

    else {
        string value;
        while (cin >> value) {
                arr.push_back(value);
            }
    }

    //for (int i = 0; i < arr.size(); i++)
        //cout << arr[i] << ' ';
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j -1;
        }
        arr[j + 1] = key;
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
