#how do i pass argumets to this ahhh

MODULE_FILENAME = hellokernel

obj-m   += $(MODULE_FILENAME).o
KO_FILE += $(MODULE_FILENAME).ko

export ROOTB=/lib/modules/$(shell uname -r)/build M=$(PWD) 

helloworld:
	make -C $(ROOTB) modules

clean:
	make -C $(ROOTB) clean
