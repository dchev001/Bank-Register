#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Date
{
	int month;
	int day;
	int year;
};

struct Register
{
	int checkNum;
	struct Date dt;
	char trans[MAX];
	double amount;
};

int main()
{
	// declare variables
	struct Register t1;
	struct Register *ptr;
	ptr = &t1;

	// file
	FILE *outfile;
	outfile = fopen("transaction.csv", "a");

	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opened file\n");
		exit(1);
	}

	// Get check number
	printf("Enter Check Number: ");
	scanf("%d", &ptr->checkNum);
	
	// Get month
	printf("Enter Month: ");
	scanf("%d", &ptr->dt.month);
	
	// Get day
	printf("Enter Day: ");
	scanf("%d", &ptr->dt.day);

	// Get year
	printf("Enter Year: ");
	scanf("%d", &ptr->dt.year);
	
	// Get transaction
	printf("Enter Transaction: ");
	getchar();
	scanf("%[^\n]s", ptr->trans);

	// Get amount
	printf("Enter Amount: ");
	scanf("%lf", &ptr->amount);

	// write info to file
	fprintf(outfile, "%d, \"%d/%d/%d\", \"%s\", %.2lf\n", ptr->checkNum, ptr->dt.month, ptr->dt.day, ptr->dt.year, ptr->trans, ptr->amount);

	// close file
	fclose(outfile);

	return 0;
}
