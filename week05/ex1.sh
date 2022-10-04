gcc subscriber.c -o sub
i=1
while [ "$i" -le $1 ]; do
    gnome-terminal -- ./sub $i
    i=$(( i + 1 ))
done
gcc publisher.c -o pub
gnome-terminal -- ./pub $1