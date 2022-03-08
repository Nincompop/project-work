#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    ifstream f1;
    f1.open("Question_14_input.txt");

    ofstream f2;
    f2.open("Question_14_output.txt");
    while (f1.good())
    {
        getline(f1, str);
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ')
                continue;

            f2 << str[i];
        }
        f2 << endl;
        str.clear();
    }
    return 0;
}