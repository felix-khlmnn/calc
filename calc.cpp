#include <iostream>
#include <cmath>

using namespace std;

//colors
string RED = "\u001b[31m";
string GREEN = "\u001b[32m";
string RESET = "\u001b[0m";

//text decorations
string BOLD = "\u001b[1m";

char ops[] = {'+', '-', '*', '/', '%', '^'};

int checkOperatorIndex(string operation, int startIndex) {
    for (int i = 0; i < 6; i++)
        {
            int temporaryIndex = operation.find(ops[i], startIndex);
            if (temporaryIndex != -1) {
                return temporaryIndex;
            }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    double savedResult; //Each result gets stored so it can be used with "ans"

    cout << BOLD + RED << "CL Calc" << RESET << endl;
    if (argc > 1) {
        if (string(argv[1]) == "--help" || string(argv[1]) == "-h") //Checking if the user wants help
        {
            cout << "Calculator for the command line.\nUsage: Write operation and confirm them by pressing enter.\nThe result will be displayed underneath.\nAvailable operators:" << GREEN << "\t+, -, *, /, % and ^" << RESET << endl;
        } 
    } else {    
        while (true)
        {
            string operation;

            getline(cin, operation);

            int operatorIndex = checkOperatorIndex(operation, 0); //checks for the operator in the operation
            if(checkOperatorIndex(operation, operatorIndex + 1) != -1) {
                cout << RED << "Invalid operation: Can only contain one operator." << RESET << endl;
                continue;
            }
            // Debug cout << operation[operatorIndex + 1] << endl << checkOperatorIndex(operation, operatorIndex + 1) << endl;
            double firstNumber;
            double secondNumber;
            if (operation.substr(0, operatorIndex) == "ans") {
                firstNumber = savedResult;
            } else {
                firstNumber = stod(operation.substr(0, operatorIndex));
            }
            if (operation.substr(operatorIndex + 1) == "ans") {
                secondNumber = savedResult;
            } else {
                secondNumber = stod(operation.substr(operatorIndex + 1));
            }
            /*cout << firstNumber << endl;
            cout << secondNumber << endl;
            cout << operatorIndex << endl; Debug*/
            cout << GREEN;
            switch (operation[operatorIndex]) //operation processor with save
            {
            case '+':
                cout << firstNumber + secondNumber << endl;
                savedResult = firstNumber + secondNumber;
                break;
            case '-':
                cout << firstNumber - secondNumber << endl;
                savedResult = firstNumber - secondNumber;
                break;
            case '*':
                cout << firstNumber * secondNumber << endl;
                savedResult = firstNumber * secondNumber;
                break;
            case '/':
                cout << firstNumber / secondNumber << endl;
                savedResult = firstNumber / secondNumber;
                break;
            case '%':
                cout << int(firstNumber) % int(secondNumber) << endl;
                savedResult = int(firstNumber) % int(secondNumber);
                break;
            case '^':
                cout << pow(firstNumber, secondNumber) << endl;
                savedResult = pow(firstNumber, secondNumber);
                break;
            default:
                cout << RED << "Syntax error: No operator given." << endl;
                savedResult = 0;
                break;
            }
            cout << RESET;
        }
        
    }
    return 0;
}