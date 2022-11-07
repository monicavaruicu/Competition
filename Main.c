#include <stdio.h>
#include <stdlib.h>
#include "Competitor.h"
#include "Menu.h"

int main()
{
    struct competitor* first = malloc(sizeof(struct competitor));
    
    first->next = NULL;
    
    char competitor_name[256];
    float competitor_score;
    char c = 0;

    int var;

    while (1)
    {
        var = menu(first);
        if (var == 0)
            break;
        printf("\n");
    }

    return 0;
}