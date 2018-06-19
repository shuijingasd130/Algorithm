/*题目：
			已知一个未排序的数组，求这个数组中第K大的数字。 如，array = [3,2,1,5,6,4] ， k = 2，return 5
思路：
维护一个K大小的最小堆，堆中元素个数小于K时，新元素直接进入堆；否则，当堆顶小于新元素时，弹出堆顶，将新元素加入堆。 解释: 由于堆是最小堆，堆顶是堆中最小元素，新元素都会保证比堆顶小(否则新元素替换堆顶)，故堆中K个元素是已扫描的元素里最大的K个；堆顶即为第K大的数。 设数组长度为N，求第K大的数，时间复杂度 : N * logK
解答：
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> Q;    //最小堆
        for(int i = 0; i<nums.size();i++){
            if(Q.size()<k){    //维护k个元素的最小堆
                Q.push(nums[i]);
            }
            else if(nums[i]>Q.top()){    //堆顶元素小，则弹出，push新元素
                Q.pop();
                Q.push(nums[i]);
            }
        }
        return Q.top();    //返回堆顶元素
    }
};