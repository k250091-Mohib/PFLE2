#include<stdio.h>
#include<stdlib.h>
#define rows 10

int main(){
    printf("The number of rows are %d\n",rows);
    int **arr=(int **)malloc(rows*sizeof(int));
    if (arr==NULL)
    {
        printf("Memory Allocation Failed.\n");
        return 1;
    }
    int cols[rows];
    for (int i = 0; i < rows; i++)
    {
        printf("Enter number of columns for Row: %d : ",i+1);
        scanf("%d",&cols[i]);
        arr[i]=(int *) malloc(cols[i]*sizeof(int *));
        if (arr[i]==NULL)
        {
            printf("Memory Allocation Failed.\n");
            return 1;
        }

        for (int j = 0; j < cols[i]; j++)
        {
            arr[i][j]=i+1;
        }
    }

    printf("\n");

    for (int i = 0; i < rows; i++) 
    {
        printf("Row %d : ", i + 1);
        for (int j = 0; j < cols[i]; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
    
    
}