#include <iostream>
#include <vector>
#define SMALLEST -999999
using namespace std;
class Result
{
public:
int i,j;
int max_val;
Result()
    {   i=j=-1;
        max_val=SMALLEST;
    }
};
Result maximumCrossOver(vector<int>&Array,int l ,int r)
{
    Result result;
    int left_max=SMALLEST;
    int right_max=SMALLEST;
    int sum=0;
    int mid = (l+r)/2;

    for(int i=mid;i>=l;i--)
    {
        sum+=Array[i];
        if(sum>left_max)
        {
            left_max=sum;
            result.i=i;
        }
    }
    sum=0;
    for(int j=mid+1;j<=r;j++)
    {
        sum+=Array[j];
        if(sum>right_max)
        {
            right_max=sum;
            result.j=j;
        }
    }
result.max_val=left_max+right_max;
return result;
}

Result maximumSubArray(vector<int>&Array,int l,int r)
{
    Result result;
    Result Left,Right,Middle;
    if(l==r)
    {
        result.max_val=Array[l];
        result.i=l;
        result.j=r;
        return result;
    }
    int mid = (l+r)/2;
    Left = maximumSubArray(Array,l,mid);
    Right= maximumSubArray(Array,mid+1,r);
    Middle= maximumCrossOver(Array,l,r);
    if(Left.max_val>Right.max_val && Left.max_val>Middle.max_val) return Left;
    else if (Right.max_val>Left.max_val && Right.max_val>Middle.max_val) return Right;
    else return Middle;
}

int main()
{
 Result R;
 int n;
 cout<<"Size:";
 cin>>n;
 vector<int>Array(n);
 for(int i =0;i<n;i++)
 {
   cin>>Array[i];
 }
R=maximumSubArray(Array,0,n-1);
cout<<"SubArray is : [ ";
while(R.i<=R.j)
{
    cout<<Array[R.i]<<" ";
    R.i++;
}
cout<<" ]";
cout<<"\n Max Sum is : "<<R.max_val;
return 0;
}
