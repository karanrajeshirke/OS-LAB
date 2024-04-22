#include<iostream>
using namespace std;
struct process 
{
    int maximum[10];
    int allocation[10];
    int need[10];
};
int main()
{

    process p[10];

    int n;
    cout<<"enter the number of processes : ";
    cin>>n;

    int m;
    cout<<"enter the number of resources : ";
    cin>>m;

    int avaiable[m];

    cout<<"enter the available resources : ";

    for(int i=0;i<m;i++)
    {
        cin>>avaiable[i];
    }

    //now take the input

    for(int i=0;i<n;i++)
    {
        cout<<"enter the maxmium resources for process :  "<<i<< " ";
        for(int j=0;j<m;j++)
        {
            //now each process i and resources j
            cin>>p[i].maximum[j];
        }

         cout<<"enter the allocated resources for process :  "<<i<< " ";
        for(int j=0;j<m;j++)
        {
            //now each process i and resources j
            cin>>p[i].allocation[j];
        }


        //calculating need

          for(int j=0;j<m;j++)
        {
            //now each process i and resources j
            p[i].need[j]=p[i].maximum[j]-p[i].allocation[j];
        }


    }


    //priting the input matrix;

    cout<<"\nPID\tMaximum\tAllocated\tNeed\n"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"P["<<i<<"]"<<" ";
        for(int j=0;j<m;j++)
        {
            cout<<p[i].maximum[j]<< " ";
        }
           cout<<"\t";
          for(int j=0;j<m;j++)
        {
            cout<<p[i].need[j]<< " ";
        }
           cout<<"\t";
          for(int j=0;j<m;j++)
        {
            cout<<p[i].allocation[j]<< " ";
        }
           cout<<"\t";
        cout<<endl;
    }


    //now we have to write the program


    int isCompleted[n];
    int safeSeq[n];
    int k=0;

    for(int i=0;i<n;i++)
    {
        isCompleted[i]=0;
        safeSeq[i]=-1;
    }

    for(int i=0;i<n;i++)
    {
        int flag=1;

        if(isCompleted[i]==0)
        {
            for(int j=0;j<m;j++)
            {
                if(p[i].need[j]>avaiable[j])
                {
                     flag=0;
                    break;
                   
                }
            }


            if(flag)
            {
                for(int j=0;j<m;j++)
                {
                    avaiable[j]=avaiable[j]+p[i].allocation[j];
                }

                isCompleted[i]=1;

                safeSeq[k]=i;
                k++;

                i=-1;
            }
        }
    }

    bool flag=1;
    for(int i=0;i<n;i++)
    {
        if(isCompleted[i]==-1)
        {
            cout<<"not a safe sequnce"<<endl;
            flag=1;
            break;
        }   
    }


    if(flag)
    {
        for(int i=0;i<n;i++)
        {
            cout<<"P["<<safeSeq[i]<<"]"<<" ";
        }cout<<endl;
    }


    cout<<"after all process available matrix is : "<<endl;

    for(int i=0;i<m;i++)
    {
        cout<<avaiable[i]<<" ";
    }cout<<endl;

    return 0;
}