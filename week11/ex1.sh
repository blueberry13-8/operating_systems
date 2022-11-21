dd if=/dev/zero of=lofs.img bs=1024 count=51200
loop=$(sudo losetup -f)
/sbin/mkfs lofs.img
mkdir lofsdisk
sudo mount -o loop=$loop lofs.img lofsdisk