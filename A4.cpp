//============================================================================================
// Name         : Merge and Intersect - Functions
// Author       : Zachary Levinson
// Student ID   : 260466524
// Assignment   : 4
// Question     : 1 and 2
// Description  : 
//============================================================================================
#include <"a4.h">

//Builds a heap from a given array a[] of given size
MinHeap::MinHeap(MinHeapNode a[], int size)
{
    heap_size = size;
    harr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l].element < harr[i].element)
        smallest = l;
    if (r < heap_size && harr[r].element < harr[smallest].element)
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 
// swaps two elements
void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp = *x;  *x = *y;  *y = temp;
}

int merge(int *arrs[], int arrs_length[], int *re_arr, int & re_size){
	//create a min heap with k heap nodes.
	MinHeapNode *harr = new MinHeapNode[5];
	
	for (int i = 0; i < 5; i++){
		harr[i].element = arrs[i][0]; //store first element of each array in heap
		harr[i].i=i; // array index
		harr[i].j=1; // index of next element 
	}
	
	MinHeap hp(harr,5); //create the heap
	
	for (int count =0; count < re_size; count++)
	{	
		//Get minimum element and store it in output
		MinHeapNode root = hp.getMIN();
		re_arr[count] = root.element;
	
		//Find the next element that will replace current
		//root of heap the next element belongs to same
		//array as the current root
		if (root.j< arrs_length[root.i]) {
			root.element = arrs[root.i][root.j];
			root.j +=1;
		}
		else {root.element = 1000000;
		}
		
		hp.replaceMin(root);
	}
    
	return 0;
}

int intersect(int *arrs[], int arrs_length[], int *re_arr, int & re_size){
	unordered_map <int,int> map1;
	int z=0; // requred to re size the length of the intersection array
	for (int i=0; i < 5; i++){
		for (int j=0; j < arrs_length[i]; j++){	
			//if value does not exist it becomes 1 otherwise it is n+1
			map1[arrs[i][j]]++;
			//checks the next position to see if they are the same value if it is we skip
			if (arrs[i][j]==arrs[i][j+1]){
				j++;
			}
		}
	}
	//iterates through map
	for (unordered_map <int,int> ::iterator it =map1.begin(); it != map1.end(); it++){
		//checks if the count or value =5 in the map and if so outputs the intersect
		if (it->second==5){
		re_arr[z]=it->first;
		z++;
		}
	}
	re_size=z;
    
	return 0;
}
