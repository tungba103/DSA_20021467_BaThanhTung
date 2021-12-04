#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

vector<int> Atm2(int a[], int money) {
    int res[8] = {0};
    int m[] = {1000,2000,5000,10000,50000,100000,200000,500000};
    for( int i = 7 ; i >=0 ; i--) {
        res[i] = min(money/m[i],a[i]);
        m -= m[i] * res[i];
    }
    return res;
}

int main() {
	// 700000 6 1 1 1 1 1 1 1 1 1
	int money,n,x;
	int a[],b[8];
	string str[] = {"So to 500000 la ","So to 200000 la ","So to 100000 la ","So to 50000 la ","So to 20000 la ","So to 10000 la ","So to 5000 la ","So to 2000 la ","So to 1000 la "};
	cin >> money;
	for(int i= 7 ; i >= 0 ; i--)
		{
		    cout << str[i];
			cin >> a[7-i];
		}
	 b = Atm2(a,money);
	 for(int i=0 ; i< 8 ; i++)
        cout << str[7-i] << " " b << endl;
}
