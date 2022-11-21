echo "victor" | sudo tee -a lofsdisk/file1
echo "kovalev" | sudo tee -a lofsdisk/file2
gcc ex2.c -o ex2.out

sudo mkdir -p lofsdisk/lib
sudo mkdir -p lofsdisk/lib/x86_64-linux-gnu
sudo mkdir -p lofsdisk/lib64
sudo cp -u /lib/x86_64-linux-gnu/libtinfo.so.6 lofsdisk/lib/x86_64-linux-gnu/
sudo cp -u /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu/
sudo cp -u /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/
sudo mkdir -p lofsdisk/bin/
sudo cp -u /bin/bash lofsdisk/bin

sudo cp -u /lib/x86_64-linux-gnu/libselinux.so.1 lofsdisk/lib/x86_64-linux-gnu/
sudo cp -u /lib/x86_64-linux-gnu/libpcre2-8.so.0 lofsdisk/lib/x86_64-linux-gnu/
sudo cp -u /bin/ls lofsdisk/bin/

sudo cp -u /bin/echo lofsdisk/bin/
sudo cp -u /bin/cat lofsdisk/bin/

sudo cp -u ex2.out lofsdisk

sudo chroot lofsdisk/ ./ex2.out > ex2.txt

./ex2.out >> ex2.txt