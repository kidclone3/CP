INCLUDE=`pkg-config --cflags opencv4`
LIBS=`pkg-config --libs opencv4`
g++ ${INCLUDE} read.cpp ${LIBS} -o read -std=c++11 && ./read && rm read