#! /bin/bash

FILES="../processes/*"

for file in $FILES;
do
  ./bin/program1 $file
done
