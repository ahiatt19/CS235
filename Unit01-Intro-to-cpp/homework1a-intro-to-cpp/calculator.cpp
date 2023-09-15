#include <iostream>
#include <string>

std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

int main(int argc, char const* argv[]) {
    double numeroUno, numeroDos;
    std::string opr = "nada"
    double answero;


    while (!opr.empty()) {
        cout << "Enter a arithmetic operation: " << endl;
        // cin >> opr;
        getline(cin, opr);


        if ((opr == '/') || (opr == "divide")) {
            cout << "Enter a primero number" << endl;
            cin >> numeroUno;
            cout << "Enter a segundo number" << endl;
            cin >> numeroDos;


            answero = numeroUno / numeroDos
            cout << "The sum is: " << answero << endl;
        }
        else {
            cout << "don't know what to do" << endl;
        }
    }


    return 0;
}

