echo "privet menya zovut Victor" > _ex3.txt
chmod a-x _ex3.txt

ls -l _ex3.txt > ex3.txt

chmod u=rwx _ex3.txt
chmod o=rwx _ex3.txt

ls -l _ex3.txt >> ex3.txt

perms=$(ls -l _ex3.txt | cut -c 2-4)
chmod g=$perms _ex3.txt

ls -l _ex3.txt >> ex3.txt

