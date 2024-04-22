


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

   //shortest seek time first;
   seekseq.push_back(head);

   int completed=0;

   int isCompleted[req];
   for(int i=0;i<req;i++)
   {
        isCompleted[i]=0;
   }


   while(completed!=req)
   {
        int min=INT_MAX;
        int index=-1;
        for(int i=0;i<req;i++)  
        {
            if(abs(head-tracks[i])<min && isCompleted[i]==0)
            {
                min=abs(head-tracks[i]);
                index=i;
            }
        }

        
            totalSeekCount+=abs(head-tracks[index]);
            isCompleted[index]=1;
            completed++;
            head=tracks[index];
            seekseq.push_back(head);
        
   }

    cout<<"total seek : "<<totalSeekCount<<endl;

    for(int i=0;i<seekseq.size();i++)
    {
        cout<<seekseq[i]<< " ";
    }cout<<endl;

}