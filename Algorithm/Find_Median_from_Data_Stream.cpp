/*
设计一个数据结构，该数据结构动态维护一组数据，且支持如下操作:
1.添加元素: void addNum(int num)，将整型num添加至数据结构中。
2.返回数据的中位数: double findMedian()，返回其维护的数据的中位数。
中位数定义:
1.若数据个数为奇数，中位数是该组数排序后中间的数。[1,2,3] -> 2
2.若数据个数为偶数，中位数是该组数排序后中间的两个数字的平均值。[1,2,3,4] -> 2.5

思路1：
动态维护一个最大堆与一个最小堆，最大堆存储一半数据，最小堆存储一般数据，维持最大堆的堆顶比最小堆的堆顶小。
添加元素：
① 最大堆和最小堆元素个数相同 最大堆栈顶元素小于该元素，插入到最小堆，否则插入到最大堆
② 最大堆元素个数大于最小堆，最大堆栈顶大于该元素，将栈顶pop，再push到最小堆，然后将该元素push到最大堆；最大堆栈顶小于该元素，将该元素push到最小堆
③ 最小堆元素个数大于最大堆，最小堆栈顶小于该元素，将栈顶pop，再push到最大堆，然后将该元素push到最小堆；最小堆栈顶大于该元素，将该元素push到最大堆
中位数获取”：
最大堆最小堆元素个数相同，取两个栈顶的均值
不相同，谁多取谁的栈顶
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>


class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (big_queue.empty()){
			big_queue.push(num);
		}
		if (small_queue.size() == big_queue.size()) {
			if (num<big_queue.top()) {
				big_queue.push(num);
			}
			else {
				small_queue.push(num);
			}
		}
		else if (big_queue.size()>small_queue.size()) {
			if (num>big_queue.top()) {
				small_queue.push(num);
			}
			else {
				small_queue.push(big_queue.top());
				big_queue.pop();
				big_queue.push(num);
			}
		}
		else if (big_queue.size()<small_queue.size()) {
			if (small_queue.top()>num) {
				big_queue.push(num);
			}
			else {
				big_queue.push(small_queue.top());
				small_queue.pop();
				small_queue.push(num);
			}
		}
	}

	double findMedian() {
		if (big_queue.size() == small_queue.size()) {
			return (big_queue.top() + small_queue.top()) / 2;
		}
		else if (big_queue.size() > small_queue.size()) {
			return big_queue.top();
		}
		return small_queue.top();
	}
private:
	std::priority_queue<int> big_queue;
	std::priority_queue<int, std::vector<int>, std::greater<int>> small_queue;
	
};

/*
思路2：
 同样维护最大堆和最小堆，有新元素直接push到最大堆，再将最大堆堆顶push到最小堆，
 最大堆pop一个元素，即每来一个元素，两个堆都要push元素，只是最小堆push的是最大堆调整后的堆顶；
 当最大堆元素个数小于最小堆时，把最小堆对顶push到最大堆中，最小堆pop，
 保证最大堆个数不小于最小堆，这样在之后的查找元素时只用输出最大堆的堆顶或两个堆的平均
 */
 
class MedianFinder1 {
public:
    /** initialize your data structure here. */
    std::priority_queue<int> lo;    //最大堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> hi;   //最小堆
    
    MedianFinder1() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        
        hi.push(lo.top());
        lo.pop();
        
        if(lo.size()<hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size() > hi.size()? (double)lo.top() : (double)(lo.top()+hi.top())/2;
    }
};

int main()
{
	MedianFinder m;
	int test[] = { 6,10,1,7,99,4,33 };
	for (size_t i = 0; i < sizeof(test)/sizeof(int); i++)
	{
		m.addNum(test[i]);
		printf("%lf\n", m.findMedian());
	}
	std::cout << std::endl;
	system("pause");
}

