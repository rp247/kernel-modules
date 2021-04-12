# credits: https://github.com/rishiba/doc_linux_kernel_workbook/blob/master/doc/code/03_modules/hello_world/Makefile
#how do i pass argumets to this ahhh

MODULE_FILENAME = 00-hello-kernel

obj-m   += $(MODULE_FILENAME).o
KO_FILE  = $(MODULE_FILENAME).ko

export ROOTD=/lib/modules/$(shell uname -r)/build M=$(PWD) 

module:
	make -C $(ROOTD) modules

install:
	make -C $(ROOTD) modules_install

clean:
	make -C $(ROOTD) clean

insert: module
	sudo insmod $(KO_FILE)

remove:
	sudo rmmod $(MODULE_FILENAME)

logs:
	sudo dmesg -c
	sudo insmod $(KO_FILE)
	dmesg
