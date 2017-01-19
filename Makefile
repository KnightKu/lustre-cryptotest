PWD=$(shell pwd)
KVER=$(shell uname -r)
KDIR=/lib/modules/$(KVER)/build
   
obj-m := crytest.o
crytest-objs := cryptotest.o crc32c-pcl-intel-asm_64.o linux-crypto.o linux-crypto-crc32c-pclmul.o crc32-pclmul_asm.o  linux-crypto-adler.o  linux-crypto-crc32.o  linux-crypto-crc32pclmul.o
all:
	${MAKE} -C $(KDIR) M=$(PWD) modules
clean:  
	rm -f *.ko
	rm -f *.o
	rm -f *.mod.*
	rm -f modules.order Module.symvers
	rm .*.cmd
