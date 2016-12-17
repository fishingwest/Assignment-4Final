//============================================================================================
// Name         : Header
// Author       : Zachary Levinson
// Student ID   : 260466524
// Assignment   : 4
// Question     : 1 and 2
//============================================================================================#include<iostream>
#include<iostream>
#include <unordered_map>
using namespace std;

//Describes Nodes in Heap Data Structure
class MinHeapNode {
	public:
	int element; // element to be stored
	int i; // index of array from which element is taken
	int j; // index of next element to picked within array
};
 
class MinHeap {
	MinHeapNode *harr; // pointer to array of elements in heap
	int heap_size; //size of min heap
	public: 
	// Constructor creates a min heap of a given size
	MinHeap(MinHeapNode a[], int size);
	
	// to heapify a subtree with root at given index
	void MinHeapify(int);
	//get index of left
	int left (int i) {return (2*i+1);}
	// get index of right
	int right (int i) {return (2*i+2);}
	//to get root
	MinHeapNode getMIN() {return harr[0];}
	//to replace root with new node x and heapify() new root
	void replaceMin(MinHeapNode x) {
		harr[0]=x;
		MinHeapify(0);
	}
	
};

//function prototypes
void swap(MinHeapNode *x, MinHeapNode *y);
int merge(int *arrs[], int arrs_length[], int *re_arr, int & re_size);
int intersect(int *arrs[], int arrs_length[], int *re_arr, int & re_size);

