#include<stdio.h>
#include<math.h>
main(){
    double a,v,l,d,w,an;
    scanf("%lf%lf%lf%lf%lf",&a,&v,&l,&d,&w);
    if(w>v)w=v;
    if(w*w/(2*a)>=d){
        if(v*v/(2*a)<=l)printf("%.9lf\n",v/a+(l-v*v/(2*a))/v);
        else printf("%.9lf\n",sqrt(2*l/a));
    }
    else{
        an=w/a;
        l-=d;
        d-=w*w/(2*a);
        if((v-w)/a*(v+w)<=d){
            an+=(v-w)/a*2;
            d-=(v-w)/a*(v+w);
            an+=d/v;
        }
        else{
            an+=2*(sqrt(w*w+a*d)-w)/a;
        }
        if((w+v)*(v-w)/(2*a)<=l){
            an+=(v-w)/a;
            l-=(w+v)*(v-w)/(2*a);
            an+=l/v;
        }
        else{
            an+=(sqrt(w*w+2*a*l)-w)/a;
        }
        printf("%.9lf\n",an);
    }
}