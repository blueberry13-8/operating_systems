gcc -pthread ex3.c -o ex3
{ time ./ex3 10000000 1 ; } 2> ex3.txt
{ time ./ex3 10000000 2 ; } 2>> ex3.txt
{ time ./ex3 10000000 4 ; } 2>> ex3.txt
{ time ./ex3 10000000 10 ; } 2>> ex3.txt
{ time ./ex3 10000000 100 ; } 2>> ex3.txt
# time ./ex3 10000000 1 > ex3.txt
# time ./ex3 10000000 2 >> ex3.txt
# time ./ex3 10000000 4 >> ex3.txt
# time ./ex3 10000000 10 >> ex3.txt
# time ./ex3 10000000 100 >> ex3.txt
rm ex3
