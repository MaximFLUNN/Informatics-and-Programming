#include <iostream>
#define TO_KILLOMETTERS 1000
#define TO_MILLES 1.60934

enum type {
	leave = 0,
	_metter = 1,
	_kilometters = 2,
	_milles = 3,
	ravno = 4,
	compare = 5,
	plus = 6,
	minus = 7,
	multiply = 8,
	equals = 9,
	eq = 10,
	neq = 11,
	greater_eq = 12,
	greater = 13,
	less_eq = 14,
	less = 15
};

class Distance {
private:
	int metters = 0;
	int type = 0;
public:
	Distance() {
		metters = 0;
	}
	Distance(int _metters, int _type) {
		type = _type;
		if (type == _metter) { metters = _metters; }
		else if (type == _kilometters) { metters = _metters * TO_KILLOMETTERS; }
		else if (type == _milles) { metters = _metters * TO_KILLOMETTERS * TO_MILLES; } // ~
	}

	Distance(const Distance& met) {
		metters = met.metters;
		if (met.type == _kilometters) { metters /= TO_KILLOMETTERS; }
		else if (met.type == _milles) { metters = (metters / TO_KILLOMETTERS / TO_MILLES); }
	}

	~Distance() {}
	friend void operator += (Distance& one, Distance& two) {
		one.metters += two.metters;
		if (one.type == _kilometters) { one.metters /= TO_KILLOMETTERS; }
		else if (one.type == _milles) { one.metters = one.metters / TO_KILLOMETTERS / TO_MILLES; }
	}

	friend void operator -= (Distance& one, Distance& two) {
		one.metters -= two.metters;
		if (one.type == _kilometters) { one.metters /= TO_KILLOMETTERS; }
		else if (one.type == _milles) { one.metters = one.metters / TO_KILLOMETTERS / TO_MILLES; }
	}

	friend void operator *= (Distance& one, Distance& two) {
		one.metters *= two.metters;
		if (one.type == _kilometters) { one.metters /= TO_KILLOMETTERS; }
		else if (one.type == _milles) { one.metters = one.metters / TO_KILLOMETTERS / TO_MILLES; }
	}

	friend void operator /= (Distance& one, Distance& two) {
		one.metters /= two.metters;
		if (one.type == _kilometters) { one.metters /= TO_KILLOMETTERS; }
		else if (one.type == _milles) { one.metters = one.metters / TO_KILLOMETTERS / TO_MILLES; }
	}

	friend std::ostream& operator << (std::ostream& out, Distance& dist) {
		out << dist.metters;
		return out;
	}

	void operator = (const Distance& dist) {
		metters = dist.metters;
	}

	friend bool operator == (Distance& num, Distance& num_two) {
		if (num.metters == num_two.metters) { return true; }
		return false;
	}
	friend bool operator != (Distance& num, Distance& num_two) {
		if (num.metters != num_two.metters) { return true; }
		return false;
	}
	friend bool operator >= (Distance& num, Distance& num_two) {
		if (num.metters >= num_two.metters) { return true; }
		return false;
	}
	friend bool operator <= (Distance& num, Distance& num_two) {
		if (num.metters <= num_two.metters) { return true; }
		return false;
	}
	friend bool operator > (Distance& num, Distance& num_two) {
		if (num.metters > num_two.metters) { return true; }
		return false;
	}
	friend bool operator < (Distance& num, Distance& num_two) {
		if (num.metters < num_two.metters) { return true; }
		return false;
	}
};


int main() {
	int met = 0, type_one = 0, type_two = 0, type = 0;
	std::cout << "You want enter Metters/Kilometters/Milles (1/2/3): ";
	std::cin >> type_one;
	std::cout << "Enter distance: ";
	std::cin >> met;
	Distance dist_one(met, type_one);
	//std::cout << "Metters = " << dist;

	while (true) {
		std::cout << "Choose operation (1 - ' + ', 2 - ' - ', 3 - ' * ', 4 - ' = ', 5 - compare): ";
		std::cin >> type_two;
		if (type_two != multiply - compare) {
			std::cout << "You want enter [Metters/Kilometters/Milles] (1/2/3) or exit 0: ";
			std::cin >> type;
		}
		//
		if (type_two == multiply - compare) { type = _metter; }
		if (type_two != multiply - compare && type != leave) { 
			std::cout << "Enter distance: ";
		}
		else if (type_two == multiply - compare) { std::cout << "Enter value: "; }
		std::cin >> met;
		Distance dist_two(met, type);
		if (type_two == plus - compare) {
			dist_one += dist_two;
		}
		else if (type_two == minus - compare) {
			dist_one -= dist_two;
		}
		else if (type_two == multiply - compare) {
			dist_one *= dist_two;
		}
		else if (type_two == equals - compare) {
			dist_one = dist_two;
		}
		else if (type_two == compare) {
			std::cout << "Choose operation \n1 - ' == ', \n2 - ' != ', \n3 - ' >= ', \n4 - ' > ', \n5 - '<=', \n6 - ' < '\n";
			std::cin >> type;
			if (type == eq - equals) {
				if (dist_one == dist_two) { std::cout << "Result compare: true\n"; }
				else { std::cout << "Result compare: false\n"; }
			}
			else if (type == neq - equals) {
				if (dist_one != dist_two) { std::cout << "Result compare: true\n"; }
				else { std::cout << "Result compare: false\n"; }
			}
			else if (type == greater_eq - equals) {
				if (dist_one >= dist_two) { std::cout << "Result compare: true\n"; }
				else { std::cout << "Result compare: false\n"; }
			}
			else if (type == greater - equals) {
				if (dist_one > dist_two) { std::cout << "Result compare: true\n"; }
				else { std::cout << "Result compare: false\n"; }
			}
			else if (type == less_eq - equals) {
				if (dist_one <= dist_two) { std::cout << "Result compare: true\n"; }
				else { std::cout << "Result compare: false\n"; }
			}
			else if (type == less - equals) {
				if (dist_one < dist_two) { std::cout << "Result compare: true\n"; }
				else { std::cout << "Result compare: false\n"; }
			}
		}
		if (type == leave) { break; }
		std::string type_dist = " (metters)";
		if (type_one == _kilometters) { type_dist = " (kilometters)"; }
		else if (type_one == _milles) { type_dist = " (milles)"; }
		std::cout << "Distance = " << dist_one << type_dist << std::endl;
		type_two = type_one = type = 0;
	}
	std::cout << "\nExit programm...\n";

	return 0;
}