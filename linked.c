/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:38:20 by emanana           #+#    #+#             */
/*   Updated: 2019/06/17 17:28:27 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	node *temp;

	last = list;
	temp = list;
	while (last->link_next != NULL)
	{
		last = last->link_next;
	}
	last->link_next = temp;
	return (temp);
}

//insert a new node on the nth node

//delte node at this position
void		deleteTargetNode(node *list, int target)
{
	node 	*del;
	node 	*trav;
	int i;

	i = 1;//beacuse the head o fthe list is at postion 1
	del = list;
	trav = list;
	while (trav->link_next && i < target)
	{
		trav = trav->link_next;
		i++;
	}
	trav->link_next = del->link_next;
	free(del);
}
int		main(void)
{
	//count from 10 to 1 using linked list-> create 10 nodes, then display
	node* list = createThisNumberOfNodes(10);
	//show th list
	showlist(list);

	//now lets add a node at the end of the list and some random number say 42
	node* addlist = ft_addlastnode(list);
	showlist(addlist);
	return (0);
}








