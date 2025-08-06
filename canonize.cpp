#include <iostream> 
#include <fstream> 
#include <cstdlib> 

int main(int argc, char *argv[]) { 
        if (argc < 2) { std::cout << "No Arguments Detected \n"; return -3; } 
        if (argc == 2 && argv[1] == "INPUTcin") { 
                // ; 
        } 
        else if (argc >= 3) {
                std::string ln = "/usr/local/bin/"; 
                ln+=argv[1]; 
                std::ofstream file(ln.c_str()); 
                file << "#!/bin/sh\n"; 
                for (short i = 2; i<argc; i++) { 
                        file << argv[i]; 
                        file << " "; 
                } 
                file << "\"$@\""; 
                file.close(); 
                std::string cmdline = (std::string) "sudo chmod +x /usr/local/bin/" + (std::string) argv[1];

                const char *cmd = (const char*) cmdline.c_str(); 
                std::system(cmd); 
        } 
        return 0; 
} 