

#include<stdio.h>
#include<stdlib.h>

void firstfit(int memory[14][10], int processes[], int lastele[])
{
	for(int i=0;i<9;i++)
	{
		//printf("point 2\n");
		int current = processes[i];
		//printf("%d \n",processes[i]);
		int flag = 0;
		for(int j=0;i<14;j++)
		{
			if(memory[j][0]>=current)
			{
				if(memory[j][0]>0)
				{
					//printf("Point 3\n");
					memory[j][0]-=current;
					memory[j][lastele[j]+1] = i;
					lastele[j]++;
					flag = 1;
				}
			}
			if(flag==1)
				break;
		}
	}

	//printing

	for(int i=0;i<14;i++)
	{
		for(int j=1;memory[i][j]!=-1;j++)
		{
			printf("%d \n",memory[i][j]);
		}
	}
}

void bestfit(int memory[14][10], int processes[], int lastele[])
{
	for(int i=0;i<9;i++)
	{
		//printf("point 2\n");
		int current = processes[i];
		//printf("%d \n",processes[i]);
		int min_size = 100000;
		int loc;
		int j;
		for(j=0;j<14;j++)
		{
			if(memory[j][0]>=current)
			{
				if(memory[j][0]<min_size)
				{
					min_size = memory[j][0];
					loc = j;
				}
			}
		}
		if(memory[loc][0]>0)
		{
			//printf("Point 3\n");
			memory[loc][0]-=current;
			memory[loc][lastele[loc]+1] = i;
			lastele[loc]++;
		}
	}

	//printing

	for(int i=0;i<14;i++)
	{
		for(int j=1;memory[i][j]!=-1;j++)
		{
			printf("%d \n",memory[i][j]);
		}
	}
}

void worstfit(int memory[14][10], int processes[], int lastele[])
{
	for(int i=0;i<9;i++)
	{
		//printf("point 2\n");
		int current = processes[i];
		//printf("%d \n",processes[i]);
		int min_size = -1;
		int loc;
		int j;
		for(j=0;j<14;j++)
		{
			if(memory[j][0]>=current)
			{
				if(memory[j][0]>min_size)
				{
					min_size = memory[j][0];
					loc = j;
				}
			}
		}
		if(memory[loc][0]>0)
		{
			//printf("Point 3\n");
			memory[loc][0]-=current;
			memory[loc][lastele[loc]+1] = i;
			lastele[loc]++;
		}
	}

	//printing

	for(int i=0;i<14;i++)
	{
		for(int j=1;memory[i][j]!=-1;j++)
		{
			printf("%d \n",memory[i][j]);
		}
	}
}

int main()
{
	
	int memory[14][10];
	int lastele[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	// for(int i=0;i<14;i++)
	// {
	// 	printf("Enter the size of memory block %d :",i);
	// 	scanf("%d",&memory[i][0]);
	// }

	// this is the main memory representation.
	memory[0][0] = 200; //200 bytes for the first block
	memory[1][0] = 300; //and so on...
	memory[2][0] = 300;
	memory[3][0] = 400;
	memory[4][0] = 200;
	memory[5][0] = 500;
	memory[6][0] = 200;
	memory[7][0] = 400;
	memory[8][0] = 200;
	memory[9][0] = 500;
	memory[10][0] = 300;
	memory[11][0] = 200;
	memory[12][0] = 200;
	memory[13][0] = 100;

	for(int i=0;i<14;i++)
	{
		for(int j=1;j<10;j++)
		{
			memory[i][j] = -1;
		}
	}

	int processes[9] = {100,300,200,100,400,300,300,200,100};

	//firstfit(memory,processes,lastele);
	//printf("-------------- %d\n");
	bestfit(memory,processes,lastele);
    //worstfit(memory,processes,lastele);


	return 0;
}