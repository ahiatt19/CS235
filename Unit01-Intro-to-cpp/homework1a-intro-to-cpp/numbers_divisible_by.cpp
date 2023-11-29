#include <iostream>
#include <string>

using namespace std;


std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

int main(int argc, char const* argv[]) {

    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int div = atoi(argv[3]);

    if (start <= end) {
    while (start <= end) {
        if (start % div == 0) {
            cout << start << "\n";
            start += 1;
        }
        else {
            start += 1;
        }
    }}

    else {
    while (start >= end) {
        if (start % div == 0) {
            cout << start << "\n";
            start -= 1;
        }
        else {
            start -= 1;
        }
    }}

    return 0;
}
