// HEX CONVERTER  
 
#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <cstring> 
#include <sstream> 


struct Result { 
    const int rcode; 
    const std::string text; 
}; 

Result convH(const char* inS) { 
    std::stringstream pres; 
    // std::string res; 
    for (size_t i = 0; i<std::strlen(inS);++i) { 
        // std::stringstream ss; 
        pres.str(""); // Clear The Stringstream After Every Iteration  
        pres << "0x"; 
        pres << std::hex << (unsigned int)((unsigned char) inS[i]); 
        pres << " "; 
        std::cout << pres.str(); 
    } 
    std::cout << "\n"; 
    return {0, pres.str()}; 
}


int main(int argc, char *argv[]) { 
    if (argc>1) { 
        for (int i = 1; i<argc; i++) { 
            if (std::strcmp(argv[i], "s") == 0) { 
                std::string inStr; 
                std::cout << "Enter String To Convert To Hex Here: "; 
                while (std::getline(std::cin, inStr) && inStr.empty()) { 
                    std::cout << "Enter String To Convert To Hex Here: "; 
                } 
                return convH(inStr.c_str()).rcode;   
            } 
        } 
    } 
    std::string inFile; 
    std::cout << "Enter File Name To Convert To Hex Here: "; 
    while (std::getline(std::cin, inFile) && inFile.empty()) { 
        std::cout << "Enter File Name To Convert To Hex Here: "; 
    } 
    std::ifstream fi(inFile); 
    if (!fi) { std::cerr << "Can't Open File \n"; fi.close(); return -1; } 
    int code = 0; 
    unsigned long line = 0; 
    std::string lin; 
    while (std::getline(fi, lin)) { 
        code += convH(lin.c_str()).rcode; 
        line++; 
    } 
    fi.close(); 
    return code; 
} 
