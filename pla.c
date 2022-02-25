#include <stdlib.h>
#include <stdio.h>
double *W;
int len,level;
double Pow(double base,int x){
    double b=base,ans=1;
    while(x){
        if(x%2)ans*=b;
        b*=b;
        x>>=1;
    }
    return ans;
}
int Sig(int level){
    return level*(level+1)/2;
}
int check(double x,double y){
    double flag=W[0]+W[1]*x+W[2]*y;
    int l,r;
    for(int j=2;j<=level;++j){
        l=Sig(j);r=l+j;
        for(int k=l;k<=r;++k)flag+=Pow(x,k-l)*Pow(y,j-k+l)*W[k];
    }
    if(flag>=0)return 1;
    return 0;
}
int main(){
    int n,l,r;
    level=5;
    len=(level+2)*(level+1)/2;

    double **X,flag,delta,L,R;
    scanf("%lf %lf %lf %d",&delta,&L,&R,&n);
    X=(double**)malloc(sizeof(double*)*n);
    W=(double*)malloc(sizeof(double)*(len+1));
    for(int i=0;i<len;++i)W[i]=0;
    for(int i=0;i<n;++i){
        X[i]=(double*)malloc(sizeof(double)*(len+1));
        X[i][0]=1;
        scanf("%lf %lf %lf",X[i]+1,X[i]+2,X[i]+len);
        //printf("%lf %lf %lf\n",X[i][1],X[i][2],X[i][len]);
        for(int j=2;j<=level;++j){
            l=Sig(j);r=l+j;
            for(int k=l;k<=r;++k)X[i][k]=Pow(X[i][1],k-l)*Pow(X[i][2],j-k+l);
        }
    }
    double c;
    for(int i=1;i<=1000000;++i){
        c=0;
        for(int j=0;j<n;++j){
            flag=0;
            for(int k=0;k<len;++k)flag+=W[k]*X[j][k];
            if(flag*X[j][len]>0)continue;
            c+=1;
            for(int k=0;k<len;++k)W[k]+=X[j][k]*X[j][len];
        }
        if((c/n)<0.001)break;
    }
    char *buf=(char*)malloc(sizeof(char)*((int)((R-L)/delta)+2)*2);
    printf("input position:");
    for(int i=0;i<((int)((R-L)/delta)+1);++i){
        gets(buf);
        printf("%s\n",buf);
    }
    printf("\n\n");
    printf("output position:\n");
    for(double i=R;i>=L;i-=delta){
        for(double j=L;j<=R;j+=delta){
            if(check(j,i))printf("O ");
            else printf(". ");
        }
        printf("\n");
    }
    return 0;
}
