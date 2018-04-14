#include<stdio.h> 
static int n;
int i,j,total_time=0;//time quantum
float avgtat=0,avgwt=0;
int queue[];
int time=0,front=0,rear=0,q_count=0,m=0,s=0;

struct data
{
	int at,st,ct,tat,wt;
	char pname[20];
	float ntat;
}temp;
int main()
{
	printf("Enter the number of Process : ");
	scanf("%d",&n);
	
	struct data aa[n];
	for(i=0;i<n;i++)
	{
		printf("\nEnter the name of process %d : ",i);
		scanf("%s",&aa[i].pname);
		printf("Enter the Arrival Time of process %d : ",i);
		scanf("%d",&aa[i].at);
		printf("Enter the Burst Time of process %d : ",i);
		scanf("%d",&aa[i].st);
	}
	
	//sorting
	for(i=0;i<n;i++)
	{
		for(j=i;j>=1;j--)
		{
			if(aa[j].at<aa[j-1].at)
			{
				temp=aa[j-1];
				aa[j-1]=aa[j];
				aa[j]=temp;
			}
			else if(aa[j].at==aa[j-1].at)
			{
				if(aa[j].st<aa[j-1].st)
				{
					temp=aa[j-1];
					aa[j-1]=aa[j];
					aa[j]=temp;
				}
			}
		}
	}
	//finding the total time
	total_time+=aa[0].at+aa[0].st;
	for(i=1;i<n;i++)
	{
		if(aa[i].at>total_time)
		total_time=aa[i].at;
		total_time+=aa[i].st;
	}
	//finding the ct
	finding(aa);
}
	
void finding(struct data a[])
{
	
	
	int temp_st[n],flag=0,count=0,p_process;
	j=0;
	int tq;
	printf("Enter the time quantum : ");
	scanf("%d",&tq);
	for(i=0;i<n;i++)
	{
		temp_st[i]=a[i].st;
	}
	time=a[0].at;

	q_count=1;
	push(j++);
	while(time<=total_time)
	{
		if(flag==1||q_count!=0)
		{
			if(flag==0&&count==0)
			{
				p_process=pop();//queue[front];
				//p_process=i;
				count=0;
				flag=1;
			}
			temp_st[p_process]--;	
			if(temp_st[p_process]==0)
			{
				time++;
				count=0;
				a[p_process].ct=time;
				flag=0;//a[i].st+=1000;
				q_count--;
				check(a);
				continue;
			}
			count++;
			//count=count%tq;
			if(count==tq)
			{
				count=0;
				time++;
				check(a);
				push(p_process);
				flag=0;
			}
			else
			{
				time++;
				check(a);
			}
		}
		else
		{
			time++;
			check(a);
		}
	}//end of while loop
	display(a);
	}
void push(int q)
{
	queue[rear++]=q;
	//rear%=n;
	m++;
}
int pop()
{
	s++;
	int x;
	x=queue[front++];
	return x;
}
	
void check(struct data a[])
{
	while(a[j].at<=time&&j<n)
	{
		q_count++;	
		push(j++);
	}
}
void display(struct data a[])
{
	//n=5;
	
	printf("\nTime Quantum = %d\n",n);
	
	for(i=0;i<n;i++)
	{
		a[i].tat=a[i].ct-a[i].at;
		a[i].wt=a[i].tat-a[i].st;
		a[i].ntat=(float)a[i].tat/a[i].st;
	}
	for(i=0;i<n;i++)
	{
		avgtat+=a[i].tat;
		avgwt+=a[i].wt;
	}
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	printf("PName\tAT\tBT\tCT\tTAT\tWT\tATAT\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\t%d\t%d\t%d\t%.2f\n",a[i].pname,a[i].at,a[i].st,a[i].ct,a[i].tat,a[i].wt,a[i].ntat);
	}
	printf("\n\nGANTT CHART is :  ");
	for(i=0;i<n;i++)
	{
		printf("%s\t",a[i].pname);
	}
	printf("\n\nAverage Turn-Around Time is = %.2f\n\nAverage Waiting-Time is = %.2f\n",avgtat,avgwt);
}
