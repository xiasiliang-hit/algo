#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    int num = 0;

    string aLine = "";

    cin >> num;
    do
    {
        int result = 0;

getline(cin, aLine);
        for (int i = 1; i<= num; i++)
        {

            getline(cin, aLine);

            if (aLine == "---")
            {
            }
            else if (aLine == "- -")
            {
                result += (int)pow(2.0, (double)num - i);
            }


        }
        cout << result << endl;

    } while (cin >> num);


    return 0;
}
