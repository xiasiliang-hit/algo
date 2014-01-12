#include <iostream>
#include <fstream>

const int m = 64;
using namespace std;

int main()
{
    string aLine = "";
    while (getline(cin, aLine))
    {
        int count = 0;
            for (int i = 0; i <= aLine.length()-1; i++)
            {
                char now = aLine.at(i);
                if(isupper(now))
                   {
                      count = count + now - m;
                   }

            }
            if(count <= 100)
            {
                cout << count << endl;
            }
            else
            {
                cout << "INVALID" << endl;
            }


    }

    return 0;
}
