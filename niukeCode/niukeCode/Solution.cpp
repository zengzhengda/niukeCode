#include "main.h"

//最高分是多少
void getMaxScore()
{
	int N,M;
	while(cin >> N >> M)
	{
		vector<int> scores;
		for(int i=0;i<N;i++)
		{
			int score;
			cin >> score;
			scores.push_back(score);
		}
		
		vector<vector<int>> records;
		while(M--)
		{
			char a1;
			int a2, a3;
			cin >> a1 >> a2 >> a3;
			records.push_back({a1,a2,a3});
		}
		for(int i =0;i <records.size();i++)
		{
			if(records[i][0] == 'Q')
			{
				auto largest= max_element(scores.begin()+records[i][1]-1,scores.begin()+records[i][2]);
				cout << *largest << endl;
			}
			else
			{
				scores[records[i][1]-1]=records[i][2];
				// cout << records[i][2] << endl;
			}
		}
	}
	return;
}
// 取近似值
void getApproximateValue()
{
    double a;
    cin>>a;
    a=a+0.5;
    int b = floor(a);
    cout<< b << endl;
    return;
}

// 合并表记录
void mergeTableRecord()
{
	int n;// 键值对数
	cin >> n;
	map<int,int> map;
	while (n--)
	{
		int index, val;
		cin >> index >> val;
		map[index] += val;
	}
	// sort(map.begin(),map.end());
	for(auto it = map.begin(); it != map.end();it++)
	{
		cout << it->first<<' ' << it->second << endl;
	}
	return;
}