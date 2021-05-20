#include<stdio.h>
void displayinwords(long n)
{
 const char words[34][15] = {" zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety","hundred","thousand","million","billion","trillion","quadrillion"};                        
 long temp,i,count=0,ncount;
 char result[100] = "\0";
 if(n<0)
    {
     printf(" negative");
     n*=-1;
    } 
 for(temp=n;temp>0;temp/=10,count++);
 if(!count)
    {
     printf("%s",words[0]);
     return;
    }
 ncount=(count%3==2)?count+1:(count%3==1)?count+2:count;
 int arr[ncount];
 for(i=0,temp=n;i<count;i++,temp/=10,arr[ncount-1-i]=temp%10); 
 for(i=count;i<ncount;i++,arr[ncount-i-1]=0);  
 for(i=0;i<count;i+=3)
    {
     if(arr[i]!=0)
        printf(" %s %s",words[arr[i]],words[28]);
     if(arr[i+1]==1)
        printf(" %s",words[arr[i+1]*10+arr[i+2]]);
     else if(arr[i+1]!=0)
        printf(" %s",words[arr[i+1]+18]);
     if(arr[i+2]!=0 && arr[i+1]!=1)
        printf(" %s",words[arr[i+2]]);
     if((ncount/3-(i/3)>1)&&(!(arr[i]==0&&arr[i+1]==0&&arr[i+2]==0)))   
        printf(" %s",words[27+ncount/3-(i/3)]);
    }
}
void main()
{
 long i=1;
 printf("\nEnter number: ");
 scanf("%ld",&i);
 displayinwords(i);
}
