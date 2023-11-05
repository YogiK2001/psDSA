#include <stdio.h>
#include <stdlib.h>

struct Activity
{
    char name;
    int start, finish;
};

int compareActivities(const void *a, const void *b)
{
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}
void activitySelection(struct Activity activities[], int n)
{
    qsort(activities, n, sizeof(struct Activity), compareActivities);

    printf("Selected Activities: %c ", activities[0].name);

    int prevFinish = activities[0].finish;

    for (int i = 1; i < n; i++)
    {
        if (activities[i].start >= prevFinish)
        {
            printf("%c ", activities[i].name);
            prevFinish = activities[i].finish;
        }
    }
}

int main()
{
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    for (int i = 0; i < n; i++)
    {
        printf("Activity %d: ", i + 1);
        scanf(" %c %d %d", &activities[i].name, &activities[i].start, &activities[i].finish);
    }

    activitySelection(activities, n);
    printf("\n");
    return 0;
}
