#ifndef PRODUCT
#define PRODUCT

struct Product{
	int item;     // which kind of product,  not the id;
	int category; // optional now;
	double  weight;   // 

	int max_number[3]; // the maximum item number for small, 

public: 
	Product(){
		item = -1;
		category = -1;
		double weight = 0;
		max_number[0] = 0;
		max_number[1] = 0;
		max_number[2] = 0;
	}
	Product(int i, int c, double w, int number1, int number2, int number3){
		item = i;
		category = c;
		weight = w;
		max_number[0] = number1;
		max_number[1] = number2;
		max_number[2] = number3;
	}
	
	int getItem() {return item;}
	int getCategory() {return category;}
	double getWeight() {return weight;}
	int getNumber1() {return max_number[0];}
	int getNumber2() {return max_number[1];}
	int getNumber3() {return max_number[2];}
	
	bool setItem(int i) { item = i; return true;}
	bool setCategory(int c) { category = c; return true;}
	bool setWeight(double w) { weight = w; return true;}
	bool setNumber1(int number1) { max_number[0] = number1; return true;}
	bool setNumber2(int number2) { max_number[1] = number2; return true;}
	bool setNumber3(int number3) { max_number[2] = number3; return true;}
};


#endif // PRODUCT

