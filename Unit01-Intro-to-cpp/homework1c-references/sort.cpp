#include <iostream>
#include <string>


using namespace std;
// void functions returns a certain variable type
// void doesn't return anything
// could say like "double" and it would return said double


void sort(std::string& a, std::string& b, std::string& c) {
    string s1;
    string s2;
    string s3;
    if ( a <= b && b <= c )
    {   s1 = a;
        s2 = b;
        s3 = c;
    }
    else if ( a  <= c && c <= b )
    {
        s1 = a;
        s2 = c;
        s3 = b;
    }
    else if ( b <= a  && a  <= c )
    {
        s1 = b;
        s2 = a;
        s3 = c;
    }
    else if ( b <= c && c <= a  )
    {
        s1 = b;
        s2 = c;
        s3 = a;
    }
    else if ( c <= a  && a  <= b )
    {
        s1 = c;
        s2 = a;
        s3 = b;
    }
    else if ( c <= b && b <= a  )
    {
        s1 = c;
        s2 = b;
        s3 = a;
    }
    a = s1;
    b = s2;
    c = s3;
}

int main(int argc, char const* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " a b c" << std::endl;
        return 1;
    }

    std::string a = argv[1];
    std::string b = argv[2];
    std::string c = argv[3];

    sort(a, b, c);

    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}
