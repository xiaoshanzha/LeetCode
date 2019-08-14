/***
	解题思路：字符串中find字符串，找到后改变母串，继续查找
	注意：注意索引的位置，容易出现越界
    ***/
vector<string> findOcurrences(string text, string first, string second) {
	vector<string> vec;
	string all = first + " " + second;
	string temp = "";
	int i = 0;
	while (i + all.length() <= text.length())
	{
		int start = text.find(all);
		if (start < text.length() - all.length())
		{
			int t = start + all.length() + 1;
			int j = t;
			//单词结束判断
			while (1)
			{
				temp = temp + text[j];
				if (text[j + 1] == ' ' || j == text.length() - 1)
				{
					break;
				}
				j++;
			}
			vec.push_back(temp);
			temp = "";
			/***
				改变母串时，应删减first子串，防止出现first、second子串相同；
				不过删减all字符串还是通过了，打脸！！！
			***/
			text = text.substr(start + first.length() + 1, text.length() - start);
			i = 0;
		}
		else
		{
			break;
		}
	}
	return vec;
}