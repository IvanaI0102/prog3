#include <iostream>
#include <vector>

using namespace std;

void segment_tree(int a[], int i, int levo, int desno, vector<int>& v)
{
    if(levo == desno)
    {
        v[i] = a[levo];
        return;
    }

    else
    {
        int sredina = (desno + levo)/2;
        segment_tree(a,i2,levo,sredina,v); // levata strana od drvoto
        segment_tree(a,i2+1,sredina+1,desno,v); // isto za desnoto
        v[i] = min(v[i2], v[i2+1]); // momentalno
    }

}

int minimum(int i, int levo, int desno, int fix_l, int fix_d, vector<int> &v)
{
    if(levo>desno)
    return 0;

    if(levo==fix_l and desno==fix_d)
    return v[i];

    int mid = (fix_d+fix_l)/2;

    // ako mora del od levo i del od desno dete zbir da se traze

    int a = minimum(2i,levo,min(mid,desno),fix_l,mid,v); //ako se bara zbir od del od levo i del od desno dete
    int b = minimum(2i+1,max(levo,mid+1),desno,mid+1,fix_d,v);

    if(a==0)
    return b;

    if(b==0)
    return a;

    return min(a,b);
}

int maximum(int i, int levo, int desno, int fix_l, int fix_d, vector<int> &v)
{
    if(levo>desno)
    return 0;

    if(levo==fix_l and desno==fix_d)
    return v[i];

    int mid = (fix_d+fix_l)/2;


    int a = maximum(2i,levo,min(mid,desno),fix_l,mid,v); //ako se bara zbir od del levoto i del desnoto dete 
    int b = maximum(2i+1,max(levo,mid+1),desno,mid+1,fix_d,v);

    if(a==0)
    return b;

    if(b==0)
    return a;

    return max(a,b);
}

void update(int i, int levo, int desno, int kaj, int val, vector<int> &v)
{
    if(levo == desno)
    v[i] = val;

    else
    {
        int mid = (levo+desno)/2;
        if(kaj<=mid)
        {
            update(i2,levo,mid,kaj,val,v);
        }
        else
        {
            update(2i+1,mid+1,desno,kaj,val,v);
        }

        v[i] = min(v[i2], v[i2+1]);
    }
} 
int main()
{
    int n=0;
    cin >> n;

    int a[n];

    for(int i=0;i<n;i++)
    cin >> a[i];

    vector <int> v(4*n,-1);

    segment_tree(a, 1, 0, n-1, v);

    for(int i:v)
    cout << i << " ";

    cout << '\n';

    cout << minimum(1,0,1,0,n-1,v) << "\n"; 

   segment_tree(a, 1, 0, n-1, v);

    for(int i:v)
    cout << i << " ";

    cout << '\n';

    cout << maximum(1,0,1,0,n-1,v) << "\n"; 
    a[0] = 100;

    update(1,0,n-1,0,100,v);

    for(int i:v)
    cout << i << " ";

    cout << '\n';

    cout << minimum(1,0,n-1,0,n-1,v);




    return 0;
}
