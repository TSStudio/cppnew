#include<bits/stdc++.h>
#pragma GCC optimize(2)

using namespace std;
 
int n,a[50005],dp[50005],ans;
 
int main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
        	if(a[i]==a[j]+1)
				dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    printf("%d\n",n-ans);
    return 0;
}
