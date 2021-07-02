
#include <iostream>
//Box 0 size 4    box 1   size 2 box 2 size 1
class Box {
public:
	Box(int max = 0, int aver = 0, int min = 0) {
		boxs[0] = max;
		boxs[1] = aver;
		boxs[2] = min;
	}
	bool add(int size);
	bool remove(int size);
	int getcount(int size);
	int sum() {
		return (boxs[0] * 4 + boxs[1] * 2 + boxs[2]);
	}
private:
	int boxs[3];
};

bool Box::add(int size) {
	if (size >= 0 && size <= 2) {
		++boxs[size];
		return true;
	}
	else return false;
}
bool Box::remove(int size) {
	if (size >= 0 && size <= 2 && boxs[size] > 0) {
		--boxs[size];
		return true;
	}
	else return false;
}

int Box::getcount(int size) {
	if (size >= 0 && size <= 2) {
		return boxs[size];
	}
	else return -1;
}




class Cont {
public:
	Cont(int m, int n, Box bo) : m(m), n(n) {
		_bo = bo;
		_boarr = new Box[3];
	};
	void placeall() {
		for (int i = 0; i < n; ++i) {
			place(i);
			std::cout << std::endl;
		}
	}

private:
	Box _bo;
	int m, n; //n-строчки
	Box* _boarr;

	void place(int rad) {
		while (_boarr[rad].sum() < m) {
			if (_boarr[rad].sum() <= m - 4 && _bo.getcount(0) > 0) { _boarr[rad].add(0); _bo.remove(0); }
			else if (_boarr[rad].sum() <= m - 2 && _bo.getcount(1) > 0) {
				_boarr[rad].add(1); _bo.remove(1);
			}
			else if (_boarr[rad].sum() <= m - 1 && _bo.getcount(2) > 0) {
				_boarr[rad].add(2); _bo.remove(2);
			}
			std::cout << _boarr[rad].sum();
		}
	}

};

int main() {
	Box bo(1, 1, 10);
	Cont container(5, 3, bo);
	container.placeall();
}