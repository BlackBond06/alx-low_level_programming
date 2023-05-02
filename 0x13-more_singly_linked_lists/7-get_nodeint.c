#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: Entry point  into the linked list
 * @index: index of the listint_t to be returned
 *
 * Return: pointer to the node, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int i = 0;
listint_t *temp = head;

while (temp && i < index)
{
temp = temp->next;
i++;
}

return (temp ? temp : NULL);
}
