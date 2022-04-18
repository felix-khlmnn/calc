#include <iostream>

using namespace std;

//colors
string GREEN = "\u001b[32m";
string RESET = "\u001b[0m";

char ops[] = {'+', '-', '*', '/'};

int checkOperatorIndex(string operation, int startIndex) {
    for (int i = 0; i < 4; i++)
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
    cout << "CL Calc\nBy Felix K." << endl;
    while (true)
    {
        string operation;

        getline(cin, operation);

        int operatorIndex = checkOperatorIndex(operation, 0); //checks for the operator in the operation
        if(checkOperatorIndex(operation, operatorIndex + 1) != -1) {
            cout << "Invalid operation: Can only contain one operator." << endl;
            continue;
        }
        // Debug cout << operation[operatorIndex + 1] << endl << checkOperatorIndex(operation, operatorIndex + 1) << endl;

        
        double firstNumber = stod(operation.substr(0, operatorIndex));
        double secondNumber = stod(operation.substr(operatorIndex + 1));
        /*cout << firstNumber << endl;
        cout << secondNumber << endl;
        cout << operatorIndex << endl; Debug*/
        cout << GREEN;
        switch (operation[operatorIndex])
        {
        case '+':
            cout << firstNumber + secondNumber << endl;
            break;
        case '-':
            cout << firstNumber - secondNumber << endl;
            break;
        case '*':
            cout << firstNumber * secondNumber << endl;
            break;
        case '/':
            cout << firstNumber / secondNumber << endl;
            break;
        default:
            break;
        }
        cout << RESET;
    }
    
    
    return 0;
}