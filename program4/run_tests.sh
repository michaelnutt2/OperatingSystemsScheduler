#! /bin/bash

FILES="../processes/*"

for file in $FILES;
do
  ./bin/program4 $file
done
