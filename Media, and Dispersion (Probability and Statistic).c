#include<stdio.h>
#include<math.h>
int main()
{

	int linhas,i,SomaFreq=0;
	puts("digite o numero de linhas da tabela");
	scanf("%d",&linhas);
	double f[99],x[99],AritmeticaP=0,VarianciaP=0,AmostralP=0;



	////////////////inicio////////////////////////
	int cont=0;
	puts("");
	puts("X	F");
	for(cont=0;cont<linhas;cont++)
		scanf("%lf %lf",&x[cont],&f[cont]);
	////////////////fim///////////////////////////

	for(i = 0; i<linhas ;i++)
		SomaFreq+=f[i];


	////////media ponderada aritmetica//////////////////////////////////////
	{

		for(i = 0; i<linhas ;i++)
			AritmeticaP+=((f[i]*x[i])/SomaFreq);
		printf("\n\nMedia Ponderada Aritimetica	=	%.3lf",AritmeticaP);
	}
	////////////////////////////////////////////////////////////////////////

	////////media ponderada geometrica//////////////////////////////////////
	{
		double GeometricaP=1;
		int raiz=0;
		for(i=0;i<linhas;i++)
			GeometricaP*=(pow(x[i],(f[i]/SomaFreq)));
		printf("\nMedia Ponderada Geometrica	=	%.3lf",GeometricaP);
	}
	////////////////////////////////////////////////////////////////////////

	////////media ponderada hamonica////////////////////////////////////////
	{
		double HarmonicaP=0;
		for(i=0;i<linhas;i++)
			HarmonicaP+=(f[i]/x[i]);
		HarmonicaP=SomaFreq/HarmonicaP;
		printf("\nMedia Ponderada Harmonica	=	%.3lf",HarmonicaP);
	}
	////////////////////////////////////////////////////////////////////////

	////////media ponderada quadratica && media raiz quadratica/////////////
	{
		double MQuadP=0;
		for(i=0;i<linhas;i++)
			MQuadP+=((f[i]*(pow(x[i],2)))/SomaFreq);
		printf("\nMedia Ponderada Quadratica	=	%.3lf",MQuadP);
		printf("\nMedia Ponderada Raiz Quadratica	=	%.3lf",pow(MQuadP,(1.0/2.0)));
	}
	////////////////////////////////////////////////////////////////////////

	////////media ponderada cubica//////////////////////////////////////////
	{
		double MCubicaP=0;
		for(i=0;i<linhas;i++)
			MCubicaP+=((f[i]*(pow(x[i],3)))/SomaFreq);
		printf("\nMedia Ponderada Cubica		=	%.3lf",MCubicaP);
	}
	////////////////////////////////////////////////////////////////////////

	////////media ponderada biquadratica////////////////////////////////////
	{
		double MBiQuadP=0;
		for(i=0;i<linhas;i++)
			MBiQuadP+=((f[i]*(pow(x[i],4)))/SomaFreq);
		printf("\nMedia Ponderada BiQuadratica	=	%.3lf",MBiQuadP);
	}
	////////////////////////////////////////////////////////////////////////

	////////media ponderada logaritmica/////////////////////////////////////
	{
		double MLogP=0;
		for(i=0;i<linhas;i++)
			MLogP+=((f[i]*log10(x[i]))/SomaFreq);
		printf("\nMedia Ponderada Logaritmica	=	%.3f",MLogP);
	}
	////////////////////////////////////////////////////////////////////////

	////////media de Dispersï¿½o Ponderada--Amplitude/////////////////////////
	{
		double AmpP=0;
		AmpP+=(x[linhas-1]-x[0]);
		printf("\n\nMedida de Amplitude		=	%.3f",AmpP);
	}
	////////////////////////////////////////////////////////////////////////

	////////media de Dispersï¿½o Ponderada--Desvio////////////////////////////
	{
		double DesvP=0;
		for(i=0;i<linhas;i++)
			DesvP+=((f[i]*pow(((pow((x[i]-AritmeticaP),2))),1.0/2.0))/SomaFreq);
		printf("\nMedida de Desvio Ponderada	=	%.3f",DesvP);
	}
	////////////////////////////////////////////////////////////////////////

	////////media de Dispersï¿½o Ponderada--Variancia/////////////////////////
	{
		for(i=0;i<linhas;i++)
			VarianciaP+=((f[i]*((pow((x[i]-AritmeticaP),2))))/SomaFreq);
		printf("\nMedida de Variancia Ponderada	=	%.3f",VarianciaP);
	}
	////////////////////////////////////////////////////////////////////////

	////////media de Dispersï¿½o Ponderada--Amostral//////////////////////////
	{
		//double AmostralP=0;
		for(i=0;i<linhas;i++)
			AmostralP+=(f[i]*((pow((x[i]-AritmeticaP),2))));
		AmostralP=pow(AmostralP/(SomaFreq-1),1.0/2.0);
		printf("\nMedida de Amostra Ponderada	=	%.3f",AmostralP);
	}
	////////////////////////////////////////////////////////////////////////

	////////Coeficiente de Curtose de Pearson3//////////////////////////////
	{
		double Pearson=0;
		for(i=0;i<linhas;i++)
			Pearson+=((f[i]*((pow((x[i]-AritmeticaP),3))))/(SomaFreq*(pow(AmostralP,3))));
		printf("\n\nCoe. de Curtose de Pearson3	=	%.3f",Pearson);
	}
	////////////////////////////////////////////////////////////////////////

	////////Coeficiente de Curtose de Pearson4//////////////////////////////
	{
		double Pearson=0;
		for(i=0;i<linhas;i++)
			Pearson+=((f[i]*((pow((x[i]-AritmeticaP),4))))/(SomaFreq*(pow(AmostralP,4))));
		printf("\nCoe. de Curtose de Pearson4	=	%.3f",Pearson);
	}
	////////////////////////////////////////////////////////////////////////


	return 0;
}
