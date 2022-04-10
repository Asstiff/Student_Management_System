#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct node{
    char name[18];
    int code;
    int grade;
    int index;
    struct node *next;
} NODE;


NODE *head, *p, *s;



void showMenu();


void displayAll(){
    p = head;
    while (p->next != NULL){
        if (p->next->index) {
            printf("\n%s的成绩是%d，他的学号是%d，他的索引是%d", p->next->name, p->next->grade, p->next->code, p->next->index);
        }
        else{
            printf("\n%s的成绩是%d，他的学号是%d", p->next->name, p->next->grade, p->next->code);
        }
        p = p->next;
    }
};


void indexing(){
    p = head;
    int indexCount = 1;
    printf("正在索引");
    while (p->next != NULL){
        p->next->index = indexCount;
        indexCount++;
        p = p->next;
    }
    printf("\n索引完成");
    showMenu();
}

void search(){
    p = head;
    char targetName[18];
    scanf("%s", targetName);
    while (p->next != NULL && strcmp(p->next->name,&targetName)){
        p = p->next;
    }
    if (p->index) {
        printf("\n%s的成绩是%d，他的学号是%d，他的索引是%d", p->next->name, p->next->grade, p->next->code, p->next->index);
    }
    else{
        printf("\n%s的成绩是%d，他的学号是%d", p->next->name, p->next->grade, p->next->code);
    }
    showMenu();
}




void createNew() {
    char nameInput[18];
    int codeInput;
    int gradeInput;
    scanf("%s", nameInput);
    scanf("%d", &gradeInput);
    scanf("%d", &codeInput);
    s = (NODE *) malloc(sizeof (NODE));
    strcpy(s->name, nameInput);
    s->grade = gradeInput;
    s->code = codeInput;
    s->next = p->next;
    p->next = s;
    p = s;
}


void showMenu() {
    int result;
    printf("\n1 - 插入数据");
    printf("\n2 - 删除数据");
    printf("\n3 - 查找信息");
    printf("\n4 - 索引");
    printf("\n5 - 排序");
    printf("\n6 - 展示全部");
    printf("\n\n输入你中意的数字…\n");
    scanf("%d", &result);

    switch (result) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            search();
            break;
        case 4:
            indexing();
            break;
        case 5:
            break;
        case 6:
            displayAll();
            break;
    };
}




int main() {
    head = (NODE *) malloc(sizeof (NODE));
    head->next = NULL;
    p = head;
    for(int i = 0; i<1; i--) {
        createNew();
        printf("结果 - %s\n", p->name);
        if(s->grade == 1){
            p = head;
            printf("\n第一个学生是%s，他的成绩是%d，他的学号是%d", p->next->name, p->next->grade, p->next->code);
            printf("\n第二个学生是%s，他的成绩是%d，他的学号是%d", head->next->next->name, head->next->next->grade, head->next->next->code);
            break;
        }
    }


    showMenu();


    return 0;
}