#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//对heap数组在[low,high]范围进行调整
//其中low为欲调整节点的数组下标
void downAdjust(vector<int>& b,int low,int high){
    int i=low,j=2*i;
    while(j<=high){ //存在孩子节点
        //如果右孩子存在，且右孩子的值大于左孩子
        if(j+1<=high && b[j]<b[j+1] ) j=j+1; //这一步的作用在于确保父亲始终与孩子中较大的相比较
        if(b[i]>=b[j]) break;
        swap(b[i],b[j]);
        i=j; j=2*i; //进入下一层
    }
}

int main(){
    int n,p=2;
    scanf("%d",&n);
    vector<int> origin(n+1),temp(n+1);
    for(int i=1;i<=n;i++) scanf("%d",&origin[i]);
    for(int i=1;i<=n;i++) scanf("%d",&temp[i]);

    while(p<=n && temp[p-1]<=temp[p]) p++; 
    int index=p;
    while(p<=n && origin[p]==temp[p]) p++;
    if(p==n+1){
        printf("Insertion Sort\n");
        sort(temp.begin()+1,temp.begin()+1+index);
    }else{
        printf("Heap Sort\n");
        p=n;
        while(p>2 && temp[p]>=temp[1]) p--;
        swap(temp[1],temp[p]);
        downAdjust(temp,1,p-1);
    }
    printf("%d",temp[1]);
    for(int i=2;i<=n;i++) 
        printf(" %d",temp[i]);
    return 0;
}
