//=================================================================
// Copyright 2021 Georgia Tech.  All rights reserved.
// The materials provided by the instructor in this course are for
// the use of the students currently enrolled in the course.
// Copyrighted course materials may not be further disseminated.
// This file must not be made publicly available anywhere.
//=================================================================

/*    
Please fill in the following
 Student Name: Spencer Kim
 Date: 3/1/2021

ECE 2035 Project 1-1

This is the only file that should be modified for the C implementation
of Project 1.

Do not include any additional libraries.
------------------------------------------

Match Puzzle

This program finds the reference pattern in the candidates which might be
rotated or flipped.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DEBUG 0 // RESET THIS TO 0 BEFORE SUBMITTING YOUR CODE

int main(int argc, char *argv[]) {
  int  Reference;
  int  Candidates[8];
  int  NumCandidates;
  int  Position = -9; //temporary initial value (you can change it)
  int  Load_Reference(char *);
  int  Load_Mem(char *, int *);

  if (argc != 2) {
    printf("usage: ./P1-1 testfile\n");
    exit(1);
  }
  Reference = Load_Reference(argv[1]);
  if (Reference == 0) {
    printf("Invalid Reference pattern.\n");
    exit(1);
   }
  NumCandidates = Load_Mem(argv[1], Candidates);
   if (NumCandidates != 8) {
      printf("testfiles must contain 8 candidates\n");
      exit(1);
   }

   /* Your program goes here */
    int ReferenceArray[8];
    int CandidatesArray[8][8];//2D array

    for(int i=0; i<8; i++){// Making the Reference Array
        ReferenceArray[i]= ((Reference >> (2 * i)) & 0x3);
    }

    int arr90[8]={ReferenceArray[6], ReferenceArray[7], ReferenceArray[0], ReferenceArray[1]		    	,ReferenceArray[2],ReferenceArray[3],ReferenceArray[4],ReferenceArray[5]};// 90 Degree Rotation
    int arr180[8]={ReferenceArray[4], ReferenceArray[5], ReferenceArray[6], ReferenceArray[7],ReferenceArray[0],ReferenceArray[1],ReferenceArray[2],ReferenceArray[3]};// 180 Degree Rotation
    int arr270[8]={ReferenceArray[2], ReferenceArray[3], ReferenceArray[4], ReferenceArray[5],ReferenceArray[6],ReferenceArray[7],ReferenceArray[0],ReferenceArray[1]};// 270 Degree Rotation
    int arrHorz[8]={ReferenceArray[6], ReferenceArray[5], ReferenceArray[4], ReferenceArray[3],ReferenceArray[2],ReferenceArray[1],ReferenceArray[0],ReferenceArray[7]};// Horizontal Flip
    int arrVert[8]={ReferenceArray[2], ReferenceArray[1], ReferenceArray[0], ReferenceArray[7],ReferenceArray[6],ReferenceArray[5],ReferenceArray[4],ReferenceArray[3]};// Vertical Flip
    int arr90andHorz[8]={ReferenceArray[4], ReferenceArray[3], ReferenceArray[2], ReferenceArray[1],Refe	renceArray[0],ReferenceArray[7],ReferenceArray[6],ReferenceArray[5]};//90 Rotation and Horz Flip
    int arr90andVert[8]={ReferenceArray[0], ReferenceArray[7], ReferenceArray[6], ReferenceArray[5],ReferenceArray[4],ReferenceArray[3],ReferenceArray[2],ReferenceArray[1]};//90 Rotation and Vertical Flip
    // Lines 65-71 are creating arrays of the variations of the Reference
    
    for (int i=0; i<8; i++){// Creates the 2D array from the Candidates array
        for(int p=0; p<8; p++){
            CandidatesArray[i][p]= ((Candidates[i] >> (2 * p)) & 0x3);
        }
    }
    
    
    bool yorn=false;
    
    for(int a=0; a<8; a++){//For loops to check 90 degree rotation
        for(int b=0; b<8; b++){
            if (CandidatesArray[a][b] == arr90[b])
            {
                yorn= true;
            }
            else
            {
                yorn=false;
                break;
            }
        }
        if(yorn==true){
            Position=a;
            break;
        }
    }
    for(int a=0; a<8; a++){//For loops to check 180 Degree Rotation
        for(int b=0; b<8; b++){
            if (CandidatesArray[a][b] == arr180[b])
            {
                yorn= true;
            }
            else
            {
                yorn=false;
                break;
            }
        }
        if(yorn==true){
            Position=a;
            break;
        }
    }
    for(int a=0; a<8; a++){// For loops to check 270 Degree Rotation
        for(int b=0; b<8; b++){
            if (CandidatesArray[a][b] == arr270[b])
            {
                yorn= true;
            }
            else
            {
                yorn=false;
                break;
            }
        }
        if(yorn==true){
            Position=a;
            break;
        }
    }
    for(int a=0; a<8; a++){//For loops to check Horizontal Flip
        for(int b=0; b<8; b++){
            if (CandidatesArray[a][b] == arrHorz[b])
            {
                yorn= true;
            }
            else
            {
                yorn=false;
                break;
            }
        }
        if(yorn==true){
            Position=a;
            break;
        }
    }
    for(int a=0; a<8; a++){// For Loops to check Vertical Flip
        for(int b=0; b<8; b++){
            if (CandidatesArray[a][b] == arrVert[b])
            {
                yorn= true;
            }
            else
            {
                yorn=false;
                break;
            }
        }
        if(yorn==true){
            Position=a;
            break;
        }
    }
    for(int a=0; a<8; a++){// For loops to check 90 degree rotation and Horz Flip
        for(int b=0; b<8; b++){
            if (CandidatesArray[a][b] == arr90andHorz[b])
            {
                yorn= true;
            }
            else
            {
                yorn=false;
                break;
            }
        }
        if(yorn==true){
            Position=a;
            break;
        }
    }
    for(int a=0; a<8; a++){// For loops to check 90 degree and Vertical Flip
        for(int b=0; b<8; b++){
            if (CandidatesArray[a][b] == arr90andVert[b])
            {
                yorn= true;
            }
            else
            {
                yorn=false;
                break;
            }
        }
        if(yorn==true){
            Position=a;
            break;
        }
    }
    
   /* Use a statement like this to print information helpful to
      debugging (e.g., the current value of some variable).
      Set DEBUG to 1 using the #define above when debugging, but
      reset it back to 0 before submitting your code so that your
      program doesn't confuse the autograder with superfluous prints. */
   if (DEBUG){
     printf("Reference: %d == 0x%08x\n", Reference, Reference);
   }

   // your program should use this print statement to report the answer
   printf("The matching pattern is at position [0-7]: %d\n", Position);
   exit(0);
}

