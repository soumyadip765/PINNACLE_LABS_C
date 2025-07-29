#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5
#define MAX_NAME_LENGTH 50
typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float grades[MAX_SUBJECTS];
    float average;
    char remark;
} Student;
Student students[MAX_STUDENTS];
int studentCount = 0;
char subjects[MAX_SUBJECTS][20] = {"Math", "C", "DSA", "Python", "Java"};
void addStudent();
void enterGrades();
void calculateAverages();
void generateReportCard();
void displayAllStudents();
char calculateRemark(float average);
int main() {
    int choice;
    printf("Student Grade Tracking System\n");
    while(1) {
        printf("Main Menu:\n");
        printf("1. Add New Student\n");
        printf("2. Enter Grades\n");
        printf("3. Calculate Averages\n");
        printf("4. Generate Report Card\n");
        printf("5. View All Students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addStudent(); break;
            case 2: enterGrades(); break;
            case 3: calculateAverages(); break;
            case 4: generateReportCard(); break;
            case 5: displayAllStudents(); break;
            case 6: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached!\n");
        return;
    }
    printf("\nEnter student name: ");
    scanf(" %[^\n]", students[studentCount].name);
    printf("Enter student ID: ");
    scanf("%d", &students[studentCount].id);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        students[studentCount].grades[i] = -1;
    }
    students[studentCount].average = 0;
    students[studentCount].remark = 'N';
    studentCount++;
    printf("Student added successfully!\n");
}
void enterGrades() {
    if (studentCount == 0) {
        printf("No students available. Please add students first.\n");
        return;
    }
    int id, found = 0;
    printf("\nEnter student ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("\nEntering grades for %s (ID: %d):\n", students[i].name, students[i].id);
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                do {
                    printf("%s: ", subjects[j]);
                    scanf("%f", &students[i].grades[j]);
                    if (students[i].grades[j] < 0 || students[i].grades[j] > 10) {
                        printf("Invalid grade! Please enter a value between 0 and 10.\n");
                    }
                } while (students[i].grades[j] < 0 || students[i].grades[j] > 10);
            }            
            printf("Grades entered successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}
void calculateAverages() {
    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }
    printf("\nCalculating averages...\n");
    for (int i = 0; i < studentCount; i++) {
        float sum = 0;
        int count = 0;        
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            if (students[i].grades[j] >= 0) {
                sum += students[i].grades[j];
                count++;
            }
        }        
        if (count > 0) {
            students[i].average = sum / count;
            students[i].remark = calculateRemark(students[i].average);
        } else {
            students[i].average = -1;
            students[i].remark = 'N';
        }
    }
    printf("Averages calculated successfully!\n");
}
char calculateRemark(float average) {
    if (average < 4) return 'F';
    else return 'P';
}
void generateReportCard() {
    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }
    int id, found = 0;
    printf("\nEnter student ID: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            printf("\nREPORT CARD\n");
            printf("Student Name: %s\n", students[i].name);
            printf("Student ID: %d\n", students[i].id);
            printf("\nSUBJECT\t\tGRADE (out of 10)\n");          
            for (int j = 0; j < MAX_SUBJECTS; j++) {
                if (students[i].grades[j] >= 0) {
                    printf("%-15s\t%6.1f\n", subjects[j], students[i].grades[j]);
                } else {
                    printf("%-15s\t   N/A\n", subjects[j]);
                }
            }
            printf("Average: %6.1f/10\n", students[i].average);
            printf("Remark: %6s\n", (students[i].remark == 'F') ? "FAIL" : "PASS");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found!\n", id);
    }
}
void displayAllStudents() {
    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }
    printf("\nLIST OF ALL STUDENTS\n");
    printf("ID\tNAME\t\tAVERAGE/10\tREMARK\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%-15s\t", students[i].id, students[i].name);
        if (students[i].average >= 0) {
            printf("%6.1f\t\t%c\n", students[i].average, students[i].remark);
        } else {
            printf("  N/A\t\tN\n");
        }
    }
    printf("Total students: %d\n", studentCount);
    printf("(F = Fail, P = Pass, N = No grades entered)\n");
}