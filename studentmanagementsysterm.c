#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int roll;
    char name[50];
    float marks;
} Student;

void addStudent(Student *s, int n) {
    int i, j, roll, duplicate;

    for (i = 0; i < n; i++) {

        if (s[i].roll != 0)
            continue;

        printf("\nEnter details of student %d\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &roll);

        if (roll <= 0) {
            printf("Invalid roll number\n");
            i--;
            continue;
        }

        duplicate = 0;

        for (j = 0; j < n; j++) {
            if (s[j].roll == roll) {
                duplicate = 1;
                break;
            }
        }

        if (duplicate == 1) {
            printf("Roll number already exists\n");
            i--;
            continue;
        }

        s[i].roll = roll;

        printf("Enter name: ");
        scanf(" %49[^\n]", s[i].name);

        printf("Enter marks: ");
        scanf("%f", &s[i].marks);

        if (s[i].marks < 0 || s[i].marks > 100) {
            printf("Invalid marks\n");
            s[i].roll = 0;
            i--;
            continue;
        }
    }

    printf("\nStudent entry completed\n");
}

void displayStudent(Student *s, int n) {
    int i, found = 0;

    for (i = 0; i < n; i++) {

        if (s[i].roll != 0) {
            printf("\nStudent %d\n", i + 1);
            printf("Roll: %d\n", s[i].roll);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);

            found = 1;
        }
    }

    if (found == 0)
        printf("No students available\n");
}

void searchStudent(Student *s, int n) {
    int roll, i, found = 0;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < n; i++) {

        if (s[i].roll == roll && roll > 0) {
            printf("\nStudent found\n");
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);

            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Student not found\n");
}

void updateStudent(Student *s, int n) {
    int roll, i, found = 0;
    float marks;

    printf("Enter roll number to update: ");
    scanf("%d", &roll);

    for (i = 0; i < n; i++) {

        if (s[i].roll == roll && roll > 0) {

            printf("Enter new marks: ");
            scanf("%f", &marks);

            if (marks < 0 || marks > 100) {
                printf("Invalid marks\n");
                return;
            }

            s[i].marks = marks;

            printf("Student updated successfully\n");
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Student not found\n");
}

void deleteStudent(Student *s, int n) {
    int roll, i, found = 0;

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    for (i = 0; i < n; i++) {

        if (s[i].roll == roll && roll > 0) {

            s[i].roll = 0;
            s[i].name[0] = '\0';
            s[i].marks = 0;

            found = 1;

            printf("Student deleted successfully\n");
            break;
        }
    }

    if (found == 0)
        printf("Student not found\n");
}

int main() {
    Student *s;
    int n, choice;

    printf("Enter maximum number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number\n");
        return 1;
    }

    s = calloc(n, sizeof(Student));

    if (s == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (1) {

        printf("\n===== STUDENT MANAGEMENT =====\n");
        printf("1. Add Students\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent(s, n);
                break;

            case 2:
                displayStudent(s, n);
                break;

            case 3:
                searchStudent(s, n);
                break;

            case 4:
                updateStudent(s, n);
                break;

            case 5:
                deleteStudent(s, n);
                break;

            case 6:
                free(s);
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}