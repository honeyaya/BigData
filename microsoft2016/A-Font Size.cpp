#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int task;
    int n,p,w,h,sum;
    vector<int> vc;
    
    while(cin >> task){
        while(task--){
            cin >> n >> p >> w >> h;
            vc.clear();
            int data;
            for(int i = 0; i < n; i++){
                cin >> data;
                vc.push_back(data);
            }        
            
            
            for(int s = 1; s <= w; s++){
                int rownum = w/s;
                
                int totalrow = 0;
                for(int i = 0; i < n; i++){
                    int tmp = vc[i]/rownum;
                    if(rownum * tmp != vc[i]) tmp++;
                    totalrow += tmp;
                }
                
                if(totalrow <= (p * (h/s))){
                    continue;
                } else{
                    cout << s - 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
