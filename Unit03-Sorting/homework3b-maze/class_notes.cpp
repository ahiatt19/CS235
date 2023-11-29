#include <iostream>
#include <map>

using namespace std;

map<int, int> lookUpTable;

int sum(int n) {
    double s = 0.0;
    for (int i = 1; i <= n; i++) {
        s += 1;
    }
    return s;
}

//recursive call now
int sumRec(int n) {

    //the couts in this function now kind of show when the function hits their call
    cout << "sumRec(" << n << ")" << endl;
    // base case
    // :step one is have a good base case
    if (n <= 0) {
        cout << "return when 0" << endl;
        return 0;
    }
    // recursive step
    // :step two is have a recursive step that is correct and works towards the base case
    int answer = n + sumRec(n-1);
    cout << "this is the answer" << answer << endl;

    return answer;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);



    //cout << "sum " << n << " = " << sumRec(n) << endl;
    //cout << "sum " << n << " = " << sum(n) << endl;

    return 0;
}

