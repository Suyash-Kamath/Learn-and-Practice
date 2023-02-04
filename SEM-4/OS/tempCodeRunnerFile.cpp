#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct ProcessControlBlock
{
	int pid;
	int BT;
	int AT;
	int waitingtime;
	
};




vector<ProcessControlBlock>PCB;
vector<ProcessControlBlock>Arrived;
queue<ProcessControlBlock>running;
vector<ProcessControlBlock>ans;

int sortByarrival(ProcessControlBlock a , ProcessControlBlock b)
{
	if(a.AT < b.AT)
		return 1;
	else 
		return 0;
}

int sortByburst(ProcessControlBlock a , ProcessControlBlock b)
{
	if(a.BT < b.BT)
		return 1;
	else 
		return 0;
}
 
int main()
{

    int clock=0,pcbindex=0;
	
	int noOfProcess;
	cout<<"ENTER THE NO. PROCESS =>"<<"\t";
	cin>>noOfProcess;
	cout<<endl;
	int n=noOfProcess;
	
	for(int i=0;i<n;i++)
	{
		ProcessControlBlock dummy;
		cout<<"Enter the pid          "<<i+1<<"\t";
		cin>>dummy.pid;
		cout<<"Enter the Burst Time   "<<i+1<<"\t";
		cin>>dummy.BT;
		cout<<"Enter the Arrival Time "<<i+1<<"\t";
		cin>>dummy.AT;
		cout<<endl;
		PCB.push_back(dummy);
	}



	

	//----------------------------------------Logic for SJF----------------------------------------------------------//

	sort(PCB.begin(),PCB.end(),sortByarrival);

    int envruntime;
    int inpcb=0;
    int time=0;
    int currBT=0;
    int index=0;
    cout<<"For how much time the env must be active";
    cin>>envruntime;

    while(envruntime--)
    {
        while(time==PCB[inpcb].AT)
        {
            Arrived.push_back(PCB[inpcb]);
            inpcb++;
            sort(PCB.begin(),PCB.end(),sortByburst);
        }

        if(running.empty())
        {