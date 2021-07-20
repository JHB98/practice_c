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
			cout << "������ �Է��ϼ��� : ";
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
		cout << "������� ������ : ";
		cin >> choice;
		if (room[choice-1])
		{
			cout << "�̹� ����Ǿ��ֽ��ϴ�." << endl;
		}
		else
		{
			room[choice-1] = true;
			cout << choice << "������ ����Ǿ����ϴ�." << endl;
		}
	}

	void Cancel()
	{
		int choice;
		this->Show();
		cout << "������ ����� ���� ������ : ";
		cin >> choice;

		if (room[choice-1])
		{
			room[choice-1] = false;
			cout << "������ ��ҵǾ����ϴ�." << endl;
		}
		else
		{
			cout << choice<< "������ ������ �Ǿ������ʽ��ϴ�." << endl;
		}
	}

	void Show()
	{
		for (int i = 0;i < 10;i++)
		{
			if (room[i])
			{
				cout << i+1 << "������ ����Ǿ��ֽ��ϴ�." << endl;
			}

			else
			{
				cout << i+1 << "������ ����Ǿ������ʽ��ϴ�." << endl;
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
			cout << "�ĺ����� �Է��ϼ���(�ѱ�) : ";
			getline(cin, candidateName, '\n');
			candidate[i] = candidateName;
		}

		for (int j = 0;j < 10;j++)
		{
			cout << "�����θ��� �Է��ϼ���(�ѱ�) : ";
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
		cout << "�ĺ� : ";
		for (int i = 0;i < 5;i++)
		{
			cout << candidate[i] << " ";
		}
		cout << endl;
		cout << "������ : ";
		for (int j = 0;j < 10;j++)
		{
			cout << voter[j] << " ";
		}
		cout << endl;
		cout << "��ǥ�� : ";
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
		cout << winner << "�� " << winnerNum << "��ǥ���� �缱�Ǿ����ϴ�." << endl;
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
		cout << "����� ������." << endl;
		cout << "1. �迭 10���� ������ ���� �Է¹޾� ����� �� �ִ밪�� �ּҰ� ���" << endl;
		cout << "2. �迭�� ���� 10���� ������ �� ���� �ش��ϴ� ���� �� �׸���" << endl;
		cout << "3. ���� ���� ���α׷�" << endl;
		cout << "4. ��ǥ ���α׷�" << endl;
		cout << "5.��" << endl;
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
				cout << "1.���� 2.������� 3.������" << endl;
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
