#include <linux/module.h> /* Butun moduller icin gereklidir*/
#include <linux/kernel.h>  /* printk debug ciktisi icin gereklidir */
#include <linux/init.h> /* module_init ve module_exit makrolari icin gereklidir */

MODULE_LICENSE("Dual BSD/GPL"); /* modulumuzun sahip oldugu lisans turunu belirtir */

/* modulun baslatilirken calistirdigi rutindir */
int __init merhaba_init(void)
{

printk(KERN_NOTICE, "MERHABA MODULU BASLATILDI \n"); /*log */
return 0;

}

/* modulun sonlandirilirken calistirildigi rutindir */
void __exit merhaba_exit(void)
{

printk(KERN_INFO "MERHABA MODULU SONLANDIRILDI \n"); /* log */
return 0;

}
/* bu makroyla kernel e modul baslatilirken merhaba_init rutininin calistirilmasi soylenir */
module_init(merhaba_init);

/* bu makroyla kernel e modul sonlandirilirken merhaba_exit rutininin calistirilmasi soylenir */
module_exit(merhaba_exit);
