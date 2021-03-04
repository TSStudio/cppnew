#include<cstdio>
#include<vector>
#include<map>
#define _GLIBCXX_USE_INT128
const int maxN=1e5+5;

typedef unsigned long long ulll;
struct frac{
    ulll nu,de;
    ulll gcd(ulll a,ulll b){
        while(b^=a^=b^=a%=b);
        return a;
    }
    void hj(){
        ulll h=gcd(nu,de);
        nu/=h,de/=h;
    }
    frac operator*(frac T){
        frac S=copy();
        T.hj();
        S.hj();
        ulll h=gcd(S.nu,T.de);
        S.nu/=h,T.de/=h;
        h=gcd(T.nu,S.de);
        T.nu/=h,S.de/=h;
        return frac{T.nu*S.nu,T.de*S.de};
    }
    frac operator+(frac T){
        frac S=copy(),temp;
        temp.de=S.de/gcd(S.de,T.de)*T.de;
        temp.nu+=S.nu*(temp.de/S.de);
        temp.nu+=T.nu*(temp.de/T.de);
        temp.hj();
        return temp;
    }
    frac copy(){
        return frac{nu,de};
    }
};

bool isOut[maxN];
std::vector<int> edge[maxN];
std::vector<frac> out;
std::map<int,int> mp;//表示i号结点对应的出水量为out[mp[i]]
void dfs(int st,frac val){
    if(isOut[st]){out[mp[st]]=out[mp[st]]+val;return;}
    int x=edge[st].size();
    for(int i=0;i<x;i++) dfs(edge[st][i],val*frac{1,x});
}
int main(){
    int n,m,cnt;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        if(t==0){
            isOut[i]=true;
            mp[i]=cnt++;
            out.push_back(frac{0,1});
        }else{
            for(int j=0;j<t;j++){
                int s;
                scanf("%d",&s);
                edge[i].push_back(s);
            }
        }
    }
    for(int i=1;i<=m;i++){
        dfs(i,frac{1,1});
    }
    for(int i=0;i<cnt;i++){
        printf("%llu %llu\n",out[i].nu,out[i].de);
    }
}