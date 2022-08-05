#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int quantity;
int buffer;
vector <vector <int>> cords;//gutter cords
vector <int> flow;//flow throw gutter
int ground;//all water on floor
int roof;//top Y of gutter end
vector <int> vec;
vector <int> vec2;
vector <int> vec3;

bool includ(vector <int> line, int x, int y)
{
	int subtraction = line[1] - line[3];
	int subtraction2 = y - line[1];

	double Pp = 0.5 * abs((line[0] - line[2]) * subtraction);
	double Pa = 0.5 * abs((line[0] * (line[3] - y) + line[2] * subtraction2 + x * subtraction));
	double Pb = 0.5 * abs((line[0] * (line[1] - y) + line[2] * subtraction2 + x * (line[1] - line[1])));
	double Pc = 0.5 * abs((line[2] * (line[3] - y) + line[2] * subtraction2 + x * subtraction));

	bool field = (Pp == Pa + Pb + Pc);
	return field;
}

bool rev_includ(vector <int> line, int x, int y)
{
	int subtraction = line[1] - line[3];

	double Pp = 0.5 * abs((line[0] - line[2]) * subtraction);
	double Pa = 0.5 * abs((line[0] * (line[3] - y) + line[2] * (y - line[1]) + x * subtraction));
	double Pb = 0.5 * abs((line[0] * (line[3] - y) + line[0] * (y - line[1]) + x * subtraction));
	double Pc = 0.5 * abs((line[0] * (line[3] - y) + line[2] * (y - line[3]) + 0));

	bool field = (Pp != Pa + Pb + Pc);
	return field;
}

int top_begin(vector <int> index)
{
	int best = 0;

	for (int i = 0; i < index.size(); i++)
	{
		if (cords[index[i]][1] > best)
		{
			best = cords[index[i]][1];
		}
	}

	for (int i = 0; i < index.size(); i++)
	{
		if (cords[index[i]][1] == best)
		{
			return index[i];
		}
	}
}

int top_out(vector <int> index)
{
	int best = 0;

	for (int i = 0; i < index.size(); i++)
	{
		if (cords[index[i]][3] > best)
		{
			best = cords[index[i]][3];
		}
	}

	for (int i = 0; i < index.size(); i++)
	{
		if (cords[index[i]][3] == best)
		{
			return index[i];
		}
	}
}

void sort()
{
	int x;
	int y;

	for (int i = 0; i < quantity; i++)
	{
		if (cords[i][1] < cords[i][3])
		{
			x = cords[i][2];
			y = cords[i][3];

			cords[i][2] = cords[i][0];
			cords[i][3] = cords[i][1];

			cords[i][0] = x;
			cords[i][1] = y;
		}
	}
}

int main()
{
	int free;

	cin >> quantity;
	cords.resize(quantity);
	flow.resize(quantity);

	ground = 0;

	for (int i = 0; i < quantity; i++)
	{
		cin >> buffer;
		cords[i].push_back(buffer);
		cin >> buffer;
		cords[i].push_back(buffer);
		cin >> buffer;
		cords[i].push_back(buffer);
		cin >> buffer;
		cords[i].push_back(buffer);
	}

	sort();

	for (int i = 0; i < 15; i++)
	{
		free = 0;
		vec.clear();
		vec2.clear();

		for (int j = 0; j < quantity; j++)
		{
			if (i >= cords[j][0] && i + 1 <= cords[j][2])
			{
				vec.push_back(j);
				free++;
			}

			if (i >= cords[j][2] && i + 1 <= cords[j][0])
			{
				vec.push_back(j);
				free++;
			}
		}

		if (free == 0)ground++;
		
		for (int j = 0; j < vec.size(); j++)
		{
			free = 0;

			for (int k = 0; k < vec.size(); k++)
			{
				if (j != k)
				{
					if (includ(cords[vec[j]], cords[vec[k]][0], cords[vec[k]][1]) || includ(cords[vec[j]], cords[vec[k]][2], cords[vec[k]][3])) {
						free = 1;
					}
				}
			}

			if (free == 0) {
				vec2.push_back(vec[j]);
			}
		}

		if (vec2.size() > 0) {
			flow[top_begin(vec2)]++;
		}
	}
	
	for (int i = 0; i < quantity; i++)
	{
		vec3.push_back(i);
		roof = cords[top_out(vec3)][3];
	}

	while (ground != 15)
	{
		vec.clear();

		for (int i = 0; i < quantity; i++)
		{
			if (cords[i][3] == roof)
			{
				vec.push_back(i);
			}
		}

		for (int i = 0; i < vec.size(); i++)
		{
			free = 0;
			vec2.clear();

			for (int j = 0; j < quantity; j++)
			{
				int a = cords[vec[i]][2];

				if (a >= cords[j][0] && a < cords[j][2] && cords[j][3] < roof && rev_includ(cords[j], cords[vec[i]][2], cords[vec[i]][3]))
				{
					vec2.push_back(j);
					free++;
				}

				if (a > cords[j][2] && a <= cords[j][0] && cords[j][3] < roof && rev_includ(cords[j], cords[vec[i]][2], cords[vec[i]][3]))
				{
					vec2.push_back(j);
					free++;
				}
			}

			if (free == 0)
			{
				ground = ground + flow[vec[i]];
			}

			for (int j = 0; j < vec2.size(); j++)
			{
				free = 0;

				for (int k = 0; k < vec2.size(); k++)
				{
					if (j != k)
					{
						if (includ(cords[vec2[j]], cords[vec2[k]][0], cords[vec2[k]][1]) || includ(cords[vec2[j]], cords[vec2[k]][2], cords[vec2[k]][3])) {
							free = 1;
						}
					}
				}

				if (free == 0) {
					vec3.push_back(vec2[j]);
				}
			}

			if (vec2.size() > 0) {
				flow[top_begin(vec2)] = flow[top_begin(vec2)] + flow[vec[i]];
			}
		}

		roof--;
	}

	for (int i = 0; i < quantity; i++)
	{
		cout << flow[i] << endl;
	}
}