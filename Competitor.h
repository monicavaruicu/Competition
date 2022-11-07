#pragma once

struct competitor
{
	char name[256];
	float score;
	struct competitor *next;
};

void add_competitor_end(struct competitor* first);
void add_competitor_beginning(struct competitor* first);
void add_competitor_at_position(struct competitor* first);
void sort_competitors(struct competitor* first);
void search_competitor(struct competitor* first);
void accepted_list(struct competitor* first);
void add_accepted_rejected_list(struct competitor* first, char name[256], float score);