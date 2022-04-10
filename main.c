#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct node{
    char name[18];
    char code[22];
    int grade;
    int index;
    struct node *next;
} NODE;


NODE *head, *p, *s;










void indexing(){

}

char search(){
    char target[18];
    printf("输入姓名");
    scanf("%s", target);
    printf("%s", s->name);
 /*   while(p->next->name != target){
        p = p->next;
    }
    if (p->next){
        printf("asda");
        return p->next->name;
    }
    else{
        printf("NOOOOOPE");
        return NULL;
    }*/
}





void Init() {

}

void createNew() {
    char name[18];
    char code[22];
    int grade;

    scanf("%d", &grade);
    scanf("%s", &name);
    scanf("%s", &code);

    s = (NODE *) malloc(sizeof (NODE));

    strcpy(s -> name, name);
    strcpy(s -> code, code);
    s->grade = grade;

    s->next = p->next;

    p->next = &s;
    p = s;
}


void showMenu() {
    int result;
    printf("1 - 插入数据");
    printf("\n2 - 删除数据");
    printf("\n3 - 查找信息");
    printf("\n4 - 统计个数");
    printf("\n5 - 排序");
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
            break;
        case 5:
            break;
    };
}




int main() {
    head = (NODE *) malloc(sizeof(NODE));
    head->next = NULL;
    p = head;
    for(int i = 0; i<1; i--) {
        createNew();
        printf("%d\n", s->grade);
        printf("结果 - %s\n", p->name);
        printf("结果 - %s\n", p->code);
        if(s->grade == 1){
            p = head;
            break;
        }
    }


    showMenu();

    return 0;
}