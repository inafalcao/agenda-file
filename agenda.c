#include "agenda.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0


/*void insert(Agenda *agenda[], Agenda *contact, int size);
void listContacts(Agenda *agenda[], int size);
int removeElementByName(Agenda *agenda[], char *name, int size);
int removeElementByIndex(Agenda *agenda[], int size, int index);
Agenda *findByName(Agenda *agenda[], char *name, int size);
Agenda *findByEmail(Agenda *agenda[], char *email, int size);
Agenda *findByPhone(Agenda *agenda[], char *phone, int size);
int isEmpty(Agenda *list[]);*/


void insert(Agenda *agenda[], Agenda *contact, int size) {
	if (size == 1000){
		return; //full
	}

	if (size == 0) {
		agenda[0] = contact;
		return;
	}

	int i;
	for (i = size-1; i >= 0; i--) {
		if(strcmp(agenda[i]->name, contact->name) > 0)	{
			agenda[i+1] = agenda[i];
			agenda[i] = contact;
		} else {
			agenda[i+1] = contact; return;
		}
	}
}

void listContacts(Agenda *agenda[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("Name: %s", agenda[i]->name);
		printf("E-mail: %s", agenda[i]->email);
		printf("Phone: %s", agenda[i]->phone);
		printf("Age: %s\n", agenda[i]->age);
	}
}

/*
*
* @returns TRUE if success
*/
int removeElementByName(Agenda *agenda[], char *name, int size) {
	int i, removedElements;
	for (i = 0; i < size; i++) {
		if(strcmp(agenda[i]->name, name) == 0)	{
			removeElementByIndex(agenda, size, i);
			return TRUE;
		}
	}
	return FALSE;
}

/*
*
* @returns number of elements removed
*/
int removeElementByIndex(Agenda *agenda[], int size, int index) {
	if (index < 0 || index >= size || isEmpty(agenda)) {
		return FALSE;
	} else {
		int i;
		for (i = index; i < size-1 ; i++) {
			agenda[i] = agenda[i+1];
		}
	}
	return TRUE;
}

Agenda *findByName(Agenda *agenda[], char *name, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if(strcmp(agenda[i]->name, name) == 0)	{
			return agenda[i];
		}
	}
	return NULL;
}

Agenda *findByEmail(Agenda *agenda[], char *email, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if(strcmp(agenda[i]->email, email) == 0)	{
			return agenda[i];
		}
	}
}

Agenda *findByPhone(Agenda *agenda[], char *phone, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if(strcmp(agenda[i]->phone, phone) == 0)	{
			return agenda[i];
		}
	}
}

int isEmpty(Agenda *list[]) {
	if (list[0] == NULL) {
		return 1;
	}
	return 0;
}
