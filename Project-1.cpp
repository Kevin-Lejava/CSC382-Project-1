#include <iostream>
#include <ctime>
#include <map>
using namespace std;

int FiboR(int n){ // array of size n

	if (n == 0 || n == 1)
		return (n);

	else return (FiboR(n - 1) + FiboR(n - 2));
}
int MODFiboR(int n) {

	static map<int, int> values;

	if (n == 0 || n == 1)
		return n;

	map<int, int>:: iterator i = values.find(n);

	if (i == values.end())
		return values[n] = MODFiboR(n - 1) + MODFiboR(n - 2);
	else
		return i->second;
}
int FiboNR(int n){ // array of size n

	int F[100];

	F[0] = 0; F[1] = 1;

	for (int i = 2; i <= n; i++){
		F[n] = F[n - 1] + F[n - 2];
	}

	return (F[n]);
}
int main(){
	clock_t startFR = clock();
	clock_t startFNR = clock();
	clock_t startMODFR = clock();

	int arr[61];

	cout << "Integer\t\tFiboR(seconds)\t\tMODFibR\t\tFiboNR(seconds)\t\tFibo-value\n";

	for (int i = 1; i < 46; i++) {

		arr[i] = i;
		int fibValue = 0;

		fibValue = MODFiboR(i);
		clock_t endMODFR = clock();

		FiboNR(i);
		clock_t endFNR = clock();

		FiboR(i);
		clock_t endFR = clock();

		cout << arr[i] << "\t\t" << double(endFR - startFR) / CLOCKS_PER_SEC
			<< "\t\t\t" << double(endMODFR - startMODFR) / CLOCKS_PER_SEC
			<< "\t\t\t" << double(endFNR - startFNR) / CLOCKS_PER_SEC
			<< "\t\t\t" << fibValue << "\n";
	}

	return 0;
}