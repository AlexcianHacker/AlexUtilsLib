#include <iostream> 
#include <fstream> 
#include <string> 
#include <cstdio>  

int main(int argc, char *argv[]) { 
        if (argc == 1 || argv[1] == "--help") { 
                std::cout << "INJECT \n\n" << "Usage: inject [File] [Line Number] [Content] \n";
                return -3; // Help Command 
        } 
        else if (argc < 4) { 
                std::cout << "Invalid, Not Enough Arguments; Run --help For More Info. \n"; 
                return -2; // Not Enough Args 
        } 
        std::ifstream file(argv[1]);
        std::string* pHemp = new std::string("temp_"); 
        *pHemp+=argv[1]; 
        const char* THEMP = (*pHemp).c_str(); 
        delete pHemp; 
        std::ofstream tfile(THEMP); 
        long num = std::stoi(argv[2]); 
        std::string line; 
        long li = 0; 
        while (std::getline(file, line)) { 
                if (li == num) { 
                        for (short i=3;i<argc;i++) { tfile << argv[i]; tfile << " "; } 
                } 
                else { 
                        tfile << line; 
                } 
                li++; 
        } 
        file.close(); 
        tfile.close(); 
        std::remove(argv[1]); 
        std::rename(THEMP, argv[1]); 
        return 0; 
} 
