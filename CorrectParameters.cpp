#include <iostream>
#include <string>
using namespace std;


bool Acceptingstateedvalues(char c) {
    return (c >= 'a' && c <= 'z') || c == ' ' || c == '(' || c == ')' || c == '[' || c == ']'; 
}

bool matching(const string& s) {
    const int maximum = 1000;
    char stack[maximum];
    int top = -1;

    for (char c : s) {
        if(!Acceptingstateedvalues(c)) return false;

        if ( c == '(' || c == '['){
            if (top +1 >= maximum)
            stack[++top] = c;
        } 
        
        else if (c == ')') {
            if (top < 0 || stack[top] != '(') return false;
            top--;
        } 
        
        else if (c == ']') {
            if (top < 0 || stack[top] != '[') return false;
            top--;
        }
        return top == -1; //this makes it so that if matching () or [] is not there, it will be rejected

    }
}

int main () {
    cout << "parameters: (a-z, space, (), [])";
    cout << "Following these parameters, type out a string: ";

    string input;
    getline(cin, input);//just to add spaces to possible sentences

    cout << (matching(input) ? "Condition's Acceptingstateed" : "conditions denied\n"); //used to confirm if conditions are met or not

    return 0;

}
