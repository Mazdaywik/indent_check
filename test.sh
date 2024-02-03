#!/bin/bash

#export LANG=C.UTF-8

# Activate the virtual environment
#source /Users/aleksey.egorov/Developer/DELETE/venv/bin/activate

for file in /Users/aleksey.egorov/Developer/DELETE/tests/acc/*
do
python3 main.py "$file"
echo "$file"
done > acc_test_results.txt