/* This routine reads in one integer value from the first line of a named file in the local directory (each line of the file is in the form Addr: integer). The integer is returned. */

int Load_Reference(char *InputFileName) {
  int	Reference, NumVals, Addr, Value;
  FILE	*FP;

  FP = fopen(InputFileName, "r");
  if (FP == NULL) {
    printf("%s could not be opened; check the filename\n", InputFileName);
    return 0;
  } else {
    NumVals = fscanf(FP, "%d: %d", &Addr, &Value);
    if (NumVals == 2)
      Reference = Value;
    else {
      printf("test file must contain Addr: Value pairs on each line.\n");
      Reference = 0;
    }
    fclose(FP);
    return Reference;
   }
}

/* This routine loads in up to 8 newline delimited integers from
a named file in the local directory. The values are placed in the
passed integer array. The number of input integers is returned. */

int Load_Mem(char *InputFileName, int IntArray[]) {
   int	N, Addr, Value, NumVals;
   FILE	*FP;

   FP = fopen(InputFileName, "r");
   if (FP == NULL) {
     printf("%s could not be opened; check the filename\n", InputFileName);
     return 0;
   } else {
     fscanf(FP, "%d: %d", &Addr, &Value); // ignore first line
     for (N=0; N < 8; N++) {
       NumVals = fscanf(FP, "%d: %d", &Addr, &Value);
       if (NumVals == 2)
	 IntArray[N] = Value;
       else
	 break;
     }
     fclose(FP);
     return N;
   }
}
