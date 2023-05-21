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
    int input_cash; //?옄?뙋湲곗뿉 ?뱾?뼱媛? ?쁽湲?
    int reward_point; // 臾쇨굔?쓣 ?궗怨? ?쟻由쏀븳 ?룷?씤?듃
} Cash;

int menu(); // 메뉴

int add_item(Item *item, int count); // 물건 추가 함수

void print_list(Item *item, int count); // 議고쉶 ?븿?닔

void updated_item(Item *item, int count); // ?닔?젙 ?븿?닔

int delete_item(Item *item, int count); // 臾쇨굔 ?궘?젣 ?븿?닔

void save_file(Item *item, int count, char filename[100]); // 파일 저장 함수

int load_file(Item *item, int count, char filename[100]); // 파일에서 읽어오는 함수

void input_money(Cash *cash); // 현금을 자판기에 투입하는 함수

void buy_item(Item *item, Cash *cash, int count); // 臾쇨굔?쓣 援щℓ?븯?뒗 ?븿?닔

void math_reward(Cash *cash ,int buy_money); // 포인트 계산 함수

void check_money(Cash *cash); // ?닾?엯?맂 湲덉븸?쓣 ?솗?씤?븯?뒗 ?븿?닔

void check_point(Cash *cash); // 현재 보유한 포인트 잔액 확인 기능