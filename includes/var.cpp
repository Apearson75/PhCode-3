#include <iostream>
#include <map>
#include <vector>
#include <regex>
#include "var.h"

using namespace std;

void varCMD(string line, map<string, string> variables)
{
    string svar = "var ";

    size_t pos = line.find(svar);
    string variable = line.erase(pos, svar.length());

    string name = variable.substr(0, variable.find(" "));
    string data = variable.substr(variable.find(" ") + 1);
    data = regex_replace(data, regex("\""), "");

    variables[name] = data;
}