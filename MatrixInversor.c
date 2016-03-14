/*
	Status: NOT READY,works on 95% of the cases for Matrix of N x N
	Name: MatrizInversa
	Copyright: Ricardo Kim
	Author: Ricardo Kim
	Date: 13/03/16 18:13 (Brazil)
	Description: Only use for studing purpose, not commercial use.
*/

#include<stdio.h>
int main()
{
	int proportion;
	//freopen( "input.txt", "r", stdin ); 
	
	printf("Type [N]umber, for matrix N x N \nthat's means one number!\n");
	scanf("%d", &proportion);
	
	/*Defines the proportion of the matrix*/
	/*Define a proporção da matriz*/
	float M[proportion+1][(proportion*2)],DeteminantTest=0; 	
	int line,column;

	for (line = 1 ; line <= proportion; line++)
	{
		printf("Input the line %d\n", line);
		for ( column = 1 ; column <= proportion ; column++)			
			scanf("%f", &M[line][column]);
	}
	
	puts("=========Matrix=Printing================");
	for (line = 1 ; line <= proportion; line++)
	{
		for ( column = 1 ; column <= proportion ; column++)
			printf("%.3f\t", M[line][column]);		
		puts("");
	}		
	puts("========================================");


	int DeterminantTest=1;
	if(DeterminantTest != 0)
	{
		/* this loop defines the matriz idendity */
		/*Esse laço configura a matriz verdade de apoio*/
		for(line = 1 ; line <= proportion ; line++)
			for( column = proportion+1 ; column <= proportion *2 ; column++)
				if (line+proportion == column)
				{
					M[line][column] = 1;
				}
				else
				{
					M[line][column] = 0;
				}
	
		puts("=========Matrix=Setup===================");		
		for (line = 1 ; line <= proportion; line++)
		{
			for ( column = 1 ; column <= proportion*2 ; column++)
				printf("%.3f\t", M[line][column]);		
			puts("");
		}	
		puts("========================================");
		
		
		
		float guide;
		int lineBase;
		for (lineBase = 1 ; lineBase <= proportion ; lineBase++)
		{	
		
			/*Matriz Sort when any value position in the main diagonal as 0*/
			/*Ordenação de matriz para quando algum valor na diagonal principal for 0*/
			/*Selection Sort*/
			float tmp_M[1][proportion*2];
			int tmp_line,search_line,tmp_column,sort_flag = 0;
			for(line = 1 ; line <= proportion ; line ++)
				for(column = 1;column <= proportion *2;column ++)
					if(line == column && M[line][column]==0 ) /*Test for the stats*/
					{
						sort_flag = 1;	/*inform when was needed*/
						for(tmp_line = line ; tmp_line <= proportion ; tmp_line++) 
							if	(M[tmp_line][column] != 0 && M[tmp_line][tmp_line] != 0) /*Select the best line swap*/
							{
								search_line = tmp_line;
								break;
							}
						
						for(tmp_column = 1; tmp_column <= proportion * 2; tmp_column ++)
							tmp_M[1][tmp_column] = M[line][tmp_column];	/*Backup entire line*/
				
						for(tmp_column = 1; tmp_column <= proportion * 2; tmp_column ++)
							M[line][tmp_column] = M[search_line][tmp_column]; /*Move best line to the actual line*/
						
						for(tmp_column = 1; tmp_column <= proportion * 2; tmp_column ++)
							M[search_line][tmp_column] = tmp_M[1][tmp_column]; /*Insert the backup into best line */
							
					}
					
			if (sort_flag==1)
			{
				/*Imprime após ordenação*/
				puts("=========Matrix=After=Sort==============");		
				for (line = 1 ; line <= proportion; line++)
				{
					for ( column = 1 ; column <= proportion*2 ; column++)
						printf("%.3f\t", M[line][column]);		
					puts("");
				}	
				puts("========================================");	
			}
			/*Gaussian Elinination - in all lines except the base line*/
			/*Eliminação Gaussiana - em todas as linhas exceto a linha base*/
			for(line = 1 ; line <= proportion ; line++)
			{
				 if (lineBase == line)
				 	line++;
				
				guide = M[line][lineBase]/M[lineBase][lineBase];
				for(column = 1 ; column <= proportion * 2 ; column++)
					M[line][column] -=( M[lineBase][column] * guide );
					
					
			}
			
			/*Divide the base line to obtain the main diagonal*/
			/*Divide a linha base para obtenção da diagonal principal*/
			guide = M[lineBase][lineBase];
				for(column = 1 ; column <= proportion * 2 ; column++)
					M[lineBase][column] /= guide;
			/*
			printf("=========Matrix=Interaction=%d===========\n",lineBase);
			for (line = 1 ; line <= proportion; line++)
			{
				for ( column = 1 ; column <= proportion*2 ; column++)
					printf("%.3f\t", M[line][column]);		
				puts("");
			}
			puts("========================================");	
			*/
		}
	
		/*Prints the answer*/
		/*Imprime a resposta final na tela*/
		puts("=========Matrix=Answer==================");
		for (line = 1 ; line <= proportion; line++)
		{
			for ( column = 1 ; column <= proportion*2 ; column++)
				printf("%.3f\t", M[line][column]);		
			puts("");
		}
		puts("========================================");	

	}
	else
	{
		puts("Determinant is ZERO, matrix can't be reversed");
	}	
	
	return 0;
}
