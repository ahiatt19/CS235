#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <map>

#include "input.h"


using namespace std;

int main(int argc, char const* argv[]) {
    // Write your code here
    // add(x) ".push(x)" -- push to the back of queue
    // remove() ".pop()" -- erase the front item from the queue
    // front() ".top()"-- returns the object at the front of the queue
    // empty()
    priority_queue<string> Q;
    string opr;

    while (input("What do you want to do? ", opr)) {
        string p;
        string name;


        if (opr == "add") {
            input("Name: ", name);
            input("Priority: ", p);
            if (stoi(p) < 10) {
                p = "0" + p;
            }
            string tmp = p + " - " + name;
            if (opr == "add") {
                Q.push(tmp);
            }
        }
        else if (opr == "take") {
            if (Q.empty()) {
                cout << "There are no more people in line" << endl;
            }
            else {
                string t_n = Q.top();
                cout << t_n << endl;
                Q.pop();
                }
            }
        else if (opr.empty()) {break;}
        else {cout << opr << " isn't a valid operation" << endl;}
    }
    return 0;
}
//automatically will prioritize from z-->a and higher num-->lower num