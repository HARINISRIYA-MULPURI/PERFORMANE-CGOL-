/*
 ============================================================================
 Name        : Conways Game of Life.c
 Author      : Harini Sriya
 Version     : 1.00
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void conways(int life[7][7]) {
	int life2[7][7] = {
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0}
	};

	int i=0; int j=0;
	int c;
	for(i=0;i<7;i++){

		for(j=0;j<7;j++) {
			c=0;

			if (i==0) {

				if (life[i][j-1]==1) c++;
				if (life[i][j+1]==1) c++;
				if (life[i+1][j]==1) c++;
				if (life[i+1][j-1]==1) c++;
				if (life[i+1][j+1]==1) c++;
				if (life[i][j]==0 && c==3) life2[i][j]=1;
				else if (life[i][j]==1&&(c==2||c==3)) life2[i][j]=1;
				else if (life[i][j]==1&&c<2) life2[i][j]=0;
				else if (life[i][j]==1&&c>3) life2[i][j]=0;
				else life2[i][j]=life[i][j];
				continue;
			}
			if (i==6) {
				if (life[i-1][j]==1) c++;
				if (life[i][j-1]==1) c++;
				if (life[i][j+1]==1) c++;
				if (life[i-1][j-1]==1) c++;
				if (life[i-1][j+1]==1) c++;
				if (life[i][j]==0 && c==3) life2[i][j]=1;
				else if (life[i][j]==1&&(c==2||c==3)) life2[i][j]=1;
				else if (life[i][j]==1&&c<2) life2[i][j]=0;
				else if (life[i][j]==1&&c>3) life2[i][j]=0;
				else life2[i][j]=life[i][j];
				continue;

			}
			if (j==0) {
				if (life[i-1][j]==1) c++;
				if (life[i][j+1]==1) c++;
				if (life[i+1][j]==1) c++;
				if (life[i-1][j+1]==1) c++;
				if (life[i+1][j+1]==1) c++;
				if (life[i][j]==0 && c==3) life2[i][j]=1;
				else if (life[i][j]==1&&(c==2||c==3)) life2[i][j]=1;
				else if (life[i][j]==1&&c<2) life2[i][j]=0;
				else if (life[i][j]==1&&c>3) life2[i][j]=0;
				else life2[i][j]=life[i][j];
				continue;


			}
			if (j==6) {
				if (life[i-1][j]==1) c++;
				if (life[i][j-1]==1) c++;
				if (life[i+1][j]==1) c++;
				if (life[i-1][j-1]==1) c++;
				if (life[i+1][j-1]==1) c++;
				if (life[i][j]==0 && c==3) life2[i][j]=1;
				else if (life[i][j]==1&&(c==2||c==3)) life2[i][j]=1;
				else if (life[i][j]==1&&c<2) life2[i][j]=0;
				else if (life[i][j]==1&&c>3) life2[i][j]=0;
				else life2[i][j]=life[i][j];
				continue;


			}


			if (life[i-1][j]==1) c++;
			if (life[i][j-1]==1) c++;
			if (life[i][j+1]==1) c++;
			if (life[i+1][j]==1) c++;



			if (life[i-1][j-1]==1) c++;
			if (life[i-1][j+1]==1) c++;
			if (life[i+1][j-1]==1) c++;
			if (life[i+1][j+1]==1) c++;



			if (life[i][j]==0 && c==3) life2[i][j]=1; // Reproduction
			else if (life[i][j]==1&&(c==2||c==3)) life2[i][j]=1;// Survival
			else if (life[i][j]==1&&c<2) life2[i][j]=0;//Under population
			else  life2[i][j]=0;//Over population
		}

	}


	for(i=0;i<7;i++){
		printf("\n");
		for(j=0;j<7;j++) {
			printf("%d   ",life2[i][j]);
		}}

		for (i=0;i<7;i++) {
			for (j=0;j<7;j++) {
				life[i][j]=life2[i][j];
			}
		}



}
int main()
{

	int life[7][7]=
	{
			{0,1,1,0,0,1,0},
			{0,0,0,0,1,0,1},
			{0,1,0,0,0,0,0},
			{0,1,0,1,0,0,0},
			{1,0,1,0,1,0,1},
			{1,0,0,0,1,0,0},
			{0,0,1,1,1,0,0}
	};
	for (int i =0; i<7;i++) {
		printf("\n");
		for (int j=0;j<7;j++) {
			printf("%d   ",life[i][j]);
		}
	}
	printf("\n\nHow Many Generations:  ");
		fflush(stdout);
		int g=0;
		scanf("%d",&g);
	printf("\n\n\n");

	for (int currGen=1;currGen<=g;currGen++) {
		printf("\nGeneration Number %d\t",currGen);
		fflush(stdout);
		conways(life);
	}

	return 0;

}
