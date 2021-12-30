#include <bits/stdc++.h> 
using namespace std; 
  
#define V 6
#define INF 99999  
  
void printSolution(int dist[][V]);  
  
void floydWarshall (int graph[][V], int p[][V])  
{  
    int dist[V][V], i, j, k;  
  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
  
    for (k = 0; k < V; k++)  
    {  
        cout << "D : " << k << "\n";
        printSolution(dist);
        cout << "P : " << k << "\n";
        printSolution(p);
        cout << "*****************\n";
        for (i = 0; i < V; i++)  
        {   
            for (j = 0; j < V; j++)  
            {  

                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j], p[i][j] = k + 1;
            }  
        }  
    }  
    cout << "D : " << V << "\n";
    printSolution(dist);  
    cout << "P : " << V << "\n";
    printSolution(p);  
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
                        {INF,9, INF, 2, INF, INF},
                        {INF,INF, INF, INF, INF, 4},
                        {INF,2, INF, 4, INF, INF},
                        {INF,2, 3, INF, INF, INF},
                        {INF,11, 7, INF, INF, INF},
                        {INF,INF, INF, INF, 3, INF}
                    };  

    int p[V][V] = { 
        {0,1, 0, 1, 0, 0},
        {0,0, 0, 0, 0, 2},
        {0,3, 0, 3, 0, 0},
        {0,4, 4, 0, 0, 0},
        {0,5, 5, 0, 0, 0},
        {0,0, 0, 0, 6, 0}
                    };  
  

/*
    int graph[V][V] = { 
                        {0, 3, 8, INF, -4},
                        {INF, 0, INF, 1, 7},
                        {INF, 4, 0, INF, INF},
                        {2, INF, -5, 0, INF},
                        {INF, INF, INF, 6, 0},
                    };  

    int p[V][V] = { 
                        {0, 1, 1, 0, 1},
                        {0, 0, 0, 2, 2},
                        {0, 3, 0, 0, 0},
                        {4, 0, 4, 0, 0},
                        {0, 0, 0, 5, 0}
                    };  
*/
    floydWarshall(graph, p);  
    return 0;  
}  
