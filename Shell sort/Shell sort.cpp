#include <string>
#include <iostream>

bool check(std::string number)
{
	std::string nums = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-'};
	bool match = false;
	for (int i = 0; i < number.length(); i++)
	{
		for (int j = 0; j < 11; j++) {
			if (number[i] == nums[j]) {
				match = true;
				break;
			}
			match = false;
		}
		if (!match)
			throw number;
	}
	return 1;
}

void output(int* arr, int size)
{
	if (size != 0) {
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
	else
		std::cout << "Empty\n";
}

void shell(int* arr, int size)
{
	for (int gap = size / 2; gap > 0 ; gap/=2)							//gap is determined by SIZE/2, and then it gets halved with every iteration of the main FOR cycle
	{
		for (int i = gap; i < size; i += 1)							//an element at the end of the gap is selected. after the next cycle is done, this one is moving to the next element
		{
			for (int j = i; j >= gap; j -= gap)								//this cycle makes it possible to compare every element with it's pair across the gap
			{
				if (arr[j] < arr[j - gap])
				{
					int temp = arr[j];
					arr[j] = arr[j - gap];
					arr[j - gap] = temp;
				}
			}
		}
	}
}

int main()
{
	int* arr = new int[1];
	std::string input;
	int size = 0;
	int pos = 0;

	std::cout << "Fill the array.\n";									//code below is simply making sure user input consists of numbers only. it's rather primitive and work in progress
	while (true) {
		std::cout << "To stop, type \"C\" character.\nInput: ";
		getline(std::cin, input);
		if (input[0] == 'c' || input[0] == 'C') {
			if (size == 0)
			{
				std::cout << "The array is empty. Deleting.\n";
				delete [] arr;
				return 0;
			}
			break;
		}
		try
		{
			check(input);
		}
		catch (std::string number)
		{
			system("cls");
			std::cout << "Not a number!\n";
			continue;
		}
		size++;
		int* arr1 = new int[size];
		if (pos != 0)
			for (int i = 0; i < size - 1; i++)
				arr1[i] = arr[i];
		arr1[size - 1] = std::stoi(input);
		delete[] arr;
		arr = arr1;
		pos++;
		system("cls");
	}

	output(arr, size);

	shell(arr, size);

	output(arr, size);


	return 0;
}
