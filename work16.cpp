#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
int main()
{
	char word[100] = "\0";
	FILE *fp;
	fp = fopen("12345678.txt", "a+");//12345678 을 학번으로 바꾸시고 실행해주세요!
	
	while (1)
	{
		scanf("%s", word);//문자열을 입력받아 word에 저장
		if (!strcmp(word ,"$"))//두 문자열이 같으면 0
		{
			break;
		}
		fputs(word, fp); //파일포인터 fp를 통해 파일포인터에 작성
		fputs("\n", fp);//fputs는 개행문자가 자동으로 추가 안되므로 개행문자 추가
	}

	fseek(fp, 0, SEEK_SET);//파일을 처음부터 읽기위해 파일포인터를 파일의 시작으로 이동

	while (1)
	{
		fgets(word, sizeof(word), fp);//한줄씩 읽어옴
		if (feof(fp))//읽어온게 EOF 인지 확인
		{
			break;
		}
		printf("%s", word);//EOF 가 아니면 출력
	}
	printf("Bye\n");
	fclose(fp);
	return 0;

}