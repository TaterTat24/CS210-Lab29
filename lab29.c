/** vector.c
* ================================================================
* Name: Benjamin Tat
* Section: T6
* Project: Lab29 - Vector ADT
* =================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// Task 1:  Write Your getNumLines Function Here
int getNumLines(char filename[]){
    FILE* inputFile = NULL;
    int numberLines = 0;
    char line[1000];

    inputFile = fopen(filename, "r");

    if (inputFile == NULL) {
        printf("Could not open file.\n");
        return -1; // -1 indicates error
    }

    while (!feof(inputFile)) {
        fgets(line, 1000, inputFile);
        numberLines = numberLines + 1;
    }
    
    fclose(inputFile);

    return numberLines;
}

// Task 3:  Write your readFile Function Here
void readFile(char fileName[], vector* v, int numberLinesInFile){
   FILE* inputFile = NULL;
   int number;

   inputFile = fopen(fileName, "r");
    
   for (int i = 0; i < numberLinesInFile; i++) {
      fscanf(inputFile, "%d,", &number);
      vector_set(v, i, number);
   }

   fclose(inputFile);
}

int main(void) {   
   // Task 0
   //  Open the vector.h file and see what operations are available

   // Task 2
   //  With the functions provided in the Vector ADT,
   //  create a correctly sized vector to read-in all
   //  data from the lab29Data.csv file
   int numberLinesInFile;
   vector v;

   numberLinesInFile = getNumLines("lab29Data.csv");
   
   vector_create(&v, numberLinesInFile);

   // Task 4
   //  Utilize your readFile() function
   //  to populate the vector -- you will need to make changes
   //  for this function to perform correctly
   readFile("lab29Data.csv", &v, numberLinesInFile);

   // Task 5
   //  With the functions provided in the Vector ADT,
   //  print the number of vector elements
   printf("%d\n", vector_size(&v));
    
   // Task 6
   //  With the functions provided in the Vector ADT,
   //  insert a 12 at index 139
   vector_insert(&v, 139, 12);

   // Task 7
   //  With the functions provided in the Vector ADT,
   //  print the number of vector elements
   printf("%d\n", vector_size(&v));
    
   // Task 8
   //  With the functions provided in the Vector ADT,
   //  print the element at index 999
   printf("%d\n", *vector_at(&v, 999));

   // Task 9
   //  With the functions provided in the Vector ADT,
   //  erase the element at index 999
    vector_erase(&v, 999);
    
   // Task 10
   //  With the functions provided in the Vector ADT,
   //  print the element at index 999
   printf("%d\n", *vector_at(&v, 999));

   // Task 11
   //  With the functions provided in the Vector ADT,
   //  print the number of vector elements
   printf("%d\n", vector_size(&v));

   // Task 12
   //  Using the Vector ADT provided function
   //  vector_push_back to insert the integer 222
   vector_push_back(&v, 222);

   // Task 13
   //  With the functions provided in the Vector ADT,
   //  print the number of vector elements
   printf("%d\n", vector_size(&v));

   // Task 14
   //  With the functions provided in the Vector ADT,
   //  destroy the vector
   vector_destroy(&v);
}