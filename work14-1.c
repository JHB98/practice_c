#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#pragma warning (disable:4996);
typedef struct list   // �л��̸��� �õ�Ƚ��, ������ ���� ����ü
{
	char name[20]; // �迭 ���κ�
	int num;
	int score;
}list;
void game(list* lists, int peopleNum); // game ����
void printOutPut(list *lists, int peopleNum); // ������
int answer; // �������� ���κ�
int main()
{
	int peopleNum;
	list *lists; // ������ ���κ�
	srand((unsigned int)time(NULL));
	answer = rand() % 301;

	printf("������ �ο��� �Է��ϼ��� : ");
	scanf("%d", &peopleNum);
	lists = (list*)malloc(sizeof(list)*peopleNum); // ������ �ο��� ��ŭ ����ü �����Ҵ�
	for (int i = 0;i < peopleNum;i++)
	{
		printf("%d��° ����� �̸��� �Է��ϼ��� : ", i + 1);
		scanf("%s", lists[i].name);
	}

	game(lists, peopleNum); // �Լ���� �κ�
	printOutPut(lists, peopleNum); //�Լ����κ�

	return 0;
}
void game(list* lists, int peopleNum)
{
	int count = 1; // �õ�Ƚ�� ǥ��
	int answerGive; // �õ��� ����
	int score = 100;
	int range = 1; // ���� ���������� �������ֱ� ���� ����
	int max = 300, min = 0;//������ ���̱� ���� �ִ밪 �ּҰ�
	int num; //��������
	for (int i = 0;i < peopleNum;i++)
	{
		answerGive = rand() % 301; // 0~300 ���̿��� �õ��� ������ ����
		while (1)
		{
			if (count == 8) // count �� 8�̸� 7�� �õ������� ������ ���ߴٴ� �̾߱��̹Ƿ� ���� 0 �� �����ϰ� while �� Ż��
			{
				score = 0;
				break;
			}

			if (range == 1) // 1��° �õ��Ҷ� ��������
			{
				num = 20;
			}
			else if (range == 2) // 2��° �õ��Ҷ� ��������
			{
				num = 15;
			}
			else if (range == 3) // 3��° �õ��Ҷ� ��������
			{
				num = 10;
			}
			else // 4,5,6,7��° �õ��Ҷ� ��������
			{
				num = 5;
			}

			if ((answerGive + num) < answer) // ������ ���������� �ִ밪���� Ŭ ��
			{
				count++; // �ٽ� �õ��ؾ� �ϹǷ� �õ�Ƚ�� +1
				score -= 10; // �õ����� �Ҷ� ���� -10 ��
				min = answerGive + num;
				answerGive = (rand() % (max - min)) + (min + 1); // ������ ���� ������ ***(���� �õ��ߴ� ������ �������� �ִ밪 +1) ~ max *** ���� ���� �� �� �õ�
				if (range != 4) // 4,5,6,7 ��° �õ����� ���������� �Ȱ����Ƿ� range�� +1 ������ �ʰ� 1,2,3 ��° �õ��϶��� +1 ���ش�
				{
					range++;
				}
			}
			else if ((answerGive - num) > answer) // ������ ���������� �ּҰ����� ���� ��
			{
				count++;
				score -= 10;
				max = answerGive - num;
				answerGive = (rand() % (max- min)) + min;// ������ ���� ������ *** min~(���� �õ��ߴ� ������ �������� �ּҰ�-1) *** ���� ���� �� ��õ�
				if (range != 4)
				{
					range++;
				}
			}
			else //((answerGive - num <= answer) && (answer <= answerGive + num)) ��, ������ ��
			{
				break;
			}
		}

		lists[i].num = count; //�õ� Ƚ���� i��° �л��� �õ�Ƚ���� �־��ش�. (�迭 �� ������ ��� �κ�)
		lists[i].score = score; // ���� (�迭 �� ������ ��� �κ�)
		count = 1; //for���� ���鼭 ���� �л��� �����ؾ� �ϹǷ�
		range = 1; // count�� range
		score = 100; // ���� ���� �ʱⰪ���� �������ش�.
	}
}

void printOutPut(list *lists, int peopleNum)
{
	printf("| �̸� | Ƚ��| ���� |\n");
	for (int i = 0;i < peopleNum;i++)
	{
		printf("-------------------------\n");
		printf("  %s    %d    %d�� \n", lists[i].name, lists[i].num, lists[i].score); //�迭�� ������ ��� �κ�
	}
}