#include <iostream>
#include <vector>

using namespace std;

void segment_tree(int a[], int index, int left, int right, vector<int>& v)
{
    if(left == right)
    {
        v[index] = a[left];
        return;
    }
   
    else
    {
        int sredina = (right + left)/2;
        segment_tree(a,index*2,left,sredina,v); // praam levo
        segment_tree(a,index*2+1,sredina+1,right,v); // praam desno
        v[index] = v[index*2] + v[index*2+1]; // praam segasno
    }
   
}

int sum(int index, int l, int r, int fix_l, int fix_r, vector<int> &v)
{
    if(l>r)
    return 0;
   
    if(l==fix_l and r==fix_r)
    return v[index];
   
    int mid = (fix_r+fix_l)/2;
   
    // ako mora del od levo i del od desno dete zbir da se traze
    return sum(2*index,l,min(mid,r),fix_l,mid,v) + sum(2*index+1,max(l,mid+1),r,mid+1,fix_r,v);
}

void update(int index, int l, int r, int deka, int val, vector<int> &v)
{
    if(l == r)
    v[index] = val;
   
    else
    {
        int mid = (l+r)/2;
        if(deka<=mid)
        {
            update(index*2,l,mid,deka,val,v);
        }
        else
        {
            update(2*index+1,mid+1,r,deka,val,v);
        }
       
        v[index] = v[index*2] + v[index*2+1];
    }
}

int main()
{
    int n=0;
    cin >> n;
   
    int a[n];
   
    for(int i=0;i<n;i++)
    cin >> a[i];
   
    vector <int> v(4*n,-234141);
   
    segment_tree(a, 1, 0, n-1, v);
   
    for(int i:v)
    cout << i << " ";
   
    cout << '\n';
   
    cout << sum(1,0,n-1,0,n-1,v) << "\n"; //indeksite so ni trebat u drvoto pocnuvat od 1
   
    a[0] = 100;
   
    update(1,0,n-1,0,100,v);
   
    for(int i:v)
    cout << i << " ";
   
    cout << '\n';
   
    cout << sum(1,0,n-1,0,n-1,v);
   
   

    return 0;
}



