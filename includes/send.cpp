#include <iostream>
#include <string.h>
#include <regex>

using namespace std;

void sendCMD(string line)
{
    string ssend = "send ";
    string quotes = "'";

    size_t pos = line.find(ssend);
    string data = line.erase(pos, ssend.length());
    data = regex_replace(data, regex("\""), "");
    cout << data << endl;
}