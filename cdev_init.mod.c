#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x51f3cabe, "module_layout" },
	{ 0x5e9c6beb, "cdev_del" },
	{ 0x10cedb6b, "kmalloc_caches" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x7c32d0f0, "printk" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x743031ea, "kmem_cache_alloc_trace" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0xda40c40f, "__class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "2B3078A0E270FF77081C142");
