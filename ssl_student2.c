#include <stdio.h>
#include <stdlib.h>

struct Student {
	char name[50];
	int rollNumber;
	float marks;
	struct Student *next;
};

int numStudents = 0;

struct Student * addStudent(struct Student *ptr ) {
	struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));
	if (newNode == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}

	printf("Enter name: ");
	scanf("%s", newNode->name);
	printf("Enter roll number: ");
	scanf("%d", &newNode->rollNumber);
	printf("Enter marks: ");
	scanf("%f", &newNode->marks);

	ptr = newNode;
	newNode->next=ptr;
	numStudents++;
	return ptr;
}

void displayStudents(struct Student *ptr) {

	if (ptr == NULL) {

		printf("No students in the database.\n");
		return;
	}

	printf("Student Database:\n");
	while (ptr != NULL) {
		printf("Name: %s, Roll Number: %d, Marks: %.2f\n", ptr->name, ptr->rollNumber, ptr->marks);
		ptr = ptr->next;
	}
}

void searchStudent(struct Student *ptr,int rollNumber) {
    int found = 0;

    while (ptr != NULL) {
        if (ptr->rollNumber == rollNumber) {
            printf("Student found!\n");
            printf("Name: %s, Roll Number: %d, Marks: %.2f\n", ptr->name, ptr->rollNumber, ptr->marks);
            found = 1;
            break;
        }
        ptr = ptr->next;
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

void displaythelistbasedonrank(struct Student *ptr) {
	// Sort students based on marks (rank) before displaying
	struct Student *temp;
	for (int i = 0; i < numStudents - 1; i++) {
		temp = ptr;
		for (int j = 0; j < numStudents - i - 1; j++) {
			if (temp->marks < temp->next->marks) {
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
		printf("Rank %d: Name: %s, Roll Number: %d, Marks: %.2f\n", rank++, current->name, current->rollNumber, current->marks);
		current = current->next;
	}
}

struct Student *deleteastudententrybasedontheirrollnumber(struct Student * ptr){
	int targetRollNumber;
	printf("Enter the Roll Number to delete: ");
	scanf("%d", &targetRollNumber);

	struct Student *prev = NULL;

	int found = 0;
	while (ptr != NULL) {
		if (ptr->rollNumber == targetRollNumber) {
			// Adjust pointers to skip the node to be deleted
			if (prev == NULL) {
				ptr = ptr->next;
			} else {
				prev->next = ptr->next;
			}
			free(ptr);
			numStudents--;
			printf("Student with Roll Number %d deleted.\n", targetRollNumber);
			found = 1;
			break;
		}
		prev = ptr;
		ptr = ptr->next;
	}

	if (!found) {
		printf("Student with Roll Number %d not found.\n", targetRollNumber);
	}
	return ptr;
}

struct Student * editthedetailsofanexistingstudententry(struct Student * ptr) {
	int targetRollNumber;
	printf("Enter the Roll Number to edit: ");
	scanf("%d", &targetRollNumber);

	int found = 0;

	while (ptr != NULL) {
		if (ptr->rollNumber == targetRollNumber) {
			// Modify details of the student
			printf("Enter new name: ");
			scanf("%s", ptr->name);
			printf("Enter new marks: ");
			scanf("%f", &ptr->marks);
			printf("Details of student with Roll Number %d updated.\n", targetRollNumber);
			found = 1;
			break;
		}
		ptr = ptr->next;
	}

	if (!found) {
		printf("Student with Roll Number %d not found.\n", targetRollNumber);
	}
	return ptr;
}

int main() {
	int choice, rollNumber;

	struct Student *head=NULL;

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
				head=addStudent(head);
				break;
			case 2:
				displayStudents(head);
				break;
			case 3:
				printf("Enter Roll Number to search: ");
				scanf("%d", &rollNumber);
				searchStudent(head,rollNumber);
				break;
			case 4:
				printf("Exiting...\n");
				break;
			case 5:
				displaythelistbasedonrank(head);
				break;
			case 7:
				head=deleteastudententrybasedontheirrollnumber(head);
				break;
			case 8:
				head=editthedetailsofanexistingstudententry(head);
				break;
			default:
				printf("Invalid choice. Please try again.\n");
		}
	} while (choice != 4);
	return 0;
}
