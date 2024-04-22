// #include<iostream>
// using namespace std;
// struct Process
// {
//     int pid;
//     int arrivalTime;
//     int startTime;
//     int burstTime;
//     int completionTime;
//     int turnAroundTime;
//     int waitingTime;
// };

// bool arrivalTime(Process p1,Process p2)
// {
//     if(p1.arrivalTime < p2.arrivalTime)
//     {
//         return true;
//     }
//     else
//     {
//         if(p1.arrivalTime==p2.arrivalTime)
//         {
//             if(p1.pid<p2.pid)
//             {
//                 return true;
//             }
//             return false;
//         }
//     }
// }
// int main()
// {
//     int n;
//     cout<<"enter the number of process : ";
//     cin>>n;

//     struct Process p[n];
// cout<<"enter the arrival time of process "<<endl;
//     for(int i=0;i<n;i++)
//     {
        
//         cin>>p[i].arrivalTime;
//     }
// cout<<"enter the bt time of process "<<endl;

//       for(int i=0;i<n;i++)
//     {
        
//         cin>>p[i].burstTime;
//         p[i].pid=i+1;
//     }


//     sort(p,p+n,arrivalTime);


   


//     int totaltat=0;
//     int totalwt=0;
//     for(int i=0;i<n;i++)
//     {
//         if(i==0)
//         {
//             p[i].startTime=p[i].arrivalTime;
//         }
//         else
//         {
//             p[i].startTime=max(p[i].arrivalTime,p[i-1].completionTime);
//         }


//         p[i].completionTime=p[i].startTime+p[i].burstTime;
//         p[i].turnAroundTime=p[i].completionTime-p[i].arrivalTime;
//         p[i].waitingTime=p[i].turnAroundTime-p[i].burstTime;

//         totaltat=totaltat+p[i].turnAroundTime;
//         totalwt=totalwt+p[i].waitingTime;


//     }

//     cout<<"-------------"<<endl;
//  for(int i=0;i<n;i++)
//     {
//         cout<<p[i].pid<<" "<<p[i].arrivalTime<<" "<<p[i].burstTime<<" "<<p[i].completionTime<<" " <<p[i].turnAroundTime<<" " <<p[i].waitingTime<<endl;
//     }


//     cout<<"average tat : "<<float(totaltat)/n<<endl;
//     cout<<"average wt : "<<float(totalwt)/n<<endl;


//     return 0;
// }


#include<iostream>
#include<algorithm>
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

bool arrivalTime(process p1,process p2)
{
    return p1.arrivalTime<p2.arrivalTime;
}
int main()
{
    int n;
    cout<<"enter the total no of process : ";
    cin>>n;

    process p[n];

    cout<<"enter the arrival time of processes : ";
    for(int i=0;i<n;i++)
    {
        cin>>p[i].arrivalTime;
        p[i].pid=i+1;
    }
    cout<<"enter the burst time of processes : ";
    for(int i=0;i<n;i++)
    {
        cin>>p[i].burstTime;
    }

    int current=0;
    int tTat=0;
    int tWat=0;
    sort(p,p+n,arrivalTime);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            current=max(current,p[i].arrivalTime);
        }
        else
        {
            current=max(current,p[i-1].completionTime);
        }

        p[i].completionTime=current+p[i].burstTime;
        p[i].turnAroundTime=p[i].completionTime-p[i].arrivalTime;
        p[i].waitingTime=p[i].turnAroundTime-p[i].burstTime;

        current=p[i].completionTime;

        tTat=tTat+p[i].turnAroundTime;
        tWat=tWat+p[i].waitingTime;

    }

    cout<<"PID "<<" \t"<<"Arrival time"<<"\t" <<" burst time "<<"\t" <<" turn around time "<<"\t" <<" waiting time "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].pid<<" \t"<<p[i].arrivalTime<<"\t "<<p[i].burstTime<<"\t"<<p[i].completionTime<<" \t"<<p[i].turnAroundTime<<"\t "<<p[i].waitingTime<<endl;
    }

    cout<<endl;

    cout<<"avg tat "<<(float(tTat)/n)<<endl;
    cout<<"avg wat "<<(float(tWat)/n)<<endl;




    return 0;
}