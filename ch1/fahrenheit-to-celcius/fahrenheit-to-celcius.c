/*
DEMO: See the usage of loops. 

Print a table with fahrenheit values and corresponding celcius values.
*/

#include <stdio.h>
#include <string.h>

struct Table{
	const char **fields;
	const int n_fields;
	const char *sep;
};

void printHeaders(const char *fields[], const int n_fields, const char *sep);
void printRow(const double fahrenheit, const double celcius, const char *fields[], const char* sep);
double toCelcius(const double fahrenheit);
struct Table makeTable(const char *fields[], const int n_fields, const char* sep);

int main(){


	struct Table temperatureTable;
	temperatureTable = makeTable( (const char *[]){"Fahrenheit", "Celcius"}, 2, "\t" );

	printHeaders(temperatureTable.fields, temperatureTable.n_fields, temperatureTable.sep);

	for (double fahrenheit=0; fahrenheit<=200; fahrenheit += 20){
		printRow(fahrenheit, toCelcius(fahrenheit), temperatureTable.fields, temperatureTable.sep);
	}
	

	return 0;
}


double toCelcius(const double fahrenheit){
	return (fahrenheit - 32) * 5 / 9;
}

void printHeaders(const char *fields[], const int n_fields, const char *sep){
	for(int i=0; i<n_fields; i++){
		printf("%s", fields[i]);
		if( i != n_fields-1 )
			printf(sep);
	}
	printf("\n");
}

void printRow(const double fahrenheit, const double celcius, const char *fields[], const char* sep){
	printf("%*.1f\t%*.1f\n", (int)strlen(fields[0]), fahrenheit, (int)strlen(fields[1]), celcius);	
}

struct Table makeTable(const char *fields[], const int n_fields, const char* sep){
	struct Table t = { fields, n_fields, sep};
	return t;
}