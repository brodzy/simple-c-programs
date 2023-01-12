#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//Creating Point Struct
struct Point{
     int x;
     int y;
};

//Creating Line Struct with Points Structs inside
struct Line{
     struct Point a;
     struct Point b;
     float length;
};

void readFile(char file_name[], int *n, struct Line *p){
    //Opening file
   FILE *file = fopen(file_name, "r");
   
   if(file == NULL){
      perror("Unable to open the file");
      exit(1);
   }
   
   //Scanning first line of file
    fscanf(file, "%d", &*n);
    printf("Array of size 200 created\n");
    
    //Assigning points to structs while going through file
    int i = *n;
    int j = 0;
    while(i > 0){
        fscanf(file, "%d %d %d %d", &p[j].a.x, &p[j].a.y, &p[j].b.x, &p[j].b.y);
        j++;
        i--;
    }
    
    printf("\nData read\n");
    
     fclose(file);
}
 
void computeLengths(struct Line *lines, int n){
    printf("\nComputing lengths...\n");
    
    //Calculating line length with distance formula then assigning to length member
    int j = 0;
    while(n > 0){
        float distance = ((lines[j].b.x - lines[j].a.x)*(lines[j].b.x-lines[j].a.x))+((lines[j].b.y - lines[j].a.y)*(lines[j].b.y - lines[j].a.y));
        lines[j].length = sqrt(distance);
        j++;
        n--;
    }
    
     printf("\nLength computation completed\n");
}
 
void saveLengths(struct Line *lines, int n){
    printf("\nSaving lengths...\n");
    
    //Writing line length to text file
    FILE *file = fopen("lengths_write.txt", "w");
    int j = 0;
    
    while(n > 0){
        fprintf(file, "%.1f\n", lines[j].length);
        
        j++;
        n--;
    }
    
    fclose(file);
     
}
 
void printStats(struct Line* lines, int n){
    //Created array of lengths
    float lengths[n];
    for(int i = 0; i < n; i++){
        lengths[i] = lines[i].length;
    }
    
    //Calcualting max
    float max = lengths[0];
    for (int j = 0; j < n; j++) {
        if (lengths[j] > max) {
            max = lengths[j];
        }
    }
    
    //Calculating min
    float min = lengths[0];
    for (int k = 0; k < n; k++) {
        if (lengths[k] < min) {
            min = lengths[k];
        }
    }
    
    //Calcualting avg
    float avg = 0;
    float sum = 0;
    for (int l = 0; l < n; l++) {
        sum += lengths[l];
    }
    avg = sum / n;
    
     printf("\nLine of max length: %.1f\n\n", max);
     
     printf("Line with min length: %.1f\n\n", min);
     
     printf("Average line length: %.1f", avg);
}


int main(int argc, char *argv[])
{
   //Take name of the input file as a command-line argument
   char fileName[100] = "sample_input.txt";
   int n;
   struct Line *p;
   struct Line lines[200];
   p = &lines[0];
   
   //Call read file
   readFile(fileName, &n, p);
   
   //Call compute lengths
   computeLengths(p, n);
   
   //Call save lengths
   saveLengths(p, n);
  
  //Asking user for rotated array if not call print stats
  char answer;
  printf("\nDo you want to use rotated array? Please enter Y or N: ");
  scanf("%c", &answer);
   
  if (answer == 'N' || answer == 'n'){
      printStats(p, n);
  }
  else if(answer == 'Y' || answer == 'y'){
      printf("\nNot Implemented");
  }
  else{
      printf("\nMake sure to enter Y/y or N/n");
  }
  
    return 0;
}