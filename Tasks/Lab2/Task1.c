/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 4/29/2021; 1:46 PM
 */

#include <dsCommon.h>

/**
 * Creates an array of ages from user input
 * @param noOfStudents total number of students
 * @return pointer to the start of the created array
 */
int *createAgeArray(int noOfStudents);

/**
 * Print the ages array
 * @param pAgeArray pointer to the age array
 * @param noOfStudents total number of students
 */
void displayAges(int *pAgeArray, int noOfStudents);

/**
 * Updates the indexed student with random age
 * @param pAgeArray pointer to the age array
 * @param index index of the student to randomly update age of
 * @param noOfStudents total number of students
 * @return 0 if successful, -1 otherwise
 */
int updateStudentAgeRandomly(int *pAgeArray, int index, int noOfStudents);

/**
 * Sort the given array in ascending order
 * @param pArray pointer to the array
 * @param lengthOfArray total number of elements
 * @return 0 if successful, -1 otherwise
 */
int sortArray(int *pArray, int lengthOfArray);

/**
 * Search the array of ages and finds the index of required age
 * @param pArray pointer to the array
 * @param requiredElement the element to find
 * @param lengthOfArray total number of elements
 * @return index of requiredElement if found, -1 otherwise
 */
int getElementIndex(int *pArray, int requiredElement, int lengthOfArray);

/**
 * Counts the number of unique elements in given array
 * @param pArray pointer to the given array
 * @param lengthOfArray no of elements in the array
 * @return no of unique elements in the array
 */
int countNoOfUniqueElements(int *pArray, int lengthOfArray);

/**
 * Creates a map of unique elements with their no of occurrences
 * @param pArray pointer to the given array
 * @param lengthOfArray no of elements in the array
 * @return a 2D array where
 * row 0 represents the unique elements and row 1 indicates their number of occurrences
 */
int **calculateElementOccurrences(int *pArray, int lengthOfArray);

int main() {

//	Taking the total number of students
	int noOfStudents;
	printf("Enter the number of students: ");
	scanf("%d", &noOfStudents);

//	Taking the age of all students
	printf("\n");
	int *pAges = createAgeArray(noOfStudents);
	printf("\n");

//	Display ages of all students
	printf("\n");
	displayAges(pAges, noOfStudents);
	printf("\n");

//	Update the age of a specific student
	printf("Enter index of a student you wish to randomly modify the age of: ");
	int tempInt;
	scanf("%d", &tempInt);
	int returnCode = updateStudentAgeRandomly(pAges, tempInt, noOfStudents);
	if (!returnCode) {
		printf("Age of student %d is randomly updated to %d\n", tempInt, pAges[tempInt]);
	} else {
		printf("Age of student %d is not updated\n", tempInt);
	}

//	Sort the ages
	sortArray(pAges, noOfStudents);

//	Display ages of all students after sorting
	printf("After sorting the ages\n");
	displayAges(pAges, noOfStudents);
	printf("\n");

//  Find the index of a specific age
	printf("Enter any age you want to find the index of: ");
	scanf("%d", &tempInt);
	int ageIndex = getElementIndex(pAges, tempInt, noOfStudents);
	printf("Age %d is found at index %d\n", tempInt, ageIndex);

//	Calculate the number of unique ages
	int noOfUniqueAges = countNoOfUniqueElements(pAges, noOfStudents);

//	Calculate the occurrences of specific age
	int **ageOccurrences = calculateElementOccurrences(pAges, noOfStudents);
	printf("Enter a specific age to calculate its occurrences: ");
	scanf("%d", &tempInt);
	ageIndex = getElementIndex(ageOccurrences[0], tempInt, noOfUniqueAges);
	printf("Occurrences of age %d: %d\n", tempInt, ageIndex > -1 ? ageOccurrences[1][ageIndex] : 0);

//	Freeing the allocated memory by arrays
	
	free(pAges);
	
	free(ageOccurrences[0]);
	free(ageOccurrences[1]);
	free(ageOccurrences);
}


int *createAgeArray(int noOfStudents) {
	int *pAges = (int *) malloc(sizeof(int) * noOfStudents);
	for (int i = 0; i < noOfStudents; i++) {
		printf("Enter the age of student %d: ", i);
		scanf("%d", &pAges[i]);
	}
	return pAges;
}

void displayAges(int *pAgeArray, int noOfStudents) {
	for (int i = 0; i < noOfStudents; i++) {
		printf("\nStudent %d is %d years old.", i, pAgeArray[i]);
	}
}

int updateStudentAgeRandomly(int *pAgeArray, int index, int noOfStudents) {
	if (index > -1 && index < noOfStudents) {
		pAgeArray[index] = rand();
		return 0;
	}
	
	return -1;
}

int sortArray(int *pArray, int lengthOfArray) {
	for (int i = 0; i < lengthOfArray - 1; i++) {
		for (int j = 0; j < lengthOfArray - 1; j++) {
			if (pArray[j] > pArray[j + 1]) {
				int temp = pArray[j + 1];
				pArray[j + 1] = pArray[j];
				pArray[j] = temp;
			}
		}
	}
	
	return 0;
}

int getElementIndex(int *pArray, int requiredElement, int lengthOfArray) {
	
	int low = 0;
	int high = lengthOfArray;
	int mid;
	for (mid = (low + high) / 2; low <= high; mid = (low + high) / 2) {
		if (pArray[mid] == requiredElement) {
			return mid;
		} else if (pArray[mid] < requiredElement) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	
	return -1;
	
}

int countNoOfUniqueElements(int *pArray, int lengthOfArray) {
	int noOfUniqueElements = 1;
	int currentElement = pArray[0];
	for (int i = 1; i < lengthOfArray; i++) {
		if (pArray[i] != currentElement) {
			noOfUniqueElements++;
			currentElement = pArray[i];
		}
	}
	
	return noOfUniqueElements;
}

int **calculateElementOccurrences(int *pArray, int lengthOfArray) {
	
	int noOfUniqueElements = countNoOfUniqueElements(pArray, lengthOfArray);
	
	int **occurrences = malloc(sizeof(int *) * 2);
	occurrences[0] = malloc(sizeof(int) * noOfUniqueElements);
	occurrences[1] = malloc(sizeof(int) * noOfUniqueElements);
	
	int currentElement = pArray[0];
	int currentElementOccurrences = 1;
	int n = 0;
	for (int i = 1; i < lengthOfArray; i++) {
		if (pArray[i] != currentElement) {
			occurrences[0][n] = currentElement;
			occurrences[1][n] = currentElementOccurrences;
			currentElementOccurrences = 1;
			n++;
			currentElement = pArray[i];
		} else {
			currentElementOccurrences++;
		}
	}
	
	occurrences[0][n] = currentElement;
	occurrences[1][n] = currentElementOccurrences;
	
	return occurrences;
}
