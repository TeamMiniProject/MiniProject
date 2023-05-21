#include "vending.h"

int menu() // 메뉴
{
    int menuNumber;
    
    printf("\n************ 원하는 메뉴 ************\n");
    printf(" \t 1. 물건 추가\n");
    printf(" \t 2. 물건 조회\n");
    printf(" \t 3. 수정\n");
    printf(" \t 4. 물건 삭제\n");
    printf(" \t 5. 파일저장\n");
    printf(" \t 6. 현금 투입\n");
    printf(" \t 7. 물건 구입\n");
    printf(" \t 8. 투입된 금액 확인\n");
    printf(" \t 9. 보유한 포인트 잔액 확인\n");
    printf(" \t 0. 종료");
    printf(" \n*************************************\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menuNumber);
    printf("\n");
    
    return  menuNumber;
} 


int add_item(Item *item, int count) // 물건 추가 함수
{
    int number = 0;

    printf("물건의 이름?: ");
    scanf("%s", &item[count].item_Name);

    printf("이 물건의 개당 가격은?: ");
    scanf("%d", &item[count].price);

    printf("이 물건의 수량은? ");
    scanf("%d", &item[count].item_Count);

    item[count].Number = count + 1; // 물건 번호 업데이트

    printf("\n물건이 추가되었습니다.\n");

    return count+1;
} 

void print_list(Item *item, int count) // 등록된 물건 내역 조회함수
{
    if (count == 0)
    {
        printf("등록된 물건이 없습니다.");
        return; 
    }

    printf("★---- 물건 목록 ----★\n");

    for (int i = 0; i < count; i++)
    {
        printf("물건의 번호: %d\n", item[i].Number);
        printf("물건 이름: %s\n", item[i].item_Name);
        printf("물건 가격: %d\n", item[i].price);
        printf("물건 수량: %d\n", item[i].item_Count);
        printf("--------------------\n");
    }
} 

void updated_item(Item *item, int count) // 물건 이름, 가격 및 수량 수정 함수
{
    char name[100];
    char Newname[100];
    int updatedPrice;
    int countNumber;

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
            printf("새로운 이름: ");
            scanf("%s", Newname);
            
            strcpy(item[i].item_Name, Newname); // 새로운 이름으로 수정하기

            printf("새로운 가격: ");
            scanf("%d", &updatedPrice);

            item[i].price = updatedPrice; // 새로운 가격으로 수정하기

            printf("새로운 수량 ");
            scanf("%d", &countNumber);
            item[i].item_Count = countNumber; // 새로운 수량으로 수정하기

            printf("\n물건 정보가 수정되었습니다.\n");
            return;
        }
    }

    printf("\n해당하는 이름의 물건이 없습니다.\n");

}

int delete_item(Item *item, int count) // 물건 삭제 함수
{
   if (count == 0)
    {
        printf("삭제할 물건이 없습니다.");
        return count; 
    }

    char name[100];
    int delete_number = -1;

    printf("삭제할 물건의 이름: ");
    scanf("%s", name);
    
    while(1)
    {
        for (int i = 0; i < count; i++)
        {
            if (strcmp(item[i].item_Name, name) == 0)
            {
                delete_number = i;
                break;
            }
        }

        if (delete_number == -1)
        {
            printf("\n해당하는 이름의 물건이 없습니다.\n");
            break;
        }

        else
        {
            for (int i = delete_number; i < count - 1; i++)
            {
                item[i] = item[i + 1];
                item[i].Number = i + 1; // 새로운 물건 번호 수정해주기 (삭제하면 물건 번호가 달라짐)
            }

            count--;
            printf("해당 물건이 삭제되었습니다.\n");
            break;
        }
    }
    return count;
}

void save_file(Item *item, int count, char filename[100]) // 파일 저장 함수
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("파일이 없습니다.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d", item[i].Number); // 물품의 숫자를 파일에 저장

        fprintf(file, "%s\n", item[i].item_Name); // 물품의 이름을 파일에 저장

        fprintf(file, "%d ", item[i].price); // 물품의 가격을 파일에 저장

        fprintf(file, "%d ", item[i].item_Count); // 물품의 수량을 파일에 저장
    }

    fclose(file);

    printf("파일 저장 완료. \n");
}

int load_file(Item *item, int count, char filename[100]) // 파일에서 읽어오는 함수
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("[경고] 파일이 존재하지 않습니다.\n");
        return 0;
    }

    for (int i = 0; i < 100; i++)
    {
        if (feof(file))
            break;

        fscanf(file, "%d", &item[i].Number);

        fscanf(file, " %s", item[i].item_Name); 

        fscanf(file, "%d", &item[i].price);

        fscanf(file, "%d ", &item[i].item_Count);

        count++;
    }

    fclose(file);

    printf("파일 불러오기 성공하였습니다.\n");

    return count;
}

void input_money(Cash *cash) // 현금을 자판기에 투입하는 함수
{
    printf("자판기에 투입할 현금 금액은 얼마입니까? ");
    scanf("%d", &cash->input_cash);

    printf("\n금액이 투입 완료되었습니다.\n");
}

void buy_item(Item *item, Cash *cash, int count) // 물건을 구매하는 함수
{
    if (count == 0) {
        printf("등록된 물건이 없습니다.\n");
        return;
    }

    int money = 0;
    
    print_list(item, count);

    char buyitem_name[100];
    int quantity;
    char point_check[2];

    printf("구매할 물건의 이름을 입력하세요: ");
    scanf("%s", buyitem_name);

    printf("구매할 물건의 수량을 입력하세요: ");
    scanf("%d", &quantity);

    printf("포인트 적립을 하시겠습니까? (Y/N) : ");
    scanf("%1s", point_check);
    printf("\n");

    int buy_total_price = 0;
    int found = 0;

    for (int i = 0; i < count; i++) 
    {
        if (strcmp(item[i].item_Name, buyitem_name) == 0) 
        {
            buy_total_price = item[i].price * quantity;

            strcpy(item[i].is_pointsave, point_check);

            if (cash->input_cash >= buy_total_price) 
            {
                printf("%s %d개를 구매합니다.\n\n", item[i].item_Name, quantity);
                cash->input_cash -= buy_total_price;
                item[i].item_Count -= quantity;

                if (strcmp(item[i].is_pointsave, "Y") == 0)
                    math_reward(cash, buy_total_price);  

                else 
                    printf("포인트 적립을 하지 않습니다.\n");

                printf("총 구매한 물건의 가격은 %d입니다.\n\n", buy_total_price);
                printf("구매가 완료되었습니다.\n\n");
                found = 1;
                break;
            } 
            
            else 
            {
                printf("금액이 부족하여 구매할 수 없습니다.\n");
                break;
            }
        }
    }

    if (!found) 
    {
        printf("해당하는 이름의 물건이 없습니다.\n");
    }

    printf("현재 자판기에 투입된 남은 금액 : %d\n", cash->input_cash);

}

void math_reward(Cash *cash ,int buy_money) // 포인트 계산 함수 ->> 구입한 금액의 5%정도를 적립하는 것으로 결정
{
    cash->reward_point += buy_money * 0.03;
}

void check_money(Cash *cash) // 자판기에 투입된 금액을 확인하는 함수
{
    printf("현재 자판기에 투입된 금액 : %d\n", cash->input_cash);
}

void check_point(Cash *cash) // 현재 물건을 구매하며 보유한 포인트 잔액 확인 기능
{
    printf("현재까지 적립된 포인트 금액 : %d\n", cash->reward_point);
}