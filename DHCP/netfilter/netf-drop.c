//Herbir paket için drop işlemini gerçekleştirme örneği

#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>

static struct nf_hook_ops nfho;         //hook fonksiyon seçeneklerini(nfho)tutan yapı.

//hook fonksiyonunun çağırılması.
unsigned int hook_func(unsigned int hooknum, struct sk_buff **skb, const struct net_device *in, const struct net_device *out, int (*okfn)(struct sk_buff *))
{
  printk(KERN_INFO "packet dropped\n");                                             //var/log/messages
  return NF_DROP;                                                                   //paket düşürme

//Called when module loaded using 'insmod'
int init_module()
{
  nfho.hook = hook_func;                       //Aşağıdaki şartlerı yerine getiren hook fonksiyonu.
  nfho.hooknum = NF_INET_PRE_ROUTING;            //Paket alındıktan sonra çağırılan ilk netfilter fonksiyonu.
  nfho.pf = PF_INET;                           //IPV4 paketleri
  nfho.priority = NF_IP_PRI_FIRST;             //önceliğin belirlenmesi
  nf_register_hook(&nfho);                     //register hook

  return 0;                                    //doğru ise 
}

//rmmod kullanılarak modülün kaldırılması
void cleanup_module()
{
  nf_unregister_hook(&nfho);                     //cleanup – unregister hook
}
