#include<bits/stdc++.h>
using namespace std;

class SegmentTree
{
private:
    int n;
    vector<int> arr, seg;

    void buildTreeUtil(int i, int l, int h)
    {
        if (l == h) {
            this->seg[i] = this->arr[l];
            return;
        }

        int m = l + (h - l)/2;
        int lc = 2*i + 1, rc = 2*i + 2; 

        this->buildTreeUtil(lc, l, m);
        this->buildTreeUtil(rc, m + 1, h);

        this->seg[i] = max(this->seg[lc], this->seg[rc]);
    }

    int getQueryUtil(int i, int l, int h, int L, int R)
    {
        if (l >= L && h <= R)
            return this->seg[i];
        
        if (h < L || l > R)
            return INT_MIN;
        
        int m = l + (h - l)/2;
        int lSub = this->getQueryUtil(2*i + 1, l, m, L, R);
        int rSub = this->getQueryUtil(2*i + 2, m + 1, h, L, R);
        return max(lSub, rSub);
    }
public:
    SegmentTree(int _n, vector<int>& a)
    {
        this->n = _n;
        this->arr = a;
        this->seg.resize(4 * this->n);
    }

    void buildTree() {
        this->buildTreeUtil(0, 0, this->n - 1);
    }

    int getQuery(int l, int r) {
        return this->getQueryUtil(0, 0, this->n - 1, l, r);
    }
};

int main()
{
    
    return 0;
}