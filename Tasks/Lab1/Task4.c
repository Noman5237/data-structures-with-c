/**
 * @file: Task4.c
 * @author: Anonyman637
 * @date: 4/22/2021; 2:48 PM
 */

#include <dsCommon.h>

typedef struct Student {
	int last2DigitsId;
	int age;
} Student;

/**
 * Finds out whether the provided argument is even or odd
 * @param x
 * @return true when x is even
 */
bool isEven(int x);

int main() {
	int noOfStudents;
	
	/* ------------------ Taking input and storing it ------------------ */
	
	printf("Enter the number of students: ");
	scanf("%d", &noOfStudents);
	Student students[noOfStudents];
	for (int i = 0; i < noOfStudents; i++) {
		printf("ID of student %d (last 2 digits): ", i);
		scanf("%2d", &students[i].last2DigitsId);
		printf("Age of student %d: ", i);
		scanf("%d", &students[i].age);
	}
	
	/* ------------------ Querying the students ------------------ */
	printf("Printing the age of students with even ID only\n");
	for (int i = 0; i < noOfStudents; i++) {
		if (isEven(students[i].last2DigitsId)) {
			printf("Student with id %d is %d years old\n", students[i].last2DigitsId, students[i].age);
		}
		
	}
}

bool isEven(int x) {
	return !(x & 1);
}
