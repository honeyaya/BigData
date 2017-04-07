// sorted array and no duplicate -- to find a value  
// if left == right

class Solution {
public:
    int search(vector<int>& nums, int target) {
		int len = nums.size();
		int left = 0, right = len - 1, mid;
		while(left <= right){
			mid = left + (right - left)/2;
			if(nums[mid] == target) {
				return mid;
			} else {
				// l--|--m--r
				if(nums[mid] <= nums[right]) {
					if(nums[mid] < target && target <= nums[right]){
						left = mid + 1;
					} else {
						right = mid - 1;
					}
				}
				// l--m--|--r
				else if(nums[mid] >= nums[left]){
					if(nums[left] <= target && target < nums[mid]) {
						right = mid - 1;
					} else {
						left = mid + 1;
					}
				}
				// l--m--r 
				else if(nums[left] <= nums[right]){
					if(target < nums[left] ||  target > nums[right]) 
						return -1;
					if(nums[mid] > target) right = mid - 1;
					else left = mid + 1;
				}
			}
		} 
		return -1;       
    }
};

//modify the above code 

class Solution {
public:
    int search(vector<int>& nums, int target) {
  		int len = nums.size();
		int left = 0, right = len - 1;
		while(left <= right){
			int mid = left + (right - left)/2;
			if(nums[mid] ==  target){
				return mid;
			} else{
				// normal order
				if(nums[left] <= nums[right]){
					if(target < nums[left] || target > nums[right])
						return -1;
					if(nums[mid] > target) right = mid - 1;
					else left = mid + 1;
				}
				// l--|-m--r
				else if(nums[mid] <= nums[right]){
					if(nums[mid] < target && target <= nums[right]){
						left = mid + 1;
					} else {
						right = mid - 1;
					}
				} 
				// l--m-|-r
				else if(nums[left] <= nums[mid]){
					if(nums[left] <= target && target < nums[mid]){
						right = mid - 1;
					} else{
						left = mid + 1;
					}
				}
			} 
		}
		
		return -1;      
    }
};


