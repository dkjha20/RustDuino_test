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
    vector <char> a;    // vector for storage of sub-parts of input
    char sign[2];       // array to store algebraic operations
    int ans,num[3],i=0,j=0,sup_flag=1;   // variables of use
    char ch[100];   gets(ch);            // array to store characters

    for(int t=0;t<strlen(ch);t++) {                // loop to get the numbers out of the expression in integer format
       if(ch[t]=='+' || ch[t]=='-' || ch[t]=='*' || ch[t]=='/' || t==strlen(ch)-1) {
              if(t==strlen(ch)-1) { a.push_back(ch[t]); }
              else { sign[i]=ch[t];  i++; } 
              
              int p=0;
              for(int k=a.size()-1;k>-1;k--) {
                   int x = a[k]-'0';
                   p = p+(pow(10,(a.size()-k-1))*x);
              }
              
              num[j]=p; 
              if(!(num[j]>=0 && num[j]<=1000)) sup_flag=0;   // check for numbers being in correct range
              j++;
              a.clear();
       }
      else {  a.push_back(ch[t]);  }
    }

    try {                                      // calculation of expression along with expression handling
       if(sup_flag!=0) {
           if(sign[0]=='*') {
                 if(sign[1]=='+') { cout<<(num[0]*num[1]+num[2]); }
                 else if(sign[1]=='-') { cout<<(num[0]*num[1]-num[2]); }
                 else if(sign[1]=='*') { cout<<(num[0]*num[1]*num[2]); }
                 else { 
                     if(num[2]==0) throw 1;
                     cout<<(num[0]*num[1]/num[2]);  } 
            }
            else if(sign[0]=='/') {
                 if(sign[1]=='+') { 
                     if(num[1]==0) throw 1;
                     cout<<(num[0]/num[1]+num[2]);  }
                 else if(sign[1]=='-') { 
                     if(num[1]==0) throw 1;
                     cout<<(num[0]/num[1]-num[2]); }
                 else if(sign[1]=='*') { 
                     if(num[1]==0) throw 1;
                     cout<<(num[0]/num[1]*num[2]); }
                 else { 
                     if(num[1]==0 || num[2]==0) throw 1;
                     cout<<(num[0]/num[1]/num[2]); } 
            }
            else if(sign[0]=='+') {
                 if(sign[1]=='+') { cout<<(num[0]+num[1]+num[2]); }
                 else if(sign[1]=='-') { cout<<(num[0]+num[1]-num[2]); }
                 else if(sign[1]=='*') { cout<<(num[0]+num[1]*num[2]); }
                 else { 
                     if(num[2]==0) throw 1;
                     cout<<(num[0]+num[1]/num[2]); } 
            }
            else {
                 if(sign[1]=='+') { cout<<(num[0]-num[1]+num[2]); }
                 else if(sign[1]=='-') { cout<<(num[0]-num[1]-num[2]); }
                 else if(sign[1]=='*') { cout<<(num[0]-num[1]*num[2]); }
                 else { 
                     if(num[2]==0) throw 1;
                     cout<<(num[0]-num[1]/num[2]); } 
            }
       }     
       else cout<<-1;               // in case of overflow out of range
    } 
    catch(int x) { cout<<"Exception"; }  // division by zero error

    return 0;
}
