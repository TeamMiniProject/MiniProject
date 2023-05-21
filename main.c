#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vending.h"

int main()
{
    Item item[100];
    Cash cash;
    char name[100];
    int menuNumber;
    int count = 0;

    printf("\n************ ���ϴ� �޴� ************\n");
    printf(" \t 1. ���� �߰�\n");
    printf(" \t 2. ���� ��ȸ\n");
    printf(" \t 3. ����\n");
    printf(" \t 4. ���� ����\n");
    printf(" \t 5. ��������\n");
    printf(" \t 6. ���� ����\n");
    printf(" \t 7. ���� ����\n");
    printf(" \t 8. ���Ե� �ݾ� Ȯ��\n");
    printf(" \t 9. ������ ����Ʈ �ܾ� Ȯ��\n");
    printf(" \t 0. ����");
    printf(" \n*************************************\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menuNumber);

    count = load_file(item, name);

    while (1)
    {
        menuNumber = menu();
        switch (menuNumber)
        {
        case 1:
            count = add_item(item, count); // ���� �߰��ϴ� �޴� 
            break;
        case 2:
            print_list(item, count); // ���� ��ȸ�ϴ� �޴� 
            break;
        case 3:
            updated_item(item, count); // ���� �̸� �� ���� ���� 
            break;
        case 4:
            count = delete_item(item, count); // ���� ����
            break;
        case 5:
            save_file(item, count, name); // ���߿� ���� ���� �Լ� �ٲٱ�
            break;
        case 6:
            input_money(cash); // �� ���� 
            break;
        case 7:
            buy_item(item, cash, count); // ���� ���԰� ���ÿ� reward point �����ϱ� 
            break;
        case 8:
            check_money(cash); //���Աݾ� Ȯ��
            break;
        case 9:
            check_point(cash); // ������ ����Ʈ Ȯ�� 
            break;
        case 0:
            printf("�����ϰڽ��ϴ�.\n");
            return 0;
        default:
            printf("���� �޴� ��ȣ�Դϴ�.\n");
            printf("�ٽ� �Է����ּ���.\n");
        }
    }

    return 0;
}

