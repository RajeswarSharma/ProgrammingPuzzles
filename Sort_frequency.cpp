#include <iostream>

using namespace std;
/*
insertion sort
*/
void Sort(int *arr,int n)
{
 int temp;
 int j;
 for(int i =1 ;i<n;i++)
 {
     j=i-1;
     temp=arr[i];
     while(temp<arr[j]&&j>=0)
     {
         arr[j+1]=arr[j];
         j--;
     }
 arr[j+1]=temp;
 }

}
/*
void Sort2D() sort the 2D array on the bases of frequency low to high using insertion sort.
*/
void Sort2D(int arr[][2],int n)
{
    int temp,element;
    int j;
    for(int i =1;i<n;i++)
    {
        j=i-1;
        temp=arr[i][1];
        element=arr[i][0];
        while(j>=0&&temp<arr[j][1])
        {
            arr[j+1][0]=arr[j][0];
            arr[j+1][1]=arr[j][1];
            j--;
        }
    arr[j+1][1]=temp;
    arr[j+1][0]=element;
    }
}
int main()
{
int A[100],Size;
int tempArray[100][2],tcounter=0;
int temp;
int counter=0;

cout<<"Size :"; cin>>Size;
for(int i =0;i<Size;i++)
    {
    cin>>A[i];
    }
Sort(A,Size);
int j;
//creating 2D array to hold element and its frequency.
for(int i=0;i<Size;i++)
{
    temp=A[i];
    counter=1;
    j=i+1;
    while(j<Size)
    {
        if(temp==A[j])
        {
            counter++;
            j++;
            i++;
        }
        else break;
    }
tempArray[tcounter][0]=temp; // saving the element
tempArray[tcounter++][1]=counter; //saving the frequency
}

temp=0;//reseting temp value to  reuse it as counter for A[]

Sort2D(tempArray,tcounter); //sorting

for(int i =0;i<tcounter;i++) // Converting 2D Array back to simple array.
{
    for(int j=0;j<tempArray[i][1];j++)
        {
        A[temp++]=tempArray[i][0];
        }
}

for(int i=0;i<Size;i++) //printing
    {
        cout<<A[i]<<"   ";
    }
    return 0;
}
