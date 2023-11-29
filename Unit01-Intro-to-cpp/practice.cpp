
Page
1
of 2
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <time.h>
using namespace std;
// ./a.out [listtype={vector,linkedlist}] [location={start,end}] [listSize]
int main(int argc, char *argv[]) {
    if (argc < 4) {
        cout << "Not enough parameters." << endl;
        return 0;
    }
    string listtype = argv[1];
    string location = argv[2];
    const int numItems = atoi(argv[3]);

    long start;
    long end;
    int num;

    vector<int> aVector; // this contains only integers
    list<int> aList; // this contains only integers

    start = clock();

    srand(time(NULL));

    for (int i = 0; i < numItems; i++) {
        num = rand() % 100; // randomly generate a number to put into the list
        if (listtype == "vector") { // this code executes if we are inserting into a vector (array)
            if (location == "start")
                aVector.insert(aVector.begin(), num);
            else if (location == "end")
                aVector.push_back(num);
            else {
                cout << "location not found" << endl;
                exit(1); // sys.exit
            }
        }
        else if (listtype == "linkedlist") { // this code executes if we are inserting into a linked list
            if (location == "start")
                aList.insert(aList.begin(), num);
            else if (location == "end")
                aList.push_back(num);
            else {
                cout << "location not found" << endl;
                exit(1);
            }
        }
        else {
            cout << "listtype not found" << endl;
            exit(1);
        }
    }
    end = clock();
    cout << "clock cycles (" << listtype << "): " << (end - start) << endl <<
         endl;
}
