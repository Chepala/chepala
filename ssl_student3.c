#include <stdio.h>
#include <stdlib.h>

struct Student {
	char name[50];
	int rollNumber;
	float marks;
	struct Student *next;
};

int numStudents = 0;

struct Student *addStudent(struct Student *head) {
	struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));
	if (newNode == NULL) {
		printf("Memory allocation failed.\n");
		return head;
	}

	printf("Enter name: ");
	scanf("%s", newNode->name);
	printf("Enter roll number: ");
	scanf("%d", &newNode->rollNumber);
	printf("Enter marks: ");
	scanf("%f", &newNode->marks);

	newNode->next = head;
	head = newNode;
	numStudents++;
	return head;
}

void displayStudents(struct Student *head) {
	if (head == NULL) {
		printf("No students in the database.\n");
		return;
	}

	printf("Student Database:\n");
	struct Student *current = head;
	while (current != NULL) {
		printf("Name: %s, Roll Number: %d, Marks: %.2f\n", current->name, current->rollNumber, current->marks);
		current = current->next;
	}
}

void searchStudent(struct Student *head, int rollNumber) {
	int found = 0;
	struct Student *current = head;

	while (current != NULL) {
		if (current->rollNumber == rollNumber) {
			printf("Student found!\n");
			printf("Name: %s, Roll Number: %d, Marks: %.2f\n", current->name, current->rollNumber, current->marks);
			found = 1;
			break;
		}
		current = current->next;
	}

	if (!found) {
		printf("Student with Roll Number %d not found.\n", rollNumber);
	}
}

void displaythelistbasedonrank(struct Student *head) {
	struct Student *temp;

	for (struct Student *i = head; i != NULL; i = i->next) {
		for (struct Student *j = i->next; j != NULL; j = j->next) {
			if (i->marks < j->marks) {
				float temp = i->marks;
				i->marks = j->marks;
				j->marks = temp;
			}
		}
	}


	printf("List based on rank:\n");
	int rank = 1;

	for (struct Student *current = head; current != NULL; current = current->next) {
		printf("Rank %d: Name: %s, Roll Number: %d, Marks: %.2f\n", rank++, current->name, current->rollNumber, current->marks);
	}
}

struct Student *deleteastudententrybasedontheirrollnumber(struct Student *head) {
	int targetRollNumber;
	printf("Enter the Roll Number to delete: ");
	scanf("%d", &targetRollNumber);

	struct Student *prev = NULL;
	struct Student *current = head;
	int found = 0;

	while (current != NULL) {
		if (current->rollNumber == targetRollNumber) {
			if (prev == NULL) {
				head = current->next;
			} else {
				prev->next = current->next;
			}
			free(current);
			numStudents--;
			printf("Student with Roll Number %d deleted.\n", targetRollNumber);
			found = 1;
			break;
		}
		prev = current;
		current = current->next;
	}

	if (!found) {
		printf("Student with Roll Number %d not found.\n", targetRollNumber);
	}

	return head;
}

struct Student *editthedetailsofanexistingstudententry(struct Student *head) {
	int targetRollNumber;
	printf("Enter the Roll Number to edit: ");
	scanf("%d", &targetRollNumber);

	int found = 0;
	struct Student *current = head;

	while (current != NULL) {
		if (current->rollNumber == targetRollNumber) {
			printf("Enter new name: ");
			scanf("%s", current->name);
			printf("Enter new marks: ");
			scanf("%f", &current->marks);
			printf("Details of student with Roll Number %d updated.\n", targetRollNumber);
			found = 1;
			break;
		}
		current = current->next;
	}

	if (!found) {
		printf("Student with Roll Number %d not found.\n", targetRollNumber);
	}

	return head;
}

int main() {
	int choice, rollNumber;

	struct Student *head = NULL;

	do {
		printf("\nStudent Database Menu:\n");
		printf("1. Add Student\n");
		printf("2. Display Students\n");
		printf("3. Search Student by Roll Number\n");
		printf("4. Exit\n");
		printf("5. Display the list based on rank\n");
		printf("7. Delete a student entry based on their roll number\n");
		printf("8. Edit the details of an existing student entry\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				head = addStudent(head);
				break;
			case 2:
				displayStudents(head);
				break;
			case 3:
				printf("Enter Roll Number to search: ");
				scanf("%d", &rollNumber);
				searchStudent(head, rollNumber);
				break;
			case 4:
				printf("Exiting...\n");
				break;
			case 5:
				displaythelistbasedonrank(head);
				break;
			case 7:
				head = deleteastudententrybasedontheirrollnumber(head);
				break;
			case 8:
				head = editthedetailsofanexistingstudententry(head);
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 4);

	// Free memory before exiting
	struct Student *current = head;
	struct Student *next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	return 0;
}

