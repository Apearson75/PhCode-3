#include <iostream>
#include <regex>

using namespace std;

void inputCMD(string line)
{
    string sinput = "input ";

    string dummyData;
    size_t pos = line.find(sinput);
    string data = line.erase(pos, sinput.length());
    data = regex_replace(data, regex("\""), "");
    cout << data << endl;
    cin >> dummyData;
}