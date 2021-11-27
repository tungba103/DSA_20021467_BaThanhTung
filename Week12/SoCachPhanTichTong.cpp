#include <iostream>
using namespace std;

void Recursion(int sum, int &count, int n, int start) {
	for(int i = start; i <= n ; i++) {
		if( sum + i == n) count++;
		else if ( sum + i < n) Recursion(sum+i,count,n,i+1);
	}
}

int main() {
	int n;
	cin >> n;
	int count=0;
	Recursion(0,count,n,1);
	cout << "So cach phan tinh tong la: " << count << endl;
	return 0;
}
