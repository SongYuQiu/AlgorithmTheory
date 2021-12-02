//
//  main.cpp
//  problem38-数字全排列
//
//  Created by JustforStar on 2021/12/2.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int nums[1000],p[1000],hashTable[1000],len=0;

void Nq(int index){
    if(index==len){
        for(int i=0;i<len;i++){
            printf("%d",p[i]);
        }
        printf(" ");
        return;
    }
    for(int i=0;i<len;i++){
        if(hashTable[i]==0){
            hashTable[i]=1;
            p[index]=nums[i];
            Nq(index+1);
            hashTable[i]=0;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    printf("Input:");
    scanf("%d",&nums[0]);
    len++;
    printf("Insert:");
    
    while (scanf("%d",&nums[len]) && nums[len]!=-1) {
        len++;
        memset(hashTable,0,sizeof(hashTable));
        memset(p, -1, sizeof(p));
        sort(nums,nums+len);
        Nq(0);
        printf("\nInsert:");
    }
    
    return 0;
}
