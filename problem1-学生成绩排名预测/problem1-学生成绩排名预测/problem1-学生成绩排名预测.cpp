//
//  main.cpp
//  problem1-学生成绩排名预测
//
//  Created by JustforStar on 2021/11/22.
//

#include <iostream>

int main() {
    int Bool[6]={0};
    int a,b,c,d;
    for(int i=1;i<5;i++){
        a=i;
        for(int j=1;j<5;j++){
            b=j;
            for(int k=1;k<5;k++){
                c=k;
                for(int l=1;l<5;l++){
                    d=l;
                    if(a==1){ Bool[0]=1; } else{ Bool[0]=0; }
                    if(b==3){ Bool[1]=1; } else{ Bool[1]=0; }
                    if(c==1){ Bool[2]=1; } else{ Bool[2]=0; }
                    if(d==4){ Bool[3]=1; } else{ Bool[3]=0; }
                    if(d==2){ Bool[4]=1; } else{ Bool[4]=0; }
                    if(a==3){ Bool[5]=1; } else{ Bool[5]=0; }
                    if((Bool[0]+Bool[1]==1) && (Bool[2]+Bool[3]==1) && (Bool[4]+Bool[5]==1)
                       && a!=b && a!=c && a!=d && b!=c && b!=d && c!=d){
                        printf("A是第%d名;\nB是第%d名;\nC是第%d名;\nD是第%d名。\n",a,b,c,d);
                        return 0;
                    }
                }
            }
        }
    }
}
