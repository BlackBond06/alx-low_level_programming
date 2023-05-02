#include "lists.h"

/**
 * insert_nodeint_at_index - that inserts a new node at a given position.
 * @head: Entry point into the linked list
 * @idx: index where the node is inserted
 * @n: data to insert into the new node
 *
 * Return: pointer to the node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int i;
listint_t *new;
listint_t *temp = *head;

new = malloc(sizeof(listint_t));
if (!new || !head)
return (NULL);

new->n = n;
new->next = NULL;

if (idx == 0)
{
new->next = *head;
*head = new;
return (new);
}

for (i = 0; temp && i < idx; i++)
{
if (i == idx - 1)
{
new->next = temp->next;
temp->next = new;
return (new);
}
else
temp = temp->next;
}

return (NULL);
}
