
#include <bits/stdc++.h>
using namespace std;

void konstruiraj(vector<int>& segtree, vector<int> &a, int n)
{
	//zadadi vrednost na listovite
	for (int i = 0; i < n; i++) 
		segtree[n + i] = a[i]; 
     //zadadi vrednost na vnatresnite
	for (int i = n - 1; i >= 1; i--)
		segtree[i] = (segtree[2 * i]+ segtree[2 * i + 1]);
}

void update(vector<int>& segtree, int kaj, int val, int n)
{
	//prvo smeni indeks na listovite
	kaj += n;

	//smeni element
	segtree[kaj] = val;

	while (kaj > 1) {

		//pomestuvaj se edno nivo nagore
		kaj >>= 1;

	
		segtree[kaj] =(segtree[2 * kaj] + segtree[2 * kaj + 1]);
	}
}

int rquery(vector<int>& segtree, int left, int right, int n)
{


	//smeni go indeksot na listovite
	left += n;
	right += n;
     //zadavame mal broj
	int su = 0;

	while (left < right) {

		//ako leviot indeks e neparen
		if (left%2==1) {
			su+=segtree[left];

			// praj leviot paren
			left++;
		}

		// ako desniot e neparen
		if (right%2==1) {

			// napraj go desniot paren
			right--;

			su+=segtree[right];
		}

		// odi nagore
		left /= 2;
		right /= 2;
	}
	return su;
}


int main()
{
	vector<int> a = { 5, 7, 19, 22, 67, 2, 88, 99, 1, 62, 3 };
	int n = a.size();


	vector<int> segtree(4 * n);
	konstruiraj(segtree, a, n);


	int left = 0, right = 5;
	cout << "Zbir na " << left << " do "<< right << " e "<< rquery(segtree, left, right + 1, n) << "\n";

	int index = 4, val = 85;

	
	update(segtree, index, val, n); 

	left = 1, right = 7;
	cout << "Zbir na " << left << " do "<< right << " e " << rquery(segtree, left, right + 1, n) << "\n";

	return 0;
}
