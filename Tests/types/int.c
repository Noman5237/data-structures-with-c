/**
 * @file: int.c
 * @author: Anonyman637
 * @date: 8/26/2021; 8:27 PM
 */


#include <types/primitives.h>

int main() {
	t_int_register();
	
	Any *a = Int(5);
	Any *b = Int(6);
	
	t_int->print(a);
	printf(", ");
	t_int->print(b);
	printf("\n");
	
	t_int->free(a);
	t_int->free(b);
	
	t_int_deregister();
}
