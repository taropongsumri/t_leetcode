



int main(){
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int i = 0;
    while (i < size) {
        int j = i + 1;
        while (j < size) {
            if (array[i] == array[j]) {
                printf("true\n");
                return 1;
            }
            j++;
        }
        i++;
    }


    printf("false\n");
    return 0;
}