ifneq ($(KERNELRELEASE),)
	TARGET = shuttle_module

	shuttle_module-obj := shuttle_module.o

	obj-m:= $(TARGET).o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build/
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
endif

