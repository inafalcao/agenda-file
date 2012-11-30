typedef struct {
   char name[50];
   char email[20];
   char phone[10];
   char age[3];
} Agenda;

void insert(Agenda *agenda[], Agenda *contact, int size);
void listContacts(Agenda *agenda[], int size);
int removeElementByName(Agenda *agenda[], char *name, int size);
int removeElementByIndex(Agenda *agenda[], int size, int index);
Agenda *findByName(Agenda *agenda[], char *name, int size);
Agenda *findByEmail(Agenda *agenda[], char *email, int size);
Agenda *findByPhone(Agenda *agenda[], char *phone, int size);
int isEmpty(Agenda *list[]);
