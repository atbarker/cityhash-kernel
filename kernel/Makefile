PWD := $(shell pwd)

ccflags-y += -I$(src)/include/ -msse4.2 -mpreferred-stack-boundary=4

citytest-objs := main.o city.o
obj-m += citytest.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

test:
	sudo insmod citytest.ko
	sudo rmmod citytest.ko

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
