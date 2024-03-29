/*
#include<bits/stdc++.h> 
using namespace std; 
  
int MatrixChainOrder(int p[], int i, int j) 
{ 
    if(i == j) 
        return 0; 
    int k; 
    int min = INT_MAX; 
    int count; 
  
    for (k = i; k < j; k++) 
    { 
        count = MatrixChainOrder(p, i, k) + 
                MatrixChainOrder(p, k + 1, j) + 
                p[i - 1] * p[k] * p[j]; 
  
        if (count < min) 
            min = count; 
    } 
  
    return min; 
} 

int main() 
{ 
    int arr[] = {1, 2, 3, 4, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, n - 1); 
} */
//With DP Array
#include<bits/stdc++.h> 
using namespace std; 

int MatrixChainOrder(int p[], int n) 
{ 
    int m[n][n]; 
    int i, j, k, L, q; 
   
    for (i = 0; i < n; i++) for (int j = 0; j < n; j++)
        m[i][j] = 0; 

    for (L = 2; L < n; L++) 
    { 
        for (i = 1; i < n - L + 1; i++) 
        { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) 
            { 

                q = m[i][k] + m[k + 1][j] +  
                    p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
    for (int  i = 1 ; i < n; i++) {
        for (int j = 1 ; j < n; j++)cout << m[i][j] << " " << fixed << setw(4) ;
        cout << "\n";
    }
    return m[1][n - 1]; 
} 
  
int main() 
{ 
    int arr[] = {100, 200, 50, 70, 1}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    
    cout << "\n";
    cout << "The minimum multiplacation is : \n" << MatrixChainOrder(arr, size); 
  
} 