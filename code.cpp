#nclude<stdio.h>
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

oid insert(int password, int id, char* name, char* location, char* destination, char* date) {
struct Travel * travel = (struct Travel *) malloc(sizeof(struct Travel)); travel->id = id; travel->password = password; strcpy(travel->name, name); strcpy(travel->location, location); strcpy(travel->destination, destination); strcpy(travel->date, date);
travel->next = NULL;
if(head==NULL){ // if head is NULL // set travel as the new head head = travel;
}
else{ // if list is not empty // insert travel in beginning of head travel->next = head; head = travel;
}
}
