// 时间序列上的更新需要提高
 
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = 0;
		int len =  timeSeries.size();
		
		if(len == 0) return 0;
		
		sum = duration ;
		int endtime = timeSeries[0] + duration;
		
		for(int i = 1; i < len; i++){
			sum += duration - (timeSeries[i] < endtime) * (endtime - timeSeries[i]);
			endtime = timeSeries[i] + duration ;
		}
		
		return sum;
    }
};

//230-68 = 162
 
 
