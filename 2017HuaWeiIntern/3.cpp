#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

struct task{
	int id,prior,start,run;
};

vector<task> t;

bool cmp(const task& a, const task& b){
	if(a.start ==b.start) 
		return a.prior > b.prior;
	return a.start < b.start;
}

int main(){
	int a,b,c,d;
	for(int i = 0; i < 4; i++){
		scanf("[%d.%d.%d.%d]|",&a,&b,&c,&d);
		t.push_back((task){a,b,c,d});
	}	
	scanf("[%d.%d.%d.%d]",&a,&b,&c,&d);
	t.push_back((task){a,b,c,d});
	
	sort(t.begin(),t.end(),cmp);
	
	
	int time = 0;

	if(t[0].start > 200) {
		cout << 0 << endl;
		return 0;
	} 
	else{
		bool one = true;
		int first = 0;
		int time = t[0].start ;
		if(time > 0){
			cout << first<<"." << time;
			one = false;
		} 
		int onetime = 0;
		int lastpos = 0;
		for(int i = t[0].start; i <= 200; i++){
			int pos = -1;
			int tmp = -1;
			for(int j = 0; j < 5;j++){
				if(t[j].start <= i && (t[j].run != 0)){
					if(t[j].prior > tmp){
						tmp = t[j].prior;
						pos = t[j].id;
					}	
				}	
			}
			if(pos == lastpos){
				if(onetime <= t[pos].run){
					onetime++;
				}else{
					cout <<pos <<"." << onetime;
					t[pos].run = 0;
				}
			} else{
				cout << lastpos<<"." <<onetime << endl;
				t[lastpos].run -= onetime;
				onetime = 0;
				
				pos = lastpos;
			}
			
		}
	}
	
	
	return 0; 
} 
/*

[1.80.1.10]|[2.20.11.15]|[3.50.21.10]|[4.120.31.10]|[5.100.41.10]


*/
