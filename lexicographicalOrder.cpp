//Using_InsertionSort
#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int Size=9;
int main()
{
char name[Size][20]={{"Olivia"},{"Amelia"},{"Isla"},{"Ava"},{"Emily"},{"Sophia"},{"Grace"},{"Mia"},{"Poppy"}};

char temp[20];
    int j=0,k;
    for(int i=1;i<Size;i++)
    {
        j=i-1;
        k=0;
        strcpy(temp,name[i]);
        while(temp[k]<name[j][k]&&j+1>=0)
        {
        if(name[j][k]==temp[k])
            {
                k++;
            }
        else
            {
            strcpy(name[j+1],name[j]);
            j--;
            k=0; //K is made zero to start new comparison after every swaping, 
            }

        }
    strcpy(name[j+1],temp);
    }

  for(int i=0;i<Size;i++)
    {
    puts(name[i]);
    cout<<endl;
    }
    return 0;
}
