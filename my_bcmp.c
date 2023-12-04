
#include "my_bcmp.h" /*my header*/

int main()
{
    int len,b1,b2,check1,check2,answer,i;
    char c,userString[S_LEN]={'\0'};
    printf("Pleas enter the length you want to compare\n");
    check1 = scanf("%d",&len);
    printf("Pleas enter the first and second start points to compare\n");
    check2 = scanf("%d %d", &b1, &b2);
    if ((check1=0)||(check2<2)||(len<0)||(b1<0)||(b2<0))/*checking if the inmput numbers are whole and positive*/
    {
        printf("One or more of your inputs arent a positive integer");
        exit(1);
    }
    if ((len>S_LEN)||(b1>S_LEN)||(b2>S_LEN)||(b1+len>S_LEN)||(b2+len>S_LEN))/*checking if we wont overflow from the array*/
    {
        printf("One of the memory segments overflows the string boundaries");
        exit(2);
    }
    printf("Pleas enter your string, must be no more then %d char long\n",S_LEN);
    for (i=0;(i<S_LEN)&&((c=getchar())!=EOF);i++)/*loop to get the whole string includes white space*/
    {
        userString[i] = c;
    }
    printf("Your input is:\nlength: %d\nfirst start point: %d\nsecond start point: %d\nthe string: %s\n", len, b1, b2, userString);/*printing all the inputs*/
    answer = my_bcmp(&userString[b1],&userString[b2],len);/*using the fuction of the question*/
    printf("The answer of the function is %d",answer);
    return 0;
}

int my_bcmp (const void *b1, const void *b2, int len)/*we check char by char that they are equal and send 0 other wise we send 1*/
{
    char *s1 = (char*)b1;
    char *s2 = (char*)b2;
    int i;
    for (i=0;i<len;i++)
    {
        if(*(s1+i)!=*(s2+i))
         return 1;
    }
    return 0;
}

