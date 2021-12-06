//
//  main.cpp
//  problem68-删除指定个数使得保留的数最小
//
//  Created by JustforStar on 2021/12/6.
//

#include <iostream>

int nums[100];

int saveTonums(int n){
    
    memset(nums, 0, sizeof(nums));
    int len=1,length;
    int temp=n;
    while(temp/10){
        len++;
        temp/=10;
    }
    
    length=len;
    
    while (len--) {
        nums[len]=n%10;
        n/=10;
    }
    
    return length;
}


int main(int argc, const char * argv[]) {
    int n,s;
    printf("请输入n的值：");
    scanf("%d",&n);
    
    printf("请输入s的值：");
    scanf("%d",&s);
    
    
    int length = saveTonums(n);
    int finalLen = length-s;
    
    while(s--){
        for(int i=0;i<length;i++){
            if(nums[i]>nums[i+1]){
                for(int j=i;j<length-1;j++){
                    nums[j]=nums[j+1];
                }
                break;
            }
        }
        length--;
    }

    for(int i=0;i<finalLen;i++){
        printf("%d",nums[i]);
    }
    printf("\n");
    
    return 0;
}
