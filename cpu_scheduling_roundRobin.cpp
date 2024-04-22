#include<iostream>
#include<queue>
using namespace std;
struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int remaining_burst_time;
};

bool arrivaltime( process p1, process p2)
{
    return p1.arrival_time<p2.arrival_time;
}
int main()
{

    struct process p[100];

    int n,time_quantum,remaining_burst_time[100];
    cout<<"enter number of process : ";
    cin>>n;


    cout<<"enter the arrival time for process : "<<endl;
    for(int i=0;i<n;i++)
    {
        
        cin>>p[i].arrival_time;
       
        p[i].pid=i+1;

    }
  cout<<"enter the burst time for process : "<<endl;
for(int i=0;i<n;i++)
    {
        cin>>p[i].burst_time;
        p[i].remaining_burst_time=p[i].burst_time;

    }
     
    cout<<"enter the time quantum :";
    cin>>time_quantum;

    int completed=0;
    int visited[100]={0};
    int current_time=0;

sort(p,p+n,arrivaltime);


    queue<int>q;
  
    q.push(0);

    visited[0]=1;


    while(completed!=n)
    {
        int index=q.front();

        q.pop();

        if(p[index].burst_time==p[index].remaining_burst_time)
        {
            //it means 
            current_time=max(current_time,p[index].arrival_time);
        }

        if(p[index].remaining_burst_time<=time_quantum)
        {
            current_time=current_time+p[index].remaining_burst_time;
            p[index].completion_time=current_time;
            p[index].turn_around_time=p[index].completion_time-p[index].arrival_time;
            p[index].waiting_time=p[index].turn_around_time-p[index].burst_time;
            completed++;
            p[index].remaining_burst_time=0;

            cout<<" completition time of process : "<<index+1<< " : "<<p[index].completion_time<<endl;
            cout<<" waiting time of process : "<<index+1<< " : "<<p[index].waiting_time<<endl;

        }
        else
        {

            current_time=current_time+time_quantum;
            p[index].remaining_burst_time=p[index].remaining_burst_time-time_quantum;
        }


        for(int i=1;i<n;i++)
        {
            if(p[i].arrival_time<=current_time && p[i].remaining_burst_time>0 && visited[i]==0)
            {
                q.push(i);
                visited[i]=1;
            }
        }

        if(p[index].remaining_burst_time>0)
        {
            q.push(index);
        }


        //this will happen when there is a process whose arrival time is not yet come 
        if(q.empty())
        {
            for(int i=1;i<n;i++)
        {
            if(p[i].remaining_burst_time>0)
            {
                q.push(i);
                visited[i]=1;
                break;
            }
        }
        }
    }


    int total_turnAroundTime=0;
    int total_waitingTime=0;


    float avg_turnAroundTime;
    float avg_waitingTime;



    for(int i=0;i<n;i++)
    {
        cout<<"process :  "<<(i+1) << " : "<<p[i].completion_time<<endl;
    }

    for(int i=0;i<n;i++)
    {
        total_turnAroundTime=total_turnAroundTime+p[i].turn_around_time;
        total_waitingTime=total_waitingTime+p[i].waiting_time;
    }


         avg_turnAroundTime=float(total_turnAroundTime)/n;
         avg_waitingTime=float(total_waitingTime)/n;


cout<<"average turn Around time "<<avg_turnAroundTime<<endl;
cout<<"average waiting time "<<avg_waitingTime<<endl;

    return 0;
}