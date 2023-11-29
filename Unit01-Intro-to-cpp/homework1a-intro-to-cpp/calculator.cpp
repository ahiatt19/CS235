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
    string opr = "nada";
    double answer;

    while (!opr.empty()) {
        string opr;
        opr = input("operation: ");

        if (opr == "divide") {
            int num1;
            int num2;
            num1 = stoi(input("left operand: "));
            num2 = stoi(input("right operand: "));
            answer = num1 / num2;
            cout << answer << endl;}

        else if (opr == "multiply") {
            int num1;
            int num2;
            num1 = stoi(input("left operand: "));
            num2 = stoi(input("right operand: "));
            answer = num1 * num2;
            cout << answer << endl;}

        else if (opr == "add") {
            int num1;
            int num2;
            num1 = stoi(input("left operand: "));
            num2 = stoi(input("right operand: "));
            answer = num1 + num2;
            cout << answer << endl;}

        else if (opr == "subtract") {
            int num1;
            int num2;
            num1 = stoi(input("left operand: "));
            num2 = stoi(input("right operand: "));
            answer = num1 - num2;
            cout << answer << endl;}

        else if (opr == "mod") {
            int num1;
            int num2;
            num1 = stoi(input("left operand: "));
            num2 = stoi(input("right operand: "));
            answer = int(num1) % int(num2);
            cout << answer << endl;}
        else if (opr.empty()) {break;}
        else {cout << opr << " isn't a valid operation" << endl;}
    }
    return 0;
}