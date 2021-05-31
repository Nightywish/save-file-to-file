#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

void print_vector(vector<int> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << " ";
	}

}
void play_game()
{
	vector<int> guesses;
	int count = 0;

	int random = rand() % 70;
	cout << random << endl;
	cout << "guess next number" << endl;
	while (true)
	{
		int guess;
		cin >> guess;
		count++;
		guesses.push_back(guess);
		if (guess == random)
		{
			cout << "u got it !" << endl;
			break;
		}
		else if (guess > random)
		{
			cout << " too high" << endl;
		}
		else
		{
			cout << " too low" << endl;
		}

	}
	ifstream input("best_score.txt");
	if (!input.is_open())
	{
		cout << "error, please do it again";
	}
	int best_score;
	input >> best_score;

	ofstream output("best_score.txt");
	if (count < best_score)
	{
		output << count;
	}
	else
	{
		output << best_score;
	}
	print_vector(guesses);
}
int main()
{
	srand(time(NULL));
	int choice;
	do
	{
		cout << "0: Quit " << endl << "1:Play game" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "good bye";
			break;
		case 1:
			play_game();
			break;
		}
	} while (choice != 0);


}

