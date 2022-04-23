#include <iostream>
#include <cmath>

using namespace std;

//Windows CMD can't use colors through escape sequences

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

    cout << "CL Calc" << endl;
    if (argc > 1) {
        if (string(argv[1]) == "--help" || string(argv[1]) == "-h") //Checking if the user wants help
        {
            cout << "Calculator for the command line.\nUsage: Write operation and confirm them by pressing enter.\nThe result will be displayed underneath.\nAvailable operators:\t+, -, *, /, % and ^" << endl;
        }
    } else {    
        while (true)
        {
            string operation;

            getline(cin, operation);

            int operatorIndex = checkOperatorIndex(operation, 0); //checks for the operator in the operation
            if(checkOperatorIndex(operation, operatorIndex + 1) != -1) {
                cout <<  "Invalid operation: Can only contain one operator." << endl;
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
                cout << "Syntax error: No operator given." << endl;
                savedResult = 0;
                break;
            }
        }
    }
    return 0;
}