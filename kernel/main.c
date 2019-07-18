/* Austen Barker (2019) */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/timekeeping.h>
#include <linux/types.h>
#include "city.h"
#include "citycrc.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AUSTEN BARKER");

#define BLOCK_BYTES 4096

static int __init km_template_init(void){
    uint8_t* data = kmalloc(BLOCK_BYTES, GFP_KERNEL);
    uint64_t time = 0;
    uint32_t hash32;
    uint64_t hash64;
    uint128 hash128;
    uint64_t *hash256 = kmalloc(sizeof(uint64_t) * 4, GFP_KERNEL);
    
    printk(KERN_INFO "Kernel Module inserted");
    
    time = ktime_get_ns();
    hash32 = CityHash32(data, BLOCK_BYTES);
    printk(KERN_INFO "time needed to generate 32 bit hash %lld", ktime_get_ns() - time);

    time = ktime_get_ns();
    hash64 = CityHash64(data, BLOCK_BYTES);
    printk(KERN_INFO "time needed to generate 64 bit hash %lld", ktime_get_ns() - time);

    time = ktime_get_ns();
    hash128 = CityHash128(data, BLOCK_BYTES);
    printk(KERN_INFO "time needed to generate 128 bit hash %lld", ktime_get_ns() - time);

    time = ktime_get_ns();
    hash128 = CityHashCrc128(data, BLOCK_BYTES);
    printk(KERN_INFO "time needed to generate 128 bit crc hash %lld", ktime_get_ns() - time);

    time = ktime_get_ns();
    CityHashCrc256(data, BLOCK_BYTES, hash256);
    printk(KERN_INFO "time needed to generate 256 bit crc hash %lld", ktime_get_ns() - time);

    kfree(data);
    kfree(hash256);
    return 0;
}

static void __exit km_template_exit(void){
    printk(KERN_INFO "Removing kernel module\n");
}

module_init(km_template_init);
module_exit(km_template_exit);
