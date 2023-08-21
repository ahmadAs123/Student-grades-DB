#include "GradesOperations.h"
#include <stdlib.h>
#include <stdio.h>

StudentList* InsertStudents(){
int id;
int g1;
int g2;
 StudentList* newS =createList();
FILE *fp;
fp = fopen("StudentsGrades.txt","r"); // open file 
if(fp == NULL)// if there is no file
{
printf("cannot open file\n");
}

   while(!feof(fp)){ 
	fscanf(fp, "%d%d%d", &id, &g1,&g2); // take the information and puts into אוגרים
	Student* stu=(Student*)malloc(sizeof(Student));
	stu->id=id;
	stu->grade1=g1;
	stu->grade2=g2;
	addToList(newS,stu);// add the new node to the list
       
   }
    return newS;
}
   
    int NumOfStudents(StudentList* a){
        int counter=0;
        StudentNode* temp=a->head;
        while(temp!=NULL){ // there is a student 
             counter+=1;
            temp=temp->next;
        }
     
        return counter;
    }
    
    int NumdidExamStudent(StudentList* a){ // number of the sudents that did only one of two exams
        int counter1=0;
         StudentNode* temp=a->head;
         while(temp!=NULL){
             if((temp->st->grade1<0 && temp->st->grade2>=0)||(temp->st->grade1>=0 && temp->st->grade2<0)){
             counter1+=1;
         }
             temp=temp->next;
         }
         return counter1;
    }
    
    int NumDidntDoExam(StudentList* a){ //number of the sudents that didnt do anyone  of two exams
         int counter=0;
         StudentNode* temp=a->head;
         while(temp!=NULL){
             if((temp->st->grade1<0)&&(temp->st->grade2<0)){// grade1 and grade2 =-1
             counter+=1;
         }
                  temp=temp->next;
         }
         return counter;
    }
    int NumStudentsDidE1(StudentList* a) {// how many student came to do the first exam
	     int counter1=0;
         StudentNode* temp=a->head;
         while(temp!=NULL){
             if(temp->st->grade1>=0)
             counter1+=1;
         
             temp=temp->next;
         }
         return counter1;
	}
	
	
	
		int NumStudentsDidE2(StudentList* a) {// how many student came to do the second exam
	     int counter1=0;
         StudentNode* temp=a->head;
         while(temp!=NULL){
             if(temp->st->grade2>=0){
             counter1+=1;
         }
             temp=temp->next;
         }
         return counter1;
	}
	
    
   double PersentOfFailE1(StudentList* a){ // the persantage of the students that faild in the first exam
        double counter=0;
         StudentNode* temp=a->head;
         while(temp!=NULL){
             
             if(temp->st->grade1<60&&temp->st->grade1!=-1){
             counter++;}
             
             temp=temp->next;
    }
    return("%f",((counter/NumStudentsDidE1(a))*100));
    
}

	
	
	
 double PersentOfFailE2(StudentList* a){// the persantage of the students that faild in the second exam
        double counter=0;
        double numS=0;
         StudentNode* temp=a->head;
         while(temp!=NULL ){
             if(temp->st->grade2<60&&temp->st->grade2!=-1){
             counter++;}
             
             temp=temp->next;
    }
    return("%f",((counter/NumStudentsDidE2(a))*100));
    
}

double AverageOfEx1(StudentList* a){//average of the first exam
        double Sum=0;
        double counter=0;
         StudentNode* temp=a->head;
         while(temp!=NULL ) { 
             if(temp->st->grade1>=0){
            counter++;
            Sum=Sum+(temp->st->grade1);
                 
             }
             temp=temp->next;
             
             
         }
         return("%f",(Sum/counter));
         }
         
         
         
         double AverageOfEx2(StudentList* a){
        double Sum=0;
        double counter=0;
         StudentNode* temp=a->head;
         while(temp!=NULL ) {
             if(temp->st->grade2>=0){
            counter++;
            Sum+=temp->st->grade2;
                 
             }
             temp=temp->next;
             
             
         }
         return("%f",(Sum/counter));
         
         }
         
         int MaxMark(StudentList* a){
             int Max=-2;
             int Max1=-2;
             int MaxId;
             int MaxId1;
              StudentNode* temp=a->head;
              StudentNode* temp1=a->head;
              while(temp!=NULL ) {// loop runs on the grades of the first exam and take the max of them
                  if(temp->st->grade1>Max && temp->st->grade1!=-1){
                      Max=temp->st->grade1;
                      MaxId=temp->st->id;
                  }
                   temp=temp->next;
             
         }
          while(temp1!=NULL ) {// loop runs on the grades of the second exam and take the max of them
                  if(temp1->st->grade2>Max1 && temp1->st->grade2!=-1){
                      Max1=temp1->st->grade2;
                      MaxId1=temp1->st->id;
                  }
                   temp1=temp1->next;
             
         }// take the max between both of them
         if(Max>Max1)
         return("%d",MaxId);
         return("%d",MaxId1);
         
         }
         
         int MinMark(StudentList* a){
             int Min=101;
             int Min1=101;
             int MinId;
             int MinId1;
              StudentNode* temp=a->head;
              StudentNode* temp1=a->head;
              while(temp!=NULL ) {// loop runs on the grades of the first exam and take the min of them
                  if(temp->st->grade1<Min && (temp->st->grade1!=-1)){
                      Min=temp->st->grade1;
                      MinId=temp->st->id;
                  }
                   temp=temp->next;
             
         }
          while(temp1!=NULL ) {// loop runs on the grades of the first exam and take the min of them
                  if(temp1->st->grade2<Min1 && temp1->st->grade2!=-1){
                      Min1=temp1->st->grade2;
                      MinId1=temp1->st->id;
                  }
                   temp1=temp1->next;
             
         }
         if(Min<Min1)// take the min between both of them
         return("%d",MinId);
         return("%d",MinId1);
         
         }
         
         
         
         
         void MakeReport(){//make the report and do free the list in the end 
            StudentList* List=InsertStudents();// insert all the information of the students that was in the file to  a list
           List=InsertStudents();
        FILE* fp= fopen("Report.txt","w"); // open the file
      
        fprintf(fp, "number of the students :%d\n" ,NumOfStudents(List));
        fprintf(fp ,"number of students that  did only one exam of the two exams :%d\n" ,NumdidExamStudent(List));
        fprintf(fp ,"number of student  that didnt do both of them :%d\n", NumDidntDoExam(List));
        fprintf(fp ,"The persentage of the students that faild in the first exam :%f\n",PersentOfFailE1(List));
        fprintf(fp ,"The persentage of student that faild in the second exam :%f\n" ,PersentOfFailE2(List));
        fprintf(fp ,"The avarage in the first exam :%f\n", AverageOfEx1(List));
        fprintf(fp ,"The avarage in the second exam :%f\n", AverageOfEx2(List));
        fprintf(fp ,"The student that had the max mark :%d\n",MaxMark(List));
        fprintf(fp, "The student that had the min mark :%d\n",MinMark(List));

        fclose(fp);// close the file 
       deleteList(List);//make free to all the nodes in the list
         }
         
         



