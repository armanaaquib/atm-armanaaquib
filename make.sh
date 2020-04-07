#! /bin/bash

rm -f *.o
gcc -c *.c
if [ $? == 0 ]
then
  gcc -o bin/$1 *.o
  rm -f *.o
  ./bin/$1
else
  echo "Compilation Error."
fi
