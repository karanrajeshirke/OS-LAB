//shortest remaining time burst


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
    int remainingBurstTime;
};

int main()
{
    int n;
    cout<<"enter the number of processes : ";
    cin>>n;

    process p[n];

    cout<<"enter the arrival time : ";
    for(int i=0;i<n;i++)
    {
        cin>>p[i].arrivalTime;
        p[i].pid=i+1;
    }
    cout<<"enter the burst time : ";
     for(int i=0;i<n;i++)
    {
        cin>>p[i].burstTime;
        p[i].remainingBurstTime=p[i].burstTime;
    }


    int current=0;
    int completed=0;
    int totalTat=0;
    int totalwt=0;


    int isCompleted[n];
    int seq[n];
    for(int i=0;i<n;i++)
    {
        isCompleted[i]=0;
    }


    while(completed!=n)
    {
        int index=-1;
        int min=9999;

        for(int i=0;i<n;i++)
        {
            if(p[i].arrivalTime<=current && isCompleted[i]==0)
            {
                if(p[i].remainingBurstTime<min)
                {
                    min=p[i].remainingBurstTime;
                    index=i;
                }
                if(p[i].remainingBurstTime==min)
                {
                    if(p[i].arrivalTime<p[index].arrivalTime)
                    {
                        min=p[i].remainingBurstTime;
                        index=i;
                    }
                }
            }
        }

        if(index!=-1)
        {
            current=current+1;
            p[index].remainingBurstTime=p[index].remainingBurstTime-1;


            if(p[index].remainingBurstTime==0)
            {
                p[index].completionTime=current;
                p[index].turnAroundTime=p[index].completionTime-p[index].arrivalTime;
                p[index].waitingTime=p[index].turnAroundTime-p[index].burstTime;

                totalTat=totalTat+p[index].turnAroundTime;
                totalwt=totalwt+p[index].waitingTime;

                isCompleted[index]=1;
                completed++;

            }
        }   
        else
        {
            current++;
        }

    }


    cout<<"total turn around time : "<<float(totalTat)/n<<endl;
    cout<<"total waiting  time : "<<float(totalwt)/n<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<"P["<<p[i].pid<<"]"<<p[i].arrivalTime<<" \t "<<p[i].burstTime<<" \t "<<p[i].completionTime<<" \t "<<p[i].turnAroundTime<<" \t "<<p[i].waitingTime<<endl;
    }

    


    return 0;
}
