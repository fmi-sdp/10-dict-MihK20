#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;
using std::unordered_map;

void count_frequency(vector<string> input) {
	unordered_map<string, int> map;
	for (string i : input) {
		if (map.count(i) > 0) {
			map[i]++;
		}
		else {
			map.insert({ i, 1 });
		}
	}
	for (std::pair<string, int> word : map) {
		std::cout << word.first << ":" << word.second << " ";
	}

}

void group_pairs(vector < std::pair<string, string>> input) {
	unordered_map<string, vector<string>> map;
	for (std::pair<string, string> i : input) {
		if (map.count(i.second) > 0) {
			map[i.second].push_back(i.first);
		}
		else {
			map.insert({ i.second, {i.first} });
		}
	}
	
	for (std::pair<string, vector<string>> i : map) {
		std::cout << i.first << ": ";
		for (string j : i.second) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
}
void algorithm(string& str, unordered_map<char, char> map) {
	int len = str.size();
	for (size_t i = 0; i < len; i++) {
		if (map.count(str[i]) > 0) {
			str[i] = map[str[i]];
		}
	}
}

bool isomorph(string str1, string str2) {
	if (str1.size() != str2.size()) return false;
	if (str1 == "" || str2=="") {
		if (str1 != "" || str2 != "") return false;
		else {
			return true;
		}
	}

	std::unordered_map<char, char> map;
	for (size_t i = 0; i < str1.size(); i++) {
		if (map.count(str1[i]) > 0) {
			if (map[str1[i]] != str2[i]) return false;
		}
		else {
			map.insert({ str1[i], str2[i] });
		}
	}
	return true;
}

int main() {
	vector<std::pair<string, string>> input = { {"apple", "fruit"}, {"carrot", "vegetable"}, {"banana", "fruit"}, {"broccoli", "vegetable"} };
	unordered_map<char, char> rules;
	string str = "Hello world";
	rules.insert({ 'h','H' });
	rules.insert({ 'e','3' });
	rules.insert({ 'o','0' });
	string str1 = "ABBA";
	string str2 = "XTCX";	
//	count_frequency(input);
//	group_pairs(input);
//	algorithm(str, rules);
	std::cout << isomorph(str1, str2);
	return 0;
}