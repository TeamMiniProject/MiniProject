#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{   
    int Number; // ��ǰ�� ��ȣ
    char item_Name[100]; //��ǰ�� �̸�
    int item_Count; //��ǰ�� ����
    int price;  // ���� ���� 
    char is_pointsave[2]; //����Ʈ ���� ����
} Item;

typedef struct
{
    int input_cash; //?��?��기에 ?��?���? ?���?
    int reward_point; // 물건?�� ?���? ?��립한 ?��?��?��
} Cash;

int menu(); // �޴�

int add_item(Item *item, int count); // ���� �߰� �Լ�

void print_list(Item *item, int count); // 조회 ?��?��

void updated_item(Item *item, int count); // ?��?�� ?��?��

int delete_item(Item *item, int count); // 물건 ?��?�� ?��?��

void save_file(Item *item, int count, char filename[100]); // ���� ���� �Լ�

int load_file(Item *item, int count, char filename[100]); // ���Ͽ��� �о���� �Լ�

void input_money(Cash *cash); // ������ ���Ǳ⿡ �����ϴ� �Լ�

void buy_item(Item *item, Cash *cash, int count); // 물건?�� 구매?��?�� ?��?��

void math_reward(Cash *cash ,int buy_money); // ����Ʈ ��� �Լ�

void check_money(Cash *cash); // ?��?��?�� 금액?�� ?��?��?��?�� ?��?��

void check_point(Cash *cash); // ���� ������ ����Ʈ �ܾ� Ȯ�� ���