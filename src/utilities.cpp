#include "utilities.h"

std::string initialsOf(std::string fullName){
std::string result {};
result += fullName[0];
result += ". ";
auto index = fullName.find(" ");
result += fullName[index+1];
result += ".";
return result;
}

std::string padName(std::string fullName, int width){
fullName.resize(width, ' ');
return fullName;
}
