cd ..
mkdir week01
echo "victor" > week01/file.txt
mkdir week10
cd week10
link ../week01/file.txt _ex2.txt
inodenumber=$(ls -i ../week01/file.txt | grep -E -o '[0-9]* ')
find ../ -inum $inodenumber > ex2.txt
find ../ -inum $inodenumber ! -path "../week01/file.txt" -exec rm {} \; >> ex2.txt
ls -l >> ex2.txt
# I decided to append ls command from week10 to output because prev. command return nothing
