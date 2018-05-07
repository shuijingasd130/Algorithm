/*
排序的基本思想是堆：
将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。将其与末尾元素进行交换，此时末尾就为最大值。
然后将剩余n - 1个元素重新构造成一个堆，这样会得到n个元素的次小值。如此反复执行，便能得到一个有序序列了

步骤一 构造初始堆。将给定无序序列构造成一个大顶堆（一般升序采用大顶堆，降序采用小顶堆)。
步骤二 将堆顶元素与末尾元素进行交换，使末尾元素最大。然后继续调整堆，再将堆顶元素与末尾元素交换，得到第二大元素。
		如此反复进行交换、重建、交换。

处于最大堆的根节点的元素一定是这个堆中的最大值。
堆排序算法就是抓住了堆的这一特点，每次都取堆顶的元素，将其放在序列最后面，然后将剩余的元素重新调整为最大堆，依次类推，最终得到排序的序列。

整个堆排序的过程: 整个过程的核心就是先初始化大顶堆，将最大数(堆顶)的放到堆的最后一个, 堆长度-1, 继续调整成大顶堆，直至有序序列为len(array_list)-1.

特别注意: 初始化大顶堆时 是从最后一个有子节点开始往上调整最大堆。而堆顶元素(最大数)与堆最后一个数交换后，需再次调整成大顶堆，
此时是从上往下调整的。
不管是初始大顶堆的从下往上调整，还是堆顶堆尾元素交换，每次调整都是从父节点、左孩子节点、右孩子节点三者中选择最大者跟父节点进行交换，
交换之后都可能造成被交换的孩子节点不满足堆的性质，因此每次交换之后要重新对被交换的孩子节点进行调整。
*/

#include <iostream>

void HeapSort(int arr[], int len);
void HeapSortAdjust(int arr[], int s, int len);
void swap(int arr[], int a, int b);

void printarr(int arr[], int len);

int main()
{
	int arr[] = { 90, 70, 80, 60, 10, 40, 50, 30, 20 };

	std::cout << "before heap sort:" << std::endl;
	int len = sizeof(arr) / sizeof(arr[0]);
	printarr(arr, len);

	HeapSort(arr,len-1);	//排序

	std::cout << "After heap sort:" << std::endl;
	printarr(arr, len);

	system("pause");
}

void HeapSort(int arr[], int len) {
	for (size_t i = len / 2; i > 0; i--)	//构建最大堆，每个非叶节点都要调整一下，从下至上
	{
		HeapSortAdjust(arr, i, len);
	}
	for (size_t i = len; i > 0; i--)
	{
		swap(arr, i, 0);		//堆顶元素与堆的最后一个元素互换
		HeapSortAdjust(arr, 0, i-1);	//堆的长度减1
	}
}

void HeapSortAdjust(int arr[], int s, int len) {	//调整s位置的元素，使arr满足最大堆
	int tmp = arr[s];
	for (size_t i = 2*s; i <= len; i*=2)		//从s的叶节点开始调整,该节点调整完后要看调整后叶节点是否满足最大堆，直至最后
	{
		if (i<len && arr[i]<arr[i + 1]){	//比较左右孩子，左孩子小 i换为右孩子的坐标
			i++;
		}
		if (tmp >= arr[i]) {
			break;		//不需要与子节点互换，本身满足最大堆，不用调整了
		}
		arr[s] = arr[i];	//s处赋新值
		s = i;				//更新s为其较大的孩子
	}
	arr[s] = tmp;	
}

void swap(int arr[], int a, int b) {
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void printarr(int arr[], int len)
{
	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}