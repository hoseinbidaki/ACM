#include <bits/stdc++.h> 
using namespace std; 
  
#define V 6
#define INF 99999  
  
void printSolution(int dist[][V]);  
  
void floydWarshall (int graph[][V])  
{  
    int dist[V][V], i, j, k;  
  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
  
    for (k = 0; k < V; k++)  
    {  
        cout << "R : " << k << "\n";
        printSolution(dist);
        cout << "*****************\n";
        for (i = 0; i < V; i++)  
        {   
            for (j = 0; j < V; j++)  
            {  
                if (dist[i][k] && dist[k][j])  
                    dist[i][j] = 1;
            }  
        }  
    }  
    cout << "R : " << V << "\n";
    printSolution(dist);  
}  
  
void printSolution(int dist[][V])  
{  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout << static_cast<unsigned char>(236) << "    "  << fixed << setw(1);  
            else
                {
                    if (dist[i][j] < 10)
                    cout << dist[i][j] << "    " << fixed << setw(1);  
                    else 
                    cout << dist[i][j] << "   " << fixed << setw(1);  
                }
        }  
        cout<<endl;  
    }  
}  
   
   
int main()  
{  
    int graph[V][V] = { 
                        {0,1, 0, 1, 0, 0},
                        {0,0, 0, 0, 0, 1},
                        {0,1, 0, 1, 0, 0},
                        {0,0, 1, 0, 0, 0},
                        {0,1, 1, 0, 0, 0},
                        {0,0, 0, 0, 1, 0}
                    };  
  
    floydWarshall(graph);  
    return 0;  
}  