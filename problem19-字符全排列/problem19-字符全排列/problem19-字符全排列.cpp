//
//  main.cpp
//  problem19-字符全排列
//
//  Created by JustforStar on 2021/12/2.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

char str[1000],p[1000];
int hashTable[1000]={0},Sum=0,len;

void Npermutation(int index){
    if(index==len){
        Sum++;
        for(int i=0;i<len;i++){
            printf("%c",p[i]);
        }
        printf(" ");
        return;
    }
    for(int i=0;i<len;i++){
        if(hashTable[i]==0){
            hashTable[i]=1;
            p[index]=str[i];
            Npermutation(index+1);
            hashTable[i]=0;
        }
    }
}

int main(int argc, const char * argv[]) {
    printf("请输入字符串string：");
    scanf("%s",str);
    len = (int)strlen(str);
    sort(str, str+len);
    
    Npermutation(0);
    printf("\n总共有%d种排列。\n",Sum);
    
    return 0;
}
