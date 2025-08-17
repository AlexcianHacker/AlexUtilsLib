/* Kill Program Variant */ 

#include <stdio.h> 
#include <signal.h> 
#include <sys/types.h> 
#include <stdlib.h> 


int main(int argc, int *argv[]) { 
        if (argc > 1) { 
                if (kill(-1, atoi((const char*)*(argv[1])))==-1) { 
                        printf("Error Sending Signal, Error Code -1 \n"); 
                        return -1; 
                } 
                return 0;
        } 
        if (kill(-1, 11) == -1) { 
                printf("Fuck \n"); 
                return -1; 
        } 
        return 0; 
} 
