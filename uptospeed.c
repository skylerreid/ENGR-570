#include <stdio.h>

int process_input(int x, int y, const char *fruit) {
    int num_fruits = x + y;

    if (num_fruits == 1) {
        printf("You have %d %s\n", num_fruits, fruit);
    } else {
        printf("You have %d %ss\n", num_fruits, fruit);
    }
    return num_fruits;
}

int main(){
    int fruit1;
    int fruit2;
    char fruitname[20];
    int out;

    printf("Enter a number of fruits: ");
    scanf("%d", &fruit1);

    printf("\n Enter another number: ");
    scanf("%d", &fruit2);

    printf("\n Enter the type of fruit: ");
    scanf("%s", fruitname);

    out = process_input(fruit1, fruit2, fruitname);
    //printf("%d", out);
    
    return 0;
}