#include<iostream>
using namespace std;

namespace SumNamespace{
	int sum(int x, int y) {
		return x + y;
	}
}

namespace ProductNamespace{
	int product(int x, int y) {
		return x * y;
	}
}

namespace Mathematics{
	using namespace SumNamespace;
	using namespace ProductNamespace;
	using namespace std;
	int sumVal = sum(4, 5);
	int prodVal = product(4, 5);
	
	void printValues() {
		cout << sumVal << " " << prodVal << endl;
	}
}

using namespace Mathematics;

int main () {
	printValues();
}