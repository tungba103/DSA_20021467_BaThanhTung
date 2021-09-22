string isBalanced(string s) {
	if( s[0]=='}' || s[0] == ']' || s[0]== ')')
	{
		 return "NO";
	}
    stack<int> st;
    for(int i=0 ; i < (int)s.size(); i++)
    {
    	if( st.size() == 0 && ( s[i]=='}' || s[i] == ']' || s[i]== ')') ) return "NO";
        if( s[i] == '{' || s[i] == '[' || s[i] == '(') st.push(s[i]);
        else
        {
            switch(s[i]){
                case '}':
                    if( st.top() == '{') st.pop();
                    else st.push(s[i]);
                    break;
                case ']':
                    if( st.top() == '[') st.pop();
                    else st.push(s[i]);
                    break;
                case ')':
                    if( st.top() == '(') st.pop();
                    else st.push(s[i]);
                    break;
            }

        }
 
    }
    if(!st.empty()) return "NO";
    return "YES";
}

