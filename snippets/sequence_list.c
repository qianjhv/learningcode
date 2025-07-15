/*
 * Sequence List
 */
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

void initList(SeqList* list) {
    list->length = 0;
}

void printList(SeqList list) {
    for (int i = 0; i < list.length; i++) {
        printf("%d", list.data[i]);
    }
    printf("\n");
}

int find(SeqList list, int elem) {
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == elem) {
            return i;
        }
    }
    return -1;
}

int insert(SeqList* list, int pos, int elem) {
    if (pos < 1 || pos > list -> length + 1) {
        printf("Error positon!\n");
        return 0;
    }

    for (int i = list->length - 1; i >= pos - 1; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[pos - 1] = elem;
    list->length++;
    return 1;
}

int delete(SeqList* list, int pos) {
    if (pos < 1 || pos > list->length) {
        printf("Error postion\n");
        return 0;
    }

    for (int i = pos; i < list -> length; i++) {
        list->data[i - 1] = list->data[i];
    }
    list->length--;
    return 1;
}
