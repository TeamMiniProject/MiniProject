typedef struct
{   
    int Number; // 물품의 번호
    char item_Name[100]; //물품의 이름
    int item_Count; //물품의 수량
    int Price;  // 개당 가격 
    char is_pointsave; //포인트 적립 유무
} Item;

int menu(); // 메뉴

int add_item(Item *item, int count); // 물건 추가 함수

void print_list(Item *item, int count); // 조회 함수

void updated_item(Item *item, int count); // 수정 함수

int delete_item(Item *item, int count); // 물건 삭제 함수

void save_file(Item *item, int count, char filename[100]); // 파일 저장 함수

int load_file(Item *item, char filename[100]); // 파일에서 읽어오는 함수

void input_money(Item *item, int count); // 현금을 자판기에 투입하는 함수

void buy_item(Item *item, int count); // 물건을 구매하는 함수

void math_reward(Item *item, int count); // 포인트 계산 함수

void check_money(Item *item, int count); // 투입된 금액을 확인하는 함수

void check_point(Item *item, int count); // 현재 보유한 포인트 잔액 확인 기능

void exchange_money(Item *item, int count); // 거스름돈 함수