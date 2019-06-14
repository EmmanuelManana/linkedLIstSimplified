


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


//a simple structure of a node
typedef	struct s_struct
{
	int data;
	//link to the next node
	struct s_struct *link_next;
}
		node;
//create nth number of nodes and put n--  in all of them
node  *createThisNumberOfNodes(int n)
{
	node *temp = NULL;//store address of first note
	node *created = NULL;
	node *head = NULL;

	temp = (node*)malloc(sizeof(node) * 1);
	while (n >= 0)
	{
		//allocate mem nth times
		temp = (node*)malloc(sizeof(node) * 1);
		//temp->link_next = temp; // point to the newly created node.
		temp->data = n;// insert n-- to the newly created note.
		temp->link_next = NULL;//point the last node to NULL.
		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			created = head;
			//while there is still a node to traverse into.
			while (created->link_next != NULL)
				created = created->link_next;
			//place a NUll at the end of the last node.
			created->link_next = temp;
		}
		n--;
	}
	return (head);
}

//display the list
void 		showlist(node *head)
{
	node	*temp;

	temp = head;
	while (temp->link_next != NULL)// while there is node traverse into
	{
		printf("%d\n", temp->data);
		temp = temp->link_next;
	}
}

//add new node at the beginning of the linked list
node		*ft_addfirstnode(node *list, int n)
{
	node *temp;

	temp = (node*)malloc(sizeof(node) * 1);
	temp->data = n;
	temp->link_next = list;
	list = temp;
	return (list);
}

//insert a new node at the end of the list
node		*ft_addlastnode(node *list)
{
	node *last;

	last = (node*)malloc(sizeof(node) * 1);
	while (list->link_next != NULL)
	{
		last->link_next = list;
		list = last;
	}
	return (last);
}

//insert a new node on the nth node

int		main(void)
{
	//count from 1 to 10 using linked list-> create 10 nodes, then display
	showlist(createThisNumberOfNodes(10));
	return (0);
}
