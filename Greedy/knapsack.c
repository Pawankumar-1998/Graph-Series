#include <stdio.h>

//  function for swapping the number
void swap(float arr[], int first, int second)
{
    float temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

// algorithm of knapsack
float knapsack(int items, float profit[], float weight[], float capacity)
{
    float selectedQuantity[3];
    float totalProfit = 0;
    float capacityRemainig = capacity;

    for (int i = 0; i < items; i++)
    {
        if (weight[i] > capacityRemainig)
        {
            selectedQuantity[i] = capacityRemainig / weight[i];
            totalProfit = totalProfit + (selectedQuantity[i] * profit[i]);
            break;
        }
        else
        {
            selectedQuantity[i] = 1.0;
            totalProfit += profit[i];
            capacityRemainig -= weight[i];
        }
    }

    return totalProfit;
}

int main()
{
    //  1st  array is for the weight , 2nd is for profit , 3 is for ratio Per weight
    float profit[3], weight[3], profitPw[3], capacity;
    // this is for total number of items
    int num;
    printf("Enter the total number of items : \n");
    scanf("%d", &num);
    printf("Entet the total capacity of the knapsack : \n");
    scanf("%f", &capacity);

    // fill the details in both the arrays
    for (int i = 0; i < num; i++)
    {
        printf("enter the profit of item no %d : ", i + 1);
        scanf("%f", &profit[i]);
        printf("enter the weight of item no %d : ", i + 1);
        scanf("%f", &weight[i]);

        // filling the ratio array by value obtained by profit / weight
        profitPw[i] = profit[i] / weight[i];
    }

    // Sort items based on profit per weight ratio (descending order)
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (profitPw[j] < profitPw[j + 1])
            {
                swap(profitPw, j, j + 1);
                swap(profit, j, j + 1);
                swap(weight, j, j + 1);
            }
        }
    }

    //  after the items are sorted according to the order call the knapsack
    float result = knapsack(num, profit, weight, capacity);

    printf("Total profit can be earned is : %.2f", result);

    return 0;
}