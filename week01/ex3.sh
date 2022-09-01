date
sleep 3
mkdir root
date
sleep 3
mkdir home
cd root
date
sleep 3
ls / -t -r > root.txt
cat root.txt
cd ..
cd home
date
sleep 3
ls ~ -t -r > home.txt
cat home.txt
ls
cd ..
cd root
ls
