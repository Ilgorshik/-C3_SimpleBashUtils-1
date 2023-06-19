#!/bin/bash

echo "test2.txt"; ./s21_cat test2.txt > s21_cat.log; cat test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -b test2.txt"; ./s21_cat -b test2.txt > s21_cat.log; cat -b test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log 
echo " -e test2.txt";./s21_cat -e test2.txt > s21_cat.log; cat -e test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log 
echo " -s test2.txt";./s21_cat -s test2.txt > s21_cat.log; cat -s test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log 
echo " -n test2.txt"; ./s21_cat -n test2.txt > s21_cat.log; cat -n test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log 
echo " -v test2.txt"; ./s21_cat -v test2.txt > s21_cat.log; cat -v test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log 
echo " -t test2.txt"; ./s21_cat -t test2.txt > s21_cat.log; cat -t test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log 
echo " --number test2.txt"; ./s21_cat --number test2.txt > s21_cat.log; cat -n test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log 
echo " --squeeze-blank test2.txt"; ./s21_cat --squeeze-blank test2.txt > s21_cat.log; cat -s test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " --number-nonblank test2.txt"; ./s21_cat --number-nonblank test2.txt > s21_cat.log; cat -b test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -be test2.txt"; ./s21_cat -be test2.txt > s21_cat.log; cat -be test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -b -e test2.txt"; ./s21_cat -b -e test2.txt > s21_cat.log; cat -b -e test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -bsn test2.txt"; ./s21_cat -bsn test2.txt > s21_cat.log; cat -bsn test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -b -v -t test2.txt"; ./s21_cat -b -v -t test2.txt > s21_cat.log; cat -b -v -t test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -bvs test2.txt"; ./s21_cat -bvs test2.txt > s21_cat.log; cat -bvs test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -bn test2.txt"; ./s21_cat -bn test2.txt > s21_cat.log; cat -bn test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -b -n test2.txt"; ./s21_cat -b -n test2.txt > s21_cat.log; cat -b -n test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -se test2.txt"; ./s21_cat -se test2.txt > s21_cat.log; cat -se test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -s -e test2.txt"; ./s21_cat -s -e test2.txt > s21_cat.log; cat -s -e test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -nes test2.txt"; ./s21_cat -nes test2.txt > s21_cat.log; cat -nes test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -benvst test2.txt"; ./s21_cat -benvst test2.txt > s21_cat.log; cat -benvst test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -nv test2.txt"; ./s21_cat -nv test2.txt > s21_cat.log; cat -nv test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -est test2.txt"; ./s21_cat -est test2.txt > s21_cat.log; cat -est test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -tn test2.txt"; ./s21_cat -tn test2.txt > s21_cat.log; cat -tn test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -t -n test2.txt"; ./s21_cat -t -n test2.txt > s21_cat.log; cat -t -n test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -bs test2.txt"; ./s21_cat -bs test2.txt > s21_cat.log; cat -bs test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -et test2.txt"; ./s21_cat -et test2.txt > s21_cat.log; cat -et test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
echo " -st test2.txt"; ./s21_cat -st test2.txt > s21_cat.log; cat -st test2.txt > cat.log; diff -s s21_cat.log cat.log; rm cat.log; rm s21_cat.log
