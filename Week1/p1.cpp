#include <iostream>
using namespace std;
int main(){
	string s,res="";
	getline(cin,s);
	for(int i= s.length()-1; i >=0 ; i--)
		{
			cout << s[i];
		}
	return 0;
}

//#include <iostream>
//using namespace std;
//int main(){
//	string s,res="";
//	getline(cin,s);
//	for(int i=0 ; i < s.size(); i++)
//	{
//		res = s[i] + res;
//	}
//	cout << res << endl;
//	return 0;
//}
