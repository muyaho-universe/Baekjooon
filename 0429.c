#include <stdio.h>

void bubble_sort(int arr[], int count);

int main(){
    int total;
    int first, second, third, fourth, fifth;
    int scores[5];
    int nums[3];
    
    scanf("%d", &total);

    for (int i = 0; i < total; i++){
        scanf("%d %d %d %d %d", &first, &second, &third, &fourth, &fifth);
        scores[0] = first;
        scores[1] = second;
        scores[2] = third;
        scores[3] = fourth;
        scores[4] = fifth;
        bubble_sort(scores, 5);
        nums[0] = scores[1];
        nums[1] = scores[2];
        nums[2] = scores[3];
        if (nums[2] - nums[0] >= 4){
            printf("KIN\n");
        }
        else{
            printf("%d\n", nums[0]+nums[1]+nums[2]);
        }
    }
    return 0;

}

void bubble_sort(int arr[], int count)    // 매개변수로 정렬할 배열과 요소의 개수를 받음
{
    int temp;

    for (int i = 0; i < count; i++)    // 요소의 개수만큼 반복
    {
        for (int j = 0; j < count - 1; j++)   // 요소의 개수 - 1만큼 반복
        {
            if (arr[j] > arr[j + 1])          // 현재 요소의 값과 다음 요소의 값을 비교하여
            {                                 // 큰 값을
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;            // 다음 요소로 보냄
            }
        }
    }
}