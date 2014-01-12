#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    int num = 0;
    int bit = 0;
    string aLine = "";

    cin >> num >> bit;
    char* rStr = (char*)malloc(bit*sizeof(char));
    memset(rStr, '\0', bit*sizeof(char));

    //char rStr[bit] = {'0'};
    while (num != 0 || bit != 0)
    {
        itoa(num,rStr, 2);

            if (num == 0)
            {
                for (int j = 0; j <= bit-1; j++)
                {
                    cout << "---" << endl;
                }

            }
            else
            {


                for (int i =0; i <= bit-1; i++)
                {
                        if (rStr[i] == '0')
                        {
                            cout << "---"<< endl;
                        }
                        else if (rStr[i] == '1')
                        {
                            cout <<"- -" << endl;
                        }

                }
            }
        cout << endl;

        cin >> num >> bit;
    }


    return 0;
}
