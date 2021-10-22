#include <iostream>
using namespace std;
int a[100001];
//  1 2 3 4 5
void merge (int left, int mid, int right) {
	int _m = mid-left+1;
	int _n = right-mid;
	int *m = new int[_m];
	int *n = new int[_n];
	for(int i=0 ; i< _m; i++)
	{
		m[i] = a[left+i];
	}
	for(int i=0 ; i < _n; i++)
	{
		n[i] = a[mid+i+1];
	}
	int k=left , x = 0, y = 0;
	while( x < _m && y < _n) {
		if( m[x] < n[y]) {
			a[k] = m[x];
			x++;
		}
		else {
			a[k] = n[y];
			y++;
		}
		k++;
	}
	while( x < _m) {
		a[k] = m[x];
		x++;
		k++;	
	}
	while( y < _n) {
		a[k] = n[y];
		y++;
		k++;
	}
	delete[]m;
	delete[]n;
	return;
	
	
}

void MergeSort(int left, int right) {
	if( left < right) {
		int mid = (left + right)/2;
		MergeSort(left,mid);
		MergeSort(mid+1,right);
		merge(left,mid,right);
	}
}

int main() {
	int n;
	cin >> n;
	for( int i=0 ; i < n ; i++) cin >> a[i];
	MergeSort(0,n-1);
	for(int i=0 ; i< n ; i++)
		cout << a[i] << " ";
	return 0;
}
