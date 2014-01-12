//Prim algorithm
//2009/06/07-/06/10
#include <iostream>
#include <cstdlib>
#include <stack>
#include <iterator>

using namespace std;

class OP
{
public:
    OP()
    {
        data = '\0';
        pri = 0;
    }
    OP(char pD, int pP)
    {
        data = pD;
        pri = pP;
    }

  char data;
  int pri;
};



int main()
{
    for (string::size_type i = 0; i <= str.length()-1; i++)
    {
        if(str[i] >= '0' && str[i]<= '9')
        {
            result += str[i];
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] =='/')
        {
            if(str[i] == '+' || str[i] == '-' )
            {
                pri = 1;
            }
            else
            {
                pri = 2;
            }

            OP* op = new OP(str[i], pri);
            if (pri >(s.top().pri))
            {
                s.push(*op);
            }
            else
            {
                while (pri <= (s.top().pri))
                {
                    result+=s.top().data;
                    s.pop();
                }

                s.push(*op);
            }
        }
        else if (str[i] == '(')
        {
            OP* op = new OP(str[i], 0);
            s.push(*op);

        }
        else if (str[i] == ')')
        {
            while (s.top().data != '(')
            {
                result += s.top().data;
                s.pop();

            }
            s.pop(); //'('
        }
        else if (str[i] == ' ')
		{

		}
		else
		{}
    }
    while (s.top().data != '\0')
    {
        result += s.top().data;
		s.pop();
    }
	cout << result.c_str();
    return 0;
}

