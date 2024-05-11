// 12S23008 - Ranty Insen Pakpahan
// 12S23015 - Kevin Kristoforus Samosir


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/dorm.h"
#include "./libs/student.h"

int main(int _argc, char **_argv) 
{
    int looping = 0;
    char *token;
    char command[100];
    int sizeasrama=0;
    int sizemurid=0;
    struct student_t *student = malloc(100 * sizeof(struct student_t));
    struct dorm_t *dorm = malloc(100 *sizeof(struct dorm_t));
    int size_student = 0;
    int size_dorm = 0;

    while (looping != 1 )
    {
        command[0] = '\0';
        short k = 0;
        while (1 == 1)
        {
            char i = getchar();
            if (i == '\n')
            {
                break;
            }
            if (i == '\r')
            {
                continue;
            }
            command[k] = i;
            command[++k] = '\0';
        }
    token = strtok(command, "#");
    if (strcmp(token, "---") == 0)
    {
      break;
    }
    else if (strcmp(token, "dorm-add")== 0){
        sizeasrama++;
        dorm = realloc(dorm, sizeasrama* sizeof(struct dorm_t));
        dorm[size_dorm] = create_dorm(command);
        size_dorm++;
    }
    else if (strcmp(token, "dorm-print-all") == 0)
    {
        for (int a = 0; a < size_dorm; a++)
        {
            print_dorm(dorm[a]);
        }
    }
    else if (strcmp(token, "dorm-print-all-detail")==0)
    {
        for (int a = 0; a < size_dorm; a++)
        {
            print_dorm_detail(dorm[a]);
        }
    }
    else if (strcmp(token, "student-add")==0)
    {
        sizemurid++;
        student = realloc(student, sizemurid * sizeof(struct student_t));
        student[size_student]= create_student(command);
        size_student++
    }
    else if (strcmp (token, "student-print-all")==0)
    {
        for (int a = 0; a < size_student; a++)
        {
            print_student(student[a]);
        }
    }
    else if (strcmp (token, "student-print-all-detail")==0)
    {
        for (int a = 0; a < size_student; a++)
        {
            print_student_detail(student[a]);
        }
    }
    else if (strcmp (token, "assign-student")==0)
    {
        char *id = strtok(NULL, "#");
        char *ldorm = strtok (NULL, "#");
        assign_student(dorm, student, id, ldorm, size_student, size_dorm, find_id, find_dorm );
    }
    else if (strcmp(token, "move-student")==0)
    {
       
        char *id = strtok(NULL, "#");
        char *ldorm = strtok (NULL, "#");
        move_student(dorm, student, id, ldorm, size_student, size_dorm, find_id, find_dorm );
    }
    else if (strcmp(token, "dorm-empty")==0)
    {
        char*ldorm = strtok(NULL, "#");
        move_student(ldorm, student, dorm, size_student, size_dorm, find_dorm);

    }
    free(student);
    free(dorm);
    return 0;
}
}
