#include <iostream>
#include <random>
#include <string>

using namespace std;

void generate(string date) {
    int range = 1000 - 0 + 1;
    for (int i = 0; i < 24; i++)
    {
        if (i < 10)
        {
            cout << date << "," << "0" << i << "," << rand() % range + 0 << "," << rand() % range + 0 << endl;
        }
        else
        {
            cout << date << "," << i << "," << rand() % range + 0 << "," << rand() % range + 0 << endl;
        }
    }
}

int main()
{   
    string date = "01/09/2022";
    generate(date);
    date = "02/09/2022";
    generate(date);
    date = "03/09/2022";
    generate(date);
    date = "04/09/2022";
    generate(date);
    date = "05/09/2022";
    generate(date);
    date = "06/09/2022";
    generate(date);
    date = "07/09/2022";
    generate(date);
    date = "08/09/2022";
    generate(date);
    date = "09/09/2022";
    generate(date);
    date = "10/09/2022";
    generate(date);
     date = "11/09/2022";
    generate(date);
     date = "13/09/2022";
    generate(date);
     date = "13/09/2022";
    generate(date);
     date = "14/09/2022";
    generate(date);
     date = "15/09/2022";
    generate(date);
     date = "16/09/2022";
    generate(date);
     date = "17/09/2022";
    generate(date);
     date = "18/09/2022";
    generate(date);
     date = "19/09/2022";
    generate(date);
     date = "20/09/2022";
    generate(date);
    date = "21/09/2022";
    generate(date);
    date = "22/09/2022";
    generate(date);
    date = "23/09/2022";
    generate(date);
    date = "24/09/2022";
    generate(date);
    date = "25/09/2022";
    generate(date);
    date = "26/09/2022";
    generate(date);
    date = "27/09/2022";
    generate(date);
    date = "28/09/2022";
    generate(date);
    date = "29/09/2022";
    generate(date);
    date = "30/09/2022";
    generate(date);
}