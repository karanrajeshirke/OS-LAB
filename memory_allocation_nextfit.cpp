#include<iostream>
using namespace std;
struct process
{
    int pid;
    int pSize;
    int blockNo;
};
int main()
{
    int totalBlocks,totalProcess;
    cout<<"enter the total no of processes and blocks : ";
    cin>>totalProcess>>totalBlocks;

    process p[totalProcess];
    int blockSize[totalBlocks];

    cout<<"enter the size of each block : ";
    for(int i=0;i<totalBlocks;i++)
    {
        cin>>blockSize[i];
    }

    cout<<"enter the size of each process : ";
    for(int i=0;i<totalProcess;i++)
    {
        cin>>p[i].pSize;
        p[i].pid=i+1;
        p[i].blockNo=-1;
    }

    int j=0;
    for(int i=0;i<totalProcess;i++)
    {
        for(int k=0;k<totalBlocks;k++)
        {
            if(p[i].pSize<=blockSize[j])
            {
                p[i].blockNo=j+1;
                blockSize[j]=blockSize[j]-p[i].pSize;
                break;
            }

            j=(j+1)%totalBlocks;

        }
    }

    cout<<"PID "<<"\t "<<"process size "<<"\t"<<"block no"<<endl;

    for(int i=0;i<totalProcess;i++)
    {
        cout<<p[i].pid<<"\t "<<p[i].pSize<<" \t"<<(p[i].blockNo==-1 ? "not allocated" : to_string(p[i].blockNo))<<endl;
    }


    return 0;
}