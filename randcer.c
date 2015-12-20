#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMBER_EACH_DRAW 6
#define NUMBER_LOWER_LIMIT 1
#define NUMBER_UPPER_LIMIT 34
#define NUMBER_RANGE (NUMBER_UPPER_LIMIT - NUMBER_LOWER_LIMIT + 1)

typedef enum {false = 0, true} bool;

bool is_number(char *str);
void start_main_loop(int draw_count);
void quick_sort (int *a, int n);

void analysis_odd_even_ratio(int *numbers, int n, char *buf, int buf_size);
void analysis_big_small_ratio(int *numbers, int n, int mid, char *buf, int buf_size);
void analysis_sum(int *numbers, int n, char *buf, int buf_size);
void analysis_continue_count(int *sorted_numbers, int n, char *buf, int buf_size);
void analysis_sum_mod(int *numbers, int n, int mod, char *buf, int buf_size);

int main(int argc, char *argv[]) {
    
    if (argc == 2 && is_number(argv[1])) {
        start_main_loop(atoi(argv[1]));
        return 0;
    }
    
    printf("Wrong argument.\nrancer number_of_draws\n");
    
    return 0;
}

bool is_number(char *str) {
    int i;
    const int len = strlen(str);
    
    for (i = 0 ; i < len ; i++) {
        if (!isdigit(str[i])) {
            break;
        }
    }
    
    return len == i;
}

void quick_sort (int *a, int n) {
    int i, j, p, t;
    if (n < 2)
        return;
    p = a[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    quick_sort(a, i);
    quick_sort(a + i, n - i);
}

void analysis_odd_even_ratio(int *numbers, int n, char *buf, int buf_size) {
    
    int odd = 0, even = 0;
    for (int i = 0 ; i < n ; i++) {
        if (numbers[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    
    memset(buf, 0, buf_size * sizeof(char));
    sprintf(buf, "%d:%d", odd, even);
}

void analysis_big_small_ratio(int *numbers, int n, int mid, char *buf, int buf_size) {
    int small = 0, big = 0;
    for (int i = 0 ; i < n ; i++) {
        if (numbers[i] <= mid) {
            small++;
        } else {
            big++;
        }
    }
    
    memset(buf, 0, buf_size * sizeof(char));
    sprintf(buf, "%d:%d", big, small);
}

void analysis_sum(int *numbers, int n, char *buf, int buf_size) {
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        sum += numbers[i];
    }
    
    memset(buf, 0, buf_size * sizeof(char));
    sprintf(buf, "%d", sum);
}

void analysis_continue_count(int *sorted_numbers, int n, char *buf, int buf_size) {
    int cont_count = 0;
    for (int i = 0 ; i < n - 1 ; i++) {
        if (sorted_numbers[i] + 1 == sorted_numbers[i + 1]) {
            cont_count++;
        }
    }
    
    memset(buf, 0, buf_size * sizeof(char));
    sprintf(buf, "%d", cont_count);
}

void analysis_sum_mod(int *numbers, int n, int mod, char *buf, int buf_size) {
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        sum += numbers[i];
    }

    sum = sum % mod;
    
    memset(buf, 0, buf_size * sizeof(char));
    sprintf(buf, "%d", sum);
}

void start_main_loop(int draw_count) {
    if (draw_count > 0) {
        
        printf("I\tII\tIII\tIV\tV\tVI\tO:E\tB:S\tSUM\tCOT\tSM7\n");
        printf("-----------------------------------------------------------------------------------\n");
        
        for (int i = 0 ; i < draw_count ; i++) {
            // each draw we generate NUMBER_EACH_DRAW random numbers
            int draw[NUMBER_EACH_DRAW];
            int occurrence[NUMBER_RANGE];
            int j = 0, numbers_needed = NUMBER_EACH_DRAW;
            memset(occurrence, 0, NUMBER_RANGE * sizeof(int));

            while (numbers_needed > 0) {
                int number = arc4random_uniform(1 + NUMBER_UPPER_LIMIT - NUMBER_LOWER_LIMIT);
                if (occurrence[number] == 1) {
                    continue;
                }

                occurrence[number] = 1;
                draw[j++] = NUMBER_LOWER_LIMIT + number;
                numbers_needed--;
            }
            
            // then we print out the draw as well as all analysis data
            quick_sort(draw, NUMBER_EACH_DRAW);
            
            for (int j = 0 ; j < NUMBER_EACH_DRAW ; j++) {
                printf("%d\t", draw[j]);
            }
            
            // analysis
            const int BUFFER_SIZE = 12;
            char result[BUFFER_SIZE];
            analysis_odd_even_ratio(draw, NUMBER_EACH_DRAW, result, BUFFER_SIZE);
            printf("%s\t", result);
            
            analysis_big_small_ratio(draw, NUMBER_EACH_DRAW, (NUMBER_UPPER_LIMIT - NUMBER_LOWER_LIMIT) / 2.0, result, BUFFER_SIZE);
            printf("%s\t", result);
            
            analysis_sum(draw, NUMBER_EACH_DRAW, result, BUFFER_SIZE);
            printf("%s\t", result);
            
            analysis_continue_count(draw, NUMBER_EACH_DRAW, result, BUFFER_SIZE);
            printf("%s\t", result);

            analysis_sum_mod(draw, NUMBER_EACH_DRAW, 7, result, BUFFER_SIZE);
            printf("%s\n", result);
        }
        
    }
}
