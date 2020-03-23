mkdir -p build
gcc -c ./unity/unity.c -o ./build/src/unity.o
gcc -c ./test/test.cpp -I./test -I./unity -o ./build/test.o
gcc ./build/src/unity.o ./build/test.o -o ./build/test
./build/test