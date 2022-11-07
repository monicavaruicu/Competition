#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "Competitor.h"

void add_competitor_end(struct competitor* first)
{
	struct competitor* new_competitor = malloc(sizeof(struct competitor));
	struct competitor* iterator = first;
	struct competitor* last_competitor;
	
	char competitor_name[256] = "";
	float competitor_score;
	int i;
	char c;

	while (iterator->next != NULL) {
		iterator = iterator->next;
	}
	
	last_competitor = iterator;
	
	last_competitor->next = new_competitor;
	

	printf("Name of competitor: ");  c = getchar(); gets(competitor_name);
	printf("Score of competitor: "); scanf_s("%f", &competitor_score);


	for (i = 0; competitor_name[i] != NULL; i++)
		new_competitor->name[i] = competitor_name[i];
	new_competitor->name[i] = '\0';
	
	new_competitor->score = competitor_score;
	new_competitor->next = NULL;

	if (new_competitor != NULL)
		printf("\nCompetitor succesfully added!\n");
}

void add_competitor_beginning(struct competitor* first)
{
	struct competitor* new_competitor = malloc(sizeof(struct competitor));
	
	char competitor_name[256] = "";
	float competitor_score;
	int i;
	char c;

	printf("Name of competitor: "); c = getchar(); gets(competitor_name);
	printf("Score of competitor: "); scanf_s("%f", &competitor_score);

	for (i = 0; i < strlen(competitor_name); i++)
		new_competitor->name[i] = competitor_name[i];
	new_competitor->name[i] = '\0';

	new_competitor->score = competitor_score;

	new_competitor->next = first->next;
	first->next = new_competitor;

	if (new_competitor != NULL)
		printf("\nCompetitor succesfully added!\n");
}

void add_competitor_at_position(struct competitor* first)
{
	struct competitor* new_competitor = malloc(sizeof(struct competitor));
	struct competitor* iterator = first;
	
	char competitor_name[256] = "";
	float competitor_score;
	int i;
	char c;

	int nr = 0;
	int pos;

	printf("The position: "); scanf_s("%d", &pos);

	while (iterator->next != NULL && nr != pos - 1)
	{
		iterator = iterator->next;
		nr++;
	}

	if (nr != pos - 1)
	{
		printf("Position not found!");
		return;
	}

	new_competitor->next = iterator->next;
	iterator->next = new_competitor;

	printf("Name of competitor: "); c = getchar(); gets(competitor_name);
	printf("Score of competitor: "); scanf_s("%f", &competitor_score);

	for (i = 0; i < strlen(competitor_name); i++)
		new_competitor->name[i] = competitor_name[i];
	new_competitor->name[i] = '\0';

	new_competitor->score = competitor_score;

	if (new_competitor != NULL)
		printf("\nCompetitor succesfully added!\n");
}

void sort_competitors(struct competitor* first)
{
	struct competitor* iterator;
	
	int ord;
	float temp;
	
	char str[256] = "";
	int i;

	do
	{
		iterator = first->next;
		ord = 1;

		while (iterator->next != NULL)

		{
			if (iterator->score < iterator->next->score)

			{
				temp = iterator->score;
				for (i = 0; i < strlen(iterator->name); i++)
					str[i] = iterator->name[i];
				str[i] = '\0';
			

				iterator->score = iterator->next->score;
				for (i = 0; i < strlen(iterator->next->name); i++)
					iterator->name[i] = iterator->next->name[i];
				iterator->name[i] = '\0';

				iterator->next->score = temp;
				for (i = 0; i < strlen(str); i++)
					iterator->next->name[i] = str[i];
				iterator->next->name[i] = '\0';


				ord = 0;

			}

			iterator = iterator->next;
		}

	}

	while (ord == 0);

	printf("\nCompetitors succesfully sorted by score!\n");
}


void search_competitor(struct competitor* first)
{
	struct competitor* iterator = first;

	int ok = 0;
	char name[256] = "";
	char c;
	int nr = 0;

	printf("Search a competitor: "); c = getchar(); gets(name);

	if (first->next == NULL)
		printf("The list is empty\n");
	else
	{
		while (iterator->next != NULL)
		{
			if (strcmp(iterator->next->name, name) == 0)
			{
				ok = 1;
				break;
			}

			iterator = iterator->next;
			nr++;
			
		}

		if (ok == 1)
			printf("The competitor was found at position %d\n", nr + 1);
		else
			printf("The competitor was not found!\n");
	}


}


void print_competitors(struct competitor* first)
{
	struct competitor* iterator = first;

	while (iterator->next != NULL)
	{
		printf("%s\n", iterator->next->name);
		printf("%.2f\n\n", iterator->next->score);
		iterator = iterator->next;
	}
}

void accepted_list(struct competitor* first)
{
	struct competitor* first_accepted = malloc(sizeof(struct competitor));
	first_accepted->next = NULL;

	struct competitor* first_rejected = malloc(sizeof(struct competitor));
	first_rejected->next = NULL;

	struct competitor* iterator = first;
	
	while (iterator->next != NULL)
	{
		if (iterator->next->score >= 50)
			add_accepted_rejected_list(first_accepted, iterator->next->name, iterator->next->score);
		else
			add_accepted_rejected_list(first_rejected, iterator->next->name, iterator->next->score);

		iterator = iterator->next;
	}

	printf("Accepted competitors:\n\n");
	print_competitors(first_accepted);

	printf("Rejected competitors:\n\n");
	print_competitors(first_rejected);
}

void add_accepted_rejected_list(struct competitor* first, char name[256], float score)
{

	struct competitor* new_accepted_rejected_competitor = malloc(sizeof(struct competitor));
	struct competitor* iterator = first;
	struct competitor* last_competitor;

	int i;

	while (iterator->next != NULL) {
		iterator = iterator->next;
	}

	last_competitor = iterator;

	last_competitor->next = new_accepted_rejected_competitor;

	for (i = 0; name[i] != NULL; i++)
		new_accepted_rejected_competitor->name[i] = name[i];
	new_accepted_rejected_competitor->name[i] = '\0';

	new_accepted_rejected_competitor->score = score;
	new_accepted_rejected_competitor->next = NULL;
}




