#include <iostream>
#include <string>

using namespace std;

int function() {
    string operation;
    string repeat;
    double number1, number2;


    cout << "Enter first number: ";
    cin >> number1;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    cout << "Enter second number: ";
    cin >> number2;

    if (operation == "+") {
        cout << number1 + number2;
    } else if (operation == "-") {
        cout << number1 - number2;
    }
    else if (operation == "*") {
        cout << number1 * number2;
    }
    else if (operation == "/") {
        cout << number1 / number2;
    }
    else {
        cout << "not a recognized operation";
    }

    cout << "\nWould you like to use the calculator again(y/n)?:";
    cin >> repeat;
     if (repeat == "y") {
        function();
     }
    else if (repeat == "n") {
          cout << "Confirmed. Calculator program has ended...";
    }
    else {
        cout << "Response is not recognized. Please try again.\n";
        
    }



  
  return 0;
}





int main()
{
 
string access;
cout << "Would you like to use the calculator (y/n)?: ";
cin >> access;

if (access == "y")
{
function();
}

else if (access == "n")
{
    cout << "Confirmed. Calculator program has ended...";
}

else {
    cout << "Response is not recognized. Please try again.\n";
    main(); 
}


}
