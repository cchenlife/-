/*
零食有重量和价值，书包有容量，寻找书包能装零食的最大价值
*/
#include<iostream>
#include<string>
#include<cstring>
#include<climits>
using namespace std;
int weight[5];
int value[5];
long maxvalue = LONG_MIN;
const int size = 5;
void findmaxvalue(int count, int index, long m){
	if (count < 0)
		return;
	else{
		if (m > maxvalue)
			maxvalue = m;
		for (int i = index; i < size; i++)
			findmaxvalue(count - weight[i], i + 1, m + value[i]);
	}
}
int main(){
	string strvalue, strweight;
	int count;
	getline(cin, strvalue);
	getline(cin, strweight);
	cin >> count;

	char *tempvalue = new char[strvalue.size()];
	strcpy(tempvalue, strvalue.c_str());
	char* tmpStrvalue = strtok(tempvalue, ",");
	int index = 0;
	while (tmpStrvalue != NULL)
	{
		value[index] = atoi(tmpStrvalue);
		index++;
		tmpStrvalue = strtok(NULL, ",");
	}

	char *tempweight = new char[strweight.size()];
	strcpy(tempvalue, strweight.c_str());
	char* tmpStrweight = strtok(tempvalue, ",");
	index = 0;
	while (tmpStrweight != NULL)

	{
		weight[index] = atoi(tmpStrweight);
		index++;
		tmpStrweight = strtok(NULL, ",");
	}


	findmaxvalue(count, 0, 0);

	cout << maxvalue << endl;

	return 0;
}
