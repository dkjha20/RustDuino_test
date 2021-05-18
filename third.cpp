#include<bits/stdc++.h>
using namespace std;
         
void dkj()            // This function is just for fast input-output operations
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
               
   #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
   #endif
}
         
int main()
{
    vector <char> a;
    char sign[2];
    int ans,num[3],i=0,j=0,sup_flag=1;
    char ch[100];   gets(ch);

    for(int t=0;t<strlen(ch);t++) {
       if(ch[t]=='+' || ch[t]=='-' || ch[t]=='*' || ch[t]=='/' || t==strlen(ch)-1) {
              if(t==strlen(ch)-1) { a.push_back(ch[t]); }
              else { sign[i]=ch[t];  i++; } 
              
              int p=0;
              for(int k=a.size()-1;k>-1;k--) {
                   int x = a[k]-'0';
                   p = p+(pow(10,(a.size()-k-1))*x);
              }
              
              num[j]=p; 
              if(!(num[j]>=0 && num[j]<=1000)) sup_flag=0;
              j++;
              a.clear();
       }
      else {  a.push_back(ch[t]);  }
    }

    if(sup_flag!=0)  { cout<<(num[0]+num[1]+num[2]); }
    else cout<<-1;

    return 0;
}
