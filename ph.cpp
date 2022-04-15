#include <iostream>
#include <fstream>
#include "includes/send.cpp"

using namespace std;

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
                sendCMD(lineContent);
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