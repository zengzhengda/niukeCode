#include "main.h"

// 任务列表
void taskLIst()
{
	int N,M;
	while(cin>>N >> M)
	{
		vector<int> list_ge;
		for(int i=0;i<N;i++)
		{
			int tmp;
			cin >> tmp;
			list_ge.push_back(tmp);
		}
		vector<int> list_tmp;
		for(int j=0;j<M;j++)
		{
			int tmp;
			cin >> tmp;
			list_tmp.push_back(tmp);
		}
		vector<int> result;
		for(int i=0;i<M;i++)
		{
			result.push_back(-1);
		}
		for(int i=0;i<N-1;i++)
		{
			if(list_ge[i+1]-list_ge[i] >1)
			{
				for(int j = list_ge[i]+1; j <list_ge[i+1];j++)
				{
					for(int k=0;k<M;k++)
					{
						if(result[k] == -1 && list_tmp[k] <= j)
						{
							result[k]=j;
						}
					}
				}
			}
		}
		for(int i=0;i<M;i++)
		{
			if (result[i] == -1 && list_tmp[i] <= list_ge[N - 1])
				result[i] = list_ge[N - 1] + 1;
			else if (result[i] == -1 && list_tmp[i]>list_ge[N - 1])
				result[i] = list_tmp[i];
		}
		for (int i = 0; i < M; i++)
		{
			cout << result[i] << endl;
		}
	}
}

// 偶串
void ouchuan()
{
	string s;
	cin >> s;
	int cnt_ou=0;
	for(int i=0;i<s.length();i++)
	{
		for(int j=i+1;j<s.length();j+=2)
		{
			string s_sub=s.substr(i,j-i+1);
			bool isOu=isOuchuan(s_sub);
			if(isOu)
			{
				cnt_ou++;
			}
		}
	}
	cout<< cnt_ou<< endl;
}

bool isOuchuan(string s)
{
	map<char,int> map;
	for(int i=0;i<s.length();i++)
	{
		map[s[i]]++;
	}
	for(auto it =map.begin();it != map.end(); it++)
	{
		if(it->second%2 ==1)
			return false;
	}
	return true;
}

// 期望
void qiwang()
{
	int n;
	cin>>n;
	vector<vector<int>> data;
	while(n--)
	{
		int a,b;
		cin>>a>>b;
		data.push_back({a,b});
	}
	double m=0;
	for(int i=0;i<data.size();i++)
	{
		m += data[i][0]* (double(data[i][1])/100);
	}
	printf("%.3f", m);
}

// 水仙花数
void shuixianhuaNum()
{
	int m,n;
	while(cin>>m>>n)
	{
		vector<int> result;
		for (int num = m; num <= n; num++)
		{
			int num_tmp = num;
			vector<int> numVec;
			while(num_tmp /10)
			{
				int tmp= num_tmp %10;
				numVec.push_back(tmp);
				num_tmp = num_tmp /10;
			}
			numVec.push_back(num_tmp);
			int tmp=0;
			for(int j=0;j<numVec.size();j++)
			{
				tmp+=pow(numVec[j],3);
			}
			if(tmp==num)
			{
				result.push_back(tmp);
			}
		}
		if(result.empty())
		{
			cout<<"no"<<endl;
		}
		else
		{
			for(int i=0;i<result.size();i++)
			{
				cout<<result[i]<<" ";
			}
			cout<<endl;
		}
	}
}

// 字符串分类
//void stringClass()
//{
//	vector<string> strVec;
//	int n;
//	cin>>n;
//	while(n--)
//	{
//		string tmp="";
//		cin>>tmp;
//		strVec.push_back(tmp);
//	}
//	
//	for(int i=0;i<strVec.size();i++)
//	{
//		sort(strVec[i].begin(),strVec.end());
//	}
//	map<string,int> map_str;
//	for(int i=0;i<strVec.size();i++)
//	{
//		map_str[strVec[i]]++;
//	}
//	return map_str.size();
//}
void pinghenshu()
{
	int num;
	while(cin>>num)
	{
		if(num<10)
		{
			cout<<"NO"<<endl;
			break;
		}
		vector<int> numVec;
		while(num/10)
		{
			int tmp=num%10;
			numVec.push_back(tmp);
			num=num/10;
		}
		numVec.push_back(num);
		bool isY = false;
		for(int i=0;i<numVec.size()-1;i++)
		{
			int left=1;
			for(int j=0;j<=i;j++)
			{
				left=left*numVec[j];
			}
			int right=1;
			for(int k=i+1;k<numVec.size();k++)
			{
				right=right*numVec[k];
			}
			if(left==right)
			{
				cout<<"YES"<<endl;
				isY = true;
				break;
			}
		}
		if (isY) break;
		cout<<"NO"<<endl;
	}
}

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