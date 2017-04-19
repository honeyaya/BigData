//227,273,385,537,539,556

class Solution {
public:
	bool isdigit(char c){
		return c>='0' && c<='9';
	}
	
    int calculate(string s) {
        stack<int> st;
        char sign = '+';
        int tmp = 0;
        int len = s.length();
        for(int i = 0; i < len;i++){
        	if(isdigit(s[i])){
        		tmp = tmp * 10 + s[i] - '0';
			}
			if(!isdigit(s[i]) && (s[i] != ' ') || (i == len - 1)){
				if(sign == '-')
					st.push(-tmp);
				else if(sign == '+'){
					st.push(tmp);
				}
				else{
					int num;
					if(sign == '*'){
						num = st.top() * tmp;
					} else{
						num = st.top() /tmp;
					}
					st.pop();
					st.push(num);
				}
				sign = s[i];
				tmp = 0;
			} 
		}
		int ans = 0;
		while(!st.empty()){
			ans += st.top();
			st.pop();
		}
		return ans;
    }
};


