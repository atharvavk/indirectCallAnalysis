#!/bin/bash

set -x
LLVM_HOME=/usr/lib
CC=/usr/bin/clang
OPT=/bin/opt

mkdir -p _build
pushd _build
cmake ..
make
popd
$CC -S -emit-llvm -o test.ll test.c
$OPT -enable-new-pm=0 -instnamer  -load _build/*/*libICA* -ica test.ll
#rm -rf _build test.bc
