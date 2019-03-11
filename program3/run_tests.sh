#! /bin/bash

FILES="../processes/*"

for file in $FILES;
do
  ./bin/program3 $file
done
