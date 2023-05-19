#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vending.h"

int menu()
{
    int menu;
    
    printf("\n***** 원하는 메뉴 *****\n");
    printf("1. 물건 추가\n");
    printf("2. 물건 조회\n");
    printf("3. 수정\n");
    printf("4. 물건 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 현금 투입\n");
    printf("7. 물건 구입\n");
    printf("8. 투입된 금액 확인\n");
    printf("9. 보유한 포인트 잔액 확인\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    
    return  menu;
} // 메뉴


int add_item(Item *item, int count) // 물건 추가 함수
{
    printf("물건의 이름?");
    scanf("%s", item[count].item_Name);

    printf("이 물건의 개당 가격은?");
    scanf("%d", &item[count].price);

    count++;
    printf("물건이 추가되었습니다.");

    return count;
} 

void print_list(Item *item, int count) // 조회함수
{
    if (count == 0)
    {
        printf("등록된 물건이 없습니다.");
        return; 
    }

    printf("***** 물건 목록 *****\n");
    for (int i = 0; i < count; i++)
    {
        printf("물건 이름: %s\n", item[i].item_Name);
        printf("물건 가격: %d\n", item[i].price);
        printf("물건 수량: %d\n", item[i].item_Count);
        printf("--------------------\n");
    }
} 

void updated_item(Item *item, int count) // 수정 함수
{
    char name[100];
    int updatedPrice;

    if (count == 0)
    {
        printf("등록된 물건이 없습니다.");
        return; 
    }

    printf("수정할 물건의 이름: ");
    scanf("%s", name);

     for (int i = 0; i < count; i++)
    {
        if (strcmp(item[i].item_Name, name) == 0)
        {
            printf("새로운 가격: ");
            scanf("%d", &updatedPrice);

            item[i].price = updatedPrice;

            printf("물건 정보가 수정되었습니다.\n");
            return;
        }
    }
    printf("해당하는 이름의 물건이 없습니다.\n"); // 이곳에 오는것이 맞는가?

}

int delete_item(Item *item, int count) // 물건 삭제 함수
{
   if (count == 0)
    {
        printf("등록된 물건이 없습니다.");
        return; 
    }

    int is_number;

    updated_item(item, count);

    printf("삭제할 물건의 번호를 입력하세요 ");

    while (1)
    {
        for (int i = 0; i < count; i++)
        {
            if (item[i].Number == is_number)
                is_number = i; // 삭제할 물건 번호 찾기
        }
        if (is_number == 0)
            printf("번호를 잘 못 입력했습니다. 다시 입력하세요. \n");

        else
            break;
    }

    for (int i = is_number; i < count - 1; i++)
        item[i] = item[i + 1]; 

    count--;

    printf("지출 내역이 삭제되었습니다.\n");

    return count;
}

void save_file(Item *item, int count, char filename[100]) // 파일 저장 함수
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d", item[i].Number); // 물품의 숫자를 파일에 저장

        fprintf(file, "%s\n", item[i].item_Name); // 물품의 이름을 파일에 저장

        fprintf(file, "%d ", item[i].price); // 물품의 가격을 파일에 저장
    }

    fclose(file);

    printf("파일이 저장되었습니다.\n");
}

int load_file(Item *item, char filename[100]) // 파일에서 읽어오는 함수
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf(" 파일이 존재하지 않습니다. 임시로 하나를 만들겠습니다.\n");
        return 0;
    }

    int count = -1;
    int a = 0;

    for (int i = 0; i < 100; i++)
    {
        if (feof(file))
            break;

        fscanf(file, "%d", &item[i].Number); // 

        for (int j = 0; j < 5; j++)
        {
            fscanf(file, " %d", &Data[i].item_Name); 
        }

        fscanf(file, "%d", &item[i].amount);    
        fscanf(file, " %[^\n]s", item[i].memo); 
        count++;
    }

    fclose(file);

    printf("파일이 불러와졌습니다.\n");

    return count;
}

void input_money(Item *item, int count) // 현금을 자판기에 투입하는 함수
{

}

void buy_item(Item *item, int count) // 물건을 구매하는 함수
{

}

void math_reward(Item *item, int count) // 포인트 계산 함수
{

}

void check_money(Item *item, int count) // 투입된 금액을 확인하는 함수
{

}

void check_point(Item *item, int count) // 현재 보유한 포인트 잔액 확인 기능
{

}

void exchange_money(Item *item, int count) // 거스름돈 함수
{

}