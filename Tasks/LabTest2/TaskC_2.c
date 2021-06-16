/**
 * @file: TaskC_2.c
 * @author: Anonyman637
 * @date: 6/10/2021; 5:04 PM
 */

#include <stdio.h>

void insertIntsInDescOrder(int *ints, int newInt);

int task2(int *ints);

int noOfItems;

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("Usage: LT2TC_2 fileName noOfItems\n");
		return 1;
	}
	
	char *fileName = argv[1];
	sscanf(argv[2], "%d", &noOfItems);
	
	int ints[noOfItems];
	for (int i = 0; i < noOfItems; i++) {
		ints[i] = -1;
	}
	
	FILE *file = fopen(fileName, "r");
	if (!file) {
		printf("Cannot open file %s\n", fileName);
	}
	
	int newInt;
	while (!feof(file)) {
		fscanf(file, "%d", &newInt);
		insertIntsInDescOrder(ints, newInt);
	}
	
	printf("No of items whose value greater than average: %d\n", task2(ints));
	
	return 0;
}

int task2(int *ints) {
	int noOfOperations = 0;
	
	double average = 0;
	++noOfOperations;
	
	++noOfOperations;
	for (int i = 0; i < noOfItems; i++) {
		noOfOperations += 2;
		
		average += ints[i] / noOfItems;
		++noOfOperations;
	}
	
	int noOfItemsGraterThanAverage = 0;
	++noOfOperations;
	
	++noOfOperations;
	for (int i = 0; i < noOfItems; i++) {
		noOfOperations += 2;
		if (ints[i] > average) {
			++noOfOperations;
			noOfItemsGraterThanAverage++;
			++noOfOperations;
		}
	}
	
	printf("No of operations required: %d\n", noOfOperations);
	
	return noOfItemsGraterThanAverage;
}
