#!/bin/sh

# This script is created for the purposes of only running flex code without Bison files

# First parameter: filepath
# Usage: comp plates.l
#        comp plates.l < tests.txt
comp() {
    file=$1
    filename=${file%.*}
    extension=${file##*.}
    flex_output=$filename-lex.yy.c
    flex -o $flex_output $file
    gcc $flex_output -lfl -o $filename
    ./$filename
}

comp $1
