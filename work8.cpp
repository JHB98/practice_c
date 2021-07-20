#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
void merge();
void separate();
int main()
{
	int choice = 0;
	printf("메뉴\n");
	printf("1 : E-mail --> 각 요소로 분리하기\n");
	printf("2 : 각 요소 --> E-mail 만들기\n");
	printf("선택하세요 : ");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1: separate();
		break;
	case 2: merge();
		break;
	}

	return 0;
}

void separate()
{
	char e_mail[100] = { " " };
	char* pE_mail;
	char* ref;

	printf("E-mail을 입력하시오 : ");
	scanf("%s", e_mail);
	printf("===============================================\n");
	printf("순서대로 [이름] [시스템] [도메인] [기관] [국가]\n");
	pE_mail = strlwr(e_mail);
	ref = strstr(pE_mail, "@");
	strncpy(ref, "\n", 1);

	ref = strstr(pE_mail, ".");
	strncpy(ref, "\n", 1);

	ref = strstr(pE_mail, ".");
	strncpy(ref, "\n", 1);

	ref = strstr(pE_mail, ".");
	if (ref == NULL)
	{
		printf("%s\n", pE_mail);
		printf("usa\n");
	}
	else
	{
		strncpy(ref, "\n", 1);
		printf("%s\n", pE_mail);
	}
}

void merge()
{
	char* name;
	char* system;
	char* domain;
	char* org;
	char* country;
	char refName[100] = { " " };
	char refSystem[100] = { " " };
	char refDomain[100] = { " " };
	char refOrg[100] = { " " };
	char refCountry[100] = { " " };

	printf("입력 :[이름] [시스템] [도메인] [기관] [국가]\n");
	printf("(E-mail에 국가 이름 없을 경우 'usa' 입력)\n");
	
	scanf("%s", refName);
	scanf("%s", refSystem);
	scanf("%s", refDomain);
	scanf("%s", refOrg);
	scanf("%s", refCountry);

	name = strlwr(refName);
	system = strlwr(refSystem);
	domain = strlwr(refDomain);
	org = strlwr(refOrg);
	country = strlwr(refCountry);
	
	strcat(name, "@");
	strcat(name, system);
	strcat(name, ".");
	strcat(name, domain);
	strcat(name, ".");
	strcat(name, org);
	if (strcmp(country, "usa") != 0)
	{
		strcat(name, ".");
		strcat(name, country);
	}

	printf("E-mail : %s\n", name);

}