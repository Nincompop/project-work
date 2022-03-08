#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    string str = "";

    for (int i = 1; i < argc; i++)
    {
        str += argv[i];
    }
    cout << str << endl;

    int freq[26] = {0}; // because we have 26 alphabets.

    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << char(i + 'a') << ", " << freq[i] << endl;
    }

    return 0;
}