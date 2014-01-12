//Prim algorithm
//2009/06/07-/06/10
#include <iostream>
#include <cmath>
using namespace std;

void Prim();

int main()
{
    Prim();

    return 0;
}
void Prim()
{
    int intMax = numeric_limits<int>::max();
    int N = 0;
    cout << "input the number of points: ";
    cin >> N;

    int coordinate[N+1][2];

    int distanceSquare = 0;
    int graph[N+1][N+1];

    int x = 0, y = 0;
    int delteX = 0, delteY = 0;

//build the graph ADT
    cout << "input the points' coordinate:" << endl;
    for (int i  = 1; i <= N; i++)
    {
        cin >> x >> y;
        coordinate[i][0] = x;
        coordinate[i][1] = y;
    }

    for (int j = 1; j <= N; j++)
    {
        for (int k = 1; k <= N; k++)
        {
            delteX = (coordinate[j][0] - coordinate[k][0]);
            delteY = (coordinate[j][1] - coordinate[k][1]);
            distanceSquare = delteX*delteX + delteY*delteY;
            graph[j][k] = distanceSquare;
        }
    }
/*
for (int j = 1; j <= N; j++)
{
    for (int k = 1; k <= N; k++)
    {
        cout << graph[j][k];
    }
    cout << '\n';
}
*/

//begin Prim algorithm
    int lowCost[N+1];
    int closestPoint[N+1];

    //initialize two array
    //choose point1 as the first point added to new zone
    for (int i = 2; i <= N; i++)
    {
        lowCost[i] = graph[1][i];
        closestPoint[i] = 1;
    }

    bool finish = false;
    int min = intMax;
    int position = 2;

    double nowDistance = 0;
    double totalDistance = 0;

    while (!finish)
    {
        min = intMax;
        for (int i = 2; i <= N; i++)
        {
            if (lowCost[i] < min)
            {
                min = lowCost[i];
                position = i;
            }
        }

        nowDistance = pow(lowCost[position], 0.5);
        totalDistance += nowDistance;
        cout << "\n" << position << " -> " << closestPoint[position];
        cout << "  distance: " << nowDistance << endl;

        lowCost[position] = intMax;//mark the lowCost with intMax to mean current point has been added to new zone
/*
for (int i = 2; i <= N; i++)
{
    cout << lowCost[i] << " ";
}
cout << endl;
*/

        //change the minist path from each point in origine zone to new zone when a point has been added to new zone
        for (int i = 2; i <= N; i++)
        {
            if (lowCost[i] != intMax && graph[i][position] < lowCost[i])
            //avoid comparing current point with itself and
            //avoid comparing current point with the points had been added to new zone earlier
            {
                lowCost[i] = graph[i][position];
                closestPoint[i] = position;
            }
        }
/*
for (int i = 2; i <= N; i++)
{
    cout << closestPoint[i] << " ";
}
cout << endl;
*/

        //check if all the points have been added to new zone
        //finish when from k = 2 to k = N, lowCost[k] are all been marked with intMax
        finish = true;
        for (int i = 2; i <= N; i++)
        {
            if (lowCost[i] != intMax)
            {
                finish = false;
                break;
            }
        }
    }
    cout << "\ntotal distance: " << totalDistance << endl;
}
