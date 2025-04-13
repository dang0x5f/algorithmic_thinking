#include <stdio.h>

#define SIZE 100000

void test1(void);
void identify_identical(int [], int);

void test2(void);
int identical_right(int [], int [], int);
int identical_left(int [], int [], int);
int are_identical(int [], int []);

void test3(void);

void test4(void);
void identify_identical2(int [][6], int);

int main(void)
{
    /* test1(); */
    /* test2(); */
    /* test3(); */
    test4();
    return(0);
}

void 
test4(void)
{
    static int snowflakes_test4[SIZE][6];
    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        for(j = 0; j < 6; j++)
            scanf("%d", &snowflakes_test4[i][j]);
    identify_identical2(snowflakes_test4, n);
}

void 
identify_identical2(int snowflakes_test4[][6], int n)
{
    int i, j;
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(are_identical(snowflakes_test4[i],snowflakes_test4[j])){
                printf("Twin snowflakes found.\n");
                return;
            }
        }
    }
    printf("No two snowflakes are alike.\n");
}

void
test3(void)
{
    int snowflake_count;

    scanf("%d", &snowflake_count);
    printf("snowflake count : %d\n", snowflake_count);

    int snowflakes[snowflake_count][6];

    for(int count = 0; count < snowflake_count; count++){
        for(int arm_count = 0; arm_count < 6; arm_count++){
            scanf("%d",&snowflakes[count][arm_count]);
            printf(" %d ", snowflakes[count][arm_count]);
            /* printf("snowflakes[%d][%d] : %d ", */ 
            /*    count, arm_count, snowflakes[count][arm_count]); */ 
        }
        printf("\n");
    }
}

void
test2(void)
{
    int snow1[6] = {1,2,3,4,5,6};
    int snow2[6] = {4,3,2,1,6,5};

    if(are_identical(snow1, snow2))
        printf("Twin snowflakes found.\n");
    else
        printf("No two snowflakes are alike.\n");
}

int 
identical_right(int snow1[], int snow2[], int start)
{
    int offset;
    for(offset = 0; offset < 6; offset++){
        if(snow1[offset] != snow2[(start+offset)] % 6)
            return(0);
    }
    return(1);
}

int 
identical_left(int snow1[], int snow2[], int start)
{
    int offset, snow2_index;
    for(offset = 0; offset < 6; offset++){
        snow2_index = start - offset;
        if(snow2_index < 0)
            snow2_index += 6;
        if(snow1[offset] != snow2[snow2_index])
            return(0);
    }
    return(1);
}

int
are_identical(int snow1[], int snow2[])
{
    int start;
    for(start = 0; start < 6; start++){
        if(identical_right(snow1,snow2,start))
            return(1);
        if(identical_left(snow1,snow2,start))
            return(1);
    }
    return(0);
}

void
test1(void)
{
    int a[5] = {1, 2, 3, 1, 5};
    identify_identical(a, 5);
}

void 
identify_identical(int values[], int n)
{
    int i, j;
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(values[i] == values[j]){
                printf("Twin integers found.\n");
                return;
            }
        }
    }
    printf("No two integers are alike.\n");
}
