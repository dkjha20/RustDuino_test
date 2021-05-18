#include<stdio.h>
#include<Windows.h>

int main()
{
    // Using the systemtime structure for getting the time
    SYSTEMTIME str_t;
    char s[100];
    int n,age;
    printf("What is your name ?\n");
    gets(s);
    printf("Hello, %s !\n",s);
    printf("What year were you born?\n");
    scanf("%d",&n);
    // This will scrap time from your system
    GetSystemTime(&str_t);
    // wYear is the element containing the current year
    age = (str_t.wYear) - n;
    printf("Congratulations, you are %d old !",age);
    return 0;
}
