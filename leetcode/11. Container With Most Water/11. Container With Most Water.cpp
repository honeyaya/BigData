// ֱ�ӱ�����TLE 
class Solution {
public:
    int maxArea(vector<int>& height) {
  		int len = height.size();
  		int maxarea = 0;
		for(int i = 0; i < len; i++){
			for(int j = i + 1; j < len;j++){
				int tmparea = abs(i - j) * min(height[i] , height[j]);
				maxarea = max(maxarea,tmparea); 
			} 
		}
		return maxarea;       
    }
};

// ˫�˱����Ż� 
class Solution {
public:
    int maxArea(vector<int>& height) {
  		
		int len = height.size();
  		int maxarea = 0;
		int l = 0, r = len - 1;
		while(l < r){
			int tmparea = abs(l - r) * min(height[l],height[r]);
			maxarea = max(maxarea,tmparea);
			if(height[l] < height[r]) l++;
			else r--;
		}
		return maxarea;       
    }
};

// area = abs(i-j) * min(height[i],height[j])  ���Ʊ�������ά��һ��������������£��ҵ�����һ������ 
//����ָ�뷽��
 
class Solution {
public:
    int maxArea(vector<int>& height) {
		int len = height.size();
  		int maxarea = 0;
		int l = 0, r = len - 1;
		while(l < r){
			int tmph = min(height[l],height[r]);
			int tmparea = abs(l - r) * tmph;
			maxarea = max(maxarea,tmparea);
			while(height[l] <= tmph && l < r) l++;
			while(height[r] <= tmph && l < r) r--; 
		}
		return maxarea;       
    }
}; 
