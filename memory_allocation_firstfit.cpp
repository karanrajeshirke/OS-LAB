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
    cout<<"enter the total no of blocks and process : ";
    cin>>totalBlocks>>totalProcess;

    process p[totalProcess];

    int BlockSize[totalBlocks];

    cout<<"enter the block size for each block : ";

    for(int i=0;i<totalBlocks;i++)
    {
        cin>>BlockSize[i];
    }
    cout<<"enter the process size for each process : ";

    for(int i=0;i<totalProcess;i++)
    {
        cin>>p[i].pSize;
        p[i].pid=i+1;
        p[i].blockNo=-1;
    }

    for(int i=0;i<totalProcess;i++)
    {
        for(int j=0;j<totalBlocks;j++)
        {
            if(p[i].pSize<=BlockSize[j])
            {
                p[i].blockNo=j+1;
                BlockSize[j]=BlockSize[j]-p[i].pSize;
                break;

            }
        }
    }

    cout<<"PID "<<"\t"<<"Process Size "<<"\t"<<"Block No"<<endl;
    for(int i=0;i<totalProcess;i++)
    {
        cout<<p[i].pid<<" \t "<<p[i].pSize<<" \t \t"<<(p[i].blockNo==-1 ? "not allocated " : to_string(p[i].blockNo))<<endl;
    }

}