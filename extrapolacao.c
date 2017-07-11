
//faremos a interpolação pelo método de Lagrange

#include <stdio.h>
#include <math.h>


int main ()
{

int m=0, i, n, a=0, j;

printf("\nDigite o grau do polinomio a ser usado:\n");
scanf("%d", &n);

double media[115], y[(n+1)], ano[115], x, x0[(n+1)], l[(n+1)], Pn; //apesar dos termos em x (anos) serem "int" declarei double para não dar conflito na hora da multiplicação P(x)=L(x)*y


FILE *medias;
medias = fopen("medias.txt","r");

	while(m<115)
	{
		fscanf(medias,"%lf %lf",&media[m], &ano[m]);
		//printf("%lf %d\n", media[m], ano[m]);
		m++;
	}

printf("\nDigite o ano em que quer fazer a interpolação:\n");
scanf("%lf", &x);

m = 115-(n+1);

	for(i=0;i<(n+1);i++)
	{	
		x0[i] = ano[m];
		y[i] = media[m];		
		//printf("\n%lf\t%lf", x0[i], y[i]);
		m++;
		
	}

	Pn = 0;
	for(i=0;i<(n+1);i++)
	{	
		l[i]=1;		
		for(j=0;j<(n+1);j++)
		{	
			if(j==i)
			{	//printf("%d\n", j);
				j++;
			}
			
			l[i]= l[i] *( (x-x0[j]) / (x0[i]-x0[j]));	
		}//printf("%.4lf\n", l[i]);
		Pn = Pn + (y[i]*l[i]);		
	}
printf("%.4lf\n", Pn);


return 0;
}
