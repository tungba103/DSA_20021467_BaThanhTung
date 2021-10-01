#include <iostream>
#include <stack>
using namespace std;


int main() {
    string str="";
    int n,x;
    stack<string> s;
    s.push("");
    cin >> n;
    int instruction=0;
    for(int i=0 ; i< n; i++)
    {
    	cin >> instruction;
    	switch(instruction){
    		case 1: // append
    			cin >> str;
    			str = s.top() + str;
    			s.push(str);
    			break;
    		case 2: // delete
    			cin >> x;
    			str = "";
				for(int i=0 ; i< s.top().size()-x; i++)
				{
					str = str + s.top()[i];
				}
				s.push(str);
    			break;
    		case 3: // get
    			cin >> x;
    			cout << s.top()[x-1] << endl;
    			break;
    		case 4: // undo
    			s.pop();
    			break;
		}
	}
    return 0;
}

