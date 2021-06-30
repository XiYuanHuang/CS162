#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand(time(NULL));
	int a = 0, b = 0, c = 0, i = 0, j = 0; 
	printf("Give me the width of the array: ");
	scanf("%d", &a);
	printf("\n");
	printf("Give me the height of the array: ");
	scanf("%d", &b);
	int **array = malloc(sizeof(int*) * a);
	for( i = 0; i < a; i++)
	{
		array[i] = malloc(sizeof(int) * b);
	}
	
	for( i  = 0; i < a; i++)
	{
		for(j = 0; j < b; j++)
		{
			array[i][j] = rand()% 50 + 1;
		}
	}

	for( i = 0; i < a; i++)
	{
		for(j = 0; j < b; j++)
		{
			printf("%d", array[i][j]);
			printf(" ");
		}
		printf("\n");
	}
	do{
		printf("Please tell me how many element do you want to add? bigger than zero but smaller than ten \n");
		scanf("%d", &c);
	}while(c < 0);

	for(i = 0; i < a; i++)
	{
		for(j = 0; j < b; j++)
		{
			array[i][j] += c;
		}
		
	}
	
	for( i = 0; i < a; i++)
	{
		for(j = 0; j < b; j++)
		{
			printf("%d", array[i][j]);
			printf(" ");
		}
		printf("\n");
	}

	for(i = 0; i < a; i++)
	{

		free(array[i]);
	}
	free(array);

return 0;
}
