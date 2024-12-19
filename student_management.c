#include "student_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    printf("Enter first name: ");
    scanf("%s", students[student_count].first_name);
    printf("Enter last name: ");
    scanf("%s", students[student_count].last_name);
    printf("Enter student ID: ");
    scanf("%s", students[student_count].student_id);
    printf("Enter average: ");
    scanf("%f", &students[student_count].average);

    student_count++;
    printf("Student added successfully!\n");
}

void delete_student() {
    char student_id[STUDENT_ID_LEN];
    printf("Enter student ID to delete: ");
    scanf("%s", student_id);

    int found = 0;
    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            found = 1;
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %s not found.\n", student_id);
    }
}

void search_student() {
    char student_id[STUDENT_ID_LEN];
    printf("Enter student ID to search: ");
    scanf("%s", student_id);

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].student_id, student_id) == 0) {
            printf("Student found:\n");
            printf("Name: %s %s\n", students[i].first_name, students[i].last_name);
            printf("ID: %s\n", students[i].student_id);
            printf("Average: %.2f\n", students[i].average);
            return;
        }
    }
    printf("Student with ID %s not found.\n", student_id);
}

void sort_students() {
    for (int i = 0; i < student_count - 1; i++) {
        for (int j = i + 1; j < student_count; j++) {
            if (students[i].average < students[j].average) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Students sorted by average successfully!\n");
}

void save_to_file() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d\n", student_count);
    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%s %s %s %.2f\n", students[i].first_name, students[i].last_name,
                students[i].student_id, students[i].average);
    }
    fclose(file);
    printf("Student list saved successfully!\n");
}

void load_from_file() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    fscanf(file, "%d", &student_count);
    for (int i = 0; i < student_count; i++) {
        fscanf(file, "%s %s %s %f", students[i].first_name, students[i].last_name,
               students[i].student_id, &students[i].average);
    }
    fclose(file);
    printf("Student list loaded successfully!\n");
}

void print_students() {
    printf("ID\tFirst Name\tLast Name\tAverage\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d\t%s\t%s\t%.2f\n", i + 1, students[i].first_name, students[i].last_name, students[i].average);
    }
}
