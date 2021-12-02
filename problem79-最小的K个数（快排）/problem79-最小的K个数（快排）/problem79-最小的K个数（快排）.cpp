//
//  main.cpp
//  problem79-最小的K个数（快排）
//
//  Created by JustforStar on 2021/12/2.
//

#include <iostream>

int Partition(int *A,int low,int high){
    int pivot = A[low];
    while (low<high) {
        while (low<high&&A[high]>=pivot) {
            --high;
        }
        A[low]=A[high];
        while (low<high&&A[low]<=pivot) {
            ++low;
        }
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}

void QuickSort(int *A,int low,int high){
    if(low<high){
        int pivot = Partition(A, low, high);
        QuickSort(A, low, pivot-1);
        QuickSort(A, pivot+1, high);
    }
}

int main(int argc, const char * argv[]) {
    int nums[100],n,K;
    printf("请输入数组的长度n：");
    scanf("%d",&n);
    printf("请输入数组nums的%d个数：",n);
    for (int i=0; i<n; i++) {
        scanf("%d",&nums[i]);
    }
    printf("请输入K的值：");
    scanf("%d",&K);
    
    QuickSort(nums, 0, n-1);
    
    for (int i=0; i<K; i++) {
        printf("%d ",nums[i]);
    }
    printf("\n");
    
    return 0;
}
