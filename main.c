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
            updated_item(item, count); // 물건 이름 및 가격 수정 
            break;

        case 4:
            count = delete_item(item, count); // 물건 삭제
            break;

        case 5:
            save_file(item, count, filename); // 나중에 파일 네임 함수 바꾸기
            break;

        case 6:
            input_money(&cash); // 돈 투입 
            break;

        case 7:
            buy_item(item, &cash, count); // 물건 구입과 동시에 reward point 정립하기 
            break;

        case 8:
            check_money(&cash); //투입금액 확인
            break;

        case 9:
            check_point(&cash); // 적립된 포인트 확인 
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

