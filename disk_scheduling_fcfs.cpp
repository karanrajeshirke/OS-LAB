//fsfs


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int req;
    cout<<"enter total request : ";
    cin>>req;

    int tracks[req];

    cout<<"enter the tracks : ";
    for(int i=0;i<req;i++)
    {
        cin>>tracks[i];
    }

    int head;
    cout<<"enter the initial position of head : ";
    cin>>head;

    int totalSeekCount=0;
    vector<int>seekseq;

    seekseq.push_back(head);
    for(int i=0;i<req;i++)
    {
        totalSeekCount=totalSeekCount+abs(head-tracks[i]);
        head=tracks[i];
        seekseq.push_back(head);
    }

    cout<<"total seek : "<<totalSeekCount<<endl;

    for(int i=0;i<seekseq.size();i++)
    {
        cout<<seekseq[i]<< " ";
    }cout<<endl;

}