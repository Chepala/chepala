#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};
struct Student students[100];
int numStudents = 0;

void addStudent() {
    if (numStudents < 100) {
        printf("Enter name: ");
        scanf("%s", students[numStudents].name);
        printf("Enter roll number: ");
        scanf("%d", &students[numStudents].rollNumber);
        printf("Enter marks: ");
        scanf("%f", &students[numStudents].marks);
        numStudents++;
    } else {
        printf("Maximum number of students reached.\n");
    }
}

void displayStudents() {
    if (numStudents > 0) {
        printf("Student Database:\n");
        for (int i = 0; i < numStudents; i++) {
            printf("Name: %s, Roll Number: %d, Marks: %.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
        }
    } else {
        printf("No students in the database.\n");
    }
}

void searchStudent(int rollNumber) {
    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student found!\n");
            printf("Name: %s, Roll Number: %d, Marks: %.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", rollNumber);
    }
}

void displaythelistbasedonrank() {
    // Sort students based on marks (rank) before displaying
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                // Swap the students if they are in the wrong order
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("List based on rank:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Rank %d: Name: %s, Roll Number: %d, Marks: %.2f\n", i + 1, students[i].name, students[i].rollNumber, students[i].marks);
    }
}

void displaythelistofstudentsbasedonrollnumber() {
    int targetRollNumber;
    printf("Enter the target Roll Number: ");
    scanf("%d", &targetRollNumber);

    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == targetRollNumber) {
            printf("Student found!\n");
            printf("Name: %s, Roll Number: %d, Marks: %.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", targetRollNumber);
    }
}

void deleteastudententrybasedontheirrollnumber() {
    int targetRollNumber;
    printf("Enter the Roll Number to delete: ");
    scanf("%d", &targetRollNumber);

    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == targetRollNumber) {
            // Shift elements to remove the student
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            printf("Student with Roll Number %d deleted.\n", targetRollNumber);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", targetRollNumber);
    }
}

void editthedetailsofanexistingstudententry() {
    int targetRollNumber;
    printf("Enter the Roll Number to edit: ");
    scanf("%d", &targetRollNumber);

    int found = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == targetRollNumber) {
            // Modify details of the student
            printf("Enter new name: ");
            scanf("%s", students[i].name);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Details of student with Roll Number %d updated.\n", targetRollNumber);
            found = 1;
            break;
        }
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
        printf("6. Display the list of students based on roll number\n");
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
            case 6:
                displaythelistofstudentsbasedonrollnumber();
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

    return 0;
}
