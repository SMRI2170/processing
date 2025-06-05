#include <stdio.h>

#define PERSON_NUM 5

typedef struct {   
    char name[20];
    char sex; 
    int age;
    double height; 
    double weight; 
} person_t;

int main()
{
    person_t p[PERSON_NUM] = {{"Bob",      'M', 19, 165.4, 72.5},
                              {"Alice",    'F', 19, 161.7, 44.2},
                              {"Tom",      'M', 20, 175.2, 66.3},
                              {"Stefany",  'F', 18, 159.3, 48.5},
                              {"Leonardo", 'M', 19, 172.8, 67.2}};
printf("%s",p[2].name);
}