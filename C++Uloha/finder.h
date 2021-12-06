#pragma once

#include <algorithm>
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class finder {
private:
	vector<vector<int>> matrix;
	finder();
public:
	finder(string pathToInputFile)
	{
		ifstream in(pathToInputFile);
		if (!in) {
			std::cout << "file doesn't exist";
			return;
		}

		string firstLine;
		getline(in, firstLine);
		firstLine.erase(std::remove(firstLine.begin(), firstLine.end(), '\n'), firstLine.end());

		string delim = ",";
		vector<string> words{};

		size_t pos = 0;
		firstLine.append(",");

		while ((pos = firstLine.find(delim)) != string::npos) {
			words.push_back(firstLine.substr(0, pos));
			firstLine.erase(0, pos + delim.length());
		}

		delim = "-";
		pos = 0;
		vector<string> names;

		for (auto a : words)
		{
			while ((pos = a.find(delim)) != string::npos) {
				names.push_back(a.substr(0, pos));
				a.erase(0, pos + delim.length());
				names.push_back(a);
			}
		}
		vector<string> TEST = names;

		sort(names.begin(), names.end());
		names.erase(unique(names.begin(), names.end()), names.end());

		for (size_t i = 0; i < names.size(); i++)
		{
			vector<int> tmpint;
			for (size_t j = 0; j < names.size(); j++)
			{
				tmpint.push_back(0);
			}
			matrix.push_back(tmpint);
		}

		for (size_t i = 0; i < TEST.size(); i = i + 2)
		{
			int pos1 = 0;
			int pos2 = 0;
			for (size_t j = 0; j < names.size(); j++)
			{
				if (names[j] == TEST[i])
				{
					pos1 = j;
				}

				if (names[j] == TEST[i + 1])
				{
					pos2 = j;
				}
			}
			matrix[pos1][pos2] = 1;
			matrix[pos2][pos1] = 1;
		}

		vector<string> input;
		int inputSize = input.size();
		string f;

		while (getline(in, f))
		{
			input.push_back(f);
		}

		string half;
		getline(in, half);
		pathToInputFile.replace(pathToInputFile.end() - 3, pathToInputFile.end(), "out");
		std::ofstream o(pathToInputFile);

		if (o.fail())
		{
			cout << "Nebolo mozne vytvorit vystupny subor";
			return;
		}

		for (size_t j = 0; j < input.size(); j++)
		{
			vector<string> daskama;
			vector<char> tmp;
			int stringl = input.at(j).length();

			vector<string> char_array;

			for (size_t i = 0; i < input[j].size(); i++)
			{
				if (input[j][i] != ',' && input[j][i] != '-')
				{
					tmp.push_back(input[j][i]);
					if (i >= input[j].size() - 1)
					{
						string s(tmp.begin(), tmp.end());
						daskama.push_back(s);
					}
				}
				else
				{
					string s(tmp.begin(), tmp.end());
					daskama.push_back(s);
					tmp.clear();
				}
			}

			int start = 0;
			int koniec = 0;

			for (size_t i = 0; i < names.size(); i++)
			{
				if (daskama[0] == names[i])
					start = i;
				if (daskama[1] == names[i])
					koniec = i;
			}

			// ALGORITHM
			vector<bool> visited;

			for (size_t i = 0; i < names.size(); i++)
			{
				visited.push_back(false);
			}

			stack<int> pom;
			bool found = false;
			bool pokracovat = true;
			int n = names.size();

			visited[start] = true;
			int current = start;

			while (pokracovat)
			{
				found = false;

				if (matrix[current][koniec] == 1)
				{
					o << "Yes\n";
					break;
				}

				for (int i = 0; i < n; i++)
				{
					if (matrix[current][i] == 1 && !visited[i]) // checking whether there is path that hasnt been checked yet
					{
						pom.push(current);
						visited[i] = true;
						current = i;
						found = true;
						break;
					}
				}

				if (!found) // if there is no available path that hasnt been checked yet we have to go back
				{
					if (!pom.empty())
					{
						current = pom.top();
						pom.pop();
					}
					else // if is stack empty => everything has been checked no path exists
					{
						o << "No\n";
						break;
					}
				}
			}
		}
		if (!o.fail())
		{
			cout << "Vystupny subor bol uspesne vytvoreny!";
			return;
		}
	}
};