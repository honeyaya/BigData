#include <iostream>
#include <cstring>

using namespace std;

int main(){
	string str;
	
	while(cin >> str) {
		int len = str.length();
		if(len < 2) {
			cout << str << endl;
			continue;
		}
		
		string tmp;
		tmp.clear();
		for(int i = 0; i < len;){
			if((i + 1 < len) && str[i] == 'r' && str[i + 1] == 'a'){
				i += 2;
			} else{
				tmp += str[i];
				i++;
			}
		}
		
		
		cout << tmp << endl;
		
	}
	return 0;
}
