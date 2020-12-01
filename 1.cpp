#include<bits/stdc++.h>

using namespace std;

int n;
long long f[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	f[0]=1;
	int tmp=0;
	for(int i=0;tmp=(1<<i),tmp<=n;i++){
		for(int j=0;j<=n;j++){
			if(j>=tmp)
				f[j]=(f[j]+f[j-tmp])%1000000007;
		}
	}
	printf("%lld",f[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
