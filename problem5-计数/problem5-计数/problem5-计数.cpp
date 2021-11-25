//
//  main.cpp
//  problem5-计数
//
//  Created by JustforStar on 2021/11/23.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int nums[1000];
    int n,m;
    
    while (scanf("%d",&n)!=EOF) {
        printf("请输入数组的%d个数字:",n);
        for(int i=0;i<n;i++){
            scanf("%d",&nums[i]);
        }
        printf("请输入要查找的数字m:");
        scanf("%d",&m);
        
        int left=0, right=n-1;
        int indexL,indexR;
        
        while (left<right) {
            int middle = (left+right)/2;
            if(nums[middle]>=m){
                right=middle;
            }else{
                left=middle+1;
            }
        }
        indexL = left;
        
        left=0;
        right=n-1;
        while (left<right) {
            int middle = (left+right)/2;
            if(nums[middle]<=m){
                left=middle;
            }else{
                right=middle-1;
            }
        }
        indexR = right;
        
        printf("indexL:%d;indexR:%d;count:%d\n",indexL,indexR,indexR-indexL+1);
    }    
    return 0;
}
