#include <stdio.h>
#include <math.h>


int main ()
{

float temp[114], x=0, y=0; 
int ano[114], m=0, n=0, contador=0;


FILE *temperaturas;
FILE *medias;
	
temperaturas = fopen("temp.txt","r");
medias = fopen("medias.txt","w");

char buffer[100]; //para pular a primeira linha do arquivo
fgets(buffer, 100, temperaturas);


while(contador<115)
{
	fscanf(temperaturas,"%f %d\t%d",&x, &ano[m], &n);
	
	y= y + x;

	if (n==12)
	{	temp[m] = y/12;
		fprintf(medias, "%.4f\t%d\n", temp[m], ano[m]);
		//gera um arquivo chamado "medias.txt" com as temperaturas médias
		m++;
		y=0;
		contador++;
	}

}

fclose(temperaturas);
fclose(medias);

return 0; 

}
