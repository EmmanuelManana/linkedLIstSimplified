/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:38:20 by emanana           #+#    #+#             */
/*   Updated: 2019/06/18 18:15:21 by emanana          ###   ########.fr       */
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

	while (n >= 0)
	{
		//isolated temp node
		temp = (node*)malloc(sizeof(node) * 1);
		temp->data = n;// insert n-- to the newly created note.
		temp->link_next = NULL;

		if (head == NULL)
		{
			head = temp;
		}
		else
		{
			created = head;
			//while there is l a node to traverse into.
			while (created->link_next != NULL)
				created = created->link_next;
			//link temp to th node pointed node.
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
node		*ft_addnodebegin(node *list, int n)
{
	node *temp;

	temp = (node*)malloc(sizeof(node) * 1);
	temp->data = n;
	temp->link_next = list;
	list = temp;
	return (list);
}

//insert a new node at the end of the list
node		*ft_addlastnode(node *list, int n)
{
	node *temp;
	node *dalist;

	dalist = list;
	temp = (node*)malloc(sizeof(node) * 1);
	temp->data = n;
	temp->link_next = NULL;

	while(dalist->link_next != NULL)
		dalist = dalist->link_next;
	dalist->link_next = temp;
	return (dalist);
}

//insert a new node on the nth node

//delte node at this position
void		deleteTargetNode(node *list, int target)
{
	node 	*temp;
	node 	*bef;
	
	//beacuse the head o fthe list is at postion 1
	temp = list;


	if (temp != NULL && temp->data == target)
	{
		list = temp->link_next;
		free(temp);
		return ;
	}
	while (temp && temp->data != target)
	{
		bef = temp;
		temp = temp->link_next;
	}
	if (temp == NULL)
		return ;
	bef->link_next = temp->link_next;
	free(temp);
}

int		main(void)
{
	//count from 10 to 1 using linked list-> create 10 nodes, then display
	node* list = createThisNumberOfNodes(10);
	//show th list
	showlist(list);

	//add a new node at the beginning of the list, and insert a 42 nyana nje
	node  *newlist  = ft_addnodebegin(list, 42);
	puts("\n");
	showlist(newlist);

	puts("\n");
	//delete the nth node
	deleteTargetNode(newlist, 5);

	// showing the list after deleteting
	showlist(newlist);



	return (0);
}
