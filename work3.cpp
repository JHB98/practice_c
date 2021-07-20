#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

class ShowNum
{
private :
	int num[10];

public :
	ShowNum()
	{
		srand((unsigned int)time(NULL));
		for (int i = 0;i < 10;i++)
		{
			num[i] = rand();
		}
	}

	void PrintNum()
	{
		for (int j = 0;j < 9;j++)
		{
			cout << num[j]<<", ";
		}

		cout << num[9];
	}

	void MiniAndMax()
	{
		int Mini = num[0];
		int Max = num[0];
		for (int k = 0;k < 10;k++)
		{
			if (Mini > num[k])
			{
				Mini = num[k];
			}
			
			if (Max < num[k])
			{
				Max = num[k];
			}
		}

		cout << Mini <<", "<< Max << endl;
	}
};
class Star
{
private :
	int num[10];

public :
	Star()
	{
		for (int i = 0;i < 10;i++)
		{
			num[i] = 0;
		}
	}
	void SetNum()
	{
		int ref = 0;
		for (int i = 0;i < 10;i++)
		{
			cout << "정수를 입력하세요 : ";
			cin >> ref;
			num[i] = ref;
		}
	}

	void DrawStar()
	{
		int starNum = 0;
		for (int j = 0;j < 10;j++)
		{
			starNum = num[j];
			for (int k = 0;k < starNum;k++)
			{
				cout << "*";
			}

			cout << endl;
		}
	}
};
class Theater
{
private : 
	bool room[10];
public :
	Theater()
	{
		for (int i = 0;i < 10;i++)
		{
			room[i] = { false };
		}
	}
	void Reservation()
	{
		int choice;
		this->Show();
		cout << "예약방을 고르세요 : ";
		cin >> choice;
		if (room[choice-1])
		{
			cout << "이미 예약되어있습니다." << endl;
		}
		else
		{
			room[choice-1] = true;
			cout << choice << "번방이 예약되었습니다." << endl;
		}
	}

	void Cancel()
	{
		int choice;
		this->Show();
		cout << "예약을 취소할 방을 고르세요 : ";
		cin >> choice;

		if (room[choice-1])
		{
			room[choice-1] = false;
			cout << "예약이 취소되었습니다." << endl;
		}
		else
		{
			cout << choice<< "번방은 예약이 되어있지않습니다." << endl;
		}
	}

	void Show()
	{
		for (int i = 0;i < 10;i++)
		{
			if (room[i])
			{
				cout << i+1 << "번방은 예약되어있습니다." << endl;
			}

			else
			{
				cout << i+1 << "번방은 예약되어있지않습니다." << endl;
			}
		}

		cout << endl;
	}
};
class Vote
{
private : 
	string candidate[5];
	string voter[10];
	int numberOfVotes[5];
public :
	Vote()
	{
		for (int i = 0;i < 5;i++)
		{
			candidate[i] = { NULL };
		}

		for (int j = 0;j < 10;j++)
		{
			voter[j] = { NULL };
		}

		for (int k = 0;k < 5;k++)
		{
			numberOfVotes[k] = { 0 };
		}
	}

	void Setter()
	{
		string candidateName;
		string voterName;
		getchar();
		for (int i = 0;i < 5;i++)
		{
			cout << "후보명을 입력하세요(한글) : ";
			getline(cin, candidateName, '\n');
			candidate[i] = candidateName;
		}

		for (int j = 0;j < 10;j++)
		{
			cout << "선거인명을 입력하세요(한글) : ";
			getline(cin, voterName, '\n');
			voter[j] = voterName;
		}
	}

	void Voting()
	{
		srand((unsigned int)time(NULL));
		for (int k = 0;k< 5;k++)
		{
			numberOfVotes[k] = rand() % 5 + 1;
			for (int l=0;l<k;l++)
			{
				if (numberOfVotes[k] == numberOfVotes[l])
				{
					while (1)
					{
						numberOfVotes[k] = rand() % 5 + 1;
						if (numberOfVotes[k] != numberOfVotes[l])
						{
							break;
						}
					}
				}
			}
		}
	}

	void Result()
	{
		int winnerNum;
		string winner;
		this->Voting();
		cout << "후보 : ";
		for (int i = 0;i < 5;i++)
		{
			cout << candidate[i] << " ";
		}
		cout << endl;
		cout << "선거인 : ";
		for (int j = 0;j < 10;j++)
		{
			cout << voter[j] << " ";
		}
		cout << endl;
		cout << "득표수 : ";
		for (int k = 0;k < 5;k++)
		{
			cout << numberOfVotes[k] << " ";
		}
		cout << endl;
		winnerNum = numberOfVotes[0];
		winner = candidate[0];
		for (int l = 0;l < 5;l++)
		{
			if (winnerNum < numberOfVotes[l])
			{
				winnerNum = numberOfVotes[l];
				winner = candidate[l];
			}
		}
		cout << winner << "가 " << winnerNum << "득표수로 당선되었습니다." << endl;
	}
};
int main()
{
	int choice;
	int choice2;
	ShowNum showNum;
	Star star;
	Theater theater;
	Vote vote;
	while (1)
	{
		cout << endl;
		cout << "기능을 고르세요." << endl;
		cout << "1. 배열 10개에 임의의 수를 입력받아 출력한 후 최대값과 최소값 출력" << endl;
		cout << "2. 배열에 정수 10개를 저장한 후 값에 해당하는 별의 수 그리기" << endl;
		cout << "3. 극장 예약 프로그램" << endl;
		cout << "4. 투표 프로그램" << endl;
		cout << "5.끝" << endl;
		cin >> choice;
		cout << "---------------------------------------------" << endl;

		if (choice < 1 || choice>5)
		{
			continue;
		}

		if (choice == 5)
		{
			break;
		}

		switch (choice)
		{
		case 1:
			showNum.PrintNum();
			cout << endl;
			showNum.MiniAndMax();
			break;

		case 2:
			star.SetNum();
			cout << endl;
			star.DrawStar();
			break;
		case 3:
			while (1)
			{
				cout << "1.예약 2.예약취소 3.끝내기" << endl;
				cin >> choice2;
				if (choice2 == 3)
				{
					break;
				}
				switch (choice2)
				{
				case 1:
					theater.Reservation();
					break;
				case 2:
					theater.Cancel();
					break;
				}
			}
			break;
		case 4:
			vote.Setter();
			vote.Result();
			break;
		}
	}
	return 0;
}
