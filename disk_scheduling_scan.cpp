#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int arr[]={1,3,4,6,8,94,3,12,23,4,56,79,87,12,34,5,6,7,9};
    int n=sizeof(arr)/4;   
    int head=2;
    string direction="right";
    sort(arr,arr+n);

    vector<int>left,right;
    vector<int>seekSeq;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<head)
        {
            
            left.push_back(arr[i]);
            
        }
        else
        {
            right.push_back(arr[i]);
        }
    }
    int sum=0;
    if(direction=="left")
    {
        
        left.insert(left.begin(),0);
        for(int i=left.size()-1;i>=0;i--)
        {
            sum=sum+abs(left[i]-head);
            head=left[i];
            seekSeq.push_back(head);

        }

        for(int i=0;i<right.size();i++)
        {         
            sum=sum+abs(right[i]-head);
            head=right[i];
            seekSeq.push_back(head);


        }
    }
    else
    {
        right.push_back(199);
        for(int i=0;i<right.size();i++)
        {
            
            sum=sum+abs(right[i]-head);
            head=right[i];
            seekSeq.push_back(head);
            
        }

        for(int i=left.size()-1;i>=0;i--)
        {  
            sum=sum+abs(left[i]-head);
            head=left[i];
            seekSeq.push_back(head);

        }
    }

    cout<<"total seek count : "<<sum<<endl;

    for(auto it=seekSeq.begin();it!=seekSeq.end();it++)
    {
        cout<<*it<<" ";
    }



    return 0;
}