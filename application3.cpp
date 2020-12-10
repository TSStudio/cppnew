#include<cstdio>
#include<cmath>

#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

double amount[50];
int main(){
    freopen("3.out","w",stdout);
    unsigned long long n;
    double targ,epis;
    unsigned long long status=0;
    unsigned long long max=0,count=0;
    scanf("%d%lf%lf",&n,&targ,&epis);
    max=(1LL<<(n-2))+(1LL<<(n-1));
    for(int i=0;i<n;i++)scanf("%lf",&amount[i]);
    printf("N:%d,MAX:%llu\n",n,max);
    for(status=(1LL<<(n-1));status<max;status++,count++){
        if(count%10000000==0){
            printf("Process: %.6lf%% (%llu)\n",status*100.0/max,status);
        }
        double sum=0;
        for(int i=0;i<n;i++){
            if((status>>i)&1){
                sum+=amount[i];
            }
        }
        if(sum>targ+epis){
            printf("OVERSIZE,OPTIMIZING,CURRENT:%llu\n",status);
            for(int i=n+1;i>=0;i--){
                if((status>>i)&1){
                    status=1LL<<(i+1);
                    printf("OPTIMIZED TO:%llu\n",status);
                    break;
                }
            }
            continue;
        }
        //printf("RESULT : %.2lf\n",sum);
        if(fabs(sum-targ)<=epis){
            printf("POSSIBLE FOUND. %llu RESULT : %.2lf\n",status,sum);
        }
    }
}