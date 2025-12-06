#include <stdio.h>

int main() {
    float data [5][12] = {
        {5.5, 2.3, 2.2, 6.7, 9.9, 1.2, 2.5, 2.3, 2.2, 6.7, 9.9, 1.2},
        {5.8, 2.3, 2.2, 6.7, 9.9, 1.2, 2.8, 2.3, 2.2, 6.2, 9.8, 4.2},
        {8.5, 2.3, 4.4, 6.7, 9.9, 1.4, 1.5, 4.3, 2.2, 6.7, 4.9, 1.2},
        {5.5, 2.3, 2.7, 6.7, 9.9, 1.7, 5.5, 7.3, 2.8, 6.3, 3.9, 1.2},
        {20.5, 2.3, 2.1, 6.7, 9.9, 1.2, 7.5, 2.6, 3.2, 6.4, 6.9, 1.2}
    };

    float yearly_sum[5];
    float yearly_average = 0;
    float monthly_average[12];

    // getting yearly sum
    for (int i=0; i<5; ++i) {
        float sum = 0;
        for (int j=0; j<12; ++j) {
            sum += data[i][j];
        }
        yearly_sum[i] = sum;
        printf("Year %d, Total Rainfall: %.2f\n", i+1, yearly_sum[i]);
    }

    for (int i = 0; i < 5; ++i) {
        yearly_average += yearly_sum[i];
    }
    yearly_average /= 5;
    printf("Average yearly rainfall: %.2f\n", yearly_average);

    for (int j = 0; j < 12; ++j) {
        float sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += data[i][j];
        }
        monthly_average[j] = sum / 5;
        printf("Month %d, Average Rainfall: %.2f\n", j+1, monthly_average[j]);
    }

    printf("Size of data array: %lu bytes\n", sizeof(data));

    return 0;
}