#include<iostream>
#include<vector>
//#include<bits/stdc++.h> 
using namespace std;
#define lowbit(x) x&-x
 vector<long long> a;//原数组
 vector<long long> c;//树状数组（不同于线段树，不用开4倍空间）
int n,q;
void fix(int x,int k)//第x个数加上k
{
   for(int i=x;i<=n;i+=lowbit(i)){
      c[i]+=k;
   }
}
long long ask(int x){//返回1到x的和
    long long ans=0;
    for(int i=x;i>=1;i-=lowbit(i)){
          ans+=c[i];
    }
    return ans;  
}
int main(){
    
    cin>>n>>q;
    a=vector<long long>(n+1,0);//原数组
    c=vector<long long>(n+1,0);//树状数组（不同于线段树，不用开4倍空间）
    for(int i=1;i<=n;i++){
        cin>>a[i];//输入原数组
    }
    for(int i=1;i<=n;i++){
        fix(i,a[i]);
    }
    while(q--){//进行q个查询
    int opera;
    cin>>opera;
    if(opera==1){//修改操作
       int x,k;//第x个数加上k
       cin>>x>>k;
       fix(x,k);
    }else if(opera==2){
        int x,y;//求区间[x,y]的和
        cin>>x>>y;
        cout<<ask(y)-ask(x-1)<<endl;
    }

    }
    getchar();//要加两个才能暂停住
    getchar();
    return 0;
}