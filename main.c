#include <stdio.h>
#include "agenda.h"

void populateFromFile(char fileName[], Agenda *agenda[]);
void askOption();
void bindOption(int option);
void findContactByName();
void findContactByEmail();
void findContactByPhone();
void removeContactByName();

Agenda* agenda[1000];
int size = 0;


void printInformation(){
     printf("Agenda\n\n");
     printf("[1] New Contact\n");
     printf("[2] Search by Name\n");
     printf("[3] Search by E-mail\n");
     printf("[4] Search by Telephone\n");
     printf("[5] Remove contact\n");
     printf("[6] List Contacts\n");
     printf("[7] Exit\n\n");
}

void populateFromFile(char fileName[], Agenda *agenda[]) {
	FILE *file;
	file = fopen(fileName, "r");
	while(!feof(file)) {
		Agenda *contact = (Agenda*)malloc(sizeof(Agenda));
		fgets (contact->name, 50, file);
		fgets (contact->email, 50, file);
		fgets (contact->phone, 50, file);
		insert(agenda, contact, size);
		size++;
	}
	fclose(file);
}

void askOption() {
	int option;
	
	while(TRUE) {
		scanf("%d", &option);
		__fpurge(stdin);
		if (option >= 1 || option <= 7) {
			bindOption(int option);
		} else {
			printf("There's no such option. Try again.\n");
		}
	}
}

/*
* Direct the user option to the correct function.
*
*/
void bindOption(int option) {
	switch(option) {
		case 1: newContact();
		case 2: findContactByName();
		case 3: findContactByEmail();
		case 4: findContactByPhone();
		case 5: removeContactByName();
		case 6: listContacts
		case 7: exit(0);
	}
}

void findContactByName() {
	Agenda *search = (Agenda*)malloc(sizeof(Agenda));
    fgets(search->name,50,stdin);
    __fpurge(stdin);

    search = findByName(agenda, search->name, size);

    printf("Name: %s", search->name);
	printf("E-mail: %s", search->email);
	printf("Phone: %s", search->phone);
	printf("Age: %s\n", search->age);
}

void findContactByEmail() {
	Agenda *search = (Agenda*)malloc(sizeof(Agenda));
    fgets(search->email,50,stdin);
    __fpurge(stdin);

    search = findByEmail(agenda, search->email, size);

    printf("Name: %s", search->name);
	printf("E-mail: %s", search->email);
	printf("Phone: %s", search->phone);
	printf("Age: %s\n", search->age);
}

void findContactByPhone() {
	Agenda *search = (Agenda*)malloc(sizeof(Agenda));
    fgets(search->phone,50,stdin);
    __fpurge(stdin);

    search = findByPhone(agenda, search->phone, size);

    printf("Name: %s", search->name);
	printf("E-mail: %s", search->email);
	printf("Phone: %s", search->phone);
	printf("Age: %s\n", search->age);
}

void removeContactByName() {
	Agenda *remov = (Agenda*)malloc(sizeof(Agenda));
    fgets(remov->name,50,stdin);
    __fpurge(stdin);
	 int status = removeElementByName(agenda, remov->name, size);
	 if(status) {
	 	size--;
	 }
	 listContacts(agenda, size);
}

void newContact() {

	Agenda *contact = (Agenda*)malloc(sizeof(Agenda));

	printf("Contact name:");
	fgets(contact->name,50,stdin);
	__fpurge(stdin);
	printf("Contact e-mail:");
	fgets(contact->email,20,stdin);
	__fpurge(stdin);
	printf("Contact phone:");
	fgets(contact->phone,10,stdin);
	__fpurge(stdin);
	fgets(contact->age,3,stdin);
	__fpurge(stdin);

	insert(agenda, contact, size);
	size++;

	listContacts(agenda, size);
}

int main(int argc, char const *argv[])
{
	
	Agenda *contact = (Agenda*)malloc(sizeof(Agenda));

	populateFromFile("agenda.txt", agenda);
	listContacts(agenda, size);

	askOption();
	
	// FILE *file;
	// file = fopen("agenda.txt", "w");


	/*fgets(contact->name,50,stdin);
	__fpurge(stdin);
	fgets(contact->email,20,stdin);
	__fpurge(stdin);
	fgets(contact->phone,10,stdin);
	__fpurge(stdin);
	contact->age = 100;

	insert(agenda, contact,0);
	printf("%d\n", isEmpty(agenda));

	Agenda *contact2 = (Agenda*)malloc(sizeof(Agenda));
	fgets(contact2->name,50,stdin);
	__fpurge(stdin);
	fgets(contact2->email,20,stdin);
	__fpurge(stdin);
	fgets(contact2->phone,10,stdin);
	__fpurge(stdin);
	contact2->age = 20;


	insert(agenda, contact2,1);

    Agenda *contact3 = (Agenda*)malloc(sizeof(Agenda));
	fgets(contact3->name,50,stdin);
	__fpurge(stdin);
	fgets(contact3->email,20,stdin);
	__fpurge(stdin);
	fgets(contact3->phone,10,stdin);
	__fpurge(stdin);
	contact3->age = 30;


	insert(agenda, contact3,2);

	Agenda *contact4 = (Agenda*)malloc(sizeof(Agenda));
	fgets(contact4->name,50,stdin);
	__fpurge(stdin);
	fgets(contact4->email,20,stdin);
	__fpurge(stdin);
	fgets(contact4->phone,10,stdin);
	__fpurge(stdin);
	contact3->age = 50;


	insert(agenda, contact4,3);


    listContacts(agenda,4);

    Agenda *search = (Agenda*)malloc(sizeof(Agenda));
    fgets(search->name,50,stdin);
    __fpurge(stdin);

    search = findByName(agenda, search->name, 4);
    printf("%s\n", search->email);

    Agenda *remover = (Agenda*)malloc(sizeof(Agenda));
    fgets(remover->name,50,stdin);
    __fpurge(stdin);
    
    int removed =  removeElementByName(agenda, remover->name, 4);
    listContacts(agenda, 3);
   */

	//return 0;
}
