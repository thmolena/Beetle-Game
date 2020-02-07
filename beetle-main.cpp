/*
Author: Thy H. Nguyen
A description of the lab: L04 Code designed to introduce design of classes in C++
Beetle image, Getrandom, and Dice by Dr. Jan Pearce, Berea College

Milestone Requirements:

Milestone 1: Submit initial whiteboard design,
pull repo and make some commits.

Milestone 2: Make sincere attempt to complete everything,
so you can come to class with questions.
However, it might not yet be working.

Final Milestone: Lab is complete.

*/

#include <iostream>
#include <string>
#include <random> //needed for Getrandom
#include <chrono> 
using namespace std;

class Getrandom {
	/** Uses <random> and <chrono> from C++11 to return a random integer in range [1..size] */
public:
	Getrandom(int size) {
		auto seed = chrono::system_clock::now().time_since_epoch().count(); //gets a new seed for the randomness
		default_random_engine generator(seed);			//seeds our randomness
		uniform_int_distribution<int> intdist(1, size); //a distibution to make each in-range integer equally likely
		self_rand_int_ = intdist(generator);			//generates the randme number
	}
	int roll() {
		return self_rand_int_;
	}
private:
	int self_rand_int_;
};

class Dice {
	/** class that can be used to make dice.
	Dependent upon the Getrandom class above. */
public:
	Dice() {// default constructor assumes a 6-sided die.
		self_roll_count_ = 0;
		self_sides_ = 6;
	}
	Dice(int sides) {        // constructor for any size dice
		self_roll_count_ = 0;
		self_sides_ = sides;
	}
	int roll() {             // return the random roll of the die
		// postcondition: number of rolls updated, random 'die' roll returned

		Getrandom newrandom(self_sides_);
		self_roll_count_ = self_roll_count_ + 1;         // update # of times die rolled
		return(newrandom.roll());
	}
	int get_sides() const {   // how many sides this die has
		// postcondition: return # of sides of die
		return self_sides_;
	}
	int get_roll_count() const {   // # times this die rolled
		// postcondition: return # of times die has been rolled
		return self_roll_count_;
	}
private:
	int self_roll_count_;       // # times die rolled
	int self_sides_;           // # sides on die
}; //a semi colon must end every C++ class declaration.

class Beetle
{
public:
	Beetle() {
		body_num = 0;
		head_num = 0;
		leg_num = 0;
	    eye_num =0 ;
		feeler_num= 0;
		tail_num=0;
		complete_beetles = false;

	}
	void beetle_game(int roll_a_dice) {
		// Get a number and add the part needed 
		if (roll_a_dice == 1 && body_num< 1) {
			body_num = 1;
			for (int i = 4; i < 9; i++) {
				partial_beetle[i] = body[i - 4];
			}
		}
		if (body_num == 1 && roll_a_dice == 2 && head_num< 1) {
			head_num = 1;
			for (int i = 1; i < 4; i++) {
				partial_beetle[i] = head[i - 1];
			}
		}
		if (body_num == 1 && roll_a_dice == 3 && leg_num <1) {
			leg_num = 1;
			partial_beetle[4] = leg_1[0];
		}

	
		if (leg_num == 1 && roll_a_dice == 3 && 1<= leg_num < 2) {
			leg_num = 2;
			partial_beetle[5] = leg_2[0];
		}
		if (leg_num == 2 && roll_a_dice == 3 && 2<= leg_num < 3) {
			leg_num = 3;
			partial_beetle[6] = leg_3[0];
		}

		if (body_num == 1 && roll_a_dice == 6 && tail_num < 1) {
			tail_num = 1;
			for (int i = 9; i < len_beetle; i++) {
				partial_beetle[i] = tail[i - 9];
			}
		}
		if (head_num == 1 && roll_a_dice == 5 && feeler_num < 1) {
			feeler_num = 1;
			for (int i = 0; i < 2; i++) {
				partial_beetle[i] = feeler_1[i];
			}
			
		}
		else if (feeler_num == 1 && roll_a_dice == 5 && 1<= feeler_num < 2) {
			feeler_num = 2;
			for (int i = 0; i < 2; i++) {
				partial_beetle[i] = feeler_2[i];
			}
		}
		if (head_num == 1 && roll_a_dice == 4 && eye_num < 1) {
			eye_num = 1;
			partial_beetle[2] = eye_1[0];
		}
		if (eye_num == 1 && roll_a_dice == 4 && 1<= eye_num < 2) {
			eye_num = 2;
			partial_beetle[2] = eye_2[0];
		}
		

		

	}

