#include "vending.h"

int menu() // �޴�
{
    int menuNumber;
    
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
    printf("\n");
    
    return  menuNumber;
} 


int add_item(Item *item, int count) // ���� �߰� �Լ�
{
    int number = 0;

    printf("������ �̸�?: ");
    scanf("%s", &item[count].item_Name);

    printf("�� ������ ���� ������?: ");
    scanf("%d", &item[count].price);

    printf("�� ������ ������? ");
    scanf("%d", &item[count].item_Count);

    item[count].Number = count + 1; // ���� ��ȣ ������Ʈ

    printf("\n������ �߰��Ǿ����ϴ�.\n");

    return count+1;
} 

void print_list(Item *item, int count) // ��ϵ� ���� ���� ��ȸ�Լ�
{
    if (count == 0)
    {
        printf("��ϵ� ������ �����ϴ�.");
        return; 
    }

    printf("��---- ���� ��� ----��\n");

    for (int i = 0; i < count; i++)
    {
        printf("������ ��ȣ: %d\n", item[i].Number);
        printf("���� �̸�: %s\n", item[i].item_Name);
        printf("���� ����: %d\n", item[i].price);
        printf("���� ����: %d\n", item[i].item_Count);
        printf("--------------------\n");
    }
} 

void updated_item(Item *item, int count) // ���� �̸�, ���� �� ���� ���� �Լ�
{
    char name[100];
    char Newname[100];
    int updatedPrice;
    int countNumber;

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

            printf("���ο� ���� ");
            scanf("%d", &countNumber);
            item[i].item_Count = countNumber; // ���ο� �������� �����ϱ�

            printf("\n���� ������ �����Ǿ����ϴ�.\n");
            return;
        }
    }

    printf("\n�ش��ϴ� �̸��� ������ �����ϴ�.\n");

}

int delete_item(Item *item, int count) // ���� ���� �Լ�
{
   if (count == 0)
    {
        printf("������ ������ �����ϴ�.");
        return count; 
    }

    char name[100];
    int delete_number = -1;

    printf("������ ������ �̸�: ");
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
            printf("\n�ش��ϴ� �̸��� ������ �����ϴ�.\n");
            break;
        }

        else
        {
            for (int i = delete_number; i < count - 1; i++)
            {
                item[i] = item[i + 1];
                item[i].Number = i + 1; // ���ο� ���� ��ȣ �������ֱ� (�����ϸ� ���� ��ȣ�� �޶���)
            }

            count--;
            printf("�ش� ������ �����Ǿ����ϴ�.\n");
            break;
        }
    }
    return count;
}

void save_file(Item *item, int count, char filename[100]) // ���� ���� �Լ�
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("������ �����ϴ�.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%d", item[i].Number); // ��ǰ�� ���ڸ� ���Ͽ� ����

        fprintf(file, "%s\n", item[i].item_Name); // ��ǰ�� �̸��� ���Ͽ� ����

        fprintf(file, "%d ", item[i].price); // ��ǰ�� ������ ���Ͽ� ����

        fprintf(file, "%d ", item[i].item_Count); // ��ǰ�� ������ ���Ͽ� ����
    }

    fclose(file);

    printf("���� ���� �Ϸ�. \n");
}

int load_file(Item *item, int count, char filename[100]) // ���Ͽ��� �о���� �Լ�
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("[���] ������ �������� �ʽ��ϴ�.\n");
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

    printf("���� �ҷ����� �����Ͽ����ϴ�.\n");

    return count;
}

void input_money(Cash *cash) // ������ ���Ǳ⿡ �����ϴ� �Լ�
{
    printf("���Ǳ⿡ ������ ���� �ݾ��� ���Դϱ�? ");
    scanf("%d", &cash->input_cash);

    printf("\n�ݾ��� ���� �Ϸ�Ǿ����ϴ�.\n");
}

void buy_item(Item *item, Cash *cash, int count) // ������ �����ϴ� �Լ�
{
    if (count == 0) {
        printf("��ϵ� ������ �����ϴ�.\n");
        return;
    }

    int money = 0;
    
    print_list(item, count);

    char buyitem_name[100];
    int quantity;
    char point_check[2];

    printf("������ ������ �̸��� �Է��ϼ���: ");
    scanf("%s", buyitem_name);

    printf("������ ������ ������ �Է��ϼ���: ");
    scanf("%d", &quantity);

    printf("����Ʈ ������ �Ͻðڽ��ϱ�? (Y/N) : ");
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
                printf("%s %d���� �����մϴ�.\n\n", item[i].item_Name, quantity);
                cash->input_cash -= buy_total_price;
                item[i].item_Count -= quantity;

                if (strcmp(item[i].is_pointsave, "Y") == 0)
                    math_reward(cash, buy_total_price);  

                else 
                    printf("����Ʈ ������ ���� �ʽ��ϴ�.\n");

                printf("�� ������ ������ ������ %d�Դϴ�.\n\n", buy_total_price);
                printf("���Ű� �Ϸ�Ǿ����ϴ�.\n\n");
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

    printf("���� ���Ǳ⿡ ���Ե� ���� �ݾ� : %d\n", cash->input_cash);

}

void math_reward(Cash *cash ,int buy_money) // ����Ʈ ��� �Լ� ->> ������ �ݾ��� 5%������ �����ϴ� ������ ����
{
    cash->reward_point += buy_money * 0.03;
}

void check_money(Cash *cash) // ���Ǳ⿡ ���Ե� �ݾ��� Ȯ���ϴ� �Լ�
{
    printf("���� ���Ǳ⿡ ���Ե� �ݾ� : %d\n", cash->input_cash);
}

void check_point(Cash *cash) // ���� ������ �����ϸ� ������ ����Ʈ �ܾ� Ȯ�� ���
{
    printf("������� ������ ����Ʈ �ݾ� : %d\n", cash->reward_point);
}