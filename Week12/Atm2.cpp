#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

vector<int> Atm2(vector<int> a, int money) {
	vector<int> result;
	stack<int> st,res;
	for(int i=0 ; i< a.size() ; i++) st.push(a[i]);
	while( money > 0) {
		int count =0;
		while(money > money > st.top() && a[st.size()-1] > 0) {
			money = money - st.top();
			a[st.size()-1]--;
			count++;
		}
		res.push(count);
		count =0;
		st.pop();
	}
	if(money >0) {
		cout << "Khong co cach lay thoa man" << endl;
		return result;
	}
	while(!res.empty()) {
		result.push_back(res.top());
		res.pop();
	}
	return result;
}

int main() {
	// 700000 6 1 1 1 1 1 1  
	int money,n,x;
	vector<int> a;
	cin >> money >> n;
	for(int i=0 ; i< n ; i++)
		{
			cin >> x;
			a.push_back(x);
		}
	vector<int> result = Atm2(a,money);
}
