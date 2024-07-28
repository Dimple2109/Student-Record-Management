#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int roll_no;
    char name[50];
    float marks;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Error: Maximum student limit reached.\n");
        return;
    }

    Student s;
    printf("Enter roll number: ");
    scanf("%d", &s.roll_no);
    printf("Enter name: ");
    scanf(" %[^\n]%*c", s.name); // Read string with spaces
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    students[student_count++] = s;
    printf("Student record added successfully.\n");
}

void view_students() {
    if (student_count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("Roll_No\tName\tMarks\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d\t%s\t%.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
}

void search_student() {
    if (student_count == 0) {
        printf("No student records found.\n");
        return;
    }

    int roll_no;
    printf("Enter roll number to search: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("Student found:\n");
            printf("Roll No: %d\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }

    printf("Error: Student record not found.\n");
}

void update_student() {
    if (student_count == 0) {
        printf("No student records found.\n");
        return;
    }

    int roll_no;
    printf("Enter roll number to update: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("Enter new name: ");
            scanf(" %[^\n]%*c", students[i].name);
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);

            printf("Student record updated successfully.\n");
            return;
        }
    }

    printf("Error: Student record not found.\n");
}

void delete_student() {
    if (student_count == 0) {
        printf("No student records to delete.\n");
        return;
    }

    int roll_no;
    printf("Enter roll number of the student to delete: ");
    scanf("%d", &roll_no);

    int index = -1;
    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Student record not found.\n");
        return;
    }

    for (int i = index; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }

    student_count--;
    printf("Student record deleted successfully.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                view_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                update_student();
                break;
            case 5:
                delete_student();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
