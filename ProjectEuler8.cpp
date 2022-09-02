#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
template <class Mujeeb>

//Calculate the products 
long long calcProducts(Mujeeb firstDigit, size_t length) {
	long long originalProduct = 1;
	for (int i = 0; i < length; i++)
		originalProduct *= *firstDigit++;
	return originalProduct;
}

//get the largest Product 
long long calcLargest(vector<int> const& input, int digits) {
	size_t max_size = input.size() - digits + 1;

	long long largestProduct = 0;

	for (int i = 0; i < max_size; i++) {
		long long product = calcProducts(&input[i], digits);
		largestProduct = max(largestProduct, product);// use max to find the largest product 
	}
	return largestProduct;// return the largest product 
}

//print function
void print(vector<int> const& input)
{
	int zero = 0; 
	for (int i = 0; i < input.size(); i++) {
		cout << input.at(i) << '*';
	}
	cout << endl;
}

int main() {
	//Reading in the file 
	ifstream input;
	input.open("projectFile.txt");
	vector<int> numbersSet;
	int numberAdded;

	//add a vector set with pushback
	while (input >> numberAdded)
	{
		numbersSet.push_back(numberAdded);
	}
	
	print(numbersSet); //print the numbers in the vector set 

	static const int digits = 13; // every 13 digits multiply

	auto largest = calcLargest(numbersSet, digits); //Find the largest product

	cout << endl;
	cout << "_____________________________________" << endl;
	cout << "The largest product is: " << largest << "\n";
	cout << "_____________________________________" <<endl;

	input.close();
}
