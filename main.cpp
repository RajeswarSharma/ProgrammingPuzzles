/*
   Written by: Rajeswar Sharma
   objective : To print the fibonacci-series and to print the missing terms which are excluded from the series.
   Note      : Size of Array "arr" must be increased in order process the larger series.
*/
#include <iostream>

using namespace std;

int main()
{
    int n,counter=0,arr[100],a=0,b=1,c=0,Beg=0,End=0;//a b and c var for swapping and storing last value of series
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<a<<" ";
        End=a;
        //swapping and storing last value
        c=b;
        b=a;
        a=b+c;
        Beg=a-End;
        for(int j=Beg+1;j<End;j++)
        arr[counter++]=j;
    }
    cout<<endl;
//Displaying Array (the missing terms)
    for(int i=0;i<counter;i++)
        cout<<arr[i]<<" ";
    return 0;
}
