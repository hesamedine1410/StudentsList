#ifndef STUDENT_MANAGEMENT_H
#define STUDENT_MANAGEMENT_H

#define MAX_STUDENTS 300
#define MAX_NAME_LEN 80
#define STUDENT_ID_LEN 11

typedef struct {
    char first_name[MAX_NAME_LEN];
    char last_name[MAX_NAME_LEN];
    char student_id[STUDENT_ID_LEN];
    float average;
} Student;

void add_student();
void delete_student();
void search_student();
void sort_students();
void save_to_file();
void load_from_file();
void print_students();

#endif // STUDENT_MANAGEMENT_H
