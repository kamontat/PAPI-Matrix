#!/bin/bash

# to current directory
cd "$(dirname "$0")"


OP="$1"

TEST="$2"

RESULT="$3"

make clean && make type="$OP" && ./multiply_matrix $TEST > $RESULT
