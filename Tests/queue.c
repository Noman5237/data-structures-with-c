/**
 * @file: queue.c
 * @author: Anonyman637
 * @date: 9/8/2021; 10:56 PM
 */

#include <dscommon.h>
#include <queue.h>
#include <criterion/criterion.h>

void setup(void) {
	t_primitives_register();
	t_queue_register();
}

void teardown(void) {
	t_primitives_deregister();
	t_queue_deregister();
}

TestSuite(TypeQueue, .init = setup, .fini = teardown);

Test(TypeQueue, TypeName) {
	let queue = Queue();
	
	cr_assert_str_eq(any_type(queue), "Queue");
	
	any_destroy(queue);
}

Test(TypeQueue, Empty) {
	let queue = Queue();
	
	cr_assert_eq(queue_isEmpty(queue), 1);
	queue_enqueue(queue, Int(1));
	cr_assert_eq(queue_isEmpty(queue), 0);
	
	any_destroy(queue);
}

Test(TypeQueue, Enqueue) {
	let queue = Queue();
	
	queue_enqueue(queue, Int(1));
	cr_assert_eq(queue_size(queue), 1);
	cr_assert_eq(*int_data(queue_front(queue)), 1);
	cr_assert_eq(*int_data(queue_rear(queue)), 1);
	
	queue_enqueue(queue, Int(2));
	cr_assert_eq(queue_size(queue), 2);
	cr_assert_eq(*int_data(queue_front(queue)), 1);
	cr_assert_eq(*int_data(queue_rear(queue)), 2);
	
	queue_enqueue(queue, Int(3));
	cr_assert_eq(queue_size(queue), 3);
	cr_assert_eq(*int_data(queue_front(queue)), 1);
	cr_assert_eq(*int_data(queue_rear(queue)), 3);
	
	any_destroy(queue);
}


Test(TypeQueue, Dequeue) {
	let queue = Queue();
	
	queue_enqueue(queue, Int(1));
	queue_enqueue(queue, Int(2));
	queue_enqueue(queue, Int(3));
	
	queue_dequeue(queue);
	cr_assert_eq(queue_size(queue), 2);
	cr_assert_eq(*int_data(queue_front(queue)), 2);
	cr_assert_eq(*int_data(queue_rear(queue)), 3);
	
	queue_dequeue(queue);
	cr_assert_eq(queue_size(queue), 1);
	cr_assert_eq(*int_data(queue_front(queue)), 3);
	cr_assert_eq(*int_data(queue_rear(queue)), 3);
	
	queue_dequeue(queue);
	cr_assert_eq(queue_size(queue), 0);
	cr_assert_null(queue_front(queue));
	cr_assert_null(queue_rear(queue));
	
	any_destroy(queue);
}
