mkdir tmp
touch tmp/file1
touch tmp/file2
link tmp/file1 tmp/link1

gcc ex4.c -o ex4
./ex4
rm ex4
rm tmp/link1
rm tmp/file1
rm tmp/file2
rmdir tmp
