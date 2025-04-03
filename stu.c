#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student students[MAX_STUDENTS];
int count = 0;

void addStudent() {
    if (count >= MAX_STUDENTS) {
        printf("Database is full!\n");
        return;
    }
    printf("Enter Roll Number: ");
    scanf("%d", &students[count].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }
    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("Roll: %d, Name: %s, Marks: %.2f\n", students[i].roll, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int roll;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Found: Roll: %d, Name: %s, Marks: %.2f\n", students[i].roll, students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student not found!\n");
}

void deleteStudent() {
    int roll, i, j;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);
    for (i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Search Student\n4. Delete Student\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
