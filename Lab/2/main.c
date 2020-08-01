#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/slab.h>


struct birthday{
	int day;
	int month;
	int year;
	struct list_head list;
};

static LIST_HEAD(birthday_list);

struct birthday *ptr;


/* this function is called when the module is loaded*/ 
int simple_init(void)
{
	struct birthday *person;

	person = kmalloc(sizeof(person), GFP_KERNEL); 
	person->day = 2;
	person->month = 8;
	person->year = 1995;
	INIT_LIST_HEAD(&person->list);
	list_add_tail(&person->list, &birthday_list);

	person = kmalloc(sizeof(person), GFP_KERNEL); 
	person->day = 3;
	person->month = 9;
	person->year = 1996;
	INIT_LIST_HEAD(&person->list);
	list_add_tail(&person->list, &birthday_list);

	person = kmalloc(sizeof(person), GFP_KERNEL); 
	person->day = 4;
	person->month = 10;
	person->year = 1997;
	INIT_LIST_HEAD(&person->list);
	list_add_tail(&person->list, &birthday_list);

	person = kmalloc(sizeof(person), GFP_KERNEL); 
	person->day = 5;
	person->month = 11;
	person->year = 1998;
	INIT_LIST_HEAD(&person->list);
	list_add_tail(&person->list, &birthday_list);

	person = kmalloc(sizeof(person), GFP_KERNEL); 
	person->day = 6;
	person->month = 12;
	person->year = 1999;
	INIT_LIST_HEAD(&person->list);
	list_add_tail(&person->list, &birthday_list);

	list_for_each_entry(ptr, &birthday_list, list)
	{
		/*on each iteration ptr points to the next birthday struct*/ 
		/*printk("%d\n", person->day);
		printk("%d\n", person->month);
		printk("%d\n", person->year);*/

		

		printk(KERN_INFO "%d", ptr->day);
	}

	printk(KERN_INFO "Loading Module\n");
	return 0; 
}





/* this function is called when the module is removed*/
void simple_exit(void)
{
	list_for_each_entry(ptr, &birthday_list, list)
	{
		/*on each iteration ptr points to the next birthday struct*/ 
		/*printk("%d\n", person->day);
		printk("%d\n", person->month);
		printk("%d\n", person->year);*/

		

		printk(KERN_INFO "free %d", ptr->day);
		kfree(ptr);
	}
	
	printk(KERN_INFO "Removing Module\n"); 
}





/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("simple module");
MODULE_AUTHOR("SGG");