#include<stdio.h>
#include<stdlib.h>

/*
void sort_array(int *array, int size) { //Perform bubble sort
    int i, j, temp;
    for(i = 0 ; i < size-1 ; i++) {
        for(j = i+1 ; j < size; j++) {
            if(array[i]>array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    // printf("ARRAY SORTED\n");
    
}
*/

    int comparator (const void * a, const void * b)
	{
		return ( *(int*)a - *(int*)b );
	}

void majority_element(int * array, int size) {
    //sort_array(array, size);
    qsort(array, size, sizeof(int), comparator);
    int sum = 0, curr_element, tot_element, total = 0, j = 0;
    
    while(j < size) {
        if(j == 0) {        //First Iteration
            curr_element = tot_element = array[j];
            sum = total = 1;
        }
        
        else if(curr_element != array[j]) {//Change current details
            curr_element = array[j];
            sum = 1;
        }
        
        else {              //Current element continues
            sum += 1;
            if(sum > total){ //Current is leading 
                tot_element = curr_element;
                total = sum;
            }
        }
        
        j++;
    }
    if(total > size/2) {
        printf("%d\n", tot_element);
    }
    else
        printf("%d\n", -1);
}

void main() {
    int tests, size, j;
    scanf("%d", &tests);    // number of test cases
    // printf("TESTS: %d\n", tests);
    while(tests>0) {
        j = 0;
        scanf("%d", &size); // size of each array
        // printf("ARRAY SIZE: %d\n", size);
        int *array = (int *)malloc(size * sizeof(int));
        while(j < size && scanf("%d", &array[j++]) == 1);//array inputs
        majority_element(array, size);  //determine value
        tests--;
    }
}
