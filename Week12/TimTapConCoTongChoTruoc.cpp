#include <iostream>
using namespace std;

void tapCon(int n, int a[], int b[], int res) {
	int k=0;
	b[k]=0;
	int s=0;
	while( k != 0) {
		b[k] = b[k] + 1;
		if( b[k] <= n) {
			if( s + a[b[k]] == res ) {
				for(int i=0 ; i < k ; i++)
					cout << a[b[k]] << " ";
			}
			else {
				s = s + a[b[k]];
				b[k+1] = b[k];
				k++;
			}
		}
		else {
			k = k -1;
			s = s - a[b[k]];
		}  
	}
}

// 7 3 5 20 15 35 69 72 38
int main() {
	int n, a[100001], b[100001], res;
	cin >> n;
	for(int i=0 ; i< n ; i++)
		cin >> a[i];
	cin >> res;
	tapCon(n,a,b,res);
		for(int i=0 ; i< n ; i++)
		cout << a[i] << " ";
	return 0;
}
