#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    
int main()
{
    //Delcare methods, initalize arrays, set vars
    void setBoard();
    void setComputerBoard();
    int playGame();
    
    char human[10];
    char computer[10];
    
    int humFlag = 0;
    int compFlag = 0;
    
    //Set pointers
    char *p = human;
    char *q = computer;
    
    
    //Set computers ship randomly
    srand(time(NULL));
    int randSpot = rand() % 10;
    
    //Start game
    setBoard(p);
    setComputerBoard(q, randSpot);
    printf("%d", playGame(p, q, humFlag, compFlag, randSpot));
    
    
    return 0;
}

void setBoard(char *p){
    //Vars being set
    int humSpot;
    
    //Prompt user
    while(humSpot > 9 || humSpot < 0){
        printf("Enter a position 0 - 9: ");
        scanf("%d", &humSpot);
    }
    
    //Set board with stars and assign ship to pos
    for(int i = 0; i < 10; i++){
            p[i] = '*';
        }
        
    p[humSpot] = 'S';
    
    
    
}

void setComputerBoard(char *q){
    //Set board with stars and assign ship to random
    for(int i = 0; i < 10; i++){
        q[i] = '*';
    }
    
}

int playGame(char *p, char *q, int humFlag, int compFlag, int randSpot){
    while(humFlag == 0 && compFlag == 0){
        //Random num generator
        int compFire;
        srand(time(NULL));
        compFire = rand() % 10;
    
        printf("Computer guesses %d \n", compFire);
        
        //Checks human board
        if(p[compFire] == 'S'){
            p[compFire] = 'H';
            printf("HIT! \n");
            printf("Computer wins! \n");
            compFlag = 1;
        }
        else{
            p[compFire] = 'M';
            printf("MISS! \n");
        }

        //Human guess
        int humFire;
        printf("Enter guess: ");
        scanf("%d", &humFire);
        
        printf("You guessed %d \n", humFire);
    
        //Checks computer board
        if(humFire == randSpot){
            q[humFire] = 'H';
            printf("HIT! \n");
            printf("Human wins! \n");
            humFlag = 1;
        }
        else{
            q[humFire] = 'M';
            printf("MISS! \n");
        }
    
        printf("Human Board: \n");
    
        printf("0 1 2 3 4 5 6 7 8 9 \n");
    
        //Prints board for human and computer
        for(int i = 0; i < 10; i++){
            printf("%c ", *(p+i));
        }
     
        printf("\nComputer Board: \n");
    
        printf("0 1 2 3 4 5 6 7 8 9 \n");
    
        for(int i = 0; i < 10; i++){
            printf("%c ", *(q+i));
        }
    
        printf("\n");
    
    }
    
    if(humFlag == 1 && compFlag == 1){
        printf("TIE!\n");
        return 2;
    }
    if(humFlag == 1){
        return 1;
    }
    if(compFlag == 1){
        return 0;
    }
    else{
        return -1;
    }
    
}