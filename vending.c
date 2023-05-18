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

void print_list(Item *item, int count) // 조회 함수
{
    if (count == 0)
    {
        printf("등록된 물건이 없습니다.");
        return; 
    }

    for (int i = 0; i < count; i++)
    {

    }
} 

void updated_item(Item *item, int count) // 수정 함수
{

}

int delete_item(Item *item, int count) // 물건 삭제 함수
{

}

void save_file(Item *item, int count, char filename[100]) // 파일 저장 함수
{

}

int load_file(Item *item, char filename[100]) // 파일에서 읽어오는 함수
{

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