	bool complete_beetle() {
		//Check to see if we get all of the parts
		if (body_num == 1 && head_num == 1 && leg_num == 3 && eye_num == 2 && feeler_num == 2 && tail_num == 1) {
			complete_beetles = true;
		}
		else
		{
			complete_beetles = false;
		}
		return complete_beetles;
		
	}
	void show() const {
		//show the beetle
		for (int i = 0; i < len_beetle; i++) {
			cout<<partial_beetle[i]<< endl;
		}		
		return;
	}

	friend ostream& operator<<(ostream& stream, const Beetle& thebeetle);
private:
	bool complete_beetles;
	int body_num;
	int head_num;
	int leg_num;
	int eye_num;
	int feeler_num;
	int tail_num;
	const int len_beetle = 12;
	string body[5] = {
	"     /  -  \\      ",
	"    |---.---|      ",
	"    |   |   |      ",
	"    \\   |   /     ",
	"     `. : .'       ",
		
	};
	string head[3] = {

	"      \\_          ",
	"                   ",
	"      \\___/       "
		

	};

	string feeler_1[2] = {
	"      Y           ",
	"      \\\\_       ",
	};
	string feeler_2[2] = {
	"      Y     Y       ",
	"      \\\\_//       ",

	};

	string eye_1[1] = {
    "     .@             "
		
	};
	string eye_2[1] = {
	"    .@      @.     ",
	};
	string tail[3] = {
	"        |:|        ",
	"        |:|        ",
	"         v         "
	};
	string leg_1[1] = {
	"  v__/  -  \\__v  ",

	};
	string leg_2[1] = {
	"v___|---.---|___v ",
    };
	string leg_3[1] = {
	" v__|   |   |__v  ",
	};

    string partial_beetle[12] = {
	"                  ",
	"                  ",
	"                  ",
	"                  ",
	"                  ",
	"                  ",
	"                  ",
	"                  ",
	"                  ",
	"                  ",
	"                  ",
	"                  "
	};


}; //don't forget semi-colon!!



/*
	const int len_beetle = 12;
	string complete_beetle[12] = {
		"      Y   Y       ",
		"      \\\\_//     ",
		"     .@   @.      ",
		"      \\___/      ",
		"  v__/  -  \\__v  ",
		"v___|---.---|___v ",
		" v__|   |   |__v  ",
		"    \\   |   /    ",
		"     `. : .'      ",
		"       |:|        ",
		"       |:|        ",
		"        v         "
	};
*/


ostream& operator<<(ostream& stream, const Beetle& thebeetle) {
	thebeetle.show();
	return stream;
}


int main() {

	char readchar;

	Dice a_dice_player;
	Dice a_dice_computer;
	string answer;
	Beetle beetle1;
	Beetle beetle2;
	cout << "Do you want to roll? [Answer 'yes' to roll, Answer everything else beside 'yes' to skip a turn]" << endl;
	cin >> answer;


	while (1>0 ) { //To keep the loop going
		if (answer == "yes") {
			int roll_a_dice_1 = a_dice_player.roll();

			cout << "You rolled a " << roll_a_dice_1 << endl;
			beetle1.beetle_game(roll_a_dice_1);
			if (beetle1.complete_beetle() == false) {
				cout << "This is your beetle" << endl;
				cout << beetle1 << endl;
			}
			else {
				cout << "This is your beetle" << endl;
				cout << beetle1 << endl;
				break;
			}
		}
		

		int roll_a_dice_2 = a_dice_computer.roll();
		cout << "Computer rolled a " << roll_a_dice_2 << endl;
		beetle2.beetle_game(roll_a_dice_2);
		if (beetle2.complete_beetle() == false) {
			cout << "This is computer's beetle" << endl;
			cout << beetle2 << endl;
		}
		else {
			cout << "This is computer's beetle" << endl;
			cout << beetle2 << endl;
			break;
		}

		
		cout << "Do you want to roll? [Answer 'yes' to roll, Answer everything else beside 'yes' to skip a turn]" << endl;
		cin >> answer;
	}

	
	cout << "The game ended!\n" << endl;
	if (beetle1.complete_beetle() == false) {
		cout << "Computer wins" << endl;
	}
	else {
		cout << "User wins" << endl;
	}
	cin >> readchar; //This is to keep screen open in some situations.
	return 0;

}

