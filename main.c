#include "vending.h"

int main()
{
    Item item[100];
    Cash cash;
    char filename[100];
    int menuNumber;
    int count = 0;

    printf("파일 명을 입력하세요 : ");
    scanf("%s", filename);

    count = load_file(item, count, filename);

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
            updated_item(item, count); // 물건 이름, 가격 및 수량 수정 
            break;

        case 4:
            count = delete_item(item, count); // 물건 삭제
            break;

        case 5:
            save_file(item, count, filename); // 파일 저장 함수
            break;

        case 6:
            input_money(&cash); // 자판기에 현금을 투입
            break;

        case 7:
            buy_item(item, &cash, count); // 메뉴 리스트를 보고 물건 구입
            break;

        case 8:
            check_money(&cash); //자판기에 투입된 금액 확인
            break;

        case 9:
            check_point(&cash); // 물건을 사고 적립한 포인트 확인 
            break;

        case 0:
            printf("종료하겠습니다.\n"); // 종료
            return 0;

        default:
            printf("없는 메뉴 번호입니다.\n");
            printf("다시 입력해주세요.\n");
        }
    }
    return 0;
} //test1