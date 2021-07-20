#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#pragma warning (disable:4996);
typedef struct list   // 학생이름과 시도횟수, 점수를 담을 구조체
{
	char name[20]; // 배열 사용부분
	int num;
	int score;
}list;
void game(list* lists, int peopleNum); // game 진행
void printOutPut(list *lists, int peopleNum); // 결과출력
int answer; // 전역변수 사용부분
int main()
{
	int peopleNum;
	list *lists; // 포인터 사용부분
	srand((unsigned int)time(NULL));
	answer = rand() % 301;

	printf("게임할 인원을 입력하세요 : ");
	scanf("%d", &peopleNum);
	lists = (list*)malloc(sizeof(list)*peopleNum); // 게임할 인원수 만큼 구조체 동적할당
	for (int i = 0;i < peopleNum;i++)
	{
		printf("%d번째 사람의 이름을 입력하세요 : ", i + 1);
		scanf("%s", lists[i].name);
	}

	game(lists, peopleNum); // 함수사용 부분
	printOutPut(lists, peopleNum); //함수사용부분

	return 0;
}
void game(list* lists, int peopleNum)
{
	int count = 1; // 시도횟수 표시
	int answerGive; // 시도한 정답
	int score = 100;
	int range = 1; // 정답 오차범위를 결정해주기 위한 수단
	int max = 300, min = 0;//범위를 줄이기 위한 최대값 최소값
	int num; //오차범위
	for (int i = 0;i < peopleNum;i++)
	{
		answerGive = rand() % 301; // 0~300 사이에서 시도할 정답을 추출
		while (1)
		{
			if (count == 8) // count 가 8이면 7번 시도했지만 맞추지 못했다는 이야기이므로 점수 0 점 세팅하고 while 문 탈출
			{
				score = 0;
				break;
			}

			if (range == 1) // 1번째 시도할때 오차범위
			{
				num = 20;
			}
			else if (range == 2) // 2번째 시도할때 오차범위
			{
				num = 15;
			}
			else if (range == 3) // 3번째 시도할때 오차범위
			{
				num = 10;
			}
			else // 4,5,6,7번째 시도할때 오차범위
			{
				num = 5;
			}

			if ((answerGive + num) < answer) // 정답이 오차범위의 최대값보다 클 때
			{
				count++; // 다시 시도해야 하므로 시도횟수 +1
				score -= 10; // 시도실패 할때 마다 -10 점
				min = answerGive + num;
				answerGive = (rand() % (max - min)) + (min + 1); // 제시할 정답 범위를 ***(원래 시도했던 숫자의 오차범위 최대값 +1) ~ max *** 으로 설정 후 재 시도
				if (range != 4) // 4,5,6,7 번째 시도에는 오차범위가 똑같으므로 range를 +1 해주지 않고 1,2,3 번째 시도일때만 +1 해준다
				{
					range++;
				}
			}
			else if ((answerGive - num) > answer) // 정답이 오차범위의 최소값보다 작을 때
			{
				count++;
				score -= 10;
				max = answerGive - num;
				answerGive = (rand() % (max- min)) + min;// 제시할 정답 범위를 *** min~(원래 시도했던 숫자의 오차범위 최소값-1) *** 으로 설정 후 재시도
				if (range != 4)
				{
					range++;
				}
			}
			else //((answerGive - num <= answer) && (answer <= answerGive + num)) 즉, 정답일 때
			{
				break;
			}
		}

		lists[i].num = count; //시도 횟수를 i번째 학생의 시도횟수에 넣어준다. (배열 및 포인터 사용 부분)
		lists[i].score = score; // 점수 (배열 및 포인터 사용 부분)
		count = 1; //for문이 돌면서 다음 학생이 게임해야 하므로
		range = 1; // count와 range
		score = 100; // 점수 까지 초기값으로 설정해준다.
	}
}

void printOutPut(list *lists, int peopleNum)
{
	printf("| 이름 | 횟수| 점수 |\n");
	for (int i = 0;i < peopleNum;i++)
	{
		printf("-------------------------\n");
		printf("  %s    %d    %d점 \n", lists[i].name, lists[i].num, lists[i].score); //배열및 포인터 사용 부분
	}
}