#include<stdio.h>
#include<conio.h>
#include<unistd.h>
struct station{
	int *trains, pass,p=1, temp;
	int part;
	int k, j=1,max;
	int stationloadtrain(){
		system("cls");
		int found=0;
		printf("TOTAL PASSENGER: %d \tPASSENGER TO TRACK: %d\n\n", pass, part);
		int m=0;
		while(m<=max){
			printf("==========");
			m++;
		}
		printf("\n\n");
		while(j<=k)
		{
			printf("BOARDING TRAIN %d [CAPACITY: %d]: ", j, trains[j-1]);
			for(int i=1;i<=trains[j-1];i++)
			{
				if(p<=pass)
				{
				printf("%d\t",p);
				}
				if(p==part)
				{
					found++;
				}
				p++;
			}
			if(found==1)
			{
				found=0;
				stationonboard(j);
			}
			if(p>pass)
			{
					printf("\n\n");
					m=0;
					while(m<=max)
					{
						printf("==========");
						m++;
					}
					printf("\n\nBOARDING STATUS:  All passsenger boarded successfully!!\n\n");
					m=0;
					while(m<=max)
					{
						printf("==========");
						m++;
					}
					break;
			}
			printf("\n\n");
			temp = temp-trains[j-1];
			j++;
		}
	
	}
	
	int stationwaittrain(){
		system("cls");
		printf("ENTER PASSENGER ID TO TRACK:(TOTAL PASSENGER: %d):", pass);
		scanf("%d", &part);
		if(part>pass){
			int g;
			printf("INVALID ID!!! \n\n");
			printf("PRESS 1 KEY TO RE-ENTER PASSENGER ID: ");
			scanf("%d", &g);
			stationwaittrain();
		}else{
			stationloadtrain();
		}
	}
	
	int stationonboard(int j){
		printf("\n");
		int m=0;
		while(m<=max)
		{
			printf("==========");
			m++;
		}
		printf("\n\nTRACKING STATUS: Successfull\nTRACKED PASSENGER: %d\n", part);
		printf("TRAIN BOARDED: Train %d\n\n", j);
		m=0;
		while(m<=max)
		{
			printf("==========");
			m++;
		}
	}
};
int main()
{
	struct station s1;
	int trains, n, total,sum=0;
	printf("Enter number of trains: ");scanf("%d", &n);
	s1.k = n;
	printf("\nEnter Total passengers to board: ");scanf("%d", &total);
	s1.pass = total;
	s1.temp = total;
	printf("\nEnter %d trains capacity for %d passengers:\n\n", n,total);
	s1.trains = new int[n];
	s1.max=0;
	repeat:
	for(int i=0;i<n;i++)
	{
		int x;
		printf("TRAIN %d: ", i+1);scanf("%d", &x);
		if(x>s1.max){
			s1.max = x;
		}
		s1.trains[i] = x;
		sum = sum+x;
	}
	if(sum>=total)
	{
		s1.stationwaittrain();	
	}
	else
	{
		system("cls");
		sum=0;
		printf("STATUS: Failed!!\n\nREASON: Not sufficient trains to board all passengers!!");
		printf("\n\nEnter train capacity again [TOTAL PASSENGERS: %d]\n", &total);
		goto repeat;
	}
}
