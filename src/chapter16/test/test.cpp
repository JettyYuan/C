// project.cpp
// Jetty

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool palindromic(string& s);

int main() {
    string st;
    cout << "Enter the string to test: ";
    getline(cin, st);
    cout << "String " << st << " is ";
    if (palindromic(st)) cout << "a palindromic string." << endl;
    else cout << "not a palindromic string." << endl;
    return 0;
}

bool palindromic(string& s) {
    auto phead = s.begin();
    auto ptail = s.end() - 1;
    while (ptail > phead) {
        if (!isalpha(*phead)) {
            phead++;
            continue;
        }
        if (!isalpha(*ptail)) {
            ptail--;
            continue;
        }
        if (toupper(*phead) == toupper(*ptail)) {
            phead++;
            ptail--;
        }
        else return false;
    }
    return true;
}