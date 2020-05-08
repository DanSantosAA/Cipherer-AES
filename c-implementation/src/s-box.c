#include <stdio.h>
#include <string.h>

#include "s-box.h"

#define MAX_LINE 50

S_box *loadBoxTable(char *path)
{
	FILE *file = fopen(path, "r");
	S_box *new_table = NULL;

	if(file != NULL)
	{
		new_table = (S_box *) malloc(sizeof(S_box));
		char line[MAX_LINE];
		char *token;

		for(int rows = 0; rows < RADIX; ++rows)
		{
			fscanf(file, "%s", line);
			token = strtok(line, ",\n");

			for(int columns = 0; columns < RADIX; ++columns)
			{
				int value = strtol(token, NULL, RADIX);

				//se carga el valor en la matriz original
				new_table->matrix[rows][columns] = value;

				//se carga el valor en la matriz inversa
				new_table->inv_matrix[value / 16][value % 16] = (rows * 16) + columns;

				token = strtok(NULL, ",\n");
			}
		}

		showBoxTable(new_table->matrix);
		//showBoxTable(new_table->inv_matrix);

		fclose(file);
	}
	else
	{
		printf("No se pudo abrir el archivo correctamente\n");
	}

	return new_table;
}

void showBoxTable(int table[RADIX][RADIX])
{
	if(table != NULL)
	{
		printf("  ");
		for(int i = 0; i < RADIX; ++i)
		{
			printf(" %2x", i);
		}

		printf("\n");

		for(int i = 0; i < RADIX; ++i)
		{
			printf("%2x ", i);

			for(int j = 0; j < RADIX; ++j)
			{
				printf("%2x ", table[i][j]);
			}

			printf("\n");
		}	
	}
	else
	{
		printf("TABLA NULA::showBoxTable\n");
	}	
}

int getValue(int table[RADIX][RADIX], int value)
{
	int value_table = -1;
	int rows = value / 16;
	int columns = value % 16;

	if((rows >= RADIX) || (columns >= RADIX))
		printf("EROR::getValue::valor ingresado no valido %i\n", value);

	else
		value_table = table[rows][columns];

	return value_table;
}