#include<stdio.h>

void solve(int processes[], int arrival[], int priority[], int bur[] )
{

	int finished[5] = {0,0,0,0,0};
	int turnaround[5] = {0,0,0,0,0};
	int waiting[5] = {0,0,0,0,0};

	int burst[5]; //temp array to store burst time
	for(int i=0;i<5;i++)
		burst[i] = bur[i];

	int time = -1;
	int count = 5;
	//assume first process is already running
	int current_proc = processes[0];
	int curr_pr = priority[0];

	printf("helo! \n");

	while(count!=0)
	{
		time++;
		
		printf("Process %d is running \n",current_proc);

		for(int i=0;i<5;i++)
		{
			if(burst[current_proc]==0)
			{
				finished[current_proc] = 1;

				//printf("Process %d has finished\n",current_proc);
				count--; 
				turnaround[current_proc] = time - arrival[current_proc];

				int min = 1000;
				for(int i=0;i<5;i++)
				{
					//printf("finished of %d is %d \n",i,finished[i]);
					if(priority[i]<min && finished[i]==0)
					{
						min = priority[i];
						current_proc = i;
					}
				}
				//printf("Minimum  is %d \n",min );
				curr_pr = min;
				break;
			}

			if(priority[i]<priority[current_proc] && finished[i]!=1 && time >= arrival[i])
			{
				current_proc = processes[i];
				curr_pr = priority[i];
			}
		}	
		burst[current_proc]--;
	}

	for(int i=0;i<5;i++)
		waiting[i] = turnaround[i] - bur[i];

		printf("process 	turnaround 		waiting\n");
	for(int i=0;i<5;i++)
	{
		printf("  %d            %d             %d \n", i, turnaround[i],waiting[i]);
	}

}

int main()
{
	int processes[5] = {0,1,2,3,4};
	int arrival[5] = {0,2,5,6,7};
	int priority[5] = {2,3,4,1,5};
	int burst[5] = {7,3,2,10,8};

	/*
	printf("Enter the arrival time for : \n");

	for(int i=0;i<5;i++)
	{
		printf("Process %d : ",i);
		scanf("%d",&arrival[i]);
	}

	printf("Enter the priority for : \n");

	for(int i=0;i<5;i++)
	{
		printf("Process %d : ",i);
		scanf("%d",&priority[i]);
	}

	printf("Enter the burst time for : \n");

	for(int i=0;i<5;i++)
	{
		printf("Process %d : ",i);
		scanf("%d",&burst[i]);
	}*/
	
	printf("HAHAH!!\n");

	solve(processes, arrival, priority, burst);


	return 0;
}