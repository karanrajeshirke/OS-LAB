//fcfs page replacement algorithm

#include<iostream>
using namespace std;
struct pageTable
{
    int pageNo;
    int validBit;
};

bool isPresent(pageTable pt[],int page)
{
    if(pt[page].validBit==-1)
    {
        return false;
    }
    return true;
}
void printFrame(int frame[],int fs)
{
    for(int i=0;i<fs;i++)
    {
        cout<<frame[i]<< " ";
    }cout<<endl;
}
int main()
{
    pageTable pt[100];

    for(int i=0;i<100;i++)
    {
        pt[i].validBit=-1;
    }

    int totalPages;
    cout<<"enter total Pages : ";
    cin>>totalPages;


    int refString[totalPages];

    cout<<"enter the ref String : ";
    for(int i=0;i<totalPages;i++)
    {
        cin>>refString[i];
    }

    int frameSize;
    cout<<"enter the frame Size : ";
    cin>>frameSize;

    int frame[frameSize];

    for(int i=0;i<frameSize;i++)
    {
        frame[i]=-1;
    }

    int current=0;
    bool flag=1;
    int pageFaults=0;

    printFrame(frame,frameSize);
    for(int i=0;i<totalPages;i++)
    {
        if(!isPresent(pt,refString[i]))
        {

            pageFaults++;
            if(current<frameSize && flag)
            {
                pt[refString[i]].pageNo=current;
                pt[refString[i]].validBit=1;

                frame[current]=refString[i];

                printFrame(frame,frameSize);

                current++;

                if(current==frameSize)
                {
                    current=0;
                    flag=0;
                }
            }
            else
            {
                pt[frame[current]].pageNo=-1;
                pt[frame[current]].validBit=-1;


                frame[current]=refString[i];

                printFrame(frame,frameSize);


                pt[refString[i]].pageNo=current;
                pt[refString[i]].validBit=1;

                current=(current+1)%frameSize;

            }
        }
        else
        {
                printFrame(frame,frameSize);
        }
    }

    cout<<endl;
    cout<<"page faults : "<<pageFaults<<endl;
    
    return 0;
}