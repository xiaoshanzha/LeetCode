/***
	关键：一个字母的单词以及其出现的位置，特别是首部尾部
  ***/
string toGoatLatin(string S) {
	int len = S.length();
	string final;
	int num = 0;
	string temp = "";
	string s = "aeiouAEIOU";
	for (int i = 0; i<len; i++)
	{
		//字符串S中每个单词的首字母判断
		if (i == 0 || S[i - 1] == ' ')
		{
			num++;
			//首字母是否元音开头
			if (s.find(S[i]) != -1)
			{
				temp = "ma";
				temp.append(num, 'a');
			}
			else
			{
				//非元音字母开头的单词是否为一个字母
				if (S[i+1]==' '|| i == len - 1)
				{
					temp = "ma";
					temp.append(num, 'a');
				}
				else
				{
					temp = temp + S[i] + "ma";
					temp.append(num, 'a');
					i++;
				}
			}
		}
		final += S[i];

		//判断每个单词的截止
		if (i == len - 1 || S[i + 1] == ' ')
		{
			final.append(temp);
			temp = "";
		}
	}
	return final;
}