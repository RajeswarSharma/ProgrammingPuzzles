//using selection_sort
#include <iostream>
#include<string.h>
using namespace std;
int Size=9;
int main()
{
    char name[Size][20]={{"Olivia"},{"Amelia"},{"Isla"},{"Ava"},{"Emily"},{"Sophia"},{"Grace"},{"Mio"},{"Poppy"}};
    char temp[20];
for(int i=0;i<Size-1;i++)
{

    for(int j=i+1;j<Size;j++)
    {
        if(strcmp(name[i],name[j])>0)
        {
            strcpy(temp,name[i]);
            strcpy(name[i],name[j]);
            strcpy(name[j],temp);
        }
    }
}
    for(int i=0;i<Size;i++)
    cout<<name[i]<<endl;

    return 0;
}
