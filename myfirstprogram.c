#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===========================
// STRUCTURE DEFINITIONS
// ============================
typedef struct {
    int id;
    char name[50];
    int age;
    float marks;
} Student;

// =======================
// FUNCTION DECLARATIONS
// =======================
void addStudent(Student students[], int *count);
void displayStudents(Student student[], int count);
void searchStudent(Student students[], int count);
void saveToFile(Student students[], int count);
void loadFromFile(Student students[], int *count);
void sortStudents(Student students[], int count);
void clearInputBuffer();

// ======================
// MAIN FUNCTION
// ======================
int main() {
    Student students[100];
    int count = 0;
    int choice;

    loadFromFile(students, &count);

    while (1) {
        printf("\n===================\n");
        printf("Student Record Manager\n");
        printf("=======================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Students\n");
        printf("4. Sort Students by Marks\n");
        printf("5. Save to File\n");
        printf("6. Exit\n");
        printf("Enter choise: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
               addStudent(students, &count);
               break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                sortStudents(students, count);
                break;
            case 5:
                saveToFile(students, count);
                break;
            case 6:
                saveToFile(students, count);
                printf("Exiting... Data saved. \n");
                exit(0);
            default:
                printf("Invalid choice! Try again. \n");            
        }
    }

    return 0;
}

// ==================================
// FUNCTION IMPLEMENTATIONS
// =================================
void addStudent(Student students[], int *count) {
    if (*count >=100) {
        printf("Maximum student limit reached.\n");
        return;
    }

    Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    clearInputBuffer();

    printf("Enter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline
    
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    students[*count] = s;
    (*count)++;

    printf("Student added successfully!\n");
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n%-5s %-20s %-5s %-7s\n", "ID", "Name", "Age", "Marks");
    printf("--------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-5d %-7.2f\n", students[i].id, students[i].name, students[i].age, students[i].marks);
    }
}

void searchStudent(Student students[], int count) {
    if (count == 0) {
        printf("No records available.\n");
        return;
    }

    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nMarks: %.2f\n",
                    students[i].id, students[i].name, students[i].age, students[i].marks);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void sortStudents(Student students[], int count) {
    if (count < 2)  {
        printf("Not enough students to sort.\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Students sorted by marks (descending).\n");
}

void saveToFile(Student students[], int count) {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error saving file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d, %s, %d, %.2f\n", students[i].id, students[i].name, students[i].age, students[i].marks);
    }

    fclose(fp);
    printf("Data saved successfully to students.txt\n");
}

void loadFromFile(Student students[], int *count) {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        // No file yet, that's fine
        return;
    }

    while (!feof(fp))  {
        Student s;
        if (fscanf(fp, "%d,%49[^,],%d,%f\n", &s.id, s.name, &s.age, &s.marks) == 4) {
            students[*count] = s;
            (*count)++;
        }
    }
    fclose(fp);
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}


