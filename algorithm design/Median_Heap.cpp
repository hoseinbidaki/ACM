#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll minHeap[100010], maxHeap[100010];
int p1 = 0, p2 = 0;

void heapyfiMin() {
    int i = p1 - 1;
    int par = (i-1)/2;
    while (par >= 0) {
        if (minHeap[i] < minHeap[par]) {
            swap(minHeap[i] , minHeap[par]);
        }
        else {
            break;
        }
        i = par;
        par = (i-1)/2;
    }
}

void heapyfiMax() {
    int i = p2 - 1;
    int par = (i-1)/2;
    while (par >= 0) {
        if (maxHeap[i] > maxHeap[par]) {
            swap(maxHeap[i] , maxHeap[par]);
        }
        else {
            break;
        }
        i = par;
        par = (i-1)/2;
    }   
}


void heapyfiMin_top(int s) {
    int left;
    int right;
    while (s < p1) {
        //cout << "s : " << s << " "; 
        left = s*2+1;
        right = s*2+2;
        if (left >= p1 && right < p1) {
            if (minHeap[s] > minHeap[right]) {
                swap(minHeap[s] , minHeap[right]);
                s = right;
            }
            else break;
        }
        else if (left < p1 && right >= p1) {
            if (minHeap[s] > minHeap[left]) {
                swap(minHeap[s] , minHeap[left]);
                s = left;
            }
            else break;
        }
        else if (left < p1 && right < p1) {
            if (minHeap[left] <= minHeap[right]) {
                if (minHeap[s] > minHeap[left]) {
                    swap(minHeap[s] , minHeap[left]);
                    s = left;
                }
                else if (minHeap[s] > minHeap[right]) {
                    swap(minHeap[s] , minHeap[right]);
                    s = right;    
                }
                else {
                    break;
                } 
            }
            else {
                if (minHeap[s] > minHeap[right]) {
                    swap(minHeap[s] , minHeap[right]);
                    s = right;    
                }
                else if (minHeap[s] > minHeap[left]) {
                    swap(minHeap[s] , minHeap[left]);
                    s = left;
                }
                else {
                    break;
                }
            }
        }
        else  {
            break;
        }
    } 
}

void heapyfiMax_top(int s) {
    int left;
    int right;
    while (s < p2) {
        left = s*2+1;
        right = s*2+2;
        if (left >= p2 && right < p2) {
            if (maxHeap[s] < maxHeap[right]) {
                swap(maxHeap[s] , maxHeap[right]);
                s = right;
            }
            else break;
        }
        else if (left < p2 && right >= p2) {
            if (maxHeap[s] < maxHeap[left]) {
                swap(maxHeap[s] , maxHeap[left]);
                s = left;
            } 
            else break;
        }
        else if (left < p2 && right < p2) {
            if (maxHeap[left] >= maxHeap[right]) {
                if (maxHeap[s] < maxHeap[left]) {
                    swap(maxHeap[s] , maxHeap[left]);
                    s = left;
                }
                else if (maxHeap[s] < maxHeap[right]) {
                    swap(maxHeap[s] , maxHeap[right]);
                    s = right;    
                }
                else {
                    break;
                } 
            }
            else {
                if (maxHeap[s] < maxHeap[right]) {
                    swap(maxHeap[s] , maxHeap[right]);
                    s = right;    
                }
                else if (maxHeap[s] < maxHeap[left]) {
                    swap(maxHeap[s] , maxHeap[left]);
                    s = left;
                }
                else {
                    break;
                }
            }
        }
        else  {
            break;
        }
    }   
}
#define sep ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main() 
{ 
    sep;
    int t; cin >> t;
    ll x;
    cin >> x;
    ll mead = x;
    cout << mead << "\n";

    minHeap[p1++] = mead;
    //maxHeap[p2++] = mead;
    for (int i = 1; i < t; ++i) {
        cin >> x;
        if (x >= mead) {
            // insert to minheap
            minHeap[p1++] = x;
            heapyfiMin();
        }
        else {
            // insert to maxheap
            maxHeap[p2++] = x;
            heapyfiMax();
        }
        ll val;
        if (p1 - p2 >= 2) {
            // delete from min and insert to max
            val = minHeap[0];
            maxHeap[p2++] = val;
            heapyfiMax();
            minHeap[0] = minHeap[p1-1];
            --p1;
            heapyfiMin_top(0);
        }
        else if (p2 - p1 >= 2) {
            // delete from max and insert to min
            val = maxHeap[0];
            minHeap[p1++] = val;
            heapyfiMin();
            maxHeap[0] = maxHeap[p2-1];
            --p2;
            heapyfiMax_top(0);
        }
        else {
            // nothing
        }

        // update mead here...
        if (p1 > p2) {
            mead = minHeap[0];
        }
        else if (p2 > p1) {
            mead = maxHeap[0];   
        }
        else {
            if (minHeap[0] < maxHeap[0])
                mead = minHeap[0];
            else
                mead = maxHeap[0];
        }
        cout << mead << "\n";
    }
    return 0; 
} 
/*8                     
2 59 91 64 66 58 16 48*/
