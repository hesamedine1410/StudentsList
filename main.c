#include "student_management.h"
#include <stdio.h>

int main() {
    int choice;
    do {
        printf("\n---- Student Management System ----\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student by ID\n");
        printf("4. Sort Students by Average\n");
        printf("5. Save List to File\n");
        printf("6. Load List from File\n");
        printf("7. Print All Students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(); break;
            case 2: delete_student(); break;
            case 3: search_student(); break;
            case 4: sort_students(); break;
            case 5: save_to_file(); break;
            case 6: load_from_file(); break;
            case 7: print_students(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
