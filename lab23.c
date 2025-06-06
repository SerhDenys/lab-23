#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char street[50];
    int building;
    int apartment;
    float price;
} Apartment;

int main() {
    system("chcp 65001");
    int n;
    printf("Введіть кількість квартир: ");
    scanf("%d", &n);

    Apartment *apartments = (Apartment*)malloc(n * sizeof(Apartment));

    for (int i = 0; i < n; i++) {
        printf("\nКвартира #%d:\n", i+1);
        printf("Вулиця: ");
        scanf("%s", apartments[i].street);
        printf("Номер будинку: ");
        scanf("%d", &apartments[i].building);
        printf("Номер квартири: ");
        scanf("%d", &apartments[i].apartment);
        printf("Вартість: ");
        scanf("%f", &apartments[i].price);
    }

    char search_street[50];
    printf("\nВведіть назву вулиці для пошуку: ");
    scanf("%s", search_street);

    FILE *file = fopen("apartments.txt", "w");
    if (file == NULL) {
        printf("Помилка відкриття файлу!\n");
        return 1;
    }
    
    printf("\nРезультати пошуку:\n");
    fprintf(file, "Квартири на вулиці %s:\n", search_street);
    
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(apartments[i].street, search_street) == 0) {
            printf("Будинок %d, квартира %d, вартість: %.2f\n", 
                  apartments[i].building, 
                  apartments[i].apartment, 
                  apartments[i].price);
            
            fprintf(file, "Будинок %d, квартира %d, вартість: %.2f\n", 
                    apartments[i].building, 
                    apartments[i].apartment, 
                    apartments[i].price);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Квартир на вулиці %s не знайдено.\n", search_street);
        fprintf(file, "Квартир на вулиці %s не знайдено.\n", search_street);
    }

    fclose(file);
    free(apartments);
    
    printf("Результати також записані у файл apartments.txt\n");
    
    return 0;
}