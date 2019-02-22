#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void cal_need(int need[][3],int maximum[][3], int allocated[][3])
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<3;j++)
		{
			need[i][j] = maximum[i][j] - allocated[i][j];
		}
	}
}

int find_SS(int available[], int maximum[][3], int processes[], int allocated[][3])
{
	int need[5][3];

	cal_need(need,maximum,allocated);

	bool finished[5] = {false,false,false,false,false};
	
	bool safe = false; //to pass final value of safety or not

	int count = 5; //count to check whether all processes are finished or not

	int avail[3]; //copy of available resources

	for(int i=0;i<3;i++)
		avail[i] = available[i];

	int safe_seq[5]; //to store the safe sequence

	while(count!=0)
	{
		safe = false; //initally it has to be declared false

		for(int i=0; i < 5; i++)
		{
			if(finished[i] == 0)
			{
				int j;
				for(j=0;j<3;j++)
				if(avail[j]<need[i][j]) //to check if need is less than available
					break; //so need is greater than the work hence, END IT!!

				if(j==3) //if all needs are met
				{
					for(int j=0;j<3;j++)
					{
						avail[j] += allocated[i][j]; //put back the allocated resources										
					}

					safe_seq[5-(count--)] = i;

					finished[i] = true;

					safe = true;
				}
			}
		}

		if(safe!=true)
		{
			printf("The system is not in safe state!\n");
			return -1;
		}
	}

	printf("System is in safe state.\nSafe sequence is: ");

    for (int i = 0; i < 5 ; i++) 
        printf("%d ",safe_seq[i]); 

    printf("\n");
  
    return true; 

}

int give_request(int request[][3],int allocated[][3], int available[], int processes[] , int  maximum[][3])
{
	for(int i=0;i<5;i++)
	{
		int j;
		for(j=0;j<3;j++)
		{
			if(request[i][j] > available[j])
				return -1;
		}

		if(j==3)
		{
			for(int j=0;j<3;j++)
			{
				available[j]-=request[i][j];
				allocated[i][j]+=request[i][j];
			}
		}

		find_SS(available, maximum, processes, allocated);
	}
}

int main()
{
	int processes[5] = {0,1,2,3,4}; 
  
    // Available instances of resources 
    int available[3] = {3,3,2}; 
  
    // Maximum R that can be allocated 
    // to processes 
    int maximum[5][3] = {{7,5,3}, 
                     	{3,2,2}, 
                     	{9,0,2}, 
                     	{2,2,2}, 
                     	{4,3,3}}; 
  
    // Resources allocated to processes 
    int allocated[5][3] = {{0, 1, 0}, 
                      {2, 0, 0}, 
                      {3, 0, 2}, 
                      {2, 1, 1}, 
                      {0, 0, 2}}; 

							
    int request[5][3] = {{2,0,0},
    					{7,0,2},
    					{0,0,0},
    					{0,0,0},
    					{0,0,0}};


    int res = find_SS(available,maximum,processes,allocated);

    if(res==-1)
    	printf("The safe sequence is not available\n");

    give_request(request,allocated,available,processes,maximum);

	return 0;
}