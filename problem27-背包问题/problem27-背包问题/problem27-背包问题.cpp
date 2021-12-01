//
//  main.cpp
//  problem27-背包问题
//
//  Created by JustforStar on 2021/12/1.
//

#include <iostream>

// 冒泡排序
void Sort(int n,float *w,float*v){
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if( (v[j]/w[j]) < (v[j+1]/w[j+1]) ){
                int tempw = w[j];
                int tempv = v[j];
                w[j] = w[j+1];
                v[j] = v[j+1];
                w[j+1] = tempw;
                v[j+1] = tempv;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    float w[1000],v[1000],x[1000]={0},C,res=0;
    int n;
    
    printf("请输入物品的种类n：");
    scanf("%d",&n);
    printf("请输入背包的容量C：");
    scanf("%f",&C);
    
    printf("请输入%d个物品的重量：",n);
    for (int i=0; i<n; i++) {
        scanf("%f",&w[i]);
    }
    printf("请输入%d个物品的价值：",n);
    for (int i=0; i<n; i++) {
        scanf("%f",&v[i]);
    }
    
    //按照物品的含金量进行排序
    Sort(n, w, v);
    
    for(int i=0;i<n;i++){
        if(C>=w[i]){
            res+=v[i];
            x[i]=w[i];
            C=C-w[i];
        }else{
            res+=C*v[i]/w[i];
            x[i]=C;
            C=0;
            break;
        }
    }
    
    printf("背包总价值为%f\n",res);
    for(int i=0;i<n;i++){
        printf("价值%.1f，重量%.1f的物品存入背包%.1f\n",v[i],w[i],x[i]);
    }
    
    return 0;
}
