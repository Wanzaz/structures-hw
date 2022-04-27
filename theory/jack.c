#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char name[21];
	int age;
}TPerson;

int main()
{
	FILE *in, *out;
	int n;
	TPerson person;

	in = fopen("file.txt", "r");
	out = fopen("18.txt", "w");
	if(in == NULL) return -1;
	if(out == NULL) return -1;

	//rewind()
	/*fscanf(in, "%d", &n);
	for(int i=0;i < n;i++)
	{
		fscanf(in, "%15s%d", person.name, &person.age);
		if(person.age >= 18)
			fprintf(out, "%s %d\n", person.name, person.age);
		fflush(out);
		system("pause");
	}*/

	while( fscanf(in, "%20s%d", person.name, &person.age)== 2 )
	{
		if(person.age >= 18)
			fprintf(out, "%s %d\n", person.name, person.age);
	}

	fclose(in);
	fclose(out);
	return 0;
}
