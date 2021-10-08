#include <iostream>
using namespace std;

class Hashtable {
	string table[1000] = {};
	int ms[1000] = {};
	public:
		// SIZE = 11
		int hash(int mssv) {
			int k = mssv %11;
			while(table[k] != "") {
				k = (k+1) %11;
			}
			return k;
		}
		
		void put (int mssv, string fullname) {
			int index = hash(mssv);
			table[index] = fullname;
			ms[index] = mssv;
		}
		
		string get (int mssv) {
			int k = mssv % 11;
			while( ms[k] != mssv) k = (k+1) %11;
			return table[k];
		}
		
		void remove (int mssv) {
			int k = mssv % 11;
			while( ms[k] != mssv) k = (k+1) %11;
			table[k] = "";
			ms[k] = 0;
			return;
		}
};

