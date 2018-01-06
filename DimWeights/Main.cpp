#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

struct company
{
	string name;
	int minForWeight;
	int dimWeightFactor;
};

struct parcel
{
	int volume;
	int weight;
};

int main()
{
	vector<company> companyVec;
	vector<parcel> parcelVec;
	int n;
	cin >> n;

	// get company data
	for (int i = 0; i < n; i++)
	{
		company temp;
		cin >> temp.name >> temp.minForWeight >> temp.dimWeightFactor;
		companyVec.push_back(temp);
	}
	int len;
	while (cin >> len)
	{
		parcel temp;
	
		int width;
		int height;
		int weight;
		cin >> width >> height >> weight;
		temp.volume = len * width * height;
		temp.weight = weight;
		parcelVec.push_back(temp);
	}
	cout << "companyvec size = " << companyVec.size() << "\nparcelVec size = " << parcelVec.size();
	for (auto p : parcelVec)
	{
		int effectiveWeight = 0;
		int minEffectiveWeight = INT16_MAX;
		company lightestCompany;

		for (auto c : companyVec)
		{
			if (p.volume > c.minForWeight)
			{
				int dimWeight = static_cast<int>(ceil(static_cast<double>(p.volume) / c.dimWeightFactor));
				effectiveWeight = max(dimWeight, p.weight);
				cout << c.name << " Dim Weight: " << dimWeight << endl;
			}
			else
				effectiveWeight = p.weight;

			if (effectiveWeight < minEffectiveWeight)
			{
				minEffectiveWeight = effectiveWeight;
				lightestCompany = c;
			}
		}
		cout << lightestCompany.name << " " << minEffectiveWeight << endl;
	}

	return 0;
}