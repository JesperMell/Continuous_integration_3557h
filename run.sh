mkdir -p build
gcc -c ./test/test.cpp -I./test -I./build/unity/src/unity -o ./build/test.o
gcc ./build/unity/src/unity.o ./build/test.o -o ./build/test
./build/test