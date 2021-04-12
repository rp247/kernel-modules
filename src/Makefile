#how do i pass argumets to this ahhh

MODULE_FILENAME=hellokernel

obj-m   += $(MODULE_FILENAME).o
KO_FILE += $(MODULE_FILENAME).ko

helloworld:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
