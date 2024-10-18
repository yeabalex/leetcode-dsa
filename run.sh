#!/bin/bash

path=""
if [ "$1" == "l" ]; then
    path="leetcode"
else
    path="data-structures"
fi

g++ "$(pwd)/$path/$2/$2.cpp" -o "$(pwd)/$path/$2/a.out"

"$(pwd)/$path/$2/a.out"

rm "$(pwd)/$path/$2/a.out"
