/*Alice and Bob are best friends. They decided to play a game named 'remainder_count'. Rule of game is that Alice gave Bob a number N and if Bob wants to win he has to find the number of distinct remainder when N is divided by all the numbers from 1 to N

Help Bob in finding the number of Distincts remainders.

Input Format

First line contains an integer T denoting the number of test cases . Next Line contains N denoting the Number Alice gave to Bob .

Constraints

1 ≤ T ≤ 10^5
1 ≤ N ≤ 10^12*/
/*************************************************************************************************/
#include <iostream>

using namespace std;


int main() {
    long int T,temp;
    long long N;
    cout<<"Enter the number of tests\n";
    cin>>T;
    while(T>0)
    { cout<<"Enter the number \n";
        cin>>N;
        if(N%2==0) cout<<(N/2)<<endl;
        else cout<<(1+N/2)<<endl;
        T--;
    }
    return 0;
}
