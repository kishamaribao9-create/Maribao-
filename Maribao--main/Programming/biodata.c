#include <stdio.h>
#include <stdlib.h>

struct StudentInfo {
    char firstName[100];
    char lastName[100];
    char course[100];
    char yearLevel[50];
    char block[50];
    char Sex[100];
    char dean[100];
    char chairperson[100];
};

struct SubjectFaculty {
    char subject[100];
    char faculty[100];
};

struct SchoolOfficials {
    char viceChancellor[100];
    char chancellor[100];
    char registrar[100];
};

int main() {

    // Allocate all structures dynamically
    struct StudentInfo *student = (struct StudentInfo*) malloc(sizeof(struct StudentInfo));
    struct SchoolOfficials *school = (struct SchoolOfficials*) malloc(sizeof(struct SchoolOfficials));

    int *numSubjects = (int*) malloc(sizeof(int));

    // Dynamic array for subjects (max 30)
    struct SubjectFaculty *subjects = 
        (struct SubjectFaculty*) malloc(30 * sizeof(struct SubjectFaculty));

    // INPUTS (using pointer access -> field)
    printf("Enter your First Name: ");
    fgets(student->firstName, sizeof(student->firstName), stdin);

    printf("Enter your Last Name: ");
    fgets(student->lastName, sizeof(student->lastName), stdin);

    printf("Enter your Course: ");
    fgets(student->course, sizeof(student->course), stdin);

    printf("Enter your Year Level: ");
    fgets(student->yearLevel, sizeof(student->yearLevel), stdin);

    printf("Enter your Block: ");
    fgets(student->block, sizeof(student->block), stdin);

    printf("Enter your Sex: ");
    fgets(student->Sex, sizeof(student->Sex), stdin);

    printf("Enter the Dean's Name: ");
    fgets(student->dean, sizeof(student->dean), stdin);

    printf("Enter the Chairperson's Name: ");
    fgets(student->chairperson, sizeof(student->chairperson), stdin);

    printf("Enter the Vice Chancellor's Name: ");
    fgets(school->viceChancellor, sizeof(school->viceChancellor), stdin);

    printf("Enter the Chancellor's Name: ");
    fgets(school->chancellor, sizeof(school->chancellor), stdin);

    printf("Enter the Registrar's Name: ");
    fgets(school->registrar, sizeof(school->registrar), stdin);

    // SUBJECT COUNT
    printf("How many subjects enrolled: ");
    scanf("%d", numSubjects);
    getchar(); // consume newline

    for (int i = 0; i < *numSubjects; i++) {
        printf("Enter subject: ");
        fgets((subjects + i)->subject, 100, stdin);

        printf("Enter faculty: ");
        fgets((subjects + i)->faculty, 100, stdin);
    }

    // FILE OUTPUT
    FILE *file = fopen("Student_biodata.txt", "w");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(file, "First Name: %s", student->firstName);
    fprintf(file, "Last Name: %s", student->lastName);
    fprintf(file, "Course: %s", student->course);
    fprintf(file, "Year Level: %s", student->yearLevel);
    fprintf(file, "Block: %s", student->block);
    fprintf(file, "Sex: %s", student->Sex);
    fprintf(file, "Dean: %s", student->dean);
    fprintf(file, "Chairperson: %s", student->chairperson);

    fprintf(file, "Vice Chancellor: %s", school->viceChancellor);
    fprintf(file, "Chancellor: %s", school->chancellor);
    fprintf(file, "Registrar: %s", school->registrar);

    fprintf(file, "\nSubjects Enrolled: %d\n", *numSubjects);
    for (int i = 0; i < *numSubjects; i++) {
        fprintf(file, "%d. Subject: %s   Faculty: %s",
            i + 1,
            (subjects + i)->subject,
            (subjects + i)->faculty
        );
    }

    fclose(file);

    printf("\nBio data saved successfully in 'Student_biodata.txt'.\n");

    // FREE MEMORY
    free(student);
    free(school);
    free(subjects);
    free(numSubjects);

    return 0;
}
