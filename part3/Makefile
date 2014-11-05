ifneq ($(KERNELRELEASE),)
	TARGET = the_shuttle_module

	the_shuttle_module-objs := shuttle_module.o syscalls.o shuttle.o

	obj-m:= $(TARGET).o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build/
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
endif

