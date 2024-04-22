//least replacement used page replacement algorithm

#include<iostream>
using namespace std;
struct pageTable
{
    int pageNo;
    int validBit;
    int lastAccessTime;
};

bool isPresent(int page,pageTable pt[])
{
    if(pt[page].validBit==1)
    {
        return true;
    }

    return false;

}

int LruReplace(int frame[],int fs,pageTable pt[])
{
    int min=9999;
    int minIndex=-1;
    for(int i=0;i<fs;i++)
    {
        if(pt[frame[i]].lastAccessTime < min)
        {
            min=pt[frame[i]].lastAccessTime;
            minIndex=i;
        }
    }

    return minIndex;
}

void printFrame(int frame[],int fs)
{
    for(int i=0;i<fs;i++)
      printf("%d ",frame[i]);
    printf("\n");  
}
int main()
{
    pageTable pt[100];
    int n;
    cout<<"enter the total no of processes : ";
    cin>>n;

    int refString[n];
    cout<<"enter the ref String : ";
    for(int i=0;i<n;i++)
    {   
        cin>>refString[i];
    }

  for(int i=0;i<n;i++)
    {   
        cout<<refString[i]<< " ";
    }

    for(int i=0;i<n;i++)
    {
        pt[i].validBit=0;
    }
    
    int current=0;

    int fs;
    cout<<"enter the frame size : ";
    cin>>fs;


    int frame[fs];

    for(int i=0;i<fs;i++)
    {
        frame[i]=-1;
    }
    int pageFaults=0;
    int flag=1;
    for(int i=0;i<n;i++)
    {


        if(!isPresent(refString[i],pt))
        {

            pageFaults++;
            if(current<fs && flag)
            {
                frame[current]=refString[i];

                  printFrame(frame,fs);
                pt[refString[i]].pageNo=current;
                pt[refString[i]].validBit=1;


                current++;

                if(current==fs)
                {
                    flag=0;
                }

            }
            else
            {
                int pageReplaceIndex=LruReplace(frame,fs,pt);
                // now we have got the index to be replaced

                pt[frame[pageReplaceIndex]].pageNo=-1;
                pt[frame[pageReplaceIndex]].validBit=0;

                frame[pageReplaceIndex]=refString[i];
                printFrame(frame,fs);

                pt[refString[i]].pageNo=pageReplaceIndex;
                pt[refString[i]].validBit=1;

            }
        }
        else
        {
                printFrame(frame,fs);
        }
        pt[refString[i]].lastAccessTime=i;
    }


    cout<<"page faults : "<<pageFaults<<endl;
    return 0;
}