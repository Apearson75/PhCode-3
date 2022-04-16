#include <iostream>
#include <fstream>
#include <map>
#include "../includes/send.cpp"
#include "../includes/var.cpp"
#include "../includes/input.cpp"
#include "../includes/var.h"

using namespace std;

map<string, string> variables;

int main()
{
    string file;
    cout << "Enter the name of the file: ";
    cin >> file;

    ifstream myReadFile;
    myReadFile.open(file);
    string lineContent;

    if (myReadFile.is_open() && file.find(".ph") != string::npos)
    {
        while (getline(myReadFile, lineContent))
        {
            if (lineContent.find("send") != string::npos)
            {
                sendCMD(lineContent, variables);
            }
            else if (lineContent.find("var") != string::npos)
            {
                varCMD(lineContent, variables);
            }
            else if (lineContent.find("input") != string::npos)
            {
                inputCMD(lineContent);
            }
        }
    }
    else
    {
        cout << "File not found or not supported";
    }
    myReadFile.close();
    return 0;
}