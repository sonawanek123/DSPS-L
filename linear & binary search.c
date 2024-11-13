#include <stdio.h>

int main() {
    int i, n, a[10], flag, key, ch, low, high, mid;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    do {
        printf("\n1. Linear search \n2. Binary search \n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number you want to search: ");
                scanf("%d", &key);
                flag = 0; 
                for (i = 0; i < n; i++) {
                    if (key == a[i]) {
                        printf("\n%d present at %d position\n", key, i);
                        flag = 1;
                        break; 
                    }
                }
                if (flag == 0) {
                    printf("Number not present\n");
                }
                break;

            case 2:
                printf("Enter the number you want to search: ");
                scanf("%d", &key);
                low = 0;
                high = n - 1;
                flag = 0; // Reset flag for each search
                while (low <= high) {
                    mid = (low + high) / 2;
                    if (key == a[mid]) {
                        printf("%d found at %d position\n", key, mid);
                        flag = 1;
                        break;
                    } else if (key > a[mid]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (flag = 0) {
                    printf("Number not found\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Wrong choice! Please choose 1, 2, or 3.\n");
        }
    } while (ch != 3); // Continue until the user chooses to exit

    return 0;
}
