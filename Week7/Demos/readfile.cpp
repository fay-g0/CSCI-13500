#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]){

    //Open the file
    std::ifstream FileReaderObject("CatStory.txt");
    //Check if it actually opened
    if (!FileReaderObject.is_open()){
        std::cout <<"File not found!" <<std::endl;
        return 0;
}
    std::string the_line = {};
    //Read the file line by line
    while (std::getline(FileReaderObject, the_line)){ //cin can only read the first word and stops at a space compared to use getline
        std::cout << the_line << std::endl;
    //Close the file

    }
}