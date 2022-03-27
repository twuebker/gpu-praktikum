#ifndef MESS_SAVER_H
#define MESS_SAVER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class MessSaver{
	public:
		static void add(std::string tag, float micros);
		static float get(std::string tag);
		static void printAll();
	private:
		static std::map<std::string, std::vector<float>> data;
	


};

#endif
