#!/bin/bash

echo $1 > input.in
g++ l.cpp && ./a.out < input.in
g++ brute.cpp && ./a.out < input.in
