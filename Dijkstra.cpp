#include<cstdio>
#include <iostream>
using namespace std;

const int P = 7;
const int maxint=1000;

void Dijkstra(int n, int v,int dist[], int prev[], int c[P][P])    //nΪ��������vΪ��ʼ�㣬dist����洢ѡ��ıߵ�Ȩ��prev[i]����i��ǰһ���㣬cΪ����ͼ����
 {
    bool s[100];
    for (int i=1;i<=n; i++)
    {
       dist[i]=c[v][i];
       s[i]=false;
       if(dist[i]==maxint)
       {
           prev[i]=0;
       }
       else
       {
           prev[i]=v ;
       }
    }
    dist[v]=0;
    s[v]=true;
    for (int i=1;i<n;i++)
    {
       int temp=maxint;
       int u= v;
       for (int j = 2;j<=n;j++)

          if ((!s[j])&&(dist[j]<temp))
          {s[v]=true;
             u=j;
             temp=dist[j];
          }
          s[u]=true;

     for (int j=2;j<=n;j++)

     if((!s[j])&&(c[u][j]<maxint))
     {
         int newdist=dist[u]+c[u][j];
         if (newdist<dist[j])
         {
           dist[j]=newdist;
           prev[j]=u;
         }
     }
    }
     /*�����ԭ�㵽��������֮������·������*/
    cout<<"�����ԭ�㵽��������֮������·������"<<endl;
    for(int j=2;j<=P-1;j++)
    {
        cout<<"dist["<<j<<"]"<<":"<<dist[j]<<endl;
    }
    /*�����ѡ�ı�*/
    cout<<"�����ѡ�ı�"<<endl;
    for(int t=2;t<=P-1;t++)
    {
        cout<<prev[t]<<"->"<<t<<endl;
    }
}

int main()
{
    /*��ʼ������ͼ*/
    int c[P][P];
    int i,j;
    //int maxint=1000;
    for(int i = 0 ;i <= P - 1; i++)
    {
        for(j = 0; j<=P-1;j++    )
        {
            c[i][j]=maxint;
        }
    }

    c[1][2]=3;
    c[1][3]=2;
    c[1][5]=2;
    c[2][3]=5;
    c[2][4]=5;
    c[2][5]=3;
    c[2][6]=1;
    c[3][5] = 1;
    c[4][6] = 2;
    c[5][6] = 1;

    for (int j = 1; j <= P-1; j++)
    {
        for (int k = 1; k <= j; k++)
        {
            c[j][k] = c[k][j];
        }
    }

    cout<<"����ͼ�������£���������֮���������"<<endl;
    for(i=1;i<=6;i++)
    {
        for(j=1;j<=6;j++    )
        {
            cout<<c[i][j]<<"  ";
        }
        cout<<endl;
    }
    int dist[P];
    int prev[P];
    int n=P-1;
    int v=3;
    Dijkstra(n,v,dist,prev,c);
    return 0;
}
