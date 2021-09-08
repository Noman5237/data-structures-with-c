/**
 * @file: Task3.c
 * @author: Anonyman637
 * @date: 6/3/2021; 2:53 PM
 */

#include <dscommon.h>
#include <queue.h>

int main() {
	t_primitives_register();
	t_queue_register();
	
	let queue = Queue();
	
	queue_enqueue(queue, Int(1));
	queue_enqueue(queue, Int(2));
	queue_enqueue(queue, Int(3));
	queue_enqueue(queue, Int(4));
	
	any_print(queue);
	
	queue_dequeue(queue);
	any_print(queue);
	
	queue_dequeue(queue);
	any_print(queue);
	
	queue_enqueue(queue, Int(5));
	any_print(queue);
	
	queue_dequeue(queue);
	any_print(queue);
	
	queue_dequeue(queue);
	queue_dequeue(queue);
	any_print(queue);
	
	queue_dequeue(queue);
	
	any_destroy(queue);
	
	t_primitives_deregister();
	t_queue_deregister();
	
	return 0;
}

