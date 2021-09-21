#include <stdio.h>
#include <string.h>
# define MAX 5000
 char num[MAX][MAX] , result[MAX], store[MAX];

 char* sum(char s1[],char s2[]){
   int l1=strlen(s1),l2=strlen(s2),minlen,maxlen,i,j,k;
   if (l1>l2)
    minlen=l2,maxlen=l1;
    else
    minlen =l1, maxlen =l2;
     int carry=0;
     for (k=0,i=l1-1,j=l2-1;k<minlen;k++,i--,j--){
       int val= (s1[i]-'0')+(s2[j]-'0')+carry;
       result[k]=(val%10) +'0';
       carry=val/10;
     }
     while(k<l1){

        int val = s1[i] - '0' + carry;
        result[k] = (val % 10) + '0';
        carry = val / 10;

        k++; i--;
     }
     while (k < l2){
        int val = s2[j] - '0' + carry;
        result[k] = (val % 10) + '0';
        carry = val / 10;

        k++; j--;

     }
     if (carry >0){
       result[maxlen]=carry +'0';
       maxlen++;
       result[maxlen]='\0';
     }
     else
    {
        result[maxlen] = '\0';
    }
    i=0;
    while (result[--maxlen])
    {
        store[i++] = result[maxlen];
    }
    store[i] = '\0';
    return store;
 }
 void fib(){
   num[0][0]='0';
   num[0][1]='\0';
   num[1][0]='1';
   num[1][1]='\0';
   for (int i=2;i<=MAX;i++)
    strcpy(num[i],sum(num[i-1],num[i-2]));
 }
   int main (){
     int n;
     fib();
     scanf("%d",&n);
     printf("%s",num[n]);
     return 0;
   }
