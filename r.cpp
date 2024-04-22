#include<iostream>
using namespace std;
int main()
{
    while(1)
    {
        string tochild;
        cout<<"enter from parent : ";
        getline(cin,tochild);


        cout<<"recived at child : "<<tochild<<endl;

        string fromchild;
        cout<<"enter from child : ";
        getline(cin,fromchild);

        cout<<"recived at parent :"<<fromchild<<endl;
    }
}

