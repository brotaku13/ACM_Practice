#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>;
using namespace std;

void checkPark(int, unordered_set<int>, const unordered_map<int, unordered_set<int>>&);
bool result(int startPoint, unordered_set<int> set, const unordered_map<int, unordered_set<int>>& parkMap);

int main()
{

	int numParks;
	cin >> numParks;
	int N;
	while (cin >> N)
	{  
		int R, tail, head;
		unordered_map<int, unordered_set<int>> m;
		unordered_set<int> parksSet;
		cin >> R;
		bool enoughConnections = N <= R;
		
		for (int r = 0; r < R; r++)
		{
			cin >> tail >> head;
			if (enoughConnections)
			{

				auto foundIter = m.find(tail);
				if (foundIter == m.end())
				{
					parksSet.insert(tail);
					unordered_set<int> heads { head };
					m.insert(make_pair(tail, heads));
				}
				else 
					foundIter->second.insert(head);		
			}
		}

		//for (auto iterM : m)
		//{
		//	cout << iterM.first << "[ ";
		//	for (auto iterS : iterM.second)
		//	{
		//		cout << iterS << " ";
		//	}
		//	cout << " ]\n\n";

		//}
		unordered_set<int> a = { 1 };
		unordered_set<int>
		
		if (!enoughConnections)
			cout << "Oh, oh!\n";
		else
		{
			
			// check if the graph is strictly connected
			auto iter = m.begin();
			auto iterEnd = m.end();
			while (iter != iterEnd)
			{
				if (result(iter->first, parksSet, m))
					cout << "Gotta Catch Them All!";
				else
					cout << "Oh, oh!";
				++iter;
			}
		}
	}


	return 0;
}

void checkPark(int num, unordered_set<int> parksSet, const unordered_map<int, unordered_set<int>>& parkMap)
{
	if (parksSet.empty()) return;
	else if (parkMap.at(num).empty()) return;
	else
	{
		auto pathIter = parkMap.at(num).begin();
		auto pathIterEnd = parkMap.at(num).end();
		while (pathIter != pathIterEnd)
		{
			parksSet.erase(num);
			if(find(parksSet.begin(), parksSet.end(), *pathIter) != parksSet.end())
				checkPark(*pathIter, parksSet, parkMap);
			++pathIter;
		}
		return;
	}
}

bool result(int startPoint, unordered_set<int> parksSet, const unordered_map<int, unordered_set<int>>& parkMap)
{
	checkPark(startPoint, parksSet, parkMap);
	return parksSet.empty();
}