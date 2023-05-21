
#include "vending.h"

int menu()
{
    int menuNumber;
    
    printf("\n***** ?��?��?�� 메뉴 *****\n");
    printf("1. 물건 추�??\n");
    printf("2. 물건 조회\n");
    printf("3. ?��?��\n");
    printf("4. 물건 ?��?��\n");
    printf("5. ?��?��????��\n");
    printf("6. ?���? ?��?��\n");
    printf("7. 물건 구입\n");
    printf("8. ?��?��?�� 금액 ?��?��\n");
    printf("9. 보유?�� ?��?��?�� ?��?�� ?��?��\n");
    printf("0. 종료\n\n");
    printf("=> ?��?��?�� 메뉴?��? ");
    scanf("%d", &menu);
    
    return  menu;
} // 메뉴


int add_item(Item *item, int count) // ���� �߰� �Լ�
{
    printf("물건?�� ?���??");
    scanf("%s", item[count].item_Name);

    printf("?�� 물건?�� 개당 �?격�???");
    scanf("%d", &item[count].price);

    printf("�� ������ ������? ");
    scanf("%d", &item[count].item_Count);

    count++;
    printf("\n������ �߰��Ǿ����ϴ�.\n");

    return count;
} 

void print_list(Item *item, int count) // ��ȸ�Լ�
{
    if (count == 0)
    {
        printf("��ϵ� ������ �����ϴ�.");
        return; 
    }

    printf("***** 물건 목록 *****\n");

    for (int i = 0; i < count; i++)
    {
        printf("���� �̸�: %s\n", item[i].item_Name);
        printf("���� ����: %d\n", item[i].price);
        printf("���� ����: %d\n", item[i].item_Count);
        printf("--------------------\n");
    }
} 

void updated_item(Item *item, int count) // ���� �Լ�
{
    char name[100];
    char Newname[100];
    int updatedPrice;

    if (count == 0)
    {
        printf("��ϵ� ������ �����ϴ�.");
        return; 
    }

    printf("?��?��?�� 물건?�� ?���?: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(item[i].item_Name, name) == 0)
        {
            printf("���ο� �̸�: ");
            scanf("%s", Newname);
            
            strcpy(item[i].item_Name, Newname); // ���ο� �̸����� �����ϱ�

            printf("���ο� ����: ");
            scanf("%d", &updatedPrice);

            item[i].price = updatedPrice; // ���ο� �������� �����ϱ�

            printf("물건 ?��보�?? ?��?��?��?��?��?��?��.\n");
            return;
        }
    }

    printf("?��?��?��?�� ?��름의 물건?�� ?��?��?��?��.\n");

}

int delete_item(Item *item, int count) // ���� ���� �Լ�
{
   if (count == 0)
    {
        printf("?��록된 물건?�� ?��?��?��?��.");
        return count; 
    }

    int is_number;

    updated_item(item, count);

    printf("������ ������ ��ȣ�� �Է��ϼ��� ");

    while (1)
    {
        for (int i = 0; i < count; i++)
        {
            if (item[i].Number == is_number)
                is_number = i; // ������ ���� ��ȣ ã��
        }
        if (is_number == 0)
            printf("��ȣ�� �� �� �Է��߽��ϴ�. �ٽ� �Է��ϼ���. \n");

        else
            break;
    }

    for (int i = is_number; i < count - 1; i++)
        item[i] = item[i + 1]; 

    count--;

    printf("���� ������ �����Ǿ����ϴ�.\n");

    return count;
}

void save_file(Item *item, int count, char filename[100]) // ���� ���� �Լ�
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d", item[i].Number); // ��ǰ�� ���ڸ� ���Ͽ� ����

        fprintf(file, "%s\n", item[i].item_Name); // ��ǰ�� �̸��� ���Ͽ� ����

        fprintf(file, "%d ", item[i].price); // ��ǰ�� ������ ���Ͽ� ����
    }

    fclose(file);

    printf("������ ����Ǿ����ϴ�.\n");
}

