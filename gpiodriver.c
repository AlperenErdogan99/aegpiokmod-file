#include <linux/module.h>
#include <linux/init.h>
#include <linux/gpio.h>
//#include <linux/delay.h>

/* Meta Information */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alperen Erdogan <falperenerdogan998@gmail.com>");
MODULE_DESCRIPTION("GPIO Led Blink");


#define GPIO_21 (21)
/**
 * @brief: This function is called, when the module is loaded into the kernel 
**/
static int __init GpioInit(void) {
	if(gpio_is_valid(GPIO_21) == false) printk("GPIO %d is not valid\n", GPIO_21);
  	else printk("GPIO %d is valid\n", GPIO_21);
		
	if(gpio_request(GPIO_21,"GPIO_21") < 0) printk("ERROR: GPIO %d request\n", GPIO_21);
	else printk("No ERROR GPIO %d request\n", GPIO_21);
	  
  	gpio_direction_output(GPIO_21, 0);
  	printk("GPIO Direction Set Output");

  	gpio_set_value(GPIO_21, 1);
  	printk("GPIO Set Value High");
	return 0;
}

/**
 * @brief: This function is called, when the module is removed from the kernel 
**/
static void __exit GpioExit(void){
	gpio_free(GPIO_21);
	printk("GPIO Exit!\n");
}

module_init(GpioInit);
module_exit(GpioExit);

