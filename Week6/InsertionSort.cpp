#include <iostream>
using namespace std; 
// Insertion Sort
int main()
{
	// 2 1 10 6 3 8 7 13 20
	int n, a[1000];
	cin >> n;
	for(int i=0 ; i< n ; i++) cin >> a[i];
	for(int i=1 ; i< n ; i++) {
		int value = a[i];
		int index = i;
		while( a[index-1] > value && index >0) {
			a[index] = a[index-1];
			index--;
		}
		a[index] = value;
	}
	for(int i=0 ; i< n ; i++)
		cout << a[i] << " ";
	return 0;
}
