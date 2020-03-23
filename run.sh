mkdir -p build
gcc -c ./unity/unity.c -o ./build/unity/unity.o
gcc -c ./test/test.cpp -I./test -I./unity -o ./build/test.o
gcc ./build/unity/unity.o ./build/test.o -o ./build/test
./build/test.exe
