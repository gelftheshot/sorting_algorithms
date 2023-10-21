#include "sort.h"

/**
 *
 *
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *temp;
    listint_t *newtemp;
    listint_t *prev;
    listint_t *prev_prev;
    listint_t *next;
    listint_t *current;


    temp = (*list) ->next;

    while (temp)
    {
        newtemp = temp;
        while(newtemp->prev)
        {
            if ( newtemp && (newtemp->n < newtemp->prev->n))
            {
                current = newtemp;
                prev = current->prev;
                prev_prev = prev->prev;
                next = current->next;
                
                if (prev_prev)
                    prev_prev->next = current;
                else
                    *list = newtemp;

                current->prev = prev_prev;
                current->next = prev;
                prev->prev = current;
                prev->next = next;
                if (next)
                    next->prev = prev;
                print_list(*list);

                newtemp = current;
            }
            else
                break;
        }
       temp = temp->next; 
    }
}
