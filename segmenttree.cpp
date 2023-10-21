#include<bits/stdc++.h>
using namespace std;
void segment_tree(int ind,int low ,int high,int seg[],int arr[])
{
    if(low==high)
    {
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    segment_tree(2*ind+1,low,mid,seg,arr);
    segment_tree(2*ind+2,mid+1,high,seg,arr);
    seg[ind]=min(seg[(2*ind)+1],seg[(2*ind)+2]);
}
int main()
{
    int db;
    int n;
    cin>>n;
    int arr[n];
    int seg[4*n];
    int mini=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mini=min(mini,arr[i]);
    }

    //seg[0]=mini;

    segment_tree(0,0,n-1,seg,arr);
    for(int i=0;i<4*n;i++)
    {
        cout<<seg[i]<<" ";
    }

}

