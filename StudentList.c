#include "StudentList.h"
#include <stdlib.h>


StudentList* createList(){
  StudentList* temp=(StudentList*) malloc(sizeof(StudentList)); // make malloc
  if(temp==NULL) //check if it null
  return NULL;
  temp->head=NULL;//the head pointer to the first node in the list
  return temp;
}

void deleteList(StudentList* a){
  StudentNode* curr= a->head;
while ( curr != NULL) {
a->head = a->head->next;
free(curr);
curr = a->head;
}
}


void printStudentNode(StudentNode* const a){ // print all the info of the student
    printf("The ID :%d\n",(a->st->id));
    printf("The first grade :%d\n",(a->st->grade1));
    printf("The second grade :%d\n",(a->st->grade2));
}
void printStudentList(StudentList* const a){
    StudentNode* temp=a->head;
    while(temp!=NULL){
        printStudentNode(temp);
     temp=temp->next;
    }
}
void addToList(StudentList* a, Student* b){ //  add to the end of the list 
    StudentNode* temp;
    StudentNode* n=(StudentNode*)malloc(sizeof(StudentNode)); // make malloc
    if(n==NULL) 
    return;
    n->st=b; 
    n->next=NULL;
    if(a->head==NULL){ // if a was null ,then make the node to be the head of the list
    a->head=n;
    return;
}
  
        for(temp=a->head ;temp->next!=NULL;temp=temp->next);
         temp->next=n;
    
}
         
  


