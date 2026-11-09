// HEX CONVERTER  

#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <cstring> 
#include <sstream> 


struct Result { 
    int rcode; 
    std::string text; 
}; 

Result convH(std::string inS) { 
    std::stringstream pres; 
    // std::string res; 
    for (int i = 0; i<std::strlen(inS.c_str());++i) { 
        // std::stringstream ss; 
        pres.str(""); // Clear The Stringstream After Every Iteration  
        pres << "0x"; 
        pres << std::hex << (int)((unsigned char) inS[i]); 
        pres << " "; 
        std::cout << pres.str(); 
    } 
    std::cout << "\n"; 
    return {0, pres.str()}; 
}


int main(int argc, char *argv[]) { 
    bool strIO = 0; 
    if (argc>1) { 
        for (int i = 1; i<argc; i++) { 
            if (std::string(argv[i]) == "s") { 
                strIO=1;
            }
        }
        if (strIO) { 
            std::string inStr; 
            std::cout << "Enter String To Convert To Hex Here: "; 
            std::cin >> inStr; 
            return convH(inStr).rcode;   
        } 
    } 
    std::string inFile; 
    std::cout << "Enter File Name To Convert To Hex Here: "; 
    std::cin >> inFile; 
    std::ifstream fi(inFile); 
    int code = 0; 
    unsigned long line = 0; 
    std::string lin; 
    while (std::getline(fi, lin)) { 
        code += convH(lin).rcode; 
        line++; 
    } 
    fi.close(); 
    return code; 
} 
