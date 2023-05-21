
#include "vending.h"

int menu()
{
    int menuNumber;
    
    printf("\n***** ���ϴ� �޴� *****\n");
    printf("1. ���� �߰�\n");
    printf("2. ���� ��ȸ\n");
    printf("3. ����\n");
    printf("4. ���� ����\n");
    printf("5. ��������\n");
    printf("6. ���� ����\n");
    printf("7. ���� ����\n");
    printf("8. ���Ե� �ݾ� Ȯ��\n");
    printf("9. ������ ����Ʈ �ܾ� Ȯ��\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menuNumber);
    
    return  menuNumber;
} // �޴�


int add_item(Item *item, int count) // ���� �߰� �Լ�
{
    printf("������ �̸�? ");
    scanf("%s", item[count].item_Name);

    printf("�� ������ ���� ������? ");
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

    printf("***** ���� ��� *****\n");

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

    printf("������ ������ �̸�: ");
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

            printf("���� ������ �����Ǿ����ϴ�.\n");
            return;
        }
    }

    printf("�ش��ϴ� �̸��� ������ �����ϴ�.\n");

}

int delete_item(Item *item, int count) // ���� ���� �Լ�
{
   if (count == 0)
    {
        printf("��ϵ� ������ �����ϴ�.");
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
        printf(" ������ �������� �ʽ��ϴ�. �ӽ÷� �ϳ��� ����ڽ��ϴ�.\n");
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
                    printf("����Ʈ �����մϴ�.\n");
                    math_reward(cash, count);  // �޽� ������ �Լ� ���� �� �����ϱ�
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