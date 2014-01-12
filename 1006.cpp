#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

static int array[1000001] = {0};
static int endx = 0;

int main()
{
    int line = 0;
    int k = 0;

    cin >> line >> k;

    while (line != 0 && k !=0)
    {
        int num = 0;
        string str = "";
        getline(cin, str);

        for (int i = 0; i<=line-1; i++)
        {
            getline(cin, str);
            if (str.at(0) == 'I')
            {
                endx++;
                num = atoi(str.substr(2).c_str());


                for (int j = 0; j<= endx-1; j++)
                    {
                        if (num < array[j])
                        {
                            continue;
                        }
                        else if (num > array[j])
                        {
                            for (int k = endx-1; k>= j; k--)
                            {
                                array[k+1] = array[k];
                            }

                            array[j] = num;
                            break;
                        }
                        else{}


                    }
            }
            else if (str.at(0) == 'Q')
            {
                cout << array[k-1] << endl;

            }
        }
        cin >> line >> k;
    }
    return 0;
}
