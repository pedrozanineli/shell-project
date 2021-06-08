#include "shell-lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wins;

char conversor(){

    char conv;
    char op[25];
    scanf("%s", op);

    if((strcmp(op,"exit")) == 0){
        conv = '0';

    }else if((strcmp(op,"help"))== 0){
        conv = '1';

    }else if((strcmp(op,"rfile")) == 0){
        conv = '2';

    }else if((strcmp(op,"lfile")) == 0){
        conv = '3';

    }else if((strcmp(op,"tfile")) == 0){
        conv = '4';

    }else if((strcmp(op,"dir")) == 0){
        conv = '5';

    }else if((strcmp(op,"cfile")) == 0){
        conv = '6';

    }else if((strcmp(op,"cpfile")) == 0){
        conv = '7';

    }else if((strcmp(op,"rps")) == 0){
        conv = '8';

    }else if((strcmp(op,"clear")) == 0){
        conv = '9';

    }

    return conv;
}

void playrps(){

    // Machine Choice
    int uchoice, mchoice = rand()%3, result;
    char rps[10];
    scanf("%s", rps);

    // 0 paper
    // 1 rock
    // 2 scissors

    if((strcmp(rps,"paper"))==0){
        uchoice = 0;
    }else if((strcmp(rps,"rock"))==0){
        uchoice = 1;
    }else if((strcmp(rps,"scissors"))==0){
        uchoice = 2;
    }else{
        printf("Invalid option.\n");
        return;
    }

    // 1 tie
    // 2 win
    // 3 loss

    if(uchoice == 0){
        if(mchoice == 0){
            // Tie
            result = 1;
        }else if(mchoice == 1){
            // Win
            result = 2;
        }else if(mchoice == 2){
            // Loss
            result = 3;
        }
    }
    if(uchoice == 1){
        if(mchoice == 0){
            result = 3;
        }else if(mchoice == 1){
            result = 1;
        }else if(mchoice == 2){
            result = 2;

        }
    }
    if(uchoice == 2){
        if(mchoice == 0){
            result = 2;
        }else if(mchoice == 1){
            result = 3;
        }else if(mchoice == 2){
            result = 1;
        }
    }

    if(result == 1){
        printf("Tie! Total wins: %d\n", wins);
    }else if(result == 2){
        wins++;
        printf("You won! Total wins: %d\n", wins);
    }else if(result == 3){
        printf("You lost! Total wins: %d\n", wins);
    }
}
