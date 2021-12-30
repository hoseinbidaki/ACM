#include <bits/stdc++.h> 
using namespace std; 
  
#define V 4  
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
        cout << "For D : " << k << "\n";
        printSolution(dist);
        cout << "*****************\n";
        for (i = 0; i < V; i++)  
        {   
            for (j = 0; j < V; j++)  
            {  

                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
    cout << "For D : " << V << "\n";
    printSolution(dist);  
}  
  
void printSolution(int dist[][V])  
{  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout << "INF " << fixed << setw(1);  
            else
                cout << dist[i][j] << " " << fixed << setw(1);  
        }  
        cout<<endl;  
    }  
}  
   
int main()  
{  
    int graph[V][V] = { {0, 5, INF, INF},  
                        {50, 0, 15, 5},  
                        {30, INF, 0, 5},  
                        {15, INF, 15, 0}  
                    };  
  
    floydWarshall(graph);  
    return 0;  
}  