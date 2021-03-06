#!/bin/bash

set -x
LLVM_HOME=/usr/lib/llvm-11
CC=$LLVM_HOME/bin/clang
OPT=$LLVM_HOME/bin/opt

mkdir -p _build
pushd _build
cmake ..
make
popd
$CC -S -emit-llvm -o test.ll test.c
$OPT -instnamer  -load _build/*/*libICA* -ica test.ll
#rm -rf _build test.bc
