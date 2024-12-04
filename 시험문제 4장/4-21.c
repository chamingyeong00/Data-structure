#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int student_id;
};

struct Student* create_student() {
    struct Student* new_student = (struct Student*)malloc(sizeof(struct Student));
    if (new_student == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }

    printf("이름을 입력하세요: ");
    scanf("%s", new_student->name);
    printf("학번을 입력하세요: ");
    scanf("%d", &new_student->student_id);

    return new_student;
}

int main() {
    struct Student* student = create_student();

    printf("이름: %s\n", student->name);
    printf("학번: %d\n", student->student_id);

    free(student);

    return 0;
}

ptr = last->link
last->link = last->link->link;