#include "libcfs_crypto.h"
static int init_cryptotest_module(void)
{
	int rc;

	printk("Regster crypto test module...\n");
	printk("Start crypto testing...\n");
	rc = cfs_crypto_register();
	if (rc) {
		printk(KERN_ERR "cfs_crypto_regster: error %d\n", rc);
		return rc;
	}

	cfs_crypto_unregister();
	printk("End crypto testing...\n");
	return 0;
}

static void exit_cryptotest_module(void)
{
	printk("Unregster crypto test module\n");
}

MODULE_AUTHOR("Gu Zheng <gzheng@ddn.com>");
MODULE_DESCRIPTION("crc32 test v3.1");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Test Module");
MODULE_ALIAS("test");
module_init(init_cryptotest_module);
module_exit(exit_cryptotest_module);
