#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{   
    int Number; // 물품의 번호
    char item_Name[100]; //물품의 이름
    int item_Count; //물품의 수량
    int price;  // 개당 가격 
    char is_pointsave[2]; //포인트 적립 유무
} Item;

typedef struct
{
    int input_cash; //자판기에 들어간 현금
    int reward_point; // 물건을 사고 적립한 포인트
} Cash;

int menu(); // 메뉴

int add_item(Item *item, int count); // 물건 추가 함수

void print_list(Item *item, int count); // 물건 조회하는 메뉴

void updated_item(Item *item, int count); // 물건 이름, 가격 및 수량 수정 

int delete_item(Item *item, int count); // 물건 삭제

void save_file(Item *item, int count, char filename[100]); // 파일 저장 함수

int load_file(Item *item, int count, char filename[100]); // 파일에서 읽어오는 함수

void input_money(Cash *cash); // 현금을 자판기에 투입하는 함수

void buy_item(Item *item, Cash *cash, int count); // 메뉴 리스트를 보고 물건을 구매하는 함수

void math_reward(Cash *cash ,int buy_money); // 포인트 계산 함수

void check_money(Cash *cash); // 자판기에 투입된 금액을 확인하는 함수

void check_point(Cash *cash); // 현재 보유한 포인트 잔액 확인 기능