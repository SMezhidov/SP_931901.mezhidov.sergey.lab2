#include <iostream>
using namespace std;

int Len = 7;
int Arr[7];

class Sort
{
public:
	int BubbleSort()
	{
		_asm
		{
			dec Len;
		CycleExt:
			xor ebx, ebx;
			mov ecx, Len;
			mov esi, 0;
		CycleIn:
			mov edi, Arr[esi];
			cmp edi, Arr[esi + 4];
			jg Exchange;
			add esi, 4;
			loop CycleIn;
			jmp Check;
		Exchange:
			mov ebx, Arr[esi + 4];
			mov Arr[esi + 4], edi;
			mov Arr[esi], ebx;
			add esi, 4;
			loop CycleIn;
		Check:
			cmp ebx, 0;
			je Exit;
			jmp CycleExt;
		Exit:

		}
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Sort bubble;

	cout << "Кол-во элементов массива: " << Len << endl;
	for (int i = 0; i < Len; i++)
	{
		cout << "Arr[" << i + 1 << "]: ";
		cin >> Arr[i];
	};

	bubble.BubbleSort();
	cout << "Отсортированный массив:\n";
	for (int i = 0; i <= Len; i++)
	{
		cout << "Arr[" << i + 1 << "]: " << Arr[i] << endl;
	}
		

	system("pause");
	return 0;
};