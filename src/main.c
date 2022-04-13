#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>  //for searching cryptocurrency, if I want to change it
#define MAX 100

typedef struct{
	char name[16];
	int year_of_creation;
	char founder_name[25];
	bool limited_coins;
}TCryptocurrency;

void menu(void);
void pause(void);
void clear(void);
void show(TCryptocurrency a[], int size);
void show_limited(TCryptocurrency a[], int size);
bool add(TCryptocurrency a[], int size);
bool edit(TCryptocurrency a[], int size, char name[]); // based on name
float average_year_of_creation(TCryptocurrency a[], int size);


int main()
{
	TCryptocurrency a[MAX] = {{"Bitcoin", 2009, "Satoshi Nakamoto",true}, 
	{"Ethereum", 2013, "Vitalik Buterin",false},
	{"Solana", 2019, "Anatoly Yakovenko",false},
	{"Cardano", 2017, "Charles Hoskinson",false},
	{"XRP", 2012, "Brad Garlinghouse",false},
	{"Terra", 2018, "Jon Pugh",false},
	{"Polkadot", 2016, "Gavin Wood",false},
	{"Polygon", 2021, "Vox Media",false},
	{"Litecoin", 2011, "Charlie Lee",false},
	{"Chainlink", 2020, "Sergey Nazarov",false},
	{"Cosmos", 2014, "Jae Kwon",false}
	};

	
	int choice = 1;
	int number_of_cryptocurrencies = 11;
	while (choice != 0)
	{
		clear();
		menu();
		scanf("%d", &choice);
		switch(choice)
		{
			case 0:
				return 0;
			case 1: 
				show(a,number_of_cryptocurrencies);	   
				break;
			case 2: 
				show_limited(a,number_of_cryptocurrencies);
				break;
			case 3: 
				printf("Enter the name of cryptocurrency which you wanna change: ");
				char name[16];
				scanf(" %15[^\n]s",name);
				if (edit(a,number_of_cryptocurrencies, name))
					printf("Cryptocurrency was editted.\n");
				else
					printf("There is not cryptocurrency with this name in database.\n");
				break;
			case 4: 
				if (add(a, number_of_cryptocurrencies))
				{
					printf("Cryptocurrency was added.\n");
					number_of_cryptocurrencies++; // number of cryptocurrencies increased by one
				}
				else
					printf("There is not enough space for adding a new cryptocurrency.\n");
				break;
			case 5:
				printf("Average year of creation is %.2f.\n",average_year_of_creation(a, number_of_cryptocurrencies));
				break;
			default: 
				printf("Something went wrong try it again\n");
				break;
		}
		if (choice != 0)
			pause();
	}

	return 0; 
}

void pause(void)
{
    #if defined __WIN32 || defined __WIN64
        system("pause"); 
	#else 
		system("read a");
	#endif
}

void clear(void)
{
	#ifdef _WIN32 
		system("cls");
	#elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
	    system("clear");
	//add some other OSes here if needed
	#else
		#error "OS not supported."
	#endif
}

void menu(void)
{
	clear();   
	printf(
			"Cryptocurrencies\n\n"
			"Operations\n"
			"0........exit\n"
			"1........show\n"
			"2......filter\n"
			"3........edit\n"
			"4.........add\n"
			"5.....average\n"
			"Choose operation: "
		  );
}



void show(TCryptocurrency a[], int size)
{
	clear();
	TCryptocurrency cryptocurrency;
	puts(
			"+------------------+------------------+------------------+------------------+\n"
			"+ Name             + Released in      + Founder name     + Limited coins?   +"
		);
	for (int index = 0; index < size; index++) {
		cryptocurrency = a[index];
		printf(
				"+------------------+------------------+------------------+------------------+\n"
				"| %-16s | %-16i | %-16s | %-16s |\n"
				, a[index].name, a[index].year_of_creation, a[index].founder_name, a[index].limited_coins ? "Yes" : "No"
			  );
	}
	puts("+------------------+------------------+------------------+------------------+");
	pause();
}

void show_limited(TCryptocurrency a[], int size)
{
	clear();
	TCryptocurrency cryptocurrency;
	puts(
			"+------------------+------------------+------------------+------------------+\n"
			"+ Name             + Released in      + Founder name     + Limited coins?   +"
		);
	for (int index = 0; index < size; index++) {
		if (a[index].limited_coins == true)
		{
			cryptocurrency = a[index];
			printf(
					"+------------------+------------------+------------------+------------------+\n"
					"| %-16s | %-16i | %-16s | %-16s |\n"
					, a[index].name, a[index].year_of_creation, a[index].founder_name, a[index].limited_coins ? "Yes" : "No"
				  );
			puts("+------------------+------------------+------------------+------------------+");
		}
		}
	pause();
}

bool add(TCryptocurrency a[], int size)
{
	if (size >= MAX)
		return false;
	else
	{
		TCryptocurrency new;
		int limited_coins;
		printf("Enter a name of new cryptocurrency: ");
		scanf(" %15[^\n]", new.name); //retrieve full line with spaces 
		printf("Enter the name of founder: ");
		scanf(" %15[^\n]",new.founder_name);
		printf("Enter the year that was released in: ");
		scanf("%d", &new.year_of_creation); //nacte cely radek do konce i s mezerami
		printf("Are the coins limited? '0' for No, '1' for Yes: ");
		scanf("%d",&limited_coins);
		if (limited_coins)
			new.limited_coins = true;
		else
			new.limited_coins = false;
		a[size] = new;

		return true;
	}
}


//Function, that search cryptocurrency and edit it. If it doesn't find it returns false
bool edit(TCryptocurrency a[], int size, char name[]) // based on name
{
	int index=0, limited_coins;
	while (index < size && strcmp(a[index].name, name)!= 0) // count expect that no cryptocurrency has the same name
		index++;
	if (index == size)
		return false; // it went through whole array, but the specific cryptocurrency wasn't there

	printf("The record of cryptocurrency: name: %s, released at: %d, founder: %s, limited coins: %s, ",a[index].name, a[index].year_of_creation, a[index].founder_name, a[index].limited_coins ? "Yes" : "No");
	printf("Enter the name of cryptocurrency: ");
	scanf(" %15[^\n]",a[index].name); //nacte cely radek do konce i s mezerami
	printf("Enter the year that was released in: ");
	scanf("%d",&a[index].year_of_creation);
	printf("Enter the name of founder: ");
	scanf(" %15[^\n]",a[index].founder_name); //nacte cely radek do konce i s mezerami
	printf("Are the coins limited? '0' for No, '1' for Yes: ");
	scanf("%d",&limited_coins);
	if (limited_coins)
		a[index].limited_coins = true;
	else
		a[index].limited_coins = false;

	return true;
}

float average_year_of_creation(TCryptocurrency a[], int size)
{
	float total = 0.0;
	for (int index = 0; index < size; index++)
		total += a[index].year_of_creation;
	if (size > 0)
		return total/size;
	else
		return 0; // if something goes wrong
}

