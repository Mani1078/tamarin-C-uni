

// alert : مبحثش جدید بود و بلدش نبودی 
// دلایل استفاده از پوینتر : 
// هدر نرفتن حافظه 
// انعطاف پذیری کد 
// تو مصاحبه هم خب طبیعتا مهمه که بلد باشی حتی به عنوان متخصص امنیت... حتی میتونه باعث ایجاد باگ بشه
//چرا ؟ چون مستقیما با حافظه سر و کار داره و اینجکشن میتونه بخوره   


#include <stdio.h>
#include <stdlib.h> // واسه ملوک
//40213161099

// دقت کن ... توی روش بابل سورت هر عنصر با بعدی خودش مقایسه میشه 
// هرکدوم بیشتر باشه جابجا میشه 
//معمولا هم همینطوریه کدش
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

double funcmedian(int *arr, int n) {
    if (n % 2 == 0) {
        return (*(arr + n / 2 - 1) + *(arr + n / 2)) / 2.0;
    } else {
        return *(arr + n / 2);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int *arr = (int *)malloc(n* sizeof(int)); // ان تعداده دیگه

    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }
    bubbleSort(arr, n);


    int min = *(arr);
    int max = *(arr + n - 1);
    double median = funcmedian(arr, n);

    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    printf("Med: %.2f\n", median);

    free(arr);

    return 0;
}
