#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vending.h"

int main()
{
    Item item[100];
    char name[100];
    int menuNumber;
    int count = 0;

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

    count = loadFromFile(item, name);

    while (1)
    {
        menuNumber = menu();
        switch (menuNumber)
        {
        case 1:
            count = add_item(item, count); // 물건 추가하는 메뉴 
            break;
        case 2:
            print_list(item, count); // 물건 조회하는 메뉴 
            break;
        case 3:
            updated_item(item, count); // 물건 이름 및 가격 수정 
            break;
        case 4:
            count = delete_item(item, count); // 물건 삭제
            break;
        case 5:
            save_file(item, count, name); // 나중에 파일 네임 함수 바꾸기
            break;
        case 6:
            input_money(item, count); // 돈 투입 
            break;
        case 7:
            buy_item(item, count); // 물건 구입과 동시에 reward point 정립하기 
            break;
        case 8:
            check_money(item, count); //투입금액 확인
            break;
        case 9:
            check_point(item, count); // 적립된 포인트 확인 
            break;
        case 0:
            printf("종료하겠습니다.\n");
            return 0;
        default:
            printf("없는 메뉴 번호입니다.\n");
            printf("다시 입력해주세요.\n");
        }
    }

    return 0;
}

