/**
 * @file: TaskC_1.c
 * @author: Anonyman637
 * @date: 6/10/2021; 4:19 PM
 */

void insertIntsInDescOrder(int *ints, int newInt) {
	extern int noOfItems;
	
	int j;
	for (j = 0; newInt < ints[j]; ++j) {
		// empty block
	}
	
	for (int jr = noOfItems; jr > j; jr--) {
		ints[jr] = ints[jr - 1];
	}
	
	ints[j] = newInt;
}
