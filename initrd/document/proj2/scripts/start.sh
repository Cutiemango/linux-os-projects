#!/bin/sh
cd ./initrd
find . | cpio -H newc -o | gzip > ../initrd.img

cd ../
qemu-system-x86_64 -nographic -append "rdinit=/linuxrc console=ttyS0" -kernel ./linux-5.15.83/arch/x86/boot/bzImage -initrd ./initrd.img -m 512 --enable-kvm

