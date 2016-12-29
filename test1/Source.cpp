#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int m;
	cin >> m;
	vector<int> A;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	int n;
	cin >> n;
	vector<int> B;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		B.push_back(tmp);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int Ai = 0, Bi = 0;
	int minDiff = INT_MAX;

	while (Ai < A.size() && Bi < B.size())
	{
		if (A[Ai] > B[Bi])
		{
			while (Bi + 1 < B.size() && B[Bi + 1] < A[Ai]) Bi++;
			int tmp = abs(A[Ai] - B[Bi]);
			if (tmp < minDiff) minDiff = tmp;
			Bi++;
		}
		else
		{
			while (Ai + 1 < A.size() && A[Ai + 1] <= B[Bi]) Ai++;
			int tmp = abs(A[Ai] - B[Bi]);
			if (tmp < minDiff) minDiff = tmp;
			Ai++;
		}

		if (minDiff == 0) break;
	}

	cout << minDiff;

	cout << "my name" << endl;
	return 0;
}
