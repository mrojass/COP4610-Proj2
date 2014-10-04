#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x9a31bb74, "module_layout" },
	{ 0xf192d0b1, "single_release" },
	{ 0xca67c6cb, "seq_read" },
	{ 0xbafecf06, "remove_proc_entry" },
	{ 0x26034a58, "proc_create_data" },
	{ 0x789bdca3, "seq_printf" },
	{ 0x92a9c60c, "time_to_tm" },
	{ 0x4f68e5c9, "do_gettimeofday" },
	{ 0xbf50d31, "single_open" },
	{ 0xbdfb6dbb, "__fentry__" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "2805DFC2B93F9C8DCA188D3");
