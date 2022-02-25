#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    int n=0,p=0;
    char *output=(char*)malloc(sizeof(char)*1000000),buf[100];
    double s=0.5;
    printf("%lf %lf %lf\n",s,-10.0,10.0);
    int buf2[(int)(20/s+1)][(int)(20/s+1)];
    for(double x=-10;x<=10;x+=s){
        for(double y=-10;y<=10;y+=s){
            double a=((x-4)*(x-4)+(y-4)*(y-4))<=7||((x+4)*(x+4)+(y+4)*(y+4))<=7||((x-4)*(x-4)+(y+4)*(y+4))<=7,b=((x+y)>=0),c=(x*x-y>=0),d=(x*x+y*y-25<=0);
            if((rand()%2)){
                if(d){
                    buf2[(int)((y+10)/s)][(int)((x+10)/s)]=1;
                    sprintf(buf,"%lf %lf 1\n",x,y);
                    sprintf(output+p,"%lf %lf 1\n",x,y);
                    p+=strlen(buf);
                }
                else{
                    buf2[(int)((y+10)/s)][(int)((x+10)/s)]=-1;
                    sprintf(buf,"%lf %lf -1\n",x,y);
                    sprintf(output+p,"%lf %lf -1\n",x,y);
                    p+=strlen(buf);
                }
                ++n;
            }
            else buf2[(int)((y+10)/s)][(int)((x+10)/s)]=0;
        }
    }
    printf("%d\n%s",n,output);
    for(double y=10;y>=-10;y-=s){
        for(double x=-10;x<=10;x+=s){
            int h=(int)((x+10)/s),m=(int)((y+10)/s);
            if(buf2[m][h]==1)printf("O ");
            else if(buf2[m][h]==0) printf("  ");
            else printf(". ");
        }
        printf("\n");
    }
}
