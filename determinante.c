#include <stdio.h>

int main(void) 
{
	float determinante[2][3], resposta[1][3];
	int i, j;
	for (i = 0 ; i < 2 ; i++)
		for( j = 0; j < 3 ; j++)
			scanf("%f",&determinante[i][j]);
			
			
	resposta[0][0] = determinante[0][1] * determinante[1][2] - determinante[0][2] * determinante[1][1];
	resposta[0][1] = determinante[0][2] * determinante[1][0] - determinante[0][0] * determinante[1][2];
	resposta[0][2] = determinante[0][0] * determinante[1][1] - determinante[0][1] * determinante[1][0];
	
	
	printf("(%.2f - %.2f)i\n",determinante[0][1] * determinante[1][2],determinante[0][2] * determinante[1][1]);
	printf("(%.2f - %.2f)j\n",determinante[0][2] * determinante[1][0],determinante[0][0] * determinante[1][2]);
	printf("(%.2f - %.2f)k\n",determinante[0][0] * determinante[1][1],determinante[0][1] * determinante[1][0]);
	puts("---------------------");
	
	printf("%.2fi %.2fj %.2fk \t\n",resposta[0][0],resposta[0][1],resposta[0][2]);
	
	
	return 0;
}
