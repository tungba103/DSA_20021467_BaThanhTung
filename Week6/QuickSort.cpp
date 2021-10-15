#include <iostream>
using namespace std;
int a[1000];

void quickSort( int l, int r){
	int p = a[(l+r)/2];
	int i=l, j=r;
	while (i < j) {
		// 4 3 2 1 => 1 2 3 4
		while( a[i] < p) i++;
		while( a[j] > p) j--;
		if(i <= j) {
			int c = a[i];
			a[i] = a[j];
			a[j] = c;
			i++;
			j--;
		}
	}
	if(i < r) quickSort(i,r);
	if(j > l) quickSort(l,j);
	return;
}
int main()
{
	int n;
	cin >> n;
	for( int i=0 ; i < n ; i++) cin >> a[i];
	quickSort(0,n-1);
	for(int i=0 ; i< n ; i++)
		cout << a[i] << " ";
	return 0;
}
