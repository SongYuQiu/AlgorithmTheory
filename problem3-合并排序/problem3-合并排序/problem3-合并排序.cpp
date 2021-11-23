//
//  main.cpp
//  problem3-合并排序
//
//  Created by JustforStar on 2021/11/23.
//

#include <iostream>

int main() {
    int nums1[100],nums2[50];
    int n,m;
    
    printf("请输入n和m:");
    scanf("%d%d",&n,&m);
    printf("请输入nums1的%d个值：\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums1[i]);
    }
    printf("请输入nums2的%d个值：\n",m);
    for(int i=0;i<m;i++){
        scanf("%d",&nums2[i]);
    }
    
    //不再另外定义新的数组，直接将结果放在nums1里面
    int index1=n-1,index2=m-1;
    int length = m+n-1;
    
    while (index1>=0 && index2>=0) {
        if(nums1[index1]>nums2[index2]){
            nums1[length--]=nums1[index1--];
        }else{
            nums1[length--]=nums2[index2--];
        }
    }
    
    while (index2>=0) {
        nums1[length--]=nums2[index2--];
    }
    
    //这里就没有必要再单独考虑nums1还没排完的情况了，本身它们就在自己该在的位置了
//    while (index1>=0) {
//        nums1[length--]=nums1[index1--];
//    }
    
    for(int i=0;i<m+n;i++){
        printf("%d ",nums1[i]);
    }
    printf("\n");
    
    return 0;
}
