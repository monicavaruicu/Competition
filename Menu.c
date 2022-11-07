#include <stdio.h>
#include <string.h>
#include "Competitor.h"
#include "Menu.h"

int menu(struct competitor* first)
{
	printf("1.Add a competitor at the end of the list\n");
	printf("2.Add a competitor at the beginnig of the list\n");
	printf("3.Add a competitor at a certain position of the list\n");
	printf("4.Print the list of competitors\n");
	printf("5.Sort the list of the competitors by score\n");
	printf("6.Search by name\n");
	printf("7.Sort and print the competitors by their status(accepted/rejected)\n");
	printf("Press 0 to exit\n\n");


	int ch = 0;
	int pos = -1;
	printf("Choose an option: ");
	scanf_s("%d", &ch);

	switch (ch)
	{
	case 1:
		system("cls");
		add_competitor_end(first);
		break;
	case 2:
		system("cls");
		add_competitor_beginning(first);
		break;
	case 3:
		system("cls");
		add_competitor_at_position(first);
		break;
	case 4:
		system("cls");
		print_competitors(first);
		break;
	case 5:
		system("cls");
		sort_competitors(first);
		break;
	case 6:
		system("cls");
		search_competitor(first);
		break;
	case 7:
		system("cls");
		accepted_list(first);
		break;
	case 0:
		return 0;
		break;
	default:
		system("cls");
		printf("Invalid option!\n");
	}



}