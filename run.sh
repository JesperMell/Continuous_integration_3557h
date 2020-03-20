mkdir -p build
gcc -c ./test/test.cpp -I./test -I./test/unity -o ./build/test.o
gcc ./test/unity/unity.o ./build/test.o -o ./build/test
./build/test