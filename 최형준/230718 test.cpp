#include <iostream>
#include <string>

using namespace std;

struct Student
{
	int no;
	string name;
	Student* next;
};

void Add();
void Delete();
void PrintAll();

class List
{
public:
	List() { head = nullptr; }
	~List() {}
	void Add(int no, string name);
	void Delete(int no);
	void PrintAll();

private:
	Student* head;
};

// ���� ��ü
List list;

int main()
{
	int input;
	bool out = true;

	while (out)
	{
		cout << "1�� : ���, 2�� : ����, 3�� : ��ü��� : ";
		cin >> input;
		switch (input)
		{
		case 1:
			Add();
			break;
		case 2:
			Delete();
			break;
		case 3:
			PrintAll();
			break;
		default:
			out = false;
			break;
		}
	}

	return 0;
}

void List::Add(int no, string name)
{
	Student* temp = new Student;
	temp->name = name;
	temp->no = no;

	// ��� ������
	if (head == nullptr)
	{
		temp->next = nullptr;
		head = temp;

		return;
	}

	temp->next = head;
	head = temp;

	return;
}

void List::Delete(int no)
{
	if (head == nullptr)
	{
		cout << "��Ͼ���" << endl;
		return;
	}

	Student* temp = head;

	if (temp->no == no) // ù ���
	{
		head = temp->next;
		temp->next = nullptr;
		delete temp;

		return;
	}

	Student* prev = temp;
	temp = temp->next;

	while (temp != nullptr)
	{
		if (temp->no == no)
		{
			if (temp->next == nullptr) // �� ������ ����϶�
			{
				prev->next = nullptr;
				temp->next = nullptr;
				delete temp;

				return;
			}
			prev->next = temp->next; // �߰� ����϶�
			temp->next = nullptr;
			delete temp;

			return;
		}

		prev = temp;
		temp = temp->next;
	}

	// ��ã�� (����ž���)
	cout << " ��ã��" << endl;
	return;
}

void List::PrintAll()
{
	Student* temp = head;
	if (temp == nullptr)
	{
		cout << "����Ʈ�� �л����� �����ϴ�." << endl;
		return;
	}

	while (temp != nullptr)
	{
		cout << temp->no << endl;
		cout << temp->name << endl << endl;
		temp = temp->next;
	}
}

void Add()
{
	int no;
	string name;

	cout << "��ȣ �Է� :";
	cin >> no;
	cout << "�̸� �Է� : ";
	cin >> name;
	list.Add(no, name);
}

void Delete()
{
	int no;

	cout << "���� ��ȣ �Է� : ";
	cin >> no;
	list.Delete(no);
}

void PrintAll()
{
	cout << "��� ��Ҹ� ����մϴ�" << endl;
	list.PrintAll();
}