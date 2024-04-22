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

    int totalProcess,totalBlocks;
    cout<<"enter the total no of processes and blocks : ";
    cin>>totalProcess>>totalBlocks;

    process p[totalProcess];
    int blockSize[totalBlocks];

    cout<<"enter the size for each block : ";

    for(int i=0;i<totalBlocks;i++)
    {
        cin>>blockSize[i];
    }

    cout<<"enter the size for each process : ";

    for(int i=0;i<totalProcess;i++)
    {
        cin>>p[i].pSize;
        p[i].pid=i+1;
        p[i].blockNo=-1;
    }
    for(int i=0;i<totalProcess;i++)
    {
        int maxSize=INT_MIN;
        int index=-1;
        for(int j=0;j<totalBlocks;j++)
        {
            if(p[i].pSize<=blockSize[j] && blockSize[j]-p[i].pSize > maxSize)
            {
                maxSize=blockSize[j]-p[i].pSize;
                index=j;
            }
        }
        if(index!=-1)
        {
            blockSize[index]=blockSize[index]-p[i].pSize;
            p[i].blockNo=index+1;
        }
    }
    cout<<"process Id"<<" \t \t "<<"process size "<<" \t"<<"block no"<<endl;
    for(int i=0;i<totalProcess;i++)
    {
        cout<<p[i].pid<<" \t "<<p[i].pSize<<" \t "<<(p[i].blockNo==-1 ? "not allocated" : to_string(p[i].blockNo))<<endl;
    }

    return 0;
}

