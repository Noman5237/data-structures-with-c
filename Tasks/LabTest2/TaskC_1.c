/**
 * @file: TaskC_1.c
 * @author: Anonyman637
 * @date: 6/10/2021; 4:19 PM
 */

void insertIntsInDescOrder(int *ints, int newInt) {
	extern int noOfItems;
	
	int jr;
	for (jr = noOfItems - 1; newInt > ints[jr] && jr > 0; --jr) {
		ints[jr] = ints[jr - 1];
	}
	
	ints[jr] = newInt;
}
