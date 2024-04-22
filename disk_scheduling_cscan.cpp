//fsfs


#include<iostream>
#include<vector>
using namespace std;
int SIZE=200;
int main()
{
    int req;
    cout<<"enter total request : ";
    cin>>req;

    vector<int>tracks;

    cout<<"enter the tracks : ";
    int t;
    for(int i=0;i<req;i++)
    {
        cin>>t;
        tracks.push_back(t);
    }

    int head;
    cout<<"enter the initial position of head : ";
    cin>>head;

    int totalSeekCount=0;
    vector<int>seekseq;
    seekseq.push_back(head);

   
    sort(tracks.begin(),tracks.end());    


   

    
    string direction="right";


    vector<int>left;
    vector<int>right;

    for(int i=0;i<req;i++)
    {
        if(tracks[i]<head)
        {
            left.push_back(tracks[i]);
        }
        else
        {
            right.push_back(tracks[i]);
        }
    }

     left.insert(left.begin(),0);
     right.push_back(SIZE-1);


    if(direction=="right")
    {
        for(int i=0;i<right.size();i++)
        {
            totalSeekCount+=abs(head-right[i]);
            head=right[i];
            seekseq.push_back(head);
        }

        totalSeekCount+=SIZE-1;
        head=0;

        for(int i=0;i<left.size();i++)
        {
            totalSeekCount+=abs(head-left[i]);
            head=left[i];
            seekseq.push_back(head);
        }
    }
    else
    {
        for(int i=left.size()-1;i>=0;i--)
        {
            totalSeekCount+=abs(head-left[i]);
            head=left[i];
            seekseq.push_back(head);
        }

        totalSeekCount+=SIZE-1;
        head=SIZE-1;


        for(int i=right.size()-1;i>=0;i--)
        {
            totalSeekCount+=abs(head-right[i]);
            head=right[i];
            seekseq.push_back(head);
        }

    }

    





    cout<<"total seek : "<<totalSeekCount<<endl;

    for(int i=0;i<seekseq.size();i++)
    {
        cout<<seekseq[i]<< " ";
    }cout<<endl;

}