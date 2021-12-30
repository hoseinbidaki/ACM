class SegmentTree
{
private:
    int n;
    vector<int> st;
    vector<int> arr;

    int getMid(int s, int e) { return s + (e -s)/2; }  

    int constructSTUtil(int ss, int se, int si)  
    {  
        if (ss == se)  
        {  
            st[si] = arr[ss];  
            return arr[ss];  
        }  
    
        int mid = getMid(ss, se);  
        st[si] = constructSTUtil(ss, mid, si*2+1) + constructSTUtil(mid+1, se, si*2+2);  
        return st[si];  
    }  
    void constructST()  
    {  
        int x = (int)(ceil(log2(n)));  
        int max_size = 2*(int)pow(2, x) - 1;  
        st = vector<int> (max_size);
        constructSTUtil(0, n-1, 0);  
    }  

    int getSumUtil(int ss, int se, int qs, int qe, int si)  
    {  
        if (qs <= ss && qe >= se)  
            return st[si];  
    
        if (se < qs || ss > qe)  
            return 0;  
    
        int mid = getMid(ss, se);  
        return getSumUtil(ss, mid, qs, qe, 2*si+1) + getSumUtil(mid+1, se, qs, qe, 2*si+2);  
    }

    void updateValueUtil(int ss, int se, int i, int diff, int si)  
    {  
        if (i < ss || i > se)  
            return;  
    
        st[si] = st[si] + diff;  
        if (se != ss)  
        {  
            int mid = getMid(ss, se);  
            updateValueUtil(ss, mid, i, diff, 2*si + 1);  
            updateValueUtil(mid+1, se, i, diff, 2*si + 2);  
        }  
    }      

public:
    SegmentTree(vector<int> input)
    {
        arr = input;
        n = arr.size();
        constructST();
    }
    int getSum(int qs, int qe)  
    {  
        if (qs < 0 || qe > n-1 || qs > qe)  
        {  
            cerr << "Invalid Input";  
            return -1;  
        }  
        return getSumUtil(0, n-1, qs, qe, 0);  
    }  

    void updateValue(int i, int new_val)  
    {  
        if (i < 0 || i > n-1)  
        {  
            cout<<"Invalid Input";  
            return;  
        }  
    
        int diff = new_val - arr[i];      
        arr[i] = new_val;      
        updateValueUtil(0, n-1, i, diff, 0);  
    }  
    void print()
    {
        for (auto it : arr) cout << it << " ";
        cout << "\n";
    }
}sg;
