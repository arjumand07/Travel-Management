#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

struct Travel {
int password; int id;
char name[100];
char location[100];
char destination[100];
char date[20];
struct Travel *next;
}* head;

void insert(int password, int id, char* name, char* location, char* destination, char* date) {
struct Travel * travel = (struct Travel *) malloc(sizeof(struct Travel)); 
travel->id = id; 
travel->password = password; 
strcpy(travel->name, name); 
strcpy(travel->location, location); 
strcpy(travel->destination, destination); 
strcpy(travel->date, date);
travel->next = NULL;
if(head==NULL){ // if head is NULL // set travel as the new head head = travel;
}
else{ // if list is not empty // insert travel in beginning of head 
  travel->next = head; 
  head = travel;
}
}

void login(int id, int password) {
struct Travel * temp = head; 
while(temp!=NULL){ if((temp->id==id)&&(temp->password==password)) {
printf("ID: %d\n", temp->id); 
printf("Password: %d\n", temp->password); 
printf("Name: %s\n", temp->name); 
printf("Location: %s\n", temp->location); 
printf("Destination: %s\n", temp->destination); 
printf("Date: %s\n", temp->date); 
return;
} temp = temp->next; } printf("Account with entered password %d associated to entered id number %d is not found !!!\n", password , id);
}

void update(int id, int password) {
struct Travel * temp = head; 
  while(temp!=NULL){ if((temp->id==id)&&(temp->password==password)) {
printf("Record with password %d associated with entered id number %d Found !!!\n", password, id); 
printf("Enter new location: "); 
scanf("%s", temp->location); 
printf("Enter new destination: "); 
scanf("%s", temp->destination); 
printf("Enter new date: "); 
scanf("%s", temp->date); 
printf("Updation Successful!!!\n"); 
return;
} temp = temp->next; } printf("Account with entered password %d associated with entered id number %d is not found !!!\n", password, id)
}

void Delete(int id, int password) {
struct Travel * temp1 = head; 
struct Travel * temp2 = head; 
while(temp1!=NULL){
if((temp1->id==id)&&(temp1->password==password)) {
printf("Record with password %d associated with id number %d Found !!!\n", password, id);
if(temp1==temp2){
// this condition will run if 
  // the record that we need to delete is the first node 
  // of the linked list 
head = head->next; 
free(temp1);
}
else{ // temp1 is the node we need to delete // temp2 is the node previous to temp1 temp2->next = temp1->next; free(temp1);
}
printf("Your Trip has been cancelled sucessfully!!!\n");
printf("Account Successfully Deleted !!!\n");
return; }
temp2 = temp1; 
temp1 = temp1->next;
} 
  printf("Account with entered password %d associated with id number %d is not found !!!\n", password, id);
}

int main() {
head = NULL; 
int choice; char name[100]; 
char location[100]; 
char destination[100]; 
char date[20]; 
int password; 
int id; 
printf("1 to create travel account\n2 to login to your account\n3 to cancel the trip\n4 to modify your scheduled trip\n"); do {
printf("\nEnter Choice: ");
scanf("%d", &choice); 
switch (choice) {
case 1: printf("Enter last 4 digits of your mobile number as your travel ID: "); 
  scanf("%d", &id); 
  printf("Create 4 digit password: "); 
  scanf("%d", &password); 
  printf("Enter name: "); 
  scanf("%s", name); 
  printf("Enter location: "); 
  scanf("%s ", location); 
  printf("Enter destination: "); 
  scanf("%s", destination);
  printf("Enter date: ");
  scanf("%s", date); insert(id, password, name, location, destination, date); 
  break;
case 2: 
  printf("Enter id number to login: "); 
  scanf("%d", &id); 
  printf("Enter password for verification: "); 
  scanf("%d", &password); 
  login(id, password);
  break;
case 3: 
  printf("Enter id number to login: "); 
  scanf("%d", &id); 
  printf("Enter password for verification: ");
  scanf("%d", &password);
  Delete(id, password); break;
case 4: 
  printf("Enter id number to update your travel plan: "); 
  scanf("%d", &id); 
  printf("Enter name for verification: "); 
  scanf("%d", &password); 
  update(id, password); 
  break;
}
} 
  while (choice != 0);
}
