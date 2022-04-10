#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ifInitialized = 0;

typedef struct node{
    char name[18];
    int code;
    int grade;
    int index;
    struct node *next;
} NODE;


NODE *head, *p, *s;



void showMenu();
void createNew();
void skip();
void searchMenu();



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
    printf("\n-----------------\n");
    printf("正在索引…");
    while (p->next != NULL){
        p->next->index = indexCount;
        indexCount++;
        p = p->next;
    }
    printf("\n索引完成");
    printf("\n-----------------\n");
    printf("\n\n-----------------\n");
    printf("总共 %d 名学生", indexCount-1);
    printf("\n-----------------\n");
}

void searchByName(){
    p = head;
    char targetName[18];
    scanf("%s", targetName);
    while (p->next != NULL && strcmp(p->next->name,&targetName)){
        p = p->next;
    }
    if(p->next){
        if (p->index) {
            printf("\n-----------------\n");
            printf("%s的成绩是%d，他的学号是%d，他的索引是%d", p->next->name, p->next->grade, p->next->code, p->next->index);
            printf("\n-----------------\n");
        }
        else{
            printf("\n-----------------\n");
            printf("%s的成绩是%d，他的学号是%d", p->next->name, p->next->grade, p->next->code);
            printf("\n-----------------\n");
        }
    }
    else{
        printf("\n-----------------\n");
        printf("没有找到。");
        printf("\n-----------------\n");
    }
}





void searchByCode(){
    p = head;
    int targetCode;
    scanf("%d", &targetCode);
    while (p->next != NULL && p->next->code != targetCode){
        p = p->next;
    }
    if(p->next){
        if (p->index) {
            printf("\n-----------------\n");
            printf("%s的成绩是%d，他的学号是%d，他的索引是%d\n", p->next->name, p->next->grade, p->next->code, p->next->index);
            printf("\n-----------------\n");
        }
        else{
            printf("\n-----------------\n");
            printf("%s的成绩是%d，他的学号是%d\n", p->next->name, p->next->grade, p->next->code);
            printf("\n-----------------\n");
        }
    }
    else{
        printf("\n-----------------\n");
        printf("没有找到。");
        printf("\n-----------------\n");
    }
}



void insert(){
    printf("\n-----------------\n");
    printf("你想在哪个学生后面插入？");
    printf("\n-----------------\n");

    searchByName();
    s = p;

    printf("\n-----------------\n");
    printf("已找到。请输入插入学生的数据");
    printf("\n-----------------\n");

    createNew();
}

void removal(){
    printf("\n-----------------\n");
    printf("你想消灭哪个学生？");
    printf("\n-----------------\n");

    searchByName();
    s = p;

    skip();

    printf("\n-----------------\n");
    printf("已消灭该学生。");
    printf("\n-----------------\n");
}

void skip(){
    s = p->next;
    p->next = p->next->next;
    free(s);
}

void swap(){

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
    if(ifInitialized == 0){
        s->next = p->next;
        p->next = s;
        p = s;
    } else{
        s->next = p->next->next;
        p->next->next = s;
        p = s;
    }

}


void searchMenu(){
    int result;
    printf("\n1 - 根据名字");
    printf("\n2 - 根据学号");
    printf("\n\n输入你中意的数字…\n");
    scanf("%d", &result);

    switch (result) {
        case 1:
            searchByName();
            break;
        case 2:
            searchByCode();
            break;
    };
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
            insert();
            system("read -n 1 -s -p \"任务完成。按下 Enter 键返回菜单。\"");
            indexing();
            showMenu();
            break;
        case 2:
            removal();
            system("read -n 1 -s -p \"任务完成。按下 Enter 键返回菜单。\"");
            indexing();
            showMenu();
            break;
        case 3:
            searchMenu();
            system("read -n 1 -s -p \"任务完成。按下 Enter 键返回菜单。\"");
            showMenu();
            break;
        case 4:
            indexing();
            system("read -n 1 -s -p \"任务完成。按下 Enter 键返回菜单。\"");
            showMenu();
            break;
        case 5:
            break;
        case 6:
            displayAll();
            system("read -n 1 -s -p \"任务完成。按下 Enter 键返回菜单。\"");
            showMenu();
            break;
        default:
            printf("\n-----------------\n");
            printf("我不理解。");
            printf("\n-----------------\n");
            system("read -n 1 -s -p \"请输入正确数字。按下 Enter 键返回菜单。\"");
            showMenu();
    };
}




int main() {
    head = (NODE *) malloc(sizeof (NODE));
    head->next = NULL;
    p = head;

    printf("\n输入初始数据个数\n");
    int count;
    scanf("%d", &count);
    for(int i = 0; i<count; i++) {

        printf("\n录入初始数据。以成绩为 -1 结束。\n");
        printf("\n｜名称｜   ｜成绩｜   ｜学号｜\n");
        createNew();
        printf("结果 - %s\n", p->name);
        if(s->grade == 1){
            p = head;
            break;
        }
    }
    ifInitialized = 1;
    indexing();
    showMenu();


    return 0;
}