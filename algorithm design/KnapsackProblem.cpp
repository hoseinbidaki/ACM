#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b) { return (a > b) ? a : b; } 
  
/*int knapSack(int W, int wt[], int val[], int n) 
{ 
  
    if (n == 0 || W == 0) 
        return 0; 
  
    if (wt[n - 1] > W) 
        return knapSack(W, wt, val, n - 1); 
    else
        return max( 
            val[n - 1] + knapSack(W - wt[n - 1],  wt, val, n - 1), knapSack(W, wt, val, n - 1)); 
} */
int knapSack(int W, int wt[], int val[], int n) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max( 
                    val[i - 1] + K[i - 1][w - wt[i - 1]], 
                    K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
    for (int i = 0 ; i <= n; i++) {
        for (int j = 0 ; j <= W; j++)cout <<  K[i][j] << " " << fixed << setw(2);
        cout << "\n";
    }
    return K[n][W]; 
} 
  
int main() 
{ 
    int val[] = {8, 5, 15, 10, 20}; 
    int wt[] = {16, 15, 25, 8, 15}; 
    int W = 40; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapSack(W, wt, val, n); 
    return 0; 
} 