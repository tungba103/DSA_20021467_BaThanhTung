#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void Atm1(int money) {
	vector<int> res;
	string str[] = {"So to 500000 la ","So to 200000 la ","So to 100000 la ","So to 50000 la ","So to 20000 la ","So to 10000 la "};
	stack<int> a;
	a.push(10000);
	a.push(20000);
	a.push(50000);
	a.push(100000);
	a.push(200000);
	a.push(500000);
	while( money > 0) {
		int m = money / a.top();
		cout << m << endl;
		res.push_back(m);
		money = money - m*a.top();
		a.pop();
	}
	while(res.size() <6) res.push_back(0);
	for(int i=0 ; i< 6; i++) {
		cout << str[i] << res[i] << endl;
	}
}

int main() {
	int money;
	cin >> money;
	Atm1(money);
}
