#include <stdio.h>
#include "linked_list.h"

int main() {
    char ch;
    int num;
    struct list *ptr = NULL;

    while(1) { // Infinite loop to accept new input
        scanf("%c", &ch);

        switch(ch) {
            case 'a':
                scanf("%d", &num);
                getchar();
                ptr = push_back(ptr, num);
                break;
            case 'b':
                scanf("%d", &num);
                getchar();
                ptr = push_front(ptr, num);
                break;
            case 'r':
                getchar();
                ptr = delete_headElement(ptr);
                break;
            case 'p':
                getchar();
                printList(ptr);
                break;
            case 'q':
                getchar();
                dispose_list(ptr);
                return 0;
            default:
                return 0;
        }
    }
}