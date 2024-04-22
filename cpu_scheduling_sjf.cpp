#include<iostream>
using namespace std;
struct process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
};
int main()
{

    int n;
    cout<<"enter the number of processes : ";
    cin>>n;

     process p[n];

    cout<<"enter arrival time "<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>p[i].arrivalTime;
    }
     cout<<"enter burst  time "<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>p[i].burstTime;
        p[i].pid=i+1;
    }


    int completed=0;
    int visited[n];

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }

    int currentTime=0;
    int totaltat=0;
    int totalwt=0;
    while(completed!=n)
    {

        int minBurstTime=99999;
        int index=-1;
        for(int i=0;i<n;i++)
        {
            if(p[i].arrivalTime<=currentTime && visited[i]==0)
            {
                    if(p[i].burstTime<minBurstTime)
                    {
                        minBurstTime=p[i].burstTime;
                        index=i;
                    }
            }
        }

        if(index!=-1)
        {
            p[index].completionTime=currentTime+p[index].burstTime;
            p[index].turnAroundTime=p[index].completionTime-p[index].arrivalTime;
            p[index].waitingTime=p[index].turnAroundTime-p[index].burstTime;

            totaltat=totaltat+p[index].turnAroundTime;
            totalwt=totalwt+p[index].waitingTime;

            visited[index]=1;

            completed++;
            currentTime=p[index].completionTime;
        }
        else
        {
            currentTime++;
        }
    }


    

    cout<<"avg turn at : "<<float(totaltat)/n<<endl;
    cout<<"avg wait at : "<<float(totalwt)/n<<endl;
    

    return 0;
}