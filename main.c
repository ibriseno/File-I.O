
/* 
 * File:   main.c
 * Author: Ivan Briseno
 *
 * Created on February 5, 2019, 12:51 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*------------------------Hold Student Information--------------------------*/
typedef struct{
    float scoreA;
    float scoreB;
    char studentName[20];
    int number;
}studentInfo;

/*------------------Sort Students based on Score A----------------------------*/

void swap( studentInfo *x, studentInfo *y){
studentInfo temp =  *x;
*x = *y;
*y = temp;
}


void sort(studentInfo student[], int count) {
    int j = 0;
    int i = 0;
    
    printf("\n\nStudents sorted by score A: \n");
    for (i = 1; i < count; i++) {
        for (j = 1; j < (count - i); j++) {
            
            if (student[j].scoreA > student[j + 1].scoreA) {
                swap(&student[j], &student[j+1]);
                
              
            }  
        }
    }
}


/*------------------Determine which students got a diploma--------------------*/
void gotDiploma(studentInfo student[], int count){
    int i = 0;
    printf("\n\nStudents that received a diploma: \n");
    for(i = 0; i< count; i++){
        if(student[i].scoreA >= 50 && student[i].scoreB >= 50)
            printf("%s\t%d\t%.2f\t%.2f\n",student[i].studentName, student[i].number, student[i].scoreA, student[i].scoreB);
      
    }
    
}

/*--------------------Find the average of each subject-------------------------*/
float findAVG_A(studentInfo student[], int count){
    int i = 0;
    float sumA = 0.0;
    float averageA = 0.0;
   
   
    for(i = 0; i < count; i++){
        sumA += student[i].scoreA;
        averageA = sumA/i;
    
     
    }   printf("\nAverage Score for Subject A: %.2f\n", averageA);
    return averageA;
}
 float findAVG_B(studentInfo student[], int count){   
    int i = 0;
    float sumB = 0.0;
    float averageB = 0.0;
  
   
      for(i = 0; i < count; i++){
     sumB += student[i].scoreB;
     averageB = sumB/i;
      }
     printf("Average Score for Subject B: %.2f\n", averageB);
     return averageB;
    }
  
   

/*-------------------Find the Standard Deviation of each Subject----------------*/
 float findSTD_A(studentInfo student[], int count){   
    float sumSTDA = 0.0;
    float divSTDA = 0.0;
    
     float sumA = 0.0;
     float averageA = 0.0;
    
    for(int i = 1; i < count; i++){ 
    sumA += student[i].scoreA;
    averageA = sumA/i;
    sumSTDA += pow((student[i].scoreA - averageA),2);
    divSTDA = sumSTDA/count;
     }
    printf("\nStandard Deviation for Score A: %.2f\n",  sqrt(divSTDA));
    return (sqrt(divSTDA));
 
 }  
  float findSTD_B(studentInfo student[], int count){
    float sumSTDB = 0.0;
    float divSTDB = 0.0;
    
    float sumB = 0.0;
    float averageB = 0.0;
    
    for(int i = 1; i < count; i++){ 
          sumB += student[i].scoreB;
     averageB = sumB/i;
    sumSTDB += pow((student[i].scoreB - averageB),2);
    divSTDB = sumSTDB/count;
    }
    
  printf("Standard Deviation for Score B: %.2f\n", sqrt(divSTDB));
   return (sqrt(divSTDB));
   
    }
   



/*------------------------Create new file to store copy---------------------------*/
void storeFile(studentInfo student[], int count, FILE *output){
   fprintf(output, "Student Name\tStudent No.\tSubject A\tSubject B\n");
   for(int i = 1; i < count; i++){
   fprintf(output,"%s\t\t%d\t\t%.2f\t\t%.2f\n",student[i].studentName, student[i].number, student[i].scoreA, student[i].scoreB);
    }
  
   fprintf(output,"\n\n Average for Subject A is: %.2f", findAVG_A(student, count));
   fprintf(output,"\n\n Average for Subject B is: %.2f", findAVG_B(student, count));
   fprintf(output,"\n\n Average for Subject A is: %.2f", findSTD_A(student, count));
   fprintf(output,"\n\n Average for Subject A is: %.2f", findSTD_B(student, count));
}


int main() {
    char temp[200];
    char c[200];
    
    char fileName[30];
    char tempFile[30];
   
    char inputMenu;
    int count = 0;
    studentInfo student[100];
    FILE *fptr2;
   
    
    
    /*--------------Ask user for file name-----------------*/
    printf("Please enter a file name to open: ");
    scanf("%s", &fileName);
    printf("\nName: %s\n", fileName);
    FILE *fptr = fopen(fileName, "r");
   
    /*---------------Check For Empty File----------------*/
    if(fptr == NULL){
        printf("Error");
        exit(0);
    }
 
   /*---------------Grab Contents of File and Display Original File----------------*/
    while(fgets(c, 200, fptr) != NULL){
        printf("%s", c);
        sscanf(c, "%s\t%d\t%f\t%f\n", student[count].studentName, &student[count].number,
                &student[count].scoreA, &student[count].scoreB);
        count++;
    }
    
    /*--------------------------------Menu---------------------------------------*/
    printf("\n\n\tMenu\n");
    printf("a) Obtain all the students that got a diploma\n"
            "b) Arrange Subject A in ascending order\n"
            "c) Calculate the Average and Standard Deviation\n"
            "d) Save all the above results in an output file\n"
            "e) Exit\n");
    
    printf("\nSelect an option: ");
    scanf("%s", &inputMenu);
    
    while(inputMenu != 'e'){
   if(inputMenu == ' '){
       printf("\n\n\tMenu\n");
    printf("a) Obtain all the students that got a diploma\n"
            "b) Arrange Subject A in ascending order\n"
            "c) Calculate the Average and Standard Deviation\n"
            "d) Save all the above results in an output file\n"
            "e) Exit\n");
        printf("\nPlease select another option: ");
        scanf("%s", &inputMenu);
   }     
    if(inputMenu == 'a'){
        gotDiploma(student, count);
        inputMenu = ' ';
        
    }else if(inputMenu == 'b'){
        sort(student, count);
        for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%.2f\t%.2f\n", student[i].studentName, student[i].number,
                student[i].scoreA, student[i].scoreB);
        }
        inputMenu = ' ';
    }else if(inputMenu == 'c'){
       findAVG_A(student, count);
       findAVG_B(student, count);
       
       findSTD_A(student, count);
       findSTD_B(student, count);
       
        inputMenu = ' ';
    }
   /*----------------------Create a new file and save output there-------------*/
    else if(inputMenu == 'd'){
        printf("Enter name of new file: ");
        scanf("%s", &tempFile);
        fptr2 = fopen(tempFile, "w");
        storeFile(student, count, fptr2);
        inputMenu = ' ';
        fclose(fptr2);
    }
    else if(inputMenu == 'e'){
        printf("\nNow exiting the Menu \nThank you!\n");
        break;
        
    }
    }

    /*----------------Test Section/Print out Information--------------------*/

   
    fclose(fptr2);
    fclose(fptr);
    return 0;
}

