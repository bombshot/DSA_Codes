#include<iostream>
using  namespace std;

class jobs
{
    int jno[100];
    int btime[100];
    int atime[100];
    int n;

public:

   jobs()
   {
   for(int i=0;i<100;i++)
       jno[i]=i+1;

   atime[100]={0};
   btime[100]={0};

   }


   void getdata()
   {

    cout<<"\nEnter the number of Jobs"<<endl;
    cin>>n;
	cout<<"\nEnter the arrival time and the burst time of the Jobs"<<endl;
            for(int i=0;i<n;i++)
            {
            cin>>atime[i];
            cin>>btime[i];
            }
   }


   void fcfs()
   {
       int wt[100];
       int tat[100];
       int time=atime[0];

           for(int i=0;i<n;i++)
            {

                    if(atime[i]<=time)
                    {
                         wt[i]= time-atime[i];
                         time=time+btime[i];
                    }

                    else
                    {
                        wt[i]=0;
                        time=atime[i]+btime[i];
                    }
                    tat[i]=wt[i]+btime[i];

            }

           cout<<"\njobs no."<<"\t\twaiting time"<<"\t\t   turn around time\n\n";
           for(int i=0;i<n;i++)
           cout<< jno[i]<<"\t\t\t\t"<<wt[i]<<"\t\t\t\t"<<tat[i]<<endl;
   }


   void shortest()
   {
       for(int i=1;i<n;i++)
           for(int j=0;j<n-i;j++)
               if(btime[j]>btime[j+1])
                    {
                        swap(btime[j],btime[j+1]);
                        swap(jno[j],jno[j+1]);
                    }

                    int wt[100];
                    wt[0]=0;

                    for(int i=0;i<n-1;i++)
                    {
                        wt[i+1]=wt[i]+btime[i];
                    }


        cout<<"\nJob no."<<"\t\t  waiting time"<<"\t\t   turn around time\n\n";
        for(int i=0;i<n;i++)
        cout<<jno[i]<<"\t\t\t\t"<<wt[i]<<"\t\t\t\t"<<btime[i]<<endl;
   }


   void priority()
   {
       int x,exe[100]={0};
       cout<<"\nGive priorities: "<<endl;

       for(int i=0;i<n;i++)
       {

           cout<<"\nPriority no. "<<i+1<<"  :";
           cin>>x;
           exe[i]=btime[x-1];
           jno[i]=x;
       }


          int wt[100];
                    wt[0]=0;

                    for(int i=0;i<n-1;i++)
                    {
                        wt[i+1]=wt[i]+exe[i];
                    }


        cout<<"\nJobs no."<<"\t\twaiting time"<<"\t\t   turn around time\n\n";
        for(int i=0;i<n;i++)
        cout<<jno[i]<<"\t\t\t\t"<<wt[i]<<"\t\t\t\t"<<exe[i]<<endl;

   }


};


int main()
{
        jobs ob1;
        cout<<"\n\t\t--------------------------JOB SCHEDULING----------------------------"<<endl<<endl;
               char ch='y';
               ob1.getdata();
               while(ch=='y' ||ch=='Y')
               {
                    
                   cout<<"\nEnter an option";
                   cout<<"\n1. First come first serve ";
                   cout<<"\n2. Shortest job first ";
                   cout<<"\n3. Priority job scheduling\n";

                   int op;
                   cin>>op;
                   switch(op)
                   {
                        case 1:
                            ob1.fcfs();
                            break;

                        case 2:
                            ob1.shortest();
                            break;
                        case 3:
                            ob1.priority();
                            break;

                    }
                    cout<<"\n\nDo you wanna continue(y/n):";
                    cin>>ch;
              }

}

