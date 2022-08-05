#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    string message;
    string pass; //encryption key

    vector <int> key; //encryption key converted to int
    vector <vector <char>> vec;

    cin >> message;
    cin.ignore(100, '\n');
    getline(cin, pass);
    
    //change pass to key

    char ch;
    string num = "0"; 
    int ii = 0;

    while (ii < pass.length())
    {
        ch = pass[ii];

        while (ii < pass.length() && ch != ' ')
        {
            num += ch;
            ii++;
            ch = pass[ii];
        }
        ii++;
        key.push_back(stoi(num)-1);

        num = "0";
    }
    
    //-----------------

    vec.resize(key.size());

    for (int i = 0; i < key.size(); i++)
    {
        vec[i].resize(floor(message.length() / key.size()));
    }
    
    for (int i = 0; i < message.length() % key.size(); i++)
    {
        vec[i].resize(floor(message.length() / key.size())+1);
    }

    //record

    int ch_num = 0;

    for (int i = 0; i < key.size(); i++)
    {
        ii = key[i];
        for (int iii = 0; iii < vec[ii].size(); iii++)
        {
            vec[ii][iii] = message[ch_num];
            ch_num++;
        }
    }

    //reading
    
    for (int i = 0; i < floor(message.length() / key.size()); i++)
    {
        for (ii = 0; ii < key.size(); ii++)
        {
            cout << vec[ii][i];
        }
    }


    for (int i = 0; i < message.length() % key.size(); i++)
    {
        cout << vec[i][message.length()/key.size()];
    }
}