#!/bin/bash

for i in {1..100}
do
    python3 submit.py -p remorse f.cpp < inp.in
done
