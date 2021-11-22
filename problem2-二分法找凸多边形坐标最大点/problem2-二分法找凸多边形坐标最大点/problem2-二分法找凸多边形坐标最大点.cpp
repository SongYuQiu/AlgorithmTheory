//
//  main.cpp
//  problem2-二分法找凸多边形坐标最大点
//
//  Created by JustforStar on 2021/11/22.
//

#include <iostream>

int main() {
    //定义坐标
    int v[8][2]={
        {0,0},{1,-1},{2,-2},{3,0},{4,1},{3,2},{2,1},{1,1}
    };
    
    int maxX,maxY;
    
    //找最大的x
    int left=0;
    int right=7;
    
    while(left<right){
        int middle = (left+right)/2;
        if(v[middle][0]>v[middle+1][0]){
            right = middle;
        }else{
            left = middle+1;
        }
    }
    maxX = right;
    
    //找最大的y
    left = right;
    right = 7;
    while (left<right) {
        int middle = (left+right)/2;
        if(v[middle][1]>v[middle+1][1]){
            right = middle;
        }else{
            left = middle+1;
        }
    }
    maxY = right;
    
    printf("x最大的坐标为：(%d,%d)\n",v[maxX][0],v[maxX][1]);
    printf("y最大的坐标为：(%d,%d)\n",v[maxY][0],v[maxY][1]);
    
    return 0;
}