int load_file(Item *item, char filename[100]) // ���Ͽ��� �о���� �Լ�
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf(" ?��?��?�� 존재?���? ?��?��?��?��. ?��?���? ?��?���? 만들겠습?��?��.\n");
        return 0;
    }

    int count = -1;
    int a = 0;

    for (int i = 0; i < 100; i++)
    {
        if (feof(file))
            break;

        fscanf(file, "%d", &item[i].Number); // 

        fscanf(file, " %s", item[i].item_Name); 

        fscanf(file, "%d", &item[i].price);

        count++;
    }

    fclose(file);

    printf("���� �ҷ����� �����Ͽ����ϴ�.\n");

    return count;
}

void input_money(Cash cash) // ������ ���Ǳ⿡ �����ϴ� �Լ�
{
    printf("���Ǳ⿡ ������ ���� �ݾ��� ���Դϱ�? ");
    scanf("%d", &cash.input_cash);
}

void buy_item(Item *item, Cash cash, int count) // ������ �����ϴ� �Լ�
{
    if (count == 0) {
        printf("��ϵ� ������ �����ϴ�.\n");
        return;
    }

    int money = 0;
    
    print_list(item, count);

    char buyitem_name[100];
    int quantity;
    char point_check;

    printf("������ ������ �̸��� �Է��ϼ���: ");
    scanf("%s", buyitem_name);

    printf("������ ������ ������ �Է��ϼ���: ");
    scanf("%d", &quantity);

    printf("����Ʈ ������ �Ͻðڽ��ϱ�? ");
    scanf("%s", point_check);

    int buy_total_price = 0;
    int found = 0;

    for (int i = 0; i < count; i++) 
    {
        if (strcmp(item[i].item_Name, buyitem_name) == 0) 
        {
            buy_total_price = item[i].price * quantity;

            strcpy(item[i].is_pointsave, &point_check);

            if (cash.input_cash >= buy_total_price) 
            {
                printf("%s %d���� �����մϴ�.\n", item[i].item_Name, quantity);
                cash.input_cash -= buy_total_price;

                if (strcmp(item[i].is_pointsave, "Y") == 0)
                {
                    printf("?��?��?�� ?��립합?��?��.\n");
                    math_reward(cash, count);  // 메스 리워?�� ?��?�� ?��?�� �? 구현?���?
                }

                else 
                    printf("����Ʈ ������ ���� �ʽ��ϴ�.\n");

                printf("�� ������ ������ ������ %d�Դϴ�.\n\n", buy_total_price);
                printf("���Ű� �Ϸ�Ǿ����ϴ�.\n");
                found = 1;
                break;
            } 
            
            else 
            {
                printf("�ݾ��� �����Ͽ� ������ �� �����ϴ�.\n");
                break;
            }
        }
    }

    if (!found) 
    {
        printf("�ش��ϴ� �̸��� ������ �����ϴ�.\n");
    }

    printf("���� ���Ǳ⿡ ���Ե� ���� �ݾ� : %d\n", cash.input_cash);

//���� ���ִ��� ������ �� //check_money(Item *item, int count) // ���Ե� �ݾ��� Ȯ���ϴ� �Լ�
//�޴����� �����ְ�        // print_list �Լ� ���
//���� ��ǰ�� �̸��� ������ ����  // �Լ� ��� X �׳� �̸��� ���� �Է� �ϱ�
//����Ʈ ���� ���� �� Buy         //����ü ����� ����  char is_pointsave; ����Ʈ ���� ����
//�� ������ ��ǰ�� ���� �����ֱ�
//���� �� �����ֱ� (�Ž�����) //exchange_money(Item *item, int count) // �Ž����� �Լ�
}

void math_reward(Cash cash ,int buy_money) // ����Ʈ ��� �Լ� ->> ������ �ݾ��� 5%������ �����ϴ� ������ ����
{
    cash.reward_point = buy_money * 0.03;
}

void check_money(Cash cash) // ���Ե� �ݾ��� Ȯ���ϴ� �Լ�
{
    printf("���� ���Ǳ⿡ ���Ե� �ݾ� : %d\n", cash.input_cash);
}

void check_point(Cash cash) // ���� ������ ����Ʈ �ܾ� Ȯ�� ���
{
    printf("������� ������ ����Ʈ �ݾ� : %d\n", cash.reward_point);
}