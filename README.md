# lab03-gradebook
## Manual Build Commands
rm -f *.o gradebook
g++ -Wall -Iinclude -c src/*.cpp
g++ *.o -o gradebook
./gradebook 
