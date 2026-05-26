#include <stdio.h> 
#include <stdlib.h> 
#include <sys/stat.h> 

int main(int argc, char *argv[]) { 
        if (argc < 2) { printf("No Arguments Detected \n"); return -3; } 
        if (argc == 2 && argv[1] == "INPUTcin") { 
                // ; 
        } 
        else if (argc >= 3) {
                char ln[69];  
                sprintf(ln, "/usr/local/bin/%s", argv[1]); 
                FILE* file = fopen(ln, "w"); 
                fprintf(file, "#!/bin/sh\n"); 
                // Concatenate Strings Using sprintf 
                for (short i = 2; i<argc; i++) { 
                        fputs(argv[i], file); 
                        fputs(" ", file); 
                } 
                // fprintf For Formatted Writes 
                // fputs For Unformatted Writes 
                fprintf(file, "\"$@\""); 
                fclose(file); 
                chmod(ln, 0755);  
                // std::string cmdline = (std::string) "sudo chmod +x /usr/local/bin/" + (std::string) argv[1];

                // const char *cmd = (const char*) cmdline.c_str(); 
                // std::system(cmd); 
        } 
        return 0; 
} 
