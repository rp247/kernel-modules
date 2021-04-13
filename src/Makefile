# credits: https://github.com/rishiba/doc_linux_kernel_workbook/blob/master/doc/code/03_modules/hello_world/Makefile
# ref: https://www.kernel.org/doc/html/v5.6/kbuild/modules.html
#how do i pass argumets to this ahhh

MODULE_FILENAME = 02-arg-parse

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
	sudo dmesg | tail

remove:
	sudo rmmod $(MODULE_FILENAME)
	sudo dmesg | tail

logs:
	sudo insmod $(KO_FILE)
	sudo dmesg | tail

all: module logs remove clean

