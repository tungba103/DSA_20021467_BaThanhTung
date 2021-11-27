#include <iostream>
using namespace std;

void Try(int k, int n, bool b[], int a[]) {
	if( k == n+1) {
		for(int i=1 ; i<= n ; i++)
			cout << a[i];
		cout << endl;
		return;
	}
	for(int i=1 ; i <= n; i++) {
		if(!b[i]) {
			b[i] = 1;
			a[k] = i;
			Try(k+1,n,b,a);
			b[i] = 0;
		}
 	}
}

int main() {
	bool b[10001];
	for(int i=0 ;i < 10001 ; i++) b[i] = 0;
	int n;
	int a[1000];
	cin >> n;
	Try(1,n,b,a);
	return 0;
}
