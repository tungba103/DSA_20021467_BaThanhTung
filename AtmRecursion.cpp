#include <iostream>
using namespace std;

int MIN(int a,int b) {
    if( a > b) return b;
    return a;
}

void AtmRecursion(int money, int a[9],string str[9])
{
    int res[9] = {0,0,0,0,0,0,0,0,0};
    int value[9] = {1000,2000,5000,10000,20000,50000,100000,200000,500000};
    for( int i=8 ; i>=0 ; i--) {
        int k = money/value[i];
        money -= k*value[i];
        res[i] = k;
    }
    if(0 != money) cout << "No way available!" << endl;
    else {
        for(int i=0 ; i < 9 ; i++) {
            if(0!= res[i]) cout << str[i] << res[i] << endl;
        }
    }
    return;
}

int main() {
    // 700000 1 1 1 1 1 1 1 1 1
	int money;
	int a[9]= {1,1,1,1,1,1,1,1,1};
	string str[9]={"So to 1000 la: ","So to 2000 la: ","So to 5000 la: ","So to 10000 la: ","So to 20000 la: ","So to 50000 la: ","So to 100000 la: ","So to 200000 la: ","So to 500000 la: "};
	cin >> money;
	for( int i=0 ; i< 9 ; i++) {
        cout << str[i];
        cin >> a[i];
	}
	cout << AtmRecursion(money,a,str);
}
