#include <iostream>
#include <string.h>
#include "var.h"
#include <regex>

using namespace std;

void sendCMD(string line, map<string, string> variables)
{
    string ssend = "send ";
    string quotes = "'";

    if (line.find(quotes) == string::npos)
    {
        size_t pos = line.find(ssend);
        string data = line.erase(pos, ssend.length());
        data = regex_replace(data, regex("\""), "");
        cout << data << endl;
    }
    else
    {
        size_t pos = line.find(ssend);
        string name = line.erase(pos, ssend.length());
        string data = variables[name];
        cout << data << endl;
    }
}