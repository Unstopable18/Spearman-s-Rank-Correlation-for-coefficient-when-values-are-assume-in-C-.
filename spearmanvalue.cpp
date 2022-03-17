#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<float> Vector;
void printVector(const Vector &X)
{
	for (auto i: X)
	cout <<"< "<<i<<" >\t";
	cout << endl;
}
Vector rankify(Vector & X) 
{
	int N = X.size();
	Vector Rank_X(N);
	
	for(int i = 0; i < N; i++)
	{
		int r = 1, s = 1;
		for(int j = 0; j < i; j++) 
		{
			if (X[j] < X[i] ) r++;
			if (X[j] == X[i] ) s++;
		}
		for (int j = i+1; j < N; j++) 
		{
			if (X[j] < X[i] ) r++;
			if (X[j] == X[i] ) s++;
		}
		Rank_X[i] = r + (s-1) * 0.5;		
	}
	return Rank_X;
}
float correlationCoefficient(Vector &X, Vector &Y)
{
	int n = X.size();
	float xsum = 0, ysum = 0,xysum = 0,x2sum = 0,y2sum = 0,p1,p2,p3,spearman;
	for (int i = 0; i < n; i++)
	{
		xsum = xsum + X[i];
		ysum = ysum + Y[i];
		xysum = xysum + X[i] * Y[i];
		x2sum = x2sum + X[i] * X[i];
		y2sum = y2sum + Y[i] * Y[i];
	}
	p1=n*xysum -xsum * ysum;
	p2=n*x2sum -xsum * xsum;
	p3=n*y2sum -ysum * ysum;
	spearman = p1/sqrt(p2 * p3);
	return spearman;
}
vector<float> X,Y;
int main()
{
	int n;
	cout<<"*******************************************************************************";
    cout<<"\nEnter Total No. of Elements = \t";
    cin>>n;
	cout<<"\nEnter "<<n<<" A : \n";
	int inputX = 0;
	for (int i = 0; i < n; i++) 
	{
		cin >> inputX;
		X.push_back(inputX);
	}
	cout<<"\nEnter "<<n<<" B : \n";
	int inputY = 0;
	for (int i = 0; i < n; i++) 
	{
		cin >> inputY;
		Y.push_back(inputY);
	}
	Vector rank_x = rankify(X);
	Vector rank_y = rankify(Y);
	cout<<"\n*******************************************************************************";
	cout << "\nVector A\n";
	printVector(X);
	cout << "\nA Rank\n";
	printVector(rank_x);
	cout<<"*******************************************************************************";
	cout << "\nVector B\n";
	printVector(Y);
	cout<< "\nB Rank\n";
	printVector(rank_y);
	cout<<"*******************************************************************************";
    cout<<"\nSpearman's Rank Correlation for Coeff. is Found to be = "<<correlationCoefficient(rank_x,rank_y)<<"\n";
	cout<<"*******************************************************************************";
	return 0;
}