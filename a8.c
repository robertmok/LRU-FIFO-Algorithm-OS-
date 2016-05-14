#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    int choice;
    FILE *fp;
    char *token;
    char delimiter[1] = ",";
    char line[48];
    int i;
    int mem[8];
    int temp[8];
    int x;
    int pagefaults = 0;
    int index = 0;
    int exists = 0;
    int y;
    int z;
    int w;
    int counter = 0;
    int lru = 3;
    int s = 0;
    int r = 0;
    int q = 0;
    int p = 0;
    int n = 0;
    int here = 0;
    int exist2 = 0;
    int count = 0;
    int count2 = 0;

    printf("Press 1 for LRU, Press 2 for FIFO: ");
    scanf("%d",&choice);

    fp = fopen("input.txt", "r");

    if(fp != NULL){
        fgets(line, sizeof line, fp);
        token = strtok(line, delimiter);
        if (choice == 1){ //LRU
            i = 0;
            counter = 0;
            while(token != NULL){
                 //24 referenced pages
                //printf("counter = %d\n", counter);
                printf("%s: ",token);
                if (i < 4){ //if mem still have slot for a page
                    temp[0] = atoi(token);
                    counter++;
                    pagefaults++;
                    for(r = 0; r < i; r++){
                        temp[r+1] = mem[r];
                    }
                    for(q = 0; q < counter; q++){
                        mem[q] = temp[q];
                        printf("%d ", temp[q]);
                    }
                    printf("| \n");
                } else { //mem does not have a slot for a page
                    for (x = 0; x < 4; x++){ //find if page exist already
                        if (mem[x] == atoi(token)){
                            exists = 1;
                            index = x;
                        }
                    }
                    if (exists == 1){ //page is already in mem
                        temp[0] = mem[index];
                        if (counter < 8) { //page is in mem with less than 8 pages
                            count = 1;
                            count2 = 0;
                            for (y = 0; y < counter; y++){ //update memory stack, put page at the front
                                if (y != index){ //dont copy the exist page in the same spot
                                    temp[count] = mem[count2];
                                    count++;
                                    count2++;
                                } else {
                                    count2++;
                                }
                            }
                            for (w = 0; w < counter; w++){
                                mem[w] = temp[w];
                                if (w == 4) { printf("| "); };
                                printf("%d ", temp[w]);
                            }
                            printf("\n");
                        } else { //page is in mem with 8 pages
                            counter = 8;
                            count = 1;
                            count2 = 0;
                            for(p = 0; p < 8; p++){
                                if(p != index){
                                    temp[count] = mem[count2];
                                    count++;
                                    count2++;
                                } else {
                                    count2++;
                                }
                            }
                            for (p = 0; p < 8; p++){
                                mem[p] = temp[p];
                                if (p == 4) { printf("| "); };
                                printf("%d ", temp[p]);
                            }
                            printf("\n");
                        }
                    } else { //page is not in mem
                        if(counter < 8){ //mem has less than 8 pages
                            for(n = 0; n < counter; n++){
                                if (mem[n] == atoi(token)){
                                    exist2 = 1;
                                    here = n;
                                }
                            }
                            if (exist2 == 1){ //it exists in mem with less than 8
                                temp[0] = mem[here];
                                count = 1;
                                count2 = 0;
                                for(n = 0; n < counter; n++){
                                    if(n != here){
                                        temp[count] = mem[count2];
                                        count++;
                                        count2++;
                                    } else {
                                        count2++;
                                    }
                                }
                                for (n = 0; n < counter; n++){
                                    mem[n] = temp[n];
                                    if (n == 4) { printf("| "); };
                                    printf("%d ", temp[n]);
                                }
                                printf("\n");
                            } else { //it does not exists in mem with less than 8
                                pagefaults++;
                                temp[0] = atoi(token);
                                counter++;
                                for(n = 0; n < i; n++){
                                    temp[n+1] = mem[n];
                                }
                                for (n = 0; n < counter; n++){
                                    mem[n] = temp[n];
                                    if (n == 4) { printf("| "); };
                                    printf("%d ", temp[n]);
                                }
                                printf("\n");
                            }
                        } else { //page is not in mem with 8 pages
                            counter = 8;
                            pagefaults++;
                            for(n = 0; n < 8; n++){
                                if (mem[n] == atoi(token)){
                                    here = n;
                                }
                            }
                            temp[0] = mem[here];
                            count = 1;
                            count2 = 0;
                            for(n = 0; n < 8; n++){
                                if(n != here){
                                    temp[count] = mem[count2];
                                    count++;
                                    count2++;
                                } else {
                                    count2++;
                                }
                            }
                            for (n = 0; n < 8; n++){
                                mem[n] = temp[n];
                                if (n == 4) { printf("| "); };
                                printf("%d ", temp[n]);
                            }
                            printf("\n");
                        }
                    }
                }
                exists = 0;
                exist2 = 0;
                count = 0;
                token = strtok(NULL,delimiter);
                i++;
            }
            printf("Page Faults: %d \n", pagefaults);
        } else { //FIFO
            i = 0;
            counter = 0;
            while(token != NULL){
                 //24 referenced pages
                //printf("counter = %d\n", counter);
                printf("%s: ",token);
                if (i < 4){ //if mem still have slot for a page
                    temp[0] = atoi(token);
                    counter++;
                    pagefaults++;
                    for(r = 0; r < i; r++){
                        temp[r+1] = mem[r];
                    }
                    for(q = 0; q < counter; q++){
                        mem[q] = temp[q];
                        printf("%d ", temp[q]);
                    }
                    printf("| \n");
                } else { //mem does not have a slot for a page
                    for (x = 0; x < 4; x++){ //find if page exist already
                        if (mem[x] == atoi(token)){
                            exists = 1;
                            index = x;
                        }
                    }
                    if (exists == 1){ //page is already in mem
                        if (counter < 8) { //page is in mem with less than 8 pages
                            for (w = 0; w < counter; w++){
                                if (w == 4) { printf("| "); };
                                printf("%d ", temp[w]);
                            }
                            printf("\n");
                        } else { //page is in mem with 8 pages
                            counter = 8;
                            for (p = 0; p < 8; p++){
                                if (p == 4) { printf("| "); };
                                printf("%d ", temp[p]);
                            }
                            printf("\n");
                        }
                    } else { //page is not in memory
                        if(counter < 8){ //var mem has less than 8 pages
                            for(n = 0; n < counter; n++){ //find if it is in disk
                                if (mem[n] == atoi(token)){
                                    exist2 = 1;
                                    here = n;
                                }
                            }
                            if (exist2 == 1){ //it exists in mem with less than 8
                                temp[0] = mem[here];
                                count = 1;
                                count2 = 0;
                                for(n = 0; n < counter; n++){
                                    if(n != here){
                                        temp[count] = mem[count2];
                                        count++;
                                        count2++;
                                    } else {
                                        count2++;
                                    }
                                }
                                for (n = 0; n < counter; n++){
                                    mem[n] = temp[n];
                                    if (n == 4) { printf("| "); };
                                    printf("%d ", temp[n]);
                                }
                                printf("\n");
                            } else { //it does not exists in mem with less than 8
                                pagefaults++;
                                temp[0] = atoi(token);
                                counter++;
                                for(n = 0; n < i; n++){
                                    temp[n+1] = mem[n];
                                }
                                for (n = 0; n < counter; n++){
                                    mem[n] = temp[n];
                                    if (n == 4) { printf("| "); };
                                    printf("%d ", temp[n]);
                                }
                                printf("\n");
                            }
                        } else { //page is not in mem with 8 pages
                            counter = 8;
                            pagefaults++;
                            for(n = 0; n < 8; n++){
                                if (mem[n] == atoi(token)){
                                    here = n;
                                }
                            }
                            temp[0] = mem[here];
                            count = 1;
                            count2 = 0;
                            for(n = 0; n < 8; n++){
                                if(n != here){
                                    temp[count] = mem[count2];
                                    count++;
                                    count2++;
                                } else {
                                    count2++;
                                }
                            }
                            for (n = 0; n < 8; n++){
                                mem[n] = temp[n];
                                if (n == 4) { printf("| "); };
                                printf("%d ", temp[n]);
                            }
                            printf("\n");
                        }
                    }
                }
                exists = 0;
                exist2 = 0;
                count = 0;
                token = strtok(NULL,delimiter);
                i++;
            }
            printf("Page Faults: %d \n", pagefaults);
        }
    } else {
        perror("Error reading input file!");
    }
    fclose(fp);
}
