/*
 "0:zero","1:one","2:two","3:three","4:four","5:five","6:six","7:seven","8:eight","9:nine",
 "10:ten","11:eleven","12:twelve","13:thirteen","14:fourteen","15:fifteen","16:sixteen","17:seventeen","18:eighteen","19:nineteen",
 "20:twenty","21:thirty","22:fourty","23:fifty","24:sixty","25:seventy","26:eighty","27:ninety",
 "28:hundred","29:thousand","30:million","31:billion","32:trillion","33:quadrillion"
 */
#include<stdio.h>

void displayinwords(long n)
{
 const char words[34][15] = {" zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven",
                             "twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",
                             "twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety","hundred","thousand",
                             "million","billion","trillion","quadrillion"};                        
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
 for(i=0,temp=n;i<count;i++,temp/=10)
     arr[ncount-1-i]=temp%10; 
 for(i=count;i<ncount;i++)
        arr[ncount-i-1]=0;  
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
 do{
     printf("\n Enter number (0 to exit) :");
     scanf("%ld",&i);
     displayinwords(i);
     printf("\n");
    }while(i!=0);
}
