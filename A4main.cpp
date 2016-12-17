//============================================================================================
// Name         : A4 - Main
// Author       : Zachary Levinson
// Student ID   : 260466524
// Assignment   : 4
// Question     : 1 amnd 2
// Description  : Executing of A4.cpp Functions and Definition of Arrays
//============================================================================================
#include <"a4.h">

int main(){
    //test case
    int * arrs[5];
    int arrs_length[5];
    int arr0[] = {1, 5, 8};
    int arr1[] = {1, 3, 5, 7, 10, 11, 15};
    int arr2[] = {1, 4, 5, 6};
    int arr3[] = {1, 5, 9, 14, 16, 19};
    int arr4[] = {1, 2, 4, 5, 6, 9, 9};
    arrs[0] = arr0;
    arrs_length[0] = sizeof(arr0) / sizeof(int);
    arrs[1] = arr1;
    arrs_length[1] = sizeof(arr1) / sizeof(int);
    arrs[2] = arr2;
    arrs_length[2] = sizeof(arr2) / sizeof(int);
    arrs[3] = arr3;
    arrs_length[3] = sizeof(arr3) / sizeof(int);
    arrs[4] = arr4;
    arrs_length[4] = sizeof(arr4) / sizeof(int);
    cout << "Input:" << endl;
    for (int i = 0; i < 5; i ++){
        cout << "[";
        for (int j = 0; j < arrs_length[i] - 1; j ++){
            cout << arrs[i][j] << ", ";
        }
        cout << arrs[i][arrs_length[i] - 1] << "]" << endl;
    }
    //sum length
    int sum_length = 0;
    for (int i = 0; i < 5; i ++){
        sum_length += arrs_length[i];
    }
    //merge manipulation
    //expected output
    //[1, 1, 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 5, 5, 6, 6, 7, 8, 9, 9, 9, 10, 11, 14, 15, 16, 19]
    
	int * merged = new int[sum_length];
    int merge_length = sum_length;
    if (merge(arrs, arrs_length, merged, merge_length) == 0){
        cout << "Output:" << endl << "[";
        for (int i = 0; i < merge_length - 1; i ++){
            cout << merged[i] << ",";
        }
        cout << merged[sum_length - 1] << "]" << endl;
    }
	
	//intersection manipulation
    //expected output
    //[1, 5]
    int * intersection = new int[sum_length];
    int intersect_length = sum_length;
    if (intersect(arrs, arrs_length, intersection, intersect_length) == 0){
        cout << "Output:" << endl << "[";
        for (int i = 0; i < intersect_length - 1; i ++){
            cout << intersection[i] << ",";
        }
        cout << intersection[intersect_length - 1] << "]" << endl;   
    }
    
    return 0;
}


 