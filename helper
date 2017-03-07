#!/bin/bash

# to current directory
cd "$(dirname "$0")"


OP="-$1"

TEST="../test_case/$2"

# file name is enough
RESULT="./result/$1/$3"

make clean && make type="$OP" && ./multiply_matrix $TEST > $RESULT
