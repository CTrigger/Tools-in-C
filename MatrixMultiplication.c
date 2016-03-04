#include<stdio.h>
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	
	int linhaA,colunaA,linhaB,colunaB;
	
	printf("Insira as Dimensao de A (Linha X Coluna)\n");
	puts("Nao digitar o X, use espaco.");
	scanf("%d %d",&linhaA,&colunaA);
	
	printf("Insira as Dimensao de B (Linha X Coluna)\n");
	puts("Nao digitar o X, use espaco.");
	scanf("%d %d",&linhaB,&colunaB);
	
	if (colunaA == linhaB)
	{
		float MatrizA[linhaA][colunaA], MatrizB[linhaB][colunaB], MatrizResposta[colunaB][linhaA];
		int i,j,k,l,m,n;
		
		//grava os valores da Matriz A
		puts("-------------------------------------------------------");
		for ( i = 0; i < linhaA;i++)
		{
			printf("insira os valores da linha %d da matriz A\n", i+1);
			for ( j = 0 ; j < colunaA ; j++)
				scanf("%f",&MatrizA[i][j]);
		}
		
		
		//imprime na tela os valores de A
		for ( i = 0; i < linhaA;i++)
		{
			for ( j = 0 ; j < colunaA;j++)
				printf("%.2f\t",MatrizA[i][j]);
			puts("");
	
		}
		puts("-------------------------------------------------------");
		
		
		
		//grava valores da Matriz B
		for ( i = 0; i < linhaB;i++)
		{
			printf("insira os valores da linha %d da matriz B\n", i+1);
			for ( j = 0 ; j<colunaB;j++)
				scanf("%f",&MatrizB[i][j]);
		}
		
		//imprime na tela os valores de B
		for ( i = 0; i < linhaB;i++)
		{
			for ( j = 0 ; j < colunaB;j++)
				printf("%.2f\t",MatrizB[i][j]);
			puts("");
	
		}		
		
		//prepara matriz resposta para incrmento
		for ( i = 0; i < linhaA ; i++)
			for ( j = 0 ; j < colunaB ; j++)
				MatrizResposta[i][j]=0;
		
		printf("\n\n");
	
		for ( i = 0 ; i < linhaA ; i++)
			for (  j = 0 ; j < colunaB ; j++)
				for( k = 0 ; k < colunaA ; k++)
					MatrizResposta[i][j] += (MatrizA[i][k] * MatrizB[k][j]);
				
			
	
		puts("=======================================================");
		for ( i = 0; i < linhaA;i++)
		{
			for ( j = 0 ; j < colunaB ; j++)
				printf("%.2f\t",MatrizResposta[i][j]);
			puts("");
		}
		puts("=======================================================");
	}
	
	else
	{
		puts("Matrizes desproporcionais, impossivel multiplicar");
	}
	
	return 0;
}
