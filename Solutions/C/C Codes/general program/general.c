# include<stdio.h>
int main(){
     int km,m,feet,inch,cm;
     printf("enter the distance in km/n");
     scanf("%d",&km);
     m=km*1000;
     cm=m*100;
     inch=cm/2.54;
     feet=inch/12;
     printf("the value in m=%d",m);
     printf("the value in cm=%d",cm);
     printf("the value in incha=%d",inch);
     printf("the value in feet =%d",feet);

    return 0;
}