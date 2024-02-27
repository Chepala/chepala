#include <stdio.h>
#include <stdlib.h>

struct Student {
	char name[50];
	int rollNumber;
	float marks;
};

struct Node {
	struct Student data;
	struct Node *next;
};

struct Node *head = NULL; // Head of the linked list
int numStudents = 0;

void addStudent() {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}

	printf("Enter name: ");
	scanf("%s", newNode->data.name);
	printf("Enter roll number: ");
	scanf("%d", &newNode->data.rollNumber);
	printf("Enter marks: ");
	scanf("%f", &newNode->data.marks);

	newNode->next = head;
	head = newNode;
	numStudents++;
}

void displayStudents() {
	struct Node *current = head;

	if (current == NULL) {
		printf("No students in the database.\n");
		return;
	}

	printf("Student Database:\n");
	while (current != NULL) {
		printf("Name: %s, Roll Number: %d, Marks: %.2f\n", current->data.name, current->data.rollNumber, current->data.marks);
		current = current->next;
	}
}

void searchStudent(int rollNumber) {
    struct Node *current = head;
    int found = 0;

    while (current != NULL) {
        if (current->data.rollNumber == rollNumber) {
            printf("Student found!\n");
            printf("Name: %s, Roll Number: %d, Marks: %.2f\n", current->data.name, current->data.rollNumber, current->data.marks);
            found = 1;
            break;
        }
        current = current->next;
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

void displaythelistbasedonrank() {
	// Sort students based on marks (rank) before displaying
	struct Node *temp;
	for (int i = 0; i < numStudents - 1; i++) {
		temp = head;
		for (int j = 0; j < numStudents - i - 1; j++) {
			if (temp->data.marks < temp->next->data.marks) {
				// Swap the students if they are in the wrong order
				struct Student tempStudent = temp->data;
				temp->data = temp->next->data;
				temp->next->data = tempStudent;
			}
			temp = temp->next;
		}
	}

	printf("List based on rank:\n");
	struct Node *current = head;
	int rank = 1;
	while (current != NULL) {
		printf("Rank %d: Name: %s, Roll Number: %d, Marks: %.2f\n", rank++, current->data.name, current->data.rollNumber, current->data.marks);
		current = current->next;
	}
}

void deleteastudententrybasedontheirrollnumber() {
	int targetRollNumber;
	printf("Enter the Roll Number to delete: ");
	scanf("%d", &targetRollNumber);

	struct Node *current = head;
	struct Node *prev = NULL;

	int found = 0;
	while (current != NULL) {
		if (current->data.rollNumber == targetRollNumber) {
			// Adjust pointers to skip the node to be deleted
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
}

void editthedetailsofanexistingstudententry() {
	int targetRollNumber;
	printf("Enter the Roll Number to edit: ");
	scanf("%d", &targetRollNumber);

	struct Node *current = head;
	int found = 0;

	while (current != NULL) {
		if (current->data.rollNumber == targetRollNumber) {
			// Modify details of the student
			printf("Enter new name: ");
			scanf("%s", current->data.name);
			printf("Enter new marks: ");
			scanf("%f", &current->data.marks);
			printf("Details of student with Roll Number %d updated.\n", targetRollNumber);
			found = 1;
			break;
		}
		current = current->next;
	}

	if (!found) {
		printf("Student with Roll Number %d not found.\n", targetRollNumber);
	}
}

int main() {
	int choice, rollNumber;

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
				addStudent();
				break;
			case 2:
				displayStudents();
				break;
			case 3:
				printf("Enter Roll Number to search: ");
				scanf("%d", &rollNumber);
				searchStudent(rollNumber);
				break;
			case 4:
				printf("Exiting...\n");
				break;
			case 5:
				displaythelistbasedonrank();
				break;
			case 7:
				deleteastudententrybasedontheirrollnumber();
				break;
			case 8:
				editthedetailsofanexistingstudententry();
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 4);

	// Free allocated memory before exiting
	struct Node *current = head;
	while (current != NULL) {
		struct Node *temp = current;
		current = current->next;
		free(temp);
	}

	return 0;
